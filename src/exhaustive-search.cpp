#include "exhaustive-search.hpp"

int xs::knapsack(std::vector<Item> &items, int w_max) {
    int best = 0;
    std::function<void(Item*,int)> f = [&](Item *it, int n) {
        int w = 0, v = 0;
        for (int i = 0; i < n; ++i) {
++op;       w += it[i].weight, v += it[i].value;
        }
++op;   if (w <= w_max && v > best)
            best = v;
    };
    xs::power_set(items, f);
    return best;
}