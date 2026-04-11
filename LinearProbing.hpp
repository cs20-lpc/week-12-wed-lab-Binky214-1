#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class LinearProbing : public HashTableClosed<T> {
private:
    int skip; // skip factor
public:
    LinearProbing(int size = 101, int skipFactor = 3)
        : HashTableClosed<T>(size), skip(skipFactor) {}

    
    int probeIndex(const T& key, int i) const override {
        int h1 = this->hash1(key);
        return (h1 + i * skip) % this->M;
    }
};
