#ifndef HASH_H_
#define HASH_H_


/** Hash Function Objects Template */
template<typename Key_Type>
  struct hash {
    size_t operator()(const Key_Type&);
};

// Specialization for string
#include <string>
template<>
  struct hash<std::string> {
    size_t operator()(const std::string& s);
};
// Specialization for int
template<>
  struct hash<int> {
    size_t operator()(int i);
};


#endif
