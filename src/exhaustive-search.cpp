#include "exhaustive-search.hpp"

int xs::knapsack(std::vector<Item> &items, int w_max) {
    int best = 0;
    std::function<void(std::vector<Item>&)> f = [&](std::vector<Item> &its) {
        int w = 0, v = 0;
        for (Item it : its) {
++op;       w += it.weight, v += it.value;
        }
++op;   if (w <= w_max)
            return;
++op;   if (v > best)
            best = v;
    };
    xs::power_set(items, f);
    return best;
}