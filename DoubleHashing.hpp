#pragma once
#include "HashTableClosed.hpp"

template <typename T>
class DoubleHashing : public HashTableClosed<T> {
public:
    DoubleHashing(int size = 101)
        : HashTableClosed<T>(size) {}

    int hash2(const T& key) const {
        return 7 - (static_cast<int>(key) % 7);
    }

    int probeIndex(const T& key, int i) const override {
        int h1 = this->hash1(key);
        int h2 = hash2(key);
        return (h1 + i * h2) % this->M;
    }
 };
