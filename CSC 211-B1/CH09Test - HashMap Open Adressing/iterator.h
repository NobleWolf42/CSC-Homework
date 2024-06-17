/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef iterator_H_
#define iterator_H_

/** The iterator class */
class iterator {
    /*<exercise chapter="9" type="programming-project" number="6">*/
    public:

        /** De-reference an iterator */
        Entry_Type& operator*() const {
            std::cout << "iterator.h - operator*" << std::endl;
            return *the_parent->the_table[the_index];
	        /*</exercise>*/
        }

        /** De-reference an iterator */
        Entry_Type * operator->()const {
            std::cout << "iterator.h - operator->" << std::endl;
            return the_parent->the_table[the_index];
	        /*</exercise>*/
        }

        /** Prefix increment operator */
        iterator & operator++() {
            std::cout << "iterator.h - &operator++" << std::endl;
            advance();
            return *this;
	        /*</exercise>*/
        }

        /** Postfix increment operator */
        iterator operator++(int) {
            std::cout << "iterator.h - operator++" << std::endl;
            iterator temp(*this);
            advance();
            return *this;
	        /*</exercise>*/
        }

        /** Equality operator */
        bool operator==(const iterator & other)const {
            std::cout << "iterator.h - operator==" << std::endl;
            return ((the_index == other.the_index) && (the_parent == other.the_parent));
        }

        /** Inequality operator */
        bool operator != (const iterator & other)const {
            std::cout << "iterator.h - operator!=" << std::endl;
            return ((the_index != other.the_index) || (the_parent != other.the_parent));
            /*</exercise>*/
        }

    private:

        // Allow the map to access the private constructor and data fields
        friend class hash_map<Key_Type, Value_Type>;

        // Allow const_iterators to access private data fields
        friend class const_iterator;

        /** Advance the iterator to the next position */
        void advance() {
            std::cout << "iterator.h - advance" << std::endl;
            while (the_index < the_parent->the_table.size() && (the_parent->the_table[the_index] == NULL || the_parent->the_table[the_index] == hash_map<Key_Type, Value_Type>::DELETED)) {
                the_index++;
            }
	    	/*</exercise>*/
        }

        // Insert constructor and data fields here

        /** Construct an iterator starting at a given position
        in a give bucket */
        iterator(hash_map<Key_Type, Value_Type>* parent, size_t index) : the_parent(parent), the_index(index) {
            std::cout << "iterator.h - constructor" << std::endl;
        }

        /** The map containing this iterator */
        hash_map<Key_Type, Value_Type>  * the_parent;

        /** The index of the bucket */
        size_t the_index;
    
}; // End iterator

#endif
