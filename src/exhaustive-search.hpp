#ifndef EXHAUSTIVE_SEARCH_H
#define EXHAUSTIVE_SEARCH_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace xs {

    template <typename T>
    void power_set(size_t n, std::vector<T> &v, std::vector<T> &buffer,
            std::vector<std::vector<T>> &p) {
        if (n == 0) {
++op;       return p.push_back(buffer);
        }
        power_set(n-1, v, buffer, p);
++op;   buffer.push_back(v[n-1]);
        power_set(n-1, v, buffer, p);
++op;   buffer.pop_back();
    }

    template <typename T>
    std::vector<std::vector<T>> power_set(std::vector<T> v) {
        std::vector<std::vector<T>> p;
        std::vector<T> buffer;
        power_set(v.size(), v, buffer, p);
        return p;
    }

    int knapsack(std::vector<Item> items, int w_max);
}

#endif