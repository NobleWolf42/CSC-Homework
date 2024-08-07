/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef HASH_TABLE_OPEN_H_
#define HASH_TABLE_OPEN_H_

/** Implementaion of the hash_map class using open hashing */

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW {
/** Definition of the hash_map class. This definition is similar
    to the unordered_map that has been proposed for the next
    version of the C++ standard.
    @param Key_Type The type of the keys
    @param Value_Type The type of the values
*/
    template<typename Key_Type, typename Value_Type>
    class hash_map {

    public:

        // Typedefs
        typedef std::pair<const Key_Type, Value_Type> Entry_Type;

        // Forward declaration of iterator
        class iterator;
        class const_iterator;

        /** Construct an empty hash_map. */
        hash_map() : hash_fcn(hash<Key_Type>()), num_keys(0), the_table(INITIAL_CAPACITY, NULL), LOAD_THRESHOLD(0.75), num_deletes(0), num_locates(0), num_probes(0) {
            std::cout << "HASH_TABLE_OPEN.h - default constructor" << std::endl;
        }

        /** TODO: Inserts an item into the map.
        post: The key is associated with the value in the map.
        @param entry The key, value pair to be inserted
        @return An iterator to the inserted item and true
        if the entry was inserted; an iterator to the existing
        item and false if the item is already present
        */
        std::pair<iterator, bool> insert(const Entry_Type &entry) {
            std::cout << "HASH_TABLE_OPEN.h - insert" << std::endl;
            double load = double(num_keys + num_deletes) / the_table.size();
            if (load > LOAD_THRESHOLD) {
                rehash(); // Double the size of the table.
            }
            // Find the position in the table.
            size_t index = locate(entry.first);
            // See whether it is empty.
            if (the_table[index] == NULL) {
                // Create a new entry.
                the_table[index] = new Entry_Type(entry);
                num_keys++;
                return std::make_pair(iterator(this, index), true);
            } else {
                // Item is already in the table.
                return std::make_pair(iterator(this, index), false);
            }
        }

        /** Lookup an item in the map
        @param key The key of the item being sought
        @return An iterator that references a
        pair<const Key_Type, Value_Type> that
        contains the key and the associated value sought,
        or end() if the key is not in the map.
        */
        iterator find(const Key_Type &key) {
            std::cout << "HASH_TABLE_OPEN.h - find" << std::endl;
            size_t index = locate(key);
            if (the_table[index] != NULL) {
                iterator it(this, index);
                return it;
            } else {
                return this->end();
            }
        }

        const_iterator find(const Key_Type &key) const {
            std::cout << "HASH_TABLE_OPEN.h - const find" << std::endl;
            size_t index = locate(key);
            if (the_table[index] != NULL) {
                const_iterator it(this, index);
                return it;
            } else {
                return this->end();
            }
        }

        /** Accesses a value in the map, using the key as an index.
        @param key The key of the item being sought
        @return A reference to the associated value. If the
        key was not in the map, a default value is inserted and
        a reference to this value is returned.
        */
        Value_Type &operator[](const Key_Type &key) {
            std::cout << "HASH_TABLE_OPEN.h - operator[]" << std::endl;
            // Try to insert a dummy item.
            std::pair<iterator, bool> out = insert(Entry_Type(key, Value_Type()));
            // Return a reference to the value found or inserted.
            return out.first->second;
        }

        /** TODO: Remove an item from the map based on a key
        @param key The key of the item to be removed
        @return true if the item removed, false if the item
        was not already in the map
        */
        bool erase(const Key_Type &key) {
            std::cout << "HASH_TABLE_OPEN.h - erase" << std::endl;
            size_t index = locate(key);
            if (the_table[index] == NULL) {
                return false;
            }
            the_table[index] = DELETED;
            num_deletes++;
            num_keys--;
            return true;
        }

        /** Return an iterator to the beginning of the map */
        iterator begin() {
            std::cout << "HASH_TABLE_OPEN.h - begin" << std::endl;
            size_t index = 0;

            while (index < the_table.size() && (the_table[index] == NULL || the_table[index] == DELETED)) {
                index++;
            }
            return iterator(this, index);
        }

        /** Return a const_iterator to the beginning of the map */
        const_iterator begin() const {
            std::cout << "HASH_TABLE_OPEN.h - const begin" << std::endl;
            size_t index = 0;

            while (index < the_table.size() && (the_table[index] == NULL || the_table[index] == DELETED)) {
                index++;
            }
            return const_iterator(this, index);
        }

        /** Return an iterator to the end of the map */
        iterator end() {
            std::cout << "HASH_TABLE_OPEN.h - end" << std::endl;
            return iterator(this, INITIAL_CAPACITY);
        }

        /** Return an iterator to the end of the map */
        const_iterator end() const {
            std::cout << "HASH_TABLE_OPEN.h - const end" << std::endl;
            return const_iterator(this, INITIAL_CAPACITY);
        }


        /** Return the size of the map */
        size_t size() const {
            std::cout << "HASH_TABLE_OPEN.h - size" << std::endl;
            return num_keys;
        }


        /** Determine if the map is empty */
        bool empty() const {
            std::cout << "HASH_TABLE_OPEN.h - empty" << std::endl;
            return num_keys == 0;
        }


        /** Return a string representation of the hash map
        @return A string that contains each pair enclosed in "[" and "]"
        with the key and value separated by a comma. The whole string
        is enclosed in "{" and "}"
        */
        std::string to_string() const {
            std::cout << "HASH_TABLE_OPEN.h - to_string" << std::endl;
            
            std::stringstream out;

            out << "{";
            for (int i = 0; i < the_table.size(); i++) {
                if (the_table[i] != NULL && the_table[i] != hash_map<Key_Type, Value_Type>::DELETED) {
                    out << "[" << the_table[i]->first << ", " << the_table[i]->second << "]";
                }
            }
            out << "}";

            return out.str();
        }

        //Think I got the math right but not sure if I am using the right formula also should be using num_probes most likely but unsure exactly what this function does.
        double average_probes() const {
            std::cout << "HASH_TABLE_OPEN.h - average_probes" << std::endl;
            double temp = 0;
            temp = (1 / 2) * (1 + (1 / (1 - LOAD_THRESHOLD)));
            return temp;
        }


        #include "const_iterator.h"
        #include "iterator.h"


    private:
        /** Expand the table size when load_factor exceeds LOAD_THRESHOLD.
        post: The size of the table is doubled.
        Each nondeleted entry from the original table is
        reinserted into the expanded table.
        The value of num_keys is reset to the number of items
        actually inserted; num_deletes is reset to 0.
        */
        void rehash() {
            std::cout << "HASH_TABLE_OPEN.h - rehash" << std::endl;
            // Create a new table whose size is double the current table.
            std::vector<Entry_Type *> other_table(the_table.size() * 2, NULL);

            // Swap this table with the current table.
            the_table.swap(other_table);

            // Reinsert all items from old table to new.
            num_deletes = 0;
            for (size_t i = 0; i < other_table.size(); i++) {
                if ((other_table[i] != NULL) && (other_table[i] != hash_map<Key_Type, Value_Type>::DELETED)) {
                    size_t index = locate(other_table[i]->first);
                    the_table[index] = other_table[i];
                }
            }
        }

        /** TODO: Locates the entry in the hash table that contains the target key
        or finds the next free entry.
        @param key The key being sought
        @return The position of the key or the first empty slot if
        the key is not in the table
        */
        size_t locate(const Key_Type &key) {
            std::cout << "HASH_TABLE_OPEN.h - locate" << std::endl;
            num_locates++;
            size_t index = hash_fcn(key) % the_table.size();
            while (the_table[index] != NULL && (the_table[index] == DELETED || the_table[index]->first != key)) {
                index = (index + 1) % the_table.size();
            }
            return index;
        }


        /** The hash function object */
        hash<Key_Type> hash_fcn;

        /** The number of items currently in the map */
        size_t num_keys;

        /** The vector containing the hash_table */
        std::vector<Entry_Type *> the_table;

        /** The initial capacity */
        static const size_t INITIAL_CAPACITY = 100;

        /** The maximum load factor */
        const double LOAD_THRESHOLD;

        /** The number of deleted keys */
        size_t num_deletes;

        /** The number of probes */
        size_t num_probes;

        /** The number of calls to locate */
        size_t num_locates;


        /** A dummy entry and a pointer to it */
        static Entry_Type dummy;
        static Entry_Type *const DELETED;

    }; // End hash_map
    template<typename Key_Type, typename Value_Type>
    typename hash_map<Key_Type, Value_Type>::Entry_Type
            hash_map<Key_Type, Value_Type>::dummy = std::pair<const Key_Type, Value_Type>(Key_Type(), Value_Type());

    template<typename Key_Type, typename Value_Type>
    typename hash_map<Key_Type, Value_Type>::Entry_Type *const
            hash_map<Key_Type, Value_Type>::DELETED = &hash_map<Key_Type, Value_Type>::dummy;
}// namespace KW

#endif
