/** The const_iterator class */
    class const_iterator {
      /*<exercise chapter="9" type="programming-project" number="5">*/
    public:
      
      /** Convert from an iterator to a const_iterator */
      const_iterator(const typename hash_map<Key_Type, 
		     Value_Type>::iterator& other);
	
      /** De-reference an const_iterator */
      Entry_Type& operator*() const;
      
      Entry_Type* operator->() const;
      
      
      /** Prefix increment operator */
      const_iterator& operator++();
      
      /** Postfix increment operator */
      const_iterator operator++(int); 
      
      /** Equality operator */
      bool operator==(const const_iterator& other);
      /** Inequality operator */
      bool operator!=(const const_iterator& other) const;
      
    private:
      
      // The Map is our friend
      friend class hash_map<Key_Type, Value_Type>;
      
      /** Advance the iterator to the next position */
      void advance();
      
      /** Construct an const_iterator starting at a given position
	  in the hash table */
      const_iterator (const hash_map<Key_Type, Value_Type>* const parent,
		      size_t index);
      
      /** Pointer to the map containing the iterator */
      const hash_map<Key_Type, Value_Type>* const the_parent;
      
      /** The index of the current position */
      size_t the_index;
      
      
    }; // End const_iterator