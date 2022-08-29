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
- C's _relational operators_ correspond to the <, >, <=, and >= operators of mathematics:
  - <: less than
  - >: greater than
  - <=: less than or equal to
  - >=: greater than or equal to
- Relational operators can compare integers and floating-point numbers, with allowance for mixed types.
- Relational operator precedence is lower than that of arithmetic operators and is left associative:
```
i + j < k - 1;
(i + j) < (k - 1);

i < j < k;
(i < j) < k;
```
  - The second set of expressions above do not test whether `j` lies between `i` and `k`; it tests whether the boolean output (0 or 1) from `(i < j)` is less than `k`.  The correct form would be:
```
i < j && j < k;
(i < j) && (j < k);
```

### EQUALITY OPERATORS
- C's _equality operators_ have a unique appearance:
  - ==: equal to
  - !=: not equal to
- Equality operators are also left associative and produce 0 if false, or 1 if true.  They also have lower precedence than relational operators:
```
i < j == j < k;    // Tests whether i < j and j < k are both true or both false
(i < j) == (j < k);
```

### LOGICAL OPERATORS
- More complicated logical expressions can be built from simpler ones using _logical operators_: and, or, and not.  The `!` operator is unary, while `&&` and `||` are binary:
  - !: logical negation
  - &&: logical and
  - ||: logical or
- Logical operators also produce either 0 (false) or 1 (true); they treat any nonzero operand as a true value and any zero operand as a false value:
```
!x    // Equal to 1 if x = 0
x && y    // Equal to 1 if x == y and x != 0
x || y    // Equal to 1 if x != 0 or y != 0
```
- Both `&&` and `||` perform "short-circuit" evaluation of their operands.  They first evaluate the left operand and then the right operand.  The right operand isn't evaluated if the expression can be deduced from the left operand alone.
```
(i != 0) && (j / i > 0);
```
  - If `i != 0` returns 1 (true), then we must evaluate `j / i > 0` to determine whether the entire expression is true or false.  If the first expression is false (`i == 0`), then there is no need to evaluate the second expression.
```
i > 0 && ++j > 0;   // If the first expression is false, j is not incremented
```
- The `!` operator has the same precedence as unary plus and minus operators.  The precedence of `&&` and `||` is lower than relational and equality operators:
```
i < j && k == m;
(i < j) && (k == m);
- The `!` operator is right associative; `&&` and `||` are left associative.

## THE IF STATEMENT
