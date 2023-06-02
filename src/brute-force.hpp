#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace bf {
    int knapsack(std::vector<Item> &items, int w);
    int knapsack(std::vector<Item> &items, int n, int w);
}

#endif