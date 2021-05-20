//
//  solver.cpp
//  Logic Validity
//
//  Created by Oliver Robson on 18/05/21.
//
#include "solver.hpp"

void Solver::solve() {
    while (r.size() > 0) {
        SolveNode root = SolveNode(r);
        while (root.main.size() > 0) { //while there are premises left to deal with
            Premise p = root.main.front(); //take the top premise
            switch (p.mainConnective) { //decide what to do based on the connective
                case p.Conjunct:
                    root.main.push_back(*p.left);//add left to the main branch
                    root.main.push_back(*p.right);//add right to the main branch
                    root.main.erase(root.main.begin());//left and right are accounted for so we can delete
                    break;
                case p.Disjunct:
                    root.left.push_back(*p.left);//add left to left branch
                    root.right.push_back(*p.right);//add right to right branch
                    root.main.erase(root.main.begin());//left and right are accounted for so we can delete
                    break;
                case p.Conditional:
                    //Need to set up negation
                    break;
                case p.Biconditional:
                    //Need to set up negation
                    break;
                case p.None:
                    //Add to both branches
                    root.left.push_back(p);
                    root.right.push_back(p);
                    break;
            }
        }
    }
}
Solver::Solver (std::vector<Premise> premises) {
    r = premises;
    solve();
};
