#include "greedy.hpp"

int gd::knapsack(std::vector<Item> &items, int w_max) {
    std::vector<Item> its = items;
    std::sort(its.begin(), its.end(), [](Item &a, Item &b) {
        ++op;
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });
    int w = 0, v = 0;
    for (Item it : its) {
++op;   if (w + it.weight <= w_max) {
++op;       w += it.weight, v += it.value;
        }
    }
    return v;
}