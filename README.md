# logic-validitiy

Solve the validity of logical arguments, using the tree decision procedure. Currently only meant to work with basic propositional logic.

Currently the program takes multiple single premises (lines), and outputs a tree structure representing a logic solving tree. Only conjunction
and disjunction are working at the moment.
The input form is relatively restrictive - no spaces, single letter atoms. The following symbols are used to represent logical connectives:
^ Conjunctive
v Disjunctive
- Conditional
< Biconditional

Valid input looks something like; x^(xvy)
(X and X or Y).

## Goals

Number one is obviously adding the second two connectives and then determining validity based on input.
After that, I hope to make input a little more permissive, with some basic input checking and correction.

I'm using c++ to help me learn c++.
