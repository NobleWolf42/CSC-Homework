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
          return *the_parent->the_table[the_index];
      }
      
      /** De-reference an iterator */
      Entry_Type* operator->() const {
          return the_parent->the_table[the_index];
      }
      
      /** Prefix increment operator */
      iterator& operator++() {
          advance();
          return *this;
      }
      
      /** Postfix increment operator */
      iterator operator++(int) {
          iterator temp = *this;
          advance();
          return temp;
      }
      
      /** Equality operator */
      bool operator==(const iterator& other) const {
          return the_parent == other.the_parent && the_index == other.the_index;
      }

      bool operator!=(const iterator& other) const {
          return !operator==(other);
      }

    private:

        // Allow the map to access the private constructor and data fields
        friend class hash_map<Key_Type, Value_Type>;

        // Allow const_iterators to access private data fields
        friend class const_iterator;

        /** Advance the iterator to the next position */
        void advance() {
          do {
             the_index++;
          } while (the_index < the_parent->the_table.size() && (the_parent->the_table[the_index] == NULL || the_parent->the_table[the_index] == hash_map<Key_Type, Value_Type>::DELETED));
      }

        /** Construct an iterator starting at a given position
	  in the hash table */
      iterator(hash_map<Key_Type, Value_Type>* parent, size_t index) : the_parent(parent), the_index(index) {}
      /** Pointer the the map containing this iterator */
      hash_map<Key_Type, Value_Type>* the_parent;
      
      /** The index of the current position */
      size_t the_index;
    
}; // End iterator

#endif
