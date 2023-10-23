# C++ Data Types

## Primitive Types

### Short Integers

- `short int`: At least 16 bits, almost always 16
- `short`
- `short int`
- `signed short int`

### Unsigned Short Integers

- `unsigned short int`: At least 16 bits
- `unsigned short`
- `unsigned short`

### Integers

- `int`: At least 16 bits, usually 32
- `int`
- `signed`
- `signed int`

### Unsigned Integers

- `unsigned int`
- `unsigned`
- `unsigned int`

### Long Integers

- `long int`: At least 32 bits, usually 32
- `long`
- `long int`
- `signed long`
- `signed long int`

### Unsigned Long Integers

- `unsigned long int`: At least 32 bits, usually 32
- `unsigned long`
- `unsigned long int`

### Long Long Integers

- `long long int`: At least 64 bits
- `long long`
- `long long int`
- `signed long long`
- `signed long long int`

### Unsigned Long Long Integers

- `unsigned long long int`: At least 64 bits
- `unsigned long long`
- `unsigned long long int`

### Fixed Width Integer Types

- `int8_t;`
- `int16_t`
- `int32_t`
- `int64_t`

### Fastest Signed Integer Types

- `int_fast8_t`
- `int_fast16_t`
- `int_fast32_t`
- `int_fast64_t`

### Smallest Signed Integer Types

- `int_least8_t`
- `int_least16_t`
- `int_least32_t`
- `int_least64_t`

### Maximum Width Signed Integer Type

- `intmax_t`

### Signed Integer Type for Holding a Pointer to Void

- `intptr_t`

### Unsigned Fixed Width Integer Types

- `uint8_t`
- `uint16_t`
- `uint32_t`
- `uint64_t`

### Fastest Unsigned Integer Types

- `uint_fast8_t`
- `uint_fast16_t`
- `uint_fast32_t`
- `uint_fast64_t`

### Smallest Unsigned Integer Types

- `uint_least8_t`
- `uint_least16_t`
- `uint_least32_t`
- `uint_least64_t`

### Maximum Width Unsigned Integer Type

- `uintmax_t`

### Unsigned Integer Type for Holding a Pointer to Void

- `uintptr_t`

### Boolean

- `bool b;` (can be `true` or `false`)

## Character Types

### Signed Char

- `signed char`

### Unsigned Char (Also Used for Raw Memory)

- `unsigned char`

### Char (Most Efficient)

- `char`

### Wide Character

- `wchar_t` (32 bits, UTF-32 on Linux, UTF-16 on Windows)

### UTF-16 Character

- `char16_t` (Type for UTF-16, required to be large enough to represent any
  UTF-16 code unit)

### UTF-32 Character

- `char32_t` (Type for UTF-32, required to be large enough to represent any
  UTF-32 code unit)

### UTF-8 Character

- `char8_t` (Type for UTF-8, required to be large enough to represent any UTF-8
  code unit, same as `unsigned char`, `sizeof(char) == 1`)

## Floating Point Types

- `float` (Single precision floating point type, IEEE-754 binary32 format)
- `double` (Double precision floating point type, IEEE-754 binary64 format)
- `long double` (Extended precision floating point type, IEEE-754 binary128
  format)

## Void

- `void`: A type with an empty set of values. It is an incomplete type and
  cannot be completed. Objects of type `void` are disallowed. There are no
  arrays of `void`, nor references to `void`. However, pointers to `void` and
  functions returning `void` are permitted.

## Null Pointer Type

- `std::nullptr_t`: The type of the null pointer literal, `nullptr`. It is a
  distinct type that is not itself a pointer type or a pointer to member type.
  Its values are null pointer constants and may be implicitly converted to any
  pointer and pointer to member type.

## Size and Pointer Difference Types

- `size_t`: Unsigned integer type returned by the `sizeof` operator
- `ptrdiff_t`: Signed integer type returned when subtracting two pointers
