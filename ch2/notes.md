# C FUNDAMENTALS
## WRITING A SIMPLE PROGRAM
1) Preprocessing: program is passed to a preprocessor that obeys directives (commands that begin with `#`).  Preprocessor adds and modifies the program
2) Compiling: the modified program is passed to a compiler that translates to machine instructions (object code).
3) Linking: a linker combines the object code produced by the compiler with any additional code needed to yield a complete executable.  Includes library functions (such as printf from stdio.h).


## THE GENERAL FORM OF A SIMPLE PROGRAM
### Three key language features
1) Directives: editing commands that modify the program prior to compilation.
2) Functions: named blocks of executable code (e.g. main).
3) Statements: commands to be performed when the program is run.

### Directives
- Directives are commands intended for the preprocessor (e.g. `#include <stdio.h>` is a directive stating that the information in `<stdio.h>` should be included in the program prior to compilation).
- Always begin with a `#` character.
- By default one line long; no semicolon or other marker at end of a directive.

### Functions
- Procedures or subroutines in other programming languages.
- Can either be written by the programmer or provided as part of the C implementation (library functions).
- A series of statements grouped together and given a name.
- Some functions compute values (and return a specified value using the return statement), some don't.
- Only the main function is mandatory though a C program may consist of many functions.  main is called automatically when a program is executed.  main returns a status code that is given to the operating system (OS) when a program terminates.  Specifying `return 0;` causes the main function to terminate with a value of 0, indicating a normal program termination; the main function will still terminate at the end with or without, but a compiler may produce a warning message (as it fails to return an integer).

### Statements
- A command to be executed when the program runs.
- A standard "Hello, world" program will include the return statement (`return 0;`) and a function call (`printf("Hello, world!\n);`)
- Each statement is required to end with a semicolon (except in compound statements), which shows the compiler where a statement ends.

## COMMENTS
- In C89 are of form: `/* This is a comment */`
- In C99 can be expressed in C++ format of form: `// This is a comment`
- The latter example can be nested within the former, which allows for simple commenting out of code blocks for testing.  The former cannot be nested within the former and the latter within the latter.

## VARIABLES AND ASSIGNMENT
- Most programs need a way to store data temporarily during program execution; such storage locations are called variables.

### Types
- Each variable must have a type, specifying the kind of data it holds.
- Proper type is critical as it affects how the variable is stored and what operations can be performed on it.
- Type of a numeric variable determines the smallest/largest numbers that can be stored and their precision.

### Declarations
- Variables must be declared before they can be used (e.g. `int x;` or `int x = 10;`).  First the type of variable is specified, then the variable name.
- Declarations must precede statements in C89 (they can be mixed in C99).

### Assignment
- A variable can be given a value by means of assignment (e.g. `x = 10;`).  A variable must be declared before being given a value:
```
// Valid in C89 and C99
int x;
x = 10;

// Valid in C99
int y = 10;
```
- It's best practice to append `f` to a constant that contains a decimal point if assigned to a float variable.
- Mixing types is possible (e.g. `int` and `float`) though not always safe.
- Once a variable has been assigned a value, it can be used to compute the value of another variable
```
x = 10;
y = x + 5;
```
- The right side of an assignment can be a formula (or expression in C terminology) involving constants, variables, and/or operators.

### Variable peculiarities
- When an integer is divided by another, the answer is truncated; the digits after the decimal are dropped rather than any rounding being performed (e.g. 12 / 7 = 1).

### Initialization
- Some variables are set to zero when a program begins to execute but most are not.  A variable without a default value that hasn't been assigned a value is _uninitialized_.
- Acessing an uninitialized variable will likely return an unpredictable result or even cause a crash.
- To avoid, a variable can be declared and initialized in one step (here, 10 is the _initializer_):
```
int x = 10;
```
- An initializer is only good for the variable it is explicitly assigned to:
```
int x, y, z = 10;   // x and y are uninitialized
```

## DEFINING NAMES FOR CONSTANTS
- Good practice to give names for constants used by a program.
- _Macro definition_ can be used to name a constant.
```
#define INCHES_PER_POUND 166
```
- `#define` is a processing directive just like `#include` (no semicolon at end of line).  When a program is compiled, the preprocessor replaces macros with the value they represent.
```
weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
```
Becomes:
```
weight = (volume + 166 - 1) / 166;
```
- Macros can also be expressions.  If they contain operators the expression should be enclosed in parentheses:
```
#define RECIPROCAL_OF_PI (1.0f / 3.14159f)
```
- Macro names are commonly defined using only upper-case letters.

## IDENTIFIERS
- While writing a program, variables, functions, macros, and other entity names are called _identifiers_.
- Identifiers may contain letters, digits, and underscores, but they must begin with a letter or underscore (in C99, identifiers can contain "universal character names").
```
times10   // Valid
_times10  // Valid
10times   // Not valid
```
- C is case-sensitive: it distinguishes between upper-case and lower-case letters.  The following identifiers are all different:
```
job
joB
jOb
Job
JoB
JOb
JOB
```
- Programmers typically use either only lower-case letters in identifiers (except with macros) with underscores for legibility.  Some also use upper-case letters to begin any proceding words without underscores:
```
symbol_table
symbolTable
```
- C has no limit on the maximum length of an identifier.

### Keywords
- Keywords have special significance to C compilers and cannot be used as identifiers.  The following are all keywords:
```
auto      enum      restrict    unsigned
break     extern    return      void
case      float     short       volatile
char      for       signed      while
const     goto      sizeof      _Bool
continue  if        static      _Complex
default   inline    struct      _Imaginary
do        int       switch
double    long      typedef
else      register  union
```
- Because of C's case-sensitivity, keywords must appear in programs as shown above.
- Names of functions in the standard library (such as `printf`) contain only lower-case letters as well.

## LAYOUT OF A C PROGRAM
- A C program can be thought of as a series of _tokens_: groups of characters that can't be split without changing their meaning.  Identifiers and keywords are tokens, as are operators such as + and -, punctuation marks such as a comma and semicolon, and string literals.
```
printf("Height: %d\n", height);
printf    (   "Height: %d\n"    ,   height    )   ;
  1       2           3         4     5       6   7
// 1 and 2: identifiers
// 3: string literal
// 2, 4, 6, and 7: punctuation
```
- The amount of space between tokens typically isn't critical, but adding space and newlines improves readability.
- C allows programmers to insert any amount of space between tokens, with some important consequences:
1) Statements can be divided over any number of lines:
```
printf("Dimensional weight (pounds): %d\n",
  (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND);
```
2) Spaces between tokens make it easier to separate them:
```
volume=height*length*width;         // Valid
volume = height * length * width;   // Easier to read
```
3) Indentation can make nesting easier to spot (see example under 1.).
4) Blank lines can divide a program into logical units, making it easier to discern a program's structure.
- Although extra spaces can be added between tokens, it's not possible to add space within a token without changing the meaning of a program or causing an error:
```
float fahrenheit, celsius   // Valid
fl oat fahrenheit, celsius  // Wrong
```
- Putting a space inside a string literal is allowed (though it changes the meaning), but splitting a string over multiple lines is illegal:
```
printf("To C or not to C:
that is the question.\n");  // Wrong
```
