#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace dpb {
    int knapsack(std::vector<Item> items, int w_max);
}

namespace dpt {
    int knapsack(std::vector<Item> items, int w_max);
}

#endif