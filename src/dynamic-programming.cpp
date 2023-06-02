#include "dynamic-programming.hpp"

int dpb::knapsack(std::vector<Item> &items, int w) {
    int v[items.size()+1][w+1];

    for (int i = 0; i <= (int)items.size(); ++i)
        v[i][0] = 0;
    for (int j = 0; j <= w; ++j)
        v[0][j] = 0;

    for (int i = 1; i <= (int)items.size(); ++i) {
        Item it = items[i-1];
        for (int j = 1; j <= w; ++j) {
++op;       if (j < it.weight) {
                v[i][j] = v[i-1][j];
            } else {
op+=2;          v[i][j] = std::max(v[i-1][j], v[i-1][j-it.weight] + it.value);
            }
        }
    }

    return v[items.size()][w];
}

int dpt::knapsack(std::vector<Item> &items, int w) {
    int v[(items.size()+1)*(w+1)];
    for (int i = 0; i < (items.size()+1)*(w+1); ++i)
        v[i] = -1;
    return knapsack(v, w+1, items, items.size(), w);
}

int dpt::knapsack(int *v, int w_max, std::vector<Item> &items, int n, int w) {
    if (v[n*w_max + w] >= 0)
        return v[n*w_max + w];
    if (n == 0)
        return v[n*w_max + w] = 0;
    Item it = items[n-1];
    ++op;
    if (it.weight > w)
        return v[n*w_max + w] = knapsack(v, w_max, items, n-1, w);
    op += 2;
    return v[n*w_max + w] = std::max(
        knapsack(v, w_max, items, n-1, w),
        knapsack(v, w_max, items, n-1, w - it.weight) + it.value
    );
}