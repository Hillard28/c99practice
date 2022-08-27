# FORMATTED INPUT/OUTPUT
## THE PRINTF FUNCTION
- The `printf` function is designed to display the contents of a string, known as the _format string_, with values possibly inserted at specified points in the string.  When called, `printf` must be supplied with the format string, followed by any values that are to be inserted during printing.
```
printf(string, expr_1, expr_2, ...);
```
- The values displayed can be constants, variables, or more complicated expressions.  There's no limit to the number of values that can be printed by a single call.
- The format string may contain ordinary characters and _conversion specifications_, beginning with the `%` character.  It is a placeholder representing a value to be filled during printing.
```
printf("This print call prints the integer %d\n", 10);
```
- Ordinary characters in a format string are printed exactly as they appear; conversion specifications are replaced by values to be printed:
```
int x, y;
x = 10;
y = 5 + x;

printf("x + 5 = %d\n", y);
```
- C compilers aren't required to check that the number of conversion specifications matches the number of output items:
```
printf("%d %d\n", x);   // Wrong
printf(%d\n", x, y);    // Wrong
```
- C compilers also aren't required to check that a conversion specification is appropriate for the type of item being printed.  An incorrect specification will produce meaningless output:
```
printf("%d %.2f\n", 10.25, 5);    // Wrong
```

### CONVERSION SPECIFICATIONS
- Conversion specifications give a high level of control over output appearance.
- Generally, a conversion specification have have the form `%m.pX` or `%-m.pX`, where `m` and `p` are integer constants and `X` is a letter.  `m` and `p` are both optional.  If `p` is omitted, the period is also dropped
- The _minimum field width_, `m`, specifies the minimum number of characters to print.  If the value to be printed required less than `m` characters, the value is right justified, with extra spaces preceding the value (`%4d` displays 123 as " 123").  If the value to be printed requires more than `m` characters, the field width automatically expands to the necessary size (`%4d` displays 12345 as "12345").
- The _conversion specifier_, `X` indicates which conversion should be applied to the value before printing, while the _precision_, `p`, specifies the precision of the value being printed.
- Typical conversion specifiers are:
  - `d`: displays an integer in decimal (base 10) form.
  - `e`: displays a floating-point number in scientific notation.
  - `f`: displays a floating-point number in fixed decimal format, without an exponent.
  - `g`: displays a floating-point nuber in exponential or fixed decimal format, depending on size.  `p` indicates the maximum number of significant digits to be displayed.  `g` doesn't show trailing zeros, unlike `f`.  `g` is particularly useful for displaying numbers whose size can't be predicted when a program is written.

### ESCAPE SEQUENCES
- An _escape sequence_ is code used to format strings.  They enable string to contain characters that would otherwise cause compiler problems, such as printing control characters or characters with special meaning (such as ", expressed in a string as \").  Common examples include:
  - Alert:            \a
  - Backspace:        \b
  - New line:         \n
  - Horizontal tab:   \t
- A string may contain any number of escape sequences.  Putting a "\" character in string causes a compiler to assume it's beginning to print an escape sequence.
```
printf("\\");   // Prints one "\" character
```

## THE SCANF FUNCTION
- Like `printf` prints output in a specified format, `scanf` reads input by a specified format.
- A `scanf` format string may contain ordinary characters as well as conversion specifications:
```
int x, y;

scanf("%d%d", &x, &y);    // Assigned by a use entering integers in form: "%d %d"
```
- `scanf` ignores _white-space characters_ (space, horizonatl and vertical tab, form-feed, and new-lines) when searching for the beginning of a number.  Numbers can those be put on a signle line or spread over multiple lines.  WHen asked to read an integer of floating-point number, `scanf` searches for a digit, plus sign, or minus sign, or series of digits possibly containing a decimal point, possibly followed by an exponent (e or E) and one or more proceding digits.
- `scanf` saves characters that can't be part of the current item to be read again when scanning for the next input item.

### ORDINARY CHARACTERS IN FORMAT STRINGS
- Format strings can be written to contain ordinary characters and conversion specifications.  Action taken by `scanf` when processing an ordinary character in a format string depends on whether or not it's a white-space character:
  - White-space character: when encountering one or more consecutive white-space characters, `scanf` reads them from the input until reaching a non-white-space character.  The number of white-space characters is irrelevant; one white-space character in the format string will match any number of white-space characters in the input.
  - Other characters: when encountering a non-white-space character in a format string, `scanf` compares it with the next input character.  If the two characters match, `scanf` discards the input character and continues processing the format string.  If the characters don't match, `scanf` puts the offending character back into the input, then aborts without further processing of the format string or reading of characters from the input.
```
int x, y;

scanf("%d/%d", &x, &y);
```
- If the input to the above is " 5/ 96", `scanf` skips the first space, matches %d with 5, matches "/" with "/", skips a space, and matches %d with 96.
- If the input to the above is " 5 / 96", `scanf` skips the first space, matches %d with 5, then attempts to match "/" with " ".  Since there is no match, `scanf` puts the space back, with " / 96" remaining to be read by the next call to `scanf`.  To allow spaces after the first number, the format string `%d /%d` should be used instead.
