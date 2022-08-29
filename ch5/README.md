# SELECTION STATEMENTS
- Aside from return and expression statements, the remainder of C's statements fall into three categories:
  1) Selection statements: the `if` and `switch` statements allow a program to select a particular execution path from a set of alternatives.
  2) Iteration statements: the `while`, `do`, and `for` statements support iteration (looping).
  3) Jump statements: the `break`, `continue`, and `goto` statements cause an unconditional jump to some other place in the program (the `return` statement is a jump statement as well).
- The only other statements in C are the compound statement, which groups several statements into a single statement, and the null statement, which performs no action.
- `if` statements rely on logical expressions to test conditions.

## LOGICAL EXPRESSIONS
- Several of C's statements (including `if`) must test the value of an expression to determine whether it is true or false.  In C, comparisons yield an integer: either 0 (false) or 1 (true).

### RELATIONAL OPERATORS
- C's relational operators correspond to the <, >, <=, and >= operators of mathematics:
  - <: less than
  - >: greater than
  - <=: less than or equal to
  - >=: greater than or equal to
- Relational operators can compare integers and floating-point numbers, with allowance for mixed types.  Relational 
