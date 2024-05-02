/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef STATEPAIR
#define STATEPAIR

template<typename T1, typename T2>
class StatePair {
    public:
        // TODO: Define constructors
        StatePair() {

        }

        StatePair(T1 userKey, T2 userValue) {
            key = userKey;
            value = userValue;
        }
   
        // TODO: Define mutators, and accessors for StatePair
        T1 GetKey() {
            return key;
        }

        void SetKey(T1 userKey) {
            key = userKey;
        }

        T2 GetValue() {
            return value;
        }

        void SetValue(T2 userValue) {
            value = userValue;
        }
	
        // TODO: Define PrintInfo() method
        void PrintInfo() {
            std::cout << key << ": " << value << std::endl;
        }

    private:
        T1 key;
        T2 value;
};

#endif
