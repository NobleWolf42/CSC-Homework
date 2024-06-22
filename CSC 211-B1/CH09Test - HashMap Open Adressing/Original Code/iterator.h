/** The iterator class */
    class iterator {
      
    public:
      
      /** De-reference an iterator */
      Entry_Type& operator*() const;
      
      /** De-reference an iterator */
      Entry_Type* operator->() const;
      
      /** Prefix increment operator */
      iterator& operator++();
      
      /** Postfix increment operator */
      iterator operator++(int);
      
      /** Equality operator */
      bool operator==(const iterator& other) const;
      
    private:
      
      // Allow the map to access the private constructor and data fields
      friend class hash_map<Key_Type, Value_Type>;
      
      // Allow const_iterators to access private data fields
      friend class const_iterator;
      
      /** Advance the iterator to the next position */
      void advance();
      
      /** Construct an iterator starting at a given position
	  in the hash table */
      iterator (hash_map<Key_Type, Value_Type>* parent,
		size_t index);
      /** Pointer the the map containing this iterator */
      hash_map<Key_Type, Value_Type>* the_parent;
      
      /** The index of the current position */
      size_t the_index;
      
      
    }; // End iterator