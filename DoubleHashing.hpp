#pragma once 

#include "HashTableClosed.hpp" 

template <typename T>
class DoubleHashing : public HashTableClosed<T> {
// inherits from HashTableClosed
// reuses the base hash table structure but changes probing strategy

public:

    // constructor: initializes hash table with given size (default 101)
    DoubleHashing(int size = 101)
        : HashTableClosed<T>(size) {} 
        // calls base class constructor to set up table size

    // secondary hash function used for double hashing
    int hash2(const T& key) const {
        // converts key to int and ensures it is compatible with modulo arithmetic
        return 7 - (static_cast<int>(key) % 7); 
        // ensures step size is non-zero and relatively prime to table size
    }

    // overrides probing function from base class
    int probeIndex(const T& key, int i) const override {
        // first hash value (starting position)
        int h1 = this->hash1(key); 
        // primary hash inherited from base class

        // second hash value (step size)
        int h2 = hash2(key);

        // double hashing formula:
        // index = (h1 + i * h2) % table_size
        return (h1 + i * h2) % this->M; 
        // ensures index stays within bounds of table
    }
};
