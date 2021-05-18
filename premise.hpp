//
//  premise.hpp
//  Logic Validity
//
//  Created by Oliver Robson on 29/04/21.
//

#ifndef premise_hpp
#define premise_hpp

#include <stdio.h>
#include <string>

class Premise {
private:
    enum connective {Conjunct, Disjunct, Conditional, Biconditional, None};
    std::string premise;
    connective mainConnective;
    Premise* left; //using pointers to assign later - not handling memory yet.
    Premise* right;
public:
    Premise (std::string p);
};

#endif /* premise_hpp */
