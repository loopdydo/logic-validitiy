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
    //set insertHeight of tree (0 = just the initial premises)
    int insertHeight = 0;
    
    //build tree
    while (insertHeight < tree.size()) {
        //work through levels
        for (int level = 0; level < tree.size(); level++) {
            //initialise the next level
//            std::vector<std::vector<Premise>> x(pow(2, level+1));
//            tree.push_back(x);
//            insertHeight++;
            //work through nodes
            for (int node = 0; node < tree.at(level).size(); node++) {
                //work through premises
                for (int premiseIndex = 0; premiseIndex < tree.at(level).at(node).size(); premiseIndex++) {
                    Premise p = tree.at(level).at(node).at(premiseIndex);
                    //determine the next empty level - if there is none, create one
                    for (int i = level + 1; i <= tree.size(); i++) {
                        if (tree.size() <= i) {
                            std::vector<std::vector<Premise>> x(pow(2, tree.size()));
                            tree.push_back(x);
                        }
                        if (tree.at(i).at(node * 2).size() == 0) {
                            insertHeight = i;
                            break;
                        }
                    }
                    //calculate where any new nodes will begin inserting from
                    int newNodeIndex = node/pow(2, level)*pow(2, insertHeight);
                    switch (p.mainConnective) { //decide what to do based on the connective
                        case p.Conjunct:
                            /* current node index * 2 gives us the correct index to start at
                             on the next level. We want to fill in the number of nodes on the
                             level we're filling (2^insertHeight) / the number of nodes on the current level (2^level) */
                            for (int newNode = newNodeIndex; newNode < newNodeIndex + (pow(2, insertHeight)/pow(2, level)); newNode++) {
                                tree.at(insertHeight).at(newNode).push_back(*p.left); // add left section to node
                                tree.at(insertHeight).at(newNode).push_back(*p.right); // add right section to node
                            }
                            break;
                        case p.Disjunct:
                            /* current node index/current layer size*insertHeight size gives us the node to start at.
                             We want to fill in the number of nodes on the
                             level we're filling / the number of nodes on the current level.
                             Increment by 2, as we're always filling 2 spots*/
                            for (int newNode = newNodeIndex; newNode < newNodeIndex + (pow(2, insertHeight)/pow(2, level)); newNode += 2) {
                                tree.at(insertHeight).at(newNode).push_back(*p.left); // add left section to left node
                                tree.at(insertHeight).at(newNode+1).push_back(*p.right); // add right section to right node
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
            for (int node = 0; node < tree.at(insertHeight).size(); node++) {
                if (tree.at(insertHeight).at(node).size() != 0) {
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
    for (int level = 0; level < tree.size(); level++){
        std::cout << "\n";
        for (int node = 0; node < tree.at(level).size(); node++) {
            for (int premiseIndex = 0; premiseIndex < tree.at(level).at(node).size(); premiseIndex++) {
                std::cout << tree.at(level).at(node).at(premiseIndex).print() << ",";
            }
            std::cout << " ";
        }
    }
}
Solver::Solver (std::vector<Premise> premises) {
    r = premises;
    solve();
};
