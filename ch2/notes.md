/*********************************************************************************************************
/ WRITING A SIMPLE PROGRAM
*********************************************************************************************************/
1) Preprocessing: program is passed to a preprocessor that obeys directives (commands that begin with #).  Preprocessor adds and modifies the program
2) Compiling: the modified program is passed to a compiler that translates to machine instructions (object code).
3) Linking: a linker combines the object code produced by the compiler with any additional code needed to yield a complete executable.  Includes library functions (such as printf from stdio.h).


/*********************************************************************************************************
/ THE GENERAL FORM OF A SIMPLE PROGRAM
*********************************************************************************************************/
Three key language features:
1) Directives: editing commands that modify the program prior to compilation.
2) Functions: named blocks of executable code (e.g. main).
3) Statements: commands to be performed when the program is run.

Directives:
- Directives are commands intended for the preprocessor (e.g. `#include <stdio.h>` is a directive stating that the information in `<stdio.h>` should be included in the program prior to compilation).
- Always begin with a `#` character.
- By default one line long; no semicolon or other marker at end of a directive.

Functions:
- Procedures or subroutines in other programming languages.
- Can either be written by the programmer or provided as part of the C implementation (library functions).
- A series of statements grouped together and given a name.
- Some functions compute values (and return a specified value using the return statement), some don't.
- Only the main function is mandatory though a C program may consist of many functions.  main is called automatically when a program is executed.  main returns a status code that is given to the operating system (OS) when a program terminates.  Specifying `return 0;` causes the main function to terminate with a value of 0, indicating a normal program termination; the main function will still terminate at the end with or without, but a compiler may produce a warning message (as it fails to return an integer).

Statements:
- A command to be executed when the program runs.
- A standard "Hello, world" program will include the return statement (`return 0;`) and a function call (`printf("Hello, world!\n);`)
- Each statement is required to end with a semicolon (except in compound statements), which shows the compiler where a statement ends.

/*********************************************************************************************************
/ COMMENTS
*********************************************************************************************************/
- In C89 are of form: `/* This is a comment */`
- In C99 can be expressed in C++ format of form: `// This is a comment`
- The latter example can be nested within the former, which allows for simple commenting out of code blocks for testing.  The former cannot be nested within the former and the latter within the latter.

/*********************************************************************************************************
/ VARIABLES AND ASSIGNMENT
*********************************************************************************************************/
- Most programs need a way to store data temporarily during program execution; such storage locations are called variables.

Types:
- Each variable must have a type, specifying the kind of data it holds.
- Proper type is critical as it affects how the variable is stored and what operations can be performed on it.
- Type of a numeric variable determines the smallest/largest numbers that can be stored and their precision.

Declarations:
- Variables must be declared before they can be used (e.g. `int x;` or `int x = 10;`).  First the type of variable is specified, then the variable name.
- Declarations must precede statements in C89 (they can be mixed in C99).

Assignment:
- A variable can be given a value by means of assignment (e.g. `x = 10;`).  A variable must be declared before being given a value:
```
// Valid in C89 and C99
int x;
x = 10;

// Valid in C99
int y = 10;
```
