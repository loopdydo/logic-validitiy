//
//  solver.cpp
//  Logic Validity
//
//  Created by Oliver Robson on 18/05/21.
//
#include "solver.hpp"
#include <math.h>
#include <iostream>


void Solver::solve() {
    /* a 3 level vector. The first vector represents each level of the tree. The second
     represents each node in a given level. The third contains the premises for that node */
    std::vector<std::vector<std::vector<Premise>>> tree;
    // initialise the top level
    std::vector<std::vector<Premise>> top;
    top.push_back(r);
    tree.push_back(top);
    //set height of tree (0 = just the initial premises)
    int height = 0;
    
    //build tree
    while (height < tree.size()) {
        //work through levels
        for (int level = 0; level < tree.size(); level++) {
            //print newline
            std::cout << "\n";
            //initialise the next level
            std::vector<std::vector<Premise>> x(pow(2, level+1));
            tree.push_back(x);
            height++;
            //work through nodes
            for (int node = 0; node < tree.at(level).size(); node++) {
                //print space
                std::cout << " ";
                //work through premises
                for (int i = 0; i < tree.at(level).at(node).size(); i++) {
                    Premise p = tree.at(level).at(node).at(i);
                    //print premise
                    std::cout << p.print() << ",";
                    switch (p.mainConnective) { //decide what to do based on the connective
                        case p.Conjunct:
                            /* current node index * 2 gives us the correct index to start at
                             on the next level. We want to fill in the number of nodes on the
                             level we're filling / the number of nodes on the current level*/
                            for (int j = node * 2; j < (node * 2) + (pow(2, height)/pow(2, level)); j++) {
                                tree.at(height).at(j).push_back(*p.left); // add left section to node
                                tree.at(height).at(j).push_back(*p.right); // add right section to node
                            }
                            break;
                        case p.Disjunct:
                            /* current node index * 2 gives us the correct index to start at
                             on the next level. We want to fill in the number of nodes on the
                             level we're filling / the number of nodes on the current level.
                             Increment by 2, as we're always filling 2 spots*/
                            for (int j = node * 2; j < (node * 2) + (pow(2, height)/pow(2, level)); j += 2) {
                                tree.at(height).at(j).push_back(*p.left); // add left section to left node
                                tree.at(height).at(j+1).push_back(*p.right); // add right section to right node
                            }
                            break;
                        case p.Conditional:
                            //Need to set up negation
                            break;
                        case p.Biconditional:
                            //Need to set up negation
                            break;
                        case p.None:
                            //do nothing
                            break;
                    }
                }
            }
            //check if there is still work to do
            bool done = true;
            for (int i = 0; i < tree.at(height).size(); i++) {
                if (tree.at(height).at(i).size() != 0) {
                    done = false;
                    break;
                }
            }
            if (done) {
                tree.pop_back();
                std::cout << "\n";
                break;
            }
        }
    }
    //print the tree
}
Solver::Solver (std::vector<Premise> premises) {
    r = premises;
    solve();
};
