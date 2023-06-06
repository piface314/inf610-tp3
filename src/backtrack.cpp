#include "backtrack.hpp"


int bt::knapsack(std::vector<Item> &items, int w) {
    int v_max = 0, v_best = 0;
    for (Item it : items) {
++op;   v_max += it.value;
    }
    return knapsack(items, 0, w, 0, v_max, v_best);
}

int bt::knapsack(std::vector<Item> &items, int i, int w,
                 int v_acc, int v_max, int &v_best) {
      if (i == (int)items.size() || w == 0)
          return v_acc;
++op; if (v_acc + v_max <= v_best)
          return v_acc;
      Item it = items[i];
++op; v_max -= it.value;
++op; if (it.weight > w)
          return knapsack(items, i+1, w, v_acc, v_max, v_best);
op+=2;int v = std::max(
          knapsack(items, i+1, w, v_acc, v_max, v_best),
          knapsack(items, i+1, w-it.weight,
                   v_acc+it.value, v_max, v_best)
      );
++op; v_best = std::max(v_best, v);
      return v;
}
