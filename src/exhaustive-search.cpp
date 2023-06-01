#include "exhaustive-search.hpp"

int xs::knapsack(std::vector<Item> &items, int w_max) {
    int best = 0;
    for (auto set : xs::power_set(items)) {
        int w = 0, v = 0;
        for (Item it : set) {
++op;       w += it.weight, v += it.value;
        }
++op;   if (w <= w_max && v > best)
            best = v;
    }
    return best;
}