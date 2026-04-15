// Inserts a key into the hash table using probing (linear / double hashing depending on probeIndex)
template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    for (int i = 0; i < M; i++) { 
        // loop through all possible probe attempts (up to table size)

        int index = probeIndex(key, i); 
        // compute the index to try using probing strategy

        if (!occupied[index]) { 
            // if slot is empty (never used or not occupied)

            table[index] = key; 
            // store key in the table at computed index

            occupied[index] = true; 
            // mark this slot as now occupied

            N++; 
            // increase number of stored elements

            return i + 1; 
            // return number of probes it took to insert
        }
    }

    throw overflow_error("Hash table is full"); 
    // if no empty slot found after full probing cycle, table is full
}

// Searches for a key in the hash table
// returns: {found?, number of probes used}
template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    for (int i = 0; i < M; i++) { 
        // loop through all possible probe positions

        int index = probeIndex(key, i); 
        // compute next index using probing function

        if (!occupied[index]) { 
            // if we hit an empty slot
            // key cannot be further in probe sequence

            return {false, i + 1}; 
            // stop early: key is not in table
            // return false and number of probes used
        }

        if (table[index] == key) { 
            // if key is found at this index

            return {true, i + 1}; 
            // return success and number of probes used
        }
    }

    return {false, M}; 
    // if full loop completed, key not found
}
