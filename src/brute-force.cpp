#include "brute-force.hpp"

int bf::knapsack(std::vector<Item> items, int w_max) {
    return knapsack((int)items.size(), items, w_max);
}

int bf::knapsack(int n, std::vector<Item> items, int w_max) {
    if (n == 0)
        return 0;
    Item it = items[n-1];
    ++op;
    if (it.weight > w_max)
        return knapsack(n-1, items, w_max);
    op += 2;
    return std::max(
        knapsack(n-1, items, w_max),
        knapsack(n-1, items, w_max - it.weight) + it.value
    );
}