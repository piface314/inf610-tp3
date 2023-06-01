#include <iostream>
#include "test.hpp"


int main(int argc, char const *argv[]) {
    if (argc <= 2) {
        std::cerr << "Usage:\n\t$ " << argv[0] << " (one|multi|all) "
            "<input-fp> [<output-fp>] [(bf|xs|bt|dpb|dpt|gd)]\n";
        return 1;
    }
    std::string mode(argv[1]);
    std::string fp_in(argv[2]);
    std::string fp_out;
    std::string paradigm;
    if (mode == "one") {
        if (argc <= 3) {
            std::cerr << "Usage:\n\t$ " << argv[0] << " one <input-fp> (bf|xs|bt|dpb|dpt|gd)\n";
            return 1;
        }
        paradigm = argv[3];
        return Test::run_one(paradigm, fp_in);
    }

    if (mode == "multi") {
        if (argc <= 4) {
            std::cerr << "Usage:\n\t$ " << argv[0] << " multi <input-fp> <output-fp> (bf|xs|bt|dpb|dpt|gd)\n";
            return 1;
        }
        fp_out = argv[3];
        paradigm = argv[4];
        return Test::run_multi(paradigm, fp_in, fp_out);
    }
    
    if (mode == "all") {
        if (argc <= 3) {
            std::cerr << "Usage:\n\t$ " << argv[0] << " all <input-fp> <output-fp>\n";
            return 1;
        }
        fp_out = argv[3];
        return Test::run_all(fp_in, fp_out);
    }

    std::cerr << "error: unknown command\n";
    return 1;
}