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
        const_iterator(const iterator & other) : the_parent(other.the_parent), the_index(other.the_index), the_pos(other.the_pos) {
            std::cout << "const_iterator.h - convert const_iterator to const_iterator" << std::endl;
        }

        /** De-reference an const_iterator */
        const Entry_Type& operator*()const {
            std::cout << "const_iterator.h - operator*" << std::endl;
            return *the_pos;
	        /*</exercise>*/
        }

        /** De-reference an const_iterator */
        const Entry_Type * operator->()const {
            std::cout << "const_iterator.h - operator->" << std::endl;
            return& (*the_pos);
	        /*</exercise>*/
        }

        /* The rest of the definition of a const_iterator is
        the same as an const_iterator except for the class name */
        /** Prefix increment operator */
        const_iterator & operator++() {
            std::cout << "const_iterator.h - &operator++" << std::endl;
            ++the_pos;
            advance();
            return *this;
	        /*</exercise>*/
        }

        /** Postfix increment operator */
        const_iterator operator++(int) {
            std::cout << "const_iterator.h - operator++" << std::endl;
            const_iterator temp(*this);
            ++(*this);
            return temp;
	        /*</exercise>*/
        }

        /** Equality operator */
        bool operator==(const const_iterator & other)const {
            std::cout << "const_iterator.h - operator==" << std::endl;
            return ((the_index == other.the_index) && (the_pos == other.the_pos));
        }

        /** Inequality operator */
        bool operator != (const const_iterator & other)const {
            std::cout << "const_iterator.h - operator!=" << std::endl;
            return ((the_index != other.the_index) || (the_pos != other.the_pos));
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

        /** Construct an const_iterator starting at a given position
        in a give bucket */
        const_iterator(hash_map<Key_Type, Value_Type>  * parent, size_t index, typename std::list<Entry_Type>::iterator pos) : the_parent(parent), the_index(index), the_pos(pos) {
            std::cout << "const_iterator.h - constructor" << std::endl;
        }

        /** The map containing this const_iterator */
        hash_map<Key_Type, Value_Type>  * the_parent;

        /** The index of the bucket */
        size_t the_index;

        /** The const_iterator within the bucket */
        typename std::list<Entry_Type>::iterator the_pos;
        /*</exercise>*/
}; // End const_iterator

#endif
