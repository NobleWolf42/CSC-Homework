/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef HASH_TABLE_CHAIN_H_
#define HASH_TABLE_CHAIN_H_

/** Implementaion of the hash_map class using chaining */

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW
{
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
        hash_map() : hash_fcn(hash<Key_Type>()), num_keys(0), the_buckets(INITIAL_CAPACITY), LOAD_THRESHOLD(3.0) {
            std::cout << "HASH_TABLE_CHAIN.h - constructor" << std::endl;
        }
        /*</exercise>*/

        /** Inserts an item into the map.
            post: The key is associated with the value in the map.
            @param entry The key, value pair to be inserted
            @return an iterator to the inserted item and true
                if the entry was inserted, an iterator to the existing
                item and false if the item is already present
        */
        std::pair<iterator, bool> insert(const Entry_Type& entry) {
            std::cout << "HASH_TABLE_CHAIN.h - insert" << std::endl;
        	/*</exercise>*/
            // Check for the need to rehash.
            double load_factor = double(num_keys) / the_buckets.size();
            if (load_factor > LOAD_THRESHOLD) {
                rehash();
            }

            // Find the position in the table.
            size_t index = hash_fcn(entry.first) % the_buckets.size();

            // Search for the key.
            typename std::list<Entry_Type>::iterator pos = the_buckets[index].begin();
            while (pos != the_buckets[index].end() && pos->first != entry.first) {
                ++pos;
            }

            if (pos == the_buckets[index].end()) { //Not in table
                the_buckets[index].push_back(Entry_Type(entry));
                num_keys++;
                return std::make_pair(iterator(this, index, --(the_buckets[index].end())), true);
            } else { //Already there
                return std::make_pair(iterator(this, index, pos), false);
            }

        }

        /** Lookup an item in the map
	    @param key The key of the item being sought
	    @return An iterator that references a 
	    pair<const Key_Type, Value_Type> that
	    contains the key and the associated value sought,
	    or end() if the key is not in the map.
        */
        iterator find(const Key_Type& key) {
            std::cout << "HASH_TABLE_CHAIN.h - find" << std::endl;
	        /*<exercise>*/
	        // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();

            // Search for the key
            for (auto it = the_buckets[index].begin(); it != the_buckets[index].end(); ++it) {
                if (it->first == key) {
                    return iterator(this, index, it);
                }
            }
            return end();
            /*</exercise>*/
        }


        /** Lookup an item in the map
	    @param key The key of the item being sought
	    @return An iterator that references a 
	    pair<const Key_Type, Value_Type> that
	    contains the key and the associated value sought,
	    or end() if the key is not in the map.
        */
        const_iterator find(const Key_Type& key) const {
            std::cout << "HASH_TABLE_CHAIN.h - const find" << std::endl;
	        /*<exercise>*/
	        // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();

            // Search for the key
            for (auto it = the_buckets[index].begin(); it != the_buckets[index].end(); ++it) {
                if (it->first == key) {
                    return iterator(this, index, it);
                }
            }
            return end();
	        /*</exercise>*/
        }

        /** Access a value in the map, using the key as an index
	    @param key The key of the item being sought
	    @return A reference to the associated value. If the
	    key was not in the map, a default value is inserted and
	    a reference to this value returned.
        */
        Value_Type& operator[](const Key_Type& key) {
            std::cout << "HASH_TABLE_CHAIN.h - operator[]" << std::endl;

            size_t index = hash_fcn(key) % the_buckets.size();
            for (auto it = the_buckets[index].begin(); it != the_buckets[index].end(); ++it) {
                if (it->first == key) {
                    return it->second;
                }
            }
            
            // Try to insert a dummy item
            Entry_Type  entry(key, Value_Type());
            the_buckets[index].push_back(entry);
            ++num_keys;
            auto it = the_buckets[index].end();
            --it;

	        // Return a reference to the value found or inserted
            return it->second;
        }

        /** Remove an item from the map based on a key
	    @param key The key of the item to be removed
	    @return true if the item removed, false if the item
	    was not already in the map
        */
        bool erase(const Key_Type& key) {
            std::cout << "HASH_TABLE_CHAIN.h - erase" << std::endl;
	        /*<exercise chapter="9" section="4" type="programming" number="2">*/
            // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();

	        // Search for the key
            for (auto it = the_buckets[index].begin(); it != the_buckets[index].end(); ++it) {
                if (it->first == key) {
                    the_buckets[index].erase(it);
                    --num_keys;
                    return true;
                }
            }
            return false;
	        /*</exercise>*/
        }

        /** Return an iterator to the beginning of the map */
        iterator begin() {
            std::cout << "HASH_TABLE_CHAIN.h - begin" << std::endl;
            size_t index = 0;
            while (index != the_buckets.size() && the_buckets[index].empty()) {
                index++;
            }
            if (index != the_buckets.size()) {
                return iterator(this, index, the_buckets[index].begin());
            } else {
                return end();
            }
        }

        /** Return a const_iterator to the beginning of the map */
        const_iterator begin() const {
            std::cout << "HASH_TABLE_CHAIN.h - const begin" << std::endl;
             size_t index = 0;
            while (index != the_buckets.size() && the_buckets[index].empty()) {
                index++;
            }
            if (index != the_buckets.size()) {
                return const_iterator(this, index, the_buckets[index].begin());
            } else {
                return end();
            }
        }

        /** Return an iterator to the end of the map */
        iterator end() {
            std::cout << "HASH_TABLE_CHAIN.h - end" << std::endl;
            size_t index = the_buckets.size();
            while (index > 0) {
                --index;
                if (!the_buckets[index].empty()) {
                    return iterator(this, index, the_buckets[index].end());
                }
            }
            return iterator(this, index, the_buckets[index].begin());
	    }

        /** Return a const_iterator to the end of the map */
        const_iterator end() const {
            std::cout << "HASH_TABLE_CHAIN.h - const end" << std::endl;
            size_t index = the_buckets.size();
            while (index > 0) {
                --index;
                if (!the_buckets[index].empty()) {
                    return const_iterator(this, index, the_buckets[index].end());
                }
            }
            return const_iterator(this, index, the_buckets[index].begin());
	    }

        /*<exercise chapter="9" section="4" type="programming" number="5">*/
        /** Return the size of the map */
        size_t size() const {
            std::cout << "HASH_TABLE_CHAIN.h - size" << std::endl;
            return num_keys;
            /*</exercise>*/
	    }

          /** Determine if the map is empty */
        bool empty() const {
            std::cout << "HASH_TABLE_CHAIN.h - empty" << std::endl;
            return num_keys == 0;
		    /*</exercise>*/
	    }

        /*</exercise chapter="9" section="4" type="programming" number="3">*/
        /** Return a string representation of the hash map 
	    @return A string that contains each pair enclosed in "[" and "]"
	    with the key and value separated by a comma. The whole string
	    is enclosed in "{" and "}" 
        */
        std::string to_string() const {
            std::cout << "HASH_TABLE_CHAIN.h - to_string" << std::endl;

            std::stringstream out;
            bool temp = false;

            out << "{";
            for (const std::list<Entry_Type>& bucket : the_buckets) {
                for (const Entry_Type& entry : bucket) {
                    if (temp) {
                        out << ",";
                    }
                    out << "[" << entry.first << ", " << entry.second << "]";
                    temp = true;
                }
            }
            out << "}";

            return out.str();
	    	/*</exercise>*/
        }

        // See iterator class
	    /*</exercise>*/
        #include "iterator.h"

	    // See const_iterator class
	    /*</exercise>*/
        #include "const_iterator.h"

    private:

        /** Expand the size of the hash table */
        void rehash() {
            std::cout << "HASH_TABLE_CHAIN.h - rehash" << std::endl;
	        /*<exercise chapter="9" section="4" type="programming" number="2">*/
	        // Create a new table that is twice the size
            std::vector<std::list<Entry_Type>> other_buckets(the_buckets.size() * 2);

	        // Swap tables
            for (std::list<Entry_Type>& bucket : the_buckets) {
                for (Entry_Type& entry : bucket) {
                    other_buckets[hash_fcn(entry.first) % (the_buckets.size() * 2)].push_back(entry);
                }
            }

	        // Reinsert items from old table to new one
            the_buckets.swap(other_buckets);

	        /*</exercise>*/
        }

        // Insert data fields here
        /** The hash function object */
        hash<Key_Type> hash_fcn;

        /** The number of items currently in the map */
        size_t num_keys;
    
        /** Vector of lists containing the buckets */
        std::vector<std::list<Entry_Type>> the_buckets;
    
        /** The initial capacity */
        static const size_t INITIAL_CAPACITY = 20;
    
        /** The maximum load factor */
        const double LOAD_THRESHOLD;

}; // End hash_map
}  // End namespace KW

#endif
