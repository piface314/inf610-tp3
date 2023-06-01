#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace bt {
    int knapsack(int w_max, std::vector<Item> items);
}

#endif