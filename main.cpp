//
//  main.cpp
//  Logic Validity
//
//  Created by Oliver Robson on 29/04/21.
//

#include <iostream>
#include "premise.cpp"
#include <string>

int main(int argc, const char * argv[]) {
    std::string premise;
    getline(std::cin, premise);
    Premise p(premise);
    return 0;
}
