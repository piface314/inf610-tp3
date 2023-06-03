#ifndef EXHAUSTIVE_SEARCH_H
#define EXHAUSTIVE_SEARCH_H

#include <functional>
#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace xs {

    template <typename T>
    void power_set_r(T *v, int n, T *b, int m, std::function<void (T *v, int n)> f) {
        if (n == 0)
            return f(b, m);
        power_set_r(v + 1, n - 1, b, m, f);
++op;   b[m] = *v;
        power_set_r(v + 1, n - 1, b, m + 1, f);
    }

    template <typename T>
    void power_set(std::vector<T> &items, std::function<void (T *v, int n)> f) {
        int n = (int)items.size();
        T buffer[n], v[n];
        for (int i = 0; i < n; ++i)
            v[i] = items[i];
        power_set_r(v, n, buffer, 0, f);
    }

    int knapsack(std::vector<Item> &items, int w_max);
}

#endif