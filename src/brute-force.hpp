#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace bf {
    int knapsack(int w_max, std::vector<Item> items);
}

#endif