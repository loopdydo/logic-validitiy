//
//  main.cpp
//  Logic Validity
//
//  Created by Oliver Robson.
//

#include <iostream>
#include "premise.hpp"
#include "solver.hpp"
#include <string>
#include <vector>

int main(int argc, const char * argv[]) {
    std::string premise;
    std::vector<Premise> premises;
    while (getline(std::cin, premise)) {
        Premise p(premise);
        premises.push_back(p);
    }
    Solver solver(premises);
    return 0;
}
