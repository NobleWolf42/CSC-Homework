/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef const_iterator_H_
#define const_iterator_H_

/** The const_iterator class */
class const_iterator {
    /*<exercise chapter="9" type="programming-project" number="5">*/
public:

        /** Convert from an iterator to a const_iterator */
    const_iterator(const typename hash_map<Key_Type,
            Value_Type>::iterator &other) : the_parent(other.the_parent), the_index(other.the_index) {}

    /** De-reference an const_iterator */
    Entry_Type &operator*() const {
        return *the_parent->the_table[the_index];
    }

    Entry_Type *operator->() const {
        return (the_parent->the_table[the_index]);
    }


    /** Prefix increment operator */
    const_iterator &operator++() {
        advance();
        return *this;
    }

    /** Postfix increment operator */
    const_iterator operator++(int) {
        const_iterator temp = *this;
        advance();
        return temp;
    }

    /** Equality operator */
    bool operator==(const const_iterator &other) const {
        return the_parent == other.the_parent && the_index == other.the_index;
    }

    /** Inequality operator */
    bool operator!=(const const_iterator &other) const {
        return !operator==(other);
    }

    private:

        // Allow the map to access the private constructor and data fields
        friend class hash_map<Key_Type, Value_Type>;

        // Allow iterators to access private data fields
        friend class iterator;

        /** Advance the const_iterator to the next position */
        void advance() {
        do {
            the_index++;
        } while (the_index < the_parent->the_table.size() && (the_parent->the_table[the_index] == NULL ||
                                                              the_parent->the_table[the_index] ==
                                                              hash_map<Key_Type, Value_Type>::DELETED));
    }

        /** Construct an const_iterator starting at a given position
    in the hash table */
    const_iterator(const hash_map<Key_Type, Value_Type> *const parent,
                   size_t index) : the_parent(parent), the_index(index) {}

    /** Pointer to the map containing the iterator */
    const hash_map<Key_Type, Value_Type> *const the_parent;

    /** The index of the current position */
    size_t the_index;
}; // End const_iterator

#endif
