#include "brute-force.hpp"

int bf::knapsack(std::vector<Item> &items, int w) {
    return knapsack(items, (int)items.size(), w);
}

int bf::knapsack(std::vector<Item> &items, int n, int w) {
    if (n == 0 || w == 0)
        return 0;
    Item it = items[n-1];
    ++op;
    if (it.weight > w)
        return knapsack(items, n-1, w);
    op += 2;
    return std::max(
        knapsack(items, n-1, w),
        knapsack(items, n-1, w - it.weight) + it.value
    );
}