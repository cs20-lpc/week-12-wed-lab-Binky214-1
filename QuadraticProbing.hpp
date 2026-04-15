#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class QuadraticProbing : public HashTableClosed<T> {
// inherits from HashTableClosed
// reuses hashing structure but changes probing behavior

public:

    // constructor: initializes hash table with given size (default 101)
    explicit QuadraticProbing(int size = 101)
        : HashTableClosed<T>(size) {}
        // calls base class constructor to set up table capacity

    // overrides probe function to use quadratic probing
    int probeIndex(const T& key, int i) const override {

        int h1 = this->hash1(key);
        // compute primary hash (starting index in table)

        return (h1 + i * i) % this->M;
        // quadratic probing formula:
        // index = (h1 + i²) mod table size

        // i increases: 0, 1, 4, 9, 16...
        // spreads out probes to reduce clustering
    }
};
