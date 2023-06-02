#ifndef BACKTRACK_H
#define BACKTRACK_H

#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"


namespace bt {
    int knapsack(std::vector<Item> &items, int w);
    int knapsack(std::vector<Item> &items, int i, int w, int v_max, int &v_best);
}

#endif