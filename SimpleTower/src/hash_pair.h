#ifndef SRC_HASH_PAIR_H
#define SRC_HASH_PAIR_H
/**
 * @file
 * @author  Kirill Gubarkov <gubarkir@cvut.cz>
 * @version 1.0
 */
/**
 * Struct for hash function for a pair
 */
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }
        return hash1;
    }
};

#endif //SRC_HASH_PAIR_H