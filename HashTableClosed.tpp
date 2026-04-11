template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    for (int i = 0; i < M; i++) {
        int index = probeIndex(key, i);

        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = true;
            N++;
            return i + 1; // number of probes
        }
    }

    throw overflow_error("Hash table is full");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    for (int i = 0; i < M; i++) {
        int index = probeIndex(key, i);

        if (!occupied[index]) {
            return {false, i + 1}; // stop early
        }

        if (table[index] == key) {
            return {true, i + 1};
        }
    }

    return {false, M};
}