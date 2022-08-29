# EXPRESSIONS
- C emphasizes _expressions_ - formulas showing how to compute a value - rather than statements.
  - Simplest expressions are variables and constants.  A variable represents a value to be computed as the program runs.  A constant represents a value that doesn't change.
  - More complicated expressions apply operators to operands: in the expression `a + (b * c)`, the `+` operators is applied to `a` and `(b * c)`, both of which are expressions.
- C provides rudimentary operators:
1) Arithmetic operators: addition, subtraction, multiplication, and division.
2) Relational operators that aid comparisons (e.g. "i is _greater than_ 0")
3) Logical operators to build conditions (e.g. "i is greater than 0 _and_ i is less than 10")

## ARITHMETIC OPERATORS
- _Arithmetic operators_, that perform addition, subtraction, multiplication, and division.

| Unary | Binary |  |
| --- | --- | --- |
| | Additive | Multiplicative |
| + unary plus | + addition | * multiplication |
| - unary minus | - subtraction | / division |
| | | % remainder |

- Additive and multiplicative operators are _binary_ because they require two operands.  The _unary_ operators require one operand.
```
i = +1;
j = -i;
```
- The unary + operators does nothing; it's used to emphasize that a numeric constant is positive.
- Binary operators allow either integer or floating-point operands with mixed usage.  When int and float operands are mixed, the result is of type float.
  - When using the / operator, if both operands are integers the result is truncated by dropping the decimal part (effectively rounding down in all cases).
    - In C99, the division operator always truncates towards zero, whereas in C89, it may round up or down when using negative operands.
  - The % operator requires integer operands and will not compile when using floats.
    - Using zero as the RHS operator in / or % produces undefined behavior.

### OPERATOR PRECEDENCE AND ASSOCIATIVITY
- C uses _operator precedence_ rules to resolve ambiguity in expressions.  Arithmetic operators have the following precedence:
1) \+ \- (unary)
2) \* \/ \%
3) \+ \- (binary)
- Operators listed on the same line have equal precedence (if in the same priority level above).
- When an expression contains two or more operators at the same level of precedence, the _associativity_ of operators is considered.  An operator is _left associative_ if it groups from left to right:
```
i - j - k = (i - j) - k
i * j / k = (i * j) / k
```
- An operator is _right associative_ if it groups from right to left.  The unary arithmetic operators are both right associative:
```
- + i = -(+i)
```

## ASSIGNMENT OPERATORS
- C's `=` (_simple assignment_) operator is used for the purpose of storing values in variables for later use.  For updating a value already stored in a variable, C has an assortment of compound assignment operators.

### SIMPLE ASSIGNMENT
- The effect of the assignment `v = e` is to evaluate the expression `e` and copy its value into `v`.  `e` can be a constant, a variable, or a more complicated expression.
```
i = 5;    // i is now 5
j = i;    // j is now 5
k + 10 * i + j;   // k is now 55
```
- If `v` and `e` don't have the same type, the value of `e` is converted to the type of `v` as the assignment takes place:
```
int i;
float f;

i = 72.99f;   // i is now 72
f = 136;    // f is now 136.0
```
- In many programming languages, assignment is a statement.  In C, assignment is an operator, just like +.  The act of assignment produces a result, just like adding two numbers.  The value of assignment `v = e` is the value of `v` _after_ the assignment.  The value of `i = 72.99f` is 72 (not 72.99).
- Since assignment is an operator, several assignments can be chained together:
```
i = j = k = 0;
// The = operator is right associative, so the assignment is equal to
i = (j = (k = 0));
```
- Programmers should be wary of type conversion in chained assignments.
```
int i;
float f;

f = i = 33.3f;    // i is assigned to 33, then f is assigned to 33.0 (not 33.3)
```
- An assignment of form `v = e` is allowed wherever a value of type `v` would be permitted.
```
i = 1;
k = 1 + (j = i);
```

### LVALUES
- Most C operators allow operands to be variables, constants, or expressions modifying other operators.  The assignment operator required an _lvalue_ as its left operand.  An lvalue represents an object stored in computer memory, not a constant or the result of a computation.  Variables are lvalues, but not constants or expressions involving constants.
```
12 = i;   // Illegal
i + j = 0;    // Illegal
-i = j;   // Illegal
```

### COMPOUND ASSIGNMENT
- Assignments that use the old value of a variable to compute its new value are common in C programs:
```
i = i + 2;
```
- C's _compound assignment_ operators allow to shorten the above and others like it:
```
i += 2;
```
- There are nine compound operators, including the following:

| Operator | Output |
| --- | --- |
| `v += e` | adds `v` to `e`, storing the result in `v` |
| `v -= e` | subtracts `e` from `v`, storing the result in `v` |
| `v *= e` | multiplies `v` by `e`, storing the result in `v` |
| `v /= e` | divides `v` by `e`, storing the result in `v` |
| `v %= e` | computes the remainder when `v` is divided by `e`, storing the result in `v` |

- Compound assignment operators aren't always equivalent to their long form, because of operator precedence (e.g. `i *= j + k` is not equivalent to `i = i * k + k`).  There are rare cases where even `v += e` differs from `v = v + e` because `v` has a side effect (this applies to other compound operators as well).
- Compound assignment operators have the same properties as = operators and are right associative.
```
i += j += k;
// This is equivalent to:
i += (j += k);
```

## INCREMENT AND DECREMENT OPERATORS
- Two of the most common operations on a variable are incrementing or decrementing, which can be accomplished by:
```
i = i + 1;    // Increment
j = j - 1;    // Decrement
// Equivalent to
i += 1;
j -= 1;
```
- C allows increments and decrements to be shortened even further, using `++` (increment) and `--` (decrement) operators.  The above can be expressed as:
```
i++;    // Yields i and then increments
j--;    // Yields j and then decrements
++i;    // Yields i + 1 while incrementing
--j;    // Yields j - 1 while decrementing
k = ++i + j++;    // Yields (i + 1) + j
```

## EXPRESSION EVALUATION







