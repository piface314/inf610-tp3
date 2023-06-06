#ifndef EXHAUSTIVE_SEARCH_H
#define EXHAUSTIVE_SEARCH_H

#include <functional>
#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace xs {
    
    template <typename T>
    void power_set_r(std::vector<T> &v, int n, std::vector<T> &b, std::function<void (std::vector<T> &v)> f) {
        if (n == 0)
            return f(b);
        power_set_r(v, n - 1, b, f);
++op;   b.push_back(v[n-1]);
        power_set_r(v, n - 1, b, f);
++op;   b.pop_back();
    }

    template <typename T>
    void power_set(std::vector<T> &v, std::function<void (std::vector<T> &v)> f) {
        std::vector<T> buffer;
        power_set_r(v, (int)v.size(), buffer, f);
    }

    int knapsack(std::vector<Item> &items, int w_max);
}

#endif
