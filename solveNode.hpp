//
//  solveNode.hpp
//  Logic Validity
//
//  Created by Oliver Robson on 20/05/21.
//

#ifndef solveNode_hpp
#define solveNode_hpp

#include <stdio.h>
#include "premise.hpp"
#include "solver.hpp"

class SolveNode {
private:
    std::vector<Premise> main;
    std::vector<Premise> left;
    std::vector<Premise> right;
    friend class Solver;
public:
    SolveNode(std::vector<Premise> r);
};

#endif /* solveNode_hpp */
