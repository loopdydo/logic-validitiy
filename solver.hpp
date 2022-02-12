//
//  solver.hpp
//  Logic Validity
//
//  Created by Oliver Robson on 18/05/21.
//

#ifndef solver_hpp
#define solver_hpp

#include <stdio.h>
#include <vector>
#include "premise.hpp"

class Solver {
private:
    std::vector<Premise> r;
public:
    Solver();
    std::vector<std::vector<std::vector<Premise>>> createTree();
    void setPremise(std::vector<Premise> premise);
};

#endif /* solver_hpp */
