#ifndef DYNAMIC_PROG_H
#define DYNAMIC_PROG_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace dpb {
    int knapsack(std::vector<Item> &items, int w);
}

namespace dpt {
    int knapsack(std::vector<Item> &items, int w);
    int knapsack(int *v, int w_max, std::vector<Item> &items, int n, int w);
}

#endif