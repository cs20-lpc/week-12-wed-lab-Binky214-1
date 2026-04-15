#pragma once
#include "HashTableClosed.hpp"

// LinearProbing class inherits from HashTableClosed
template <typename T>
class LinearProbing : public HashTableClosed<T> {

private:
    int skip; 
    // skip factor determines how far we jump on each collision
    // instead of +1 each time, we jump by "skip"

public:

    // constructor: initializes table size and skip factor
    LinearProbing(int size = 101, int skipFactor = 3)
        : HashTableClosed<T>(size), skip(skipFactor) {}
        // calls base class constructor to set table size
        // initializes skip value used in probing

    // overrides probing function from base class
    int probeIndex(const T& key, int i) const override {

        int h1 = this->hash1(key); 
        // compute primary hash (starting index)

        return (h1 + i * skip) % this->M; 
        // linear probing formula with custom step size:
        // index = (start + i * skip) mod table size

        // ensures index always stays within valid table bounds
    }
};
