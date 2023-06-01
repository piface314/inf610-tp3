#ifndef TEST_H
#define TEST_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "data.hpp"
#include "test-counter.hpp"
#include "utils.hpp"

#include "brute-force.hpp"
#include "exhaustive-search.hpp"
#include "backtrack.hpp"
#include "dynamic-programming.hpp"
#include "greedy.hpp"


struct Instance {
    int w_max;
    std::vector<Item> items;
};

class Test {
private:
    static std::map<std::string, int (*)(int, std::vector<Item>)> fns;
    static Instance read(std::ifstream &f);
    static void run_paradigm(std::string &paradigm, int (*)(int, std::vector<Item>), std::string &fp_in, std::ofstream &f_out);
public:
    static void reset();
    static int run_all(std::string &fp_in, std::string &fp_out);
    static int run_multi(std::string &paradigm, std::string &fp_in, std::string &fp_out);
    static int run_one(std::string &paradigm, std::string &fp_in);
};

#endif