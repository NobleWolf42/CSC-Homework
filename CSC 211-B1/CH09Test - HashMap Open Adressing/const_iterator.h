/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef const_iterator_H_
#define const_iterator_H_

/** The const_iterator class */
class const_iterator {
    /*<exercise chapter="9" type="programming-project" number="6">*/
    public:

        /** Convert from an const_iterator to a const_iterator */
        const_iterator(const typename hash_map<Key_Type, Value_Type>::iterator &other) : the_parent(other.the_parent), the_index(other.the_index) {
            std::cout << "const_iterator.h - convert iterator to const_iterator" << std::endl;
        }

        /** De-reference an const_iterator */
        const Entry_Type &operator*() const {
            std::cout << "const_iterator.h - operator*" << std::endl;
            return *the_parent->the_table[the_index];
	        /*</exercise>*/
        }

        /** De-reference an const_iterator */
        const Entry_Type *operator->() const {
            return (the_parent->the_table[the_index]);
	        /*</exercise>*/
        }

        /* The rest of the definition of a const_iterator is
        the same as an iterator except for the class name */
        /** Prefix increment operator */
        const_iterator & operator++() {
            std::cout << "const_iterator.h - &operator++" << std::endl;
            advance();
            return *this;
	        /*</exercise>*/
        }

        /** Postfix increment operator */
        const_iterator operator++(int) {
            std::cout << "const_iterator.h - operator++" << std::endl;
            const_iterator temp = *this;
            advance();
            return temp;
	        /*</exercise>*/
        }

        /** Equality operator */
        bool operator==(const const_iterator & other)const {
            std::cout << "const_iterator.h - operator==" << std::endl;
            return ((the_index == other.the_index) && (the_parent == other.the_parent));
        }

        /** Inequality operator */
        bool operator != (const const_iterator & other)const {
            std::cout << "const_iterator.h - operator!=" << std::endl;
            return ((the_index != other.the_index) || (the_parent != other.the_parent));
            /*</exercise>*/
        }

    private:

        // Allow the map to access the private constructor and data fields
        friend class hash_map<Key_Type, Value_Type>;

        // Allow iterators to access private data fields
        friend class iterator;

        /** Advance the const_iterator to the next position */
        void advance() {
            std::cout << "const_iterator.h - advance" << std::endl;
            while (the_index < the_parent->the_table.size() && (the_parent->the_table[the_index] == NULL || the_parent->the_table[the_index] == hash_map<Key_Type, Value_Type>::DELETED)) {
                the_index++;
            }
	    	/*</exercise>*/
        }

        // Insert constructor and data fields here

        /** Construct an const_iterator starting at a given position
        in a given bucket */
        const_iterator(const hash_map<Key_Type, Value_Type> *const parent,
                   size_t index) : the_parent(parent), the_index(index) {
            std::cout << "const_iterator.h - constructor" << std::endl;
        }

        /** Pointer to the map containing the iterator */
        const hash_map<Key_Type, Value_Type> *const the_parent;

        /** The index of the bucket */
        size_t the_index;
        /*</exercise>*/
}; // End const_iterator

#endif
