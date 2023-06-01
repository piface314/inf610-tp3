#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace bt {
    int knapsack(std::vector<Item> items, int w_max);
}

#endif