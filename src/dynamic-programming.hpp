#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace dpb {
    int knapsack(int w_max, std::vector<Item> items);
}

namespace dpt {
    int knapsack(int w_max, std::vector<Item> items);
}

#endif