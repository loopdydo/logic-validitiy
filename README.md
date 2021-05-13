# logic-validitiy

Solve the validity of logical arguments, using the tree decision procedure. Currently only meant to work with basic propositional logic.

Currently the program takes a single premise (line), breaks it down into atoms, and spits out numbers corrosponding to the connectives.
The input form is relatively restrictive - no spaces, single letter atoms. The following symbols are used to represent logical connectives:
^ Conjunctive (0)
v Disjunctive (1)
- Conditional (2) 
< Biconditional (3)

Valid input looks something like; x-(xvy)
(X implies X or Y).

## Goals

Number one is obviously allowing multiple lines of input, and then determining validity.
After that, I hope to make input a little more permissive, with some basic input checking and correction.
