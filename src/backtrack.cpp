#include "backtrack.hpp"

int bt::knapsack(std::vector<Item> &items, int w_max) {
    return knapsack((int)items.size(), items, w_max);
}

int bt::knapsack(int n, std::vector<Item> &items, int w_max) {
    return 0;
}