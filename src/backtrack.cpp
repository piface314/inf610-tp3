#include "backtrack.hpp"


int bt::knapsack(std::vector<Item> &items, int w) {
    int v = 0, v_best = 0;
    for (Item it : items) {
++op;   v += it.value;
    }
    return knapsack(items, 0, w, v, v_best);
}

int bt::knapsack(std::vector<Item> &items, int i, int w, int v_max, int &v_best) {
    if (i == (int)items.size())
        return 0;
    Item it = items[i];
    int v1 = 0, v2 = 0;

++op; if (it.weight <= w) {
++op;   v1 = it.value + knapsack(items, i+1, w-it.weight, v_max-it.value, v_best);
++op;   v_best = std::max(v_best, v1);
    }

++op; if (v_max - it.value > v_best) {
        v2 = knapsack(items, i+1, w, v_max-it.value, v_best);
++op;   v_best = std::max(v_best, v2);
    }
    
++op; return std::max(v1, v2);
}
