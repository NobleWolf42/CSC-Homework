/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef HASH_H_
#define HASH_H_

/** Write a Hash Function Objects Template */
template<typename Key_Type>
struct hash {
    size_t operator()(const Key_Type&);
};

// Write a specialization for string
#include <string>
template<>
struct hash<std::string> {
    size_t operator()(const std::string& s) {
        size_t result = 0;
        for (size_t i = 0; i < s.length(); i++) {
            result = result * 31 + s[i];
        }
        return result;
    }
};

// Write a specialization for int
template<>
struct hash<int> {
    size_t operator()(int i) {
        return size_t(4262999287U * i);
    }
};

// Write a specialization for person
#include "Person.h"
template<>
struct hash<Person> {
    size_t operator() (const Person& p) {
        return hash<std::string>()(p.get_family_name());
    }
};

#endif
