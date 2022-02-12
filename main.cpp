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
    std::vector<std::vector<std::vector<Premise>>> tree;
    while (getline(std::cin, premise)) {
        Premise p(premise);
        premises.push_back(p);
    }
    Solver solver;
    solver.setPremise(premises);
    tree = solver.createTree();
    
    //print the tree
    for (int level = 0; level < tree.size(); level++){
        std::cout << "\n";
        for (int node = 0; node < tree.at(level).size(); node++) {
            for (int premiseIndex = 0; premiseIndex < tree.at(level).at(node).size(); premiseIndex++) {
                std::cout << tree.at(level).at(node).at(premiseIndex).print() << ",";
            }
            std::cout << " ";
        }
    }
    
    return 0;
}
