#ifndef DATA_H
#define DATA_H

#include <ostream>


struct Item {
    int weight;
    double value;

    friend std::ostream& operator<<(std::ostream& os, Item &i) {
        return os << '{' << i.weight << ',' << i.value << '}';
    }
};

#endif