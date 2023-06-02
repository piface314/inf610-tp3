#include "test.hpp"

size_t op = 0;

std::map<std::string, int (*)(std::vector<Item>&, int)> Test::fns = {
    {"bf",  bf::knapsack},
    {"xs",  xs::knapsack},
    {"bt",  bt::knapsack},
    {"dpb", dpb::knapsack},
    {"dpt", dpt::knapsack},
    {"gd",  gd::knapsack},
};

void Test::reset() {
    op = 0;
}

Instance Test::read(std::ifstream &f) {
    if (not f.is_open())
        return {0, std::vector<Item>()};
    std::vector<Item> items;
    int n, w_max, w, v;
    if (f >> n >> w_max) {
        for (int i = 0; i < n; ++i) {
            f >> w >> v;
            items.push_back(Item {w, v});
        }
        return {w_max, items};
    }
    return {0, items};
}

void Test::run_paradigm(std::string &paradigm, int (*fn)(std::vector<Item>&, int), std::string &fp_in, std::ofstream &f_out) {
    Instance instance;
    int iter_count = 0;
    std::ifstream f_in(fp_in);

    std::cout << "Paradigm: " << paradigm << "\n";
    while ((instance = Test::read(f_in)).w_max > 0) {
        std::cout << "Instance #" << ++iter_count << "\n";
        Test::reset();
        int answer = fn(instance.items, instance.w_max);
        f_out << paradigm << ',' << instance.items.size() << ',' << instance.w_max << ','
            << answer << ',' << op << '\n';
        f_out.flush();
    }

    f_in.close();
}

int Test::run_all(std::string &fp_in, std::string &fp_out) {
    std::ofstream f_out(fp_out);
    if (not f_out.is_open())
        return 1;
    f_out << "paradigm,n_items,w_max,answer,op\n";
    try {
        for (auto it : Test::fns) {
            std::string paradigm = it.first;
            auto fn = it.second;
            Test::run_paradigm(paradigm, fn, fp_in, f_out);
        }
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        f_out.close();
        return 1;
    }
    f_out.close();
    return 0;
}

int Test::run_multi(std::string &paradigm, std::string &fp_in, std::string &fp_out) {
    std::ofstream f_out(fp_out);
    if (not f_out.is_open())
        return 1;
    f_out << "paradigm,w_max,n_items,answer,op\n";
    try {
        auto fn = Test::fns.at(paradigm);
        Test::run_paradigm(paradigm, fn, fp_in, f_out);
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        f_out.close();
        return 1;
    }
    f_out.close();
    return 0;
}

int Test::run_one(std::string &paradigm, std::string &fp_in) {
    if (Test::fns.find(paradigm) == Test::fns.end()) {
        std::cerr << "error: unknown paradigm\n";
        return 1;
    }
    auto fn = Test::fns.at(paradigm);
    std::ifstream f_in(fp_in);
    Instance instance = Test::read(f_in);
    if (instance.w_max <= 0) {
        std::cerr << "error: input file not found\n";
        return 1;
    }
    std::cout << "Paradigm: " << paradigm << "\n";
    std::cout << "W_max: " << instance.w_max << "\n";
    std::cout << "Items: ";
    PRINT_V(instance.items);
    Test::reset();
    int answer = fn(instance.items, instance.w_max);
    std::cout << "Answer: " << answer << "\n";
    std::cout << "Operations: " << op << "\n";
    f_in.close();
    return 0;
}
