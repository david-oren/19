VIA Ykman Martin

# ft_printf

```C
int ft_printf( const char *, ... );
```

## Conversion Specification

Usage : 
> %[[flags](#flag-directives)][[width](#width-specification)][[.precision](#precision-specification)][type](#type-conversion-specifier)


### Type conversion specifier

| Format specifier | Suitable type | Output format |
| --- | --- | --- |
| `c` | `char` | Single-bytes charcater. | 
| `s` | `char *` | Single-byte or multi-byte character string |
| `p` | `void *` | Address in hexadecimal digits. |
| `d` | `int` | Signed decimal integer. |
| `i` | `int` | Signed decimal integer. | 
| `u` | `unsigned int` | Unsigned decimal integer. |
| `x` | `unsigned int` | Unsigned hexadecimal integers (using "`abcdef`"). |
| `X` | `unsigned int` | Unsigned hexadecimal integers (using "`ABCDEF`"). |
| `%` | `NONE` | Display the `%` character |

#### How types work with specifiers

| Format specifier | `0` | `-` | width | precision |
| --- | :---: | :---: | :---: | --- |
| `c`, `p` | ⚠️ | ✅ | ✅ | ⚠️ |
| `s` | ⚠️ | ✅ | ✅ | Max number of char printed |
| `d`, `i`, `u`, `x`, `X` | ✅ | ✅ | ✅ | Work like `0` with width |

✅ : Working as usual</br>
⚠️ : Warning

### Flag directives

The first optional field in a conversion specification contains flag directives, zero or more flag characters that specify output justification and control output of signs, blanks, leading zeros, decimal points, and octal and hexadecimal prefixes. More than one flag directive may appear in a conversion specification, and the flag characters can appear in any order.

#### Flag characters

| Flag | Description |
| --- | --- |
| `-` | Left justify |
| `0` | Pad with leading `0`. </br>Flag `0` is ignored when flag `-` is present |

### Width specification

The width argument is a non-negative decimal integer that controls the minimum number of characters that are output. If the number of characters in the output value is less than the specified width, blanks are added to the left or the right of the values—depending on whether the left-alignment flag (`-`) is specified—until the minimum width is reached. If width is prefixed by `0`, leading zeros are added to integer or floating-point conversions until the minimum width is reached.

If the width specification is an asterisk (`*`), an `int` argument from the argument list supplies the value.

```C
printf( "%0*d", 4, 50 ); /* 0050 is output */
```

### Precision specification

It consists of a period (`.`) followed by a non-negative decimal integer that, depending on the conversion type, specifies the number of string characters, the number of decimal places, or the number of significant digits to be output.

If precision is specified as 0, and the value to be converted is 0, the result is no characters output, as shown in this example:
```C
printf( "%.0d", 0 ); /* No characters output */
```

If the width specification is an asterisk (`*`), an `int` argument from the argument list supplies the value.
```C
printf( "%.*f", 3, 3.14159265 ); /* 3.142 output */
```

#### How precision values affect type

| Type | Meaning | Default |
| --- | --- | --- |
| `c` | The precision has no effect. | Character is printed |
| `d`, `i`, `u`, `x`, `X` | The precision specifies the minimum number of digits to be printed. If the number of digits in the argument is less than precision, the output value is padded on the left with zeros. | Default precision is 1 |
| `s` | The precision specifies the maximum number of characters to be printed. | Characters are printed until a null character is found |

## Sources

+ [Microsoft documentation](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions)

## Licenses & copyright

© Ykman Martin, School 19