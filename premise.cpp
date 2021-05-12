//
//  premise.cpp
//  Logic Validity
//
//  Created by Oliver Robson on 29/04/21.
//

#include "premise.hpp"
#include <string>
#include <iostream>
#include <regex>

enum connective {Conjunct, Disjunct, Conditional, Biconditional, None};

class Premise {
private:
    std::string premise;
    connective mainConnective;
    Premise* left;
    Premise* right;
public:
    Premise (std::string p) {
        premise = p;
        if (p.length() == 1) { //The premise is an atom! We're done here.
            mainConnective = None;
            delete left;
            delete right;
        } else {
            //look for a connective symbol not contained in brackets
            int c = 0; //keep count of position in string
            bool connectiveFound = false; //Have we found the main connective?
            while (c < p.length() && connectiveFound == false) {
                int b = 0; //keep count of bracket depth
                if (p[c] == '(') {
                    b++;
                    c++;
                    while (c < p.length() && b > 0) { //progress through brackets
                        if (p[c] == '(') {
                            b++;
                        } else if (p[c] == ')') {
                            b--;
                        }
                        c++;
                    }
                }
                
                switch (p[c]) { //check for a connective
                    case '^':
                        mainConnective = Conjunct;
                        connectiveFound = true;
                        break;
                    case 'v':
                        mainConnective = Disjunct;
                        connectiveFound = true;
                        break;
                    case '-':
                        mainConnective = Conditional;
                        connectiveFound = true;
                        break;
                    case '<':
                        mainConnective = Biconditional;
                        connectiveFound = true;
                        break;
                        
                }
                
                c++;
            }
            if (p[0] == '(') { //strip brackets
                left = new Premise(p.substr(1, c-2));
            } else {
                left = new Premise(p.substr(0, c-1));
            }
            if (p[c+1] == '(') { //strip brackets
                right = new Premise(p.substr(c+2, p.length()-1));
            } else {
                right = new Premise(p.substr(c+1, p.length()));
            }
        }
        
        std::cout << mainConnective << "\n";

    }
};
