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
        Entry_Type& operator*()const {
            std::cout << "iterator.h - operator*" << std::endl;
            return *the_pos;
	        /*</exercise>*/
        }

        /** De-reference an iterator */
        Entry_Type * operator->()const {
            std::cout << "iterator.h - operator->" << std::endl;
            return& (*the_pos);
	        /*</exercise>*/
        }

        /** Prefix increment operator */
        iterator & operator++() {
            std::cout << "iterator.h - &operator++" << std::endl;
            ++the_pos;
            advance();
            return *this;
	        /*</exercise>*/
        }

        /** Postfix increment operator */
        iterator operator++(int) {
            std::cout << "iterator.h - operator++" << std::endl;
            iterator temp(*this);
            ++(*this);
            return temp;
	        /*</exercise>*/
        }

        /** Equality operator */
        bool operator==(const iterator & other)const {
            std::cout << "iterator.h - operator==" << std::endl;
            return ((the_index == other.the_index) && (the_pos == other.the_pos));
        }

        /** Inequality operator */
        bool operator != (const iterator & other)const {
            std::cout << "iterator.h - operator!=" << std::endl;
            return ((the_index != other.the_index) || (the_pos != other.the_pos));
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
            if (the_pos != the_parent->the_buckets[the_index].end()) {
                return;
            } else {
                while (the_index < the_parent->the_buckets.size() - 1) {
                    the_index++;
                    the_pos = the_parent->the_buckets[the_index].begin();
                    if (the_pos != the_parent->the_buckets[the_index].end()) {
                        return;
                    }
                }
                the_pos = the_parent->the_buckets[the_index].end();
            }
	    	/*</exercise>*/
        }

        // Insert constructor and data fields here

        /** Construct an iterator starting at a given position
        in a give bucket */
        iterator(hash_map<Key_Type, Value_Type>  * parent, size_t index, typename std::list<Entry_Type>::iterator pos) : the_parent(parent), the_index(index), the_pos(pos) {
            std::cout << "iterator.h - constructor" << std::endl;
        }

        /** The map containing this iterator */
        hash_map<Key_Type, Value_Type>  * the_parent;

        /** The index of the bucket */
        size_t the_index;

        /** The iterator within the bucket */
        typename std::list<Entry_Type>::iterator the_pos;

    
}; // End iterator

#endif
