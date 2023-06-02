#ifndef DATA_H
#define DATA_H

#include <ostream>


struct Item {
    int weight;
    int value;

    friend std::ostream& operator<<(std::ostream& os, Item &i) {
        return os << '{' << i.weight << ',' << i.value << '}';
    }

    friend bool operator< (const Item& i1, const Item& i2) {
        return (double)i1.value / i1.weight < (double)i2.value / i2.weight;
    }

    friend bool operator> (const Item& i1, const Item& i2) {
        return (double)i1.value / i1.weight > (double)i2.value / i2.weight;
    }
};

#endif