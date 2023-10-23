# Variables and Data Types

Every name and every expression has a certain data type, which tells C++ what
kind of data is being specified so it knows how to work with that data.

For example the declaration:

```cpp
int inch;
```

specifies that `inch` is of type `int`; that is, `inch` is an integer variable.

- `Declaration` : a statement that introduces an entity into the program and
  specifies its type.
- `Type` : defines a set of possible values and a set of operations for an
  object.
- `Object` : some memory that holds a value of some type.
- `Value` : a set of bits interpreted according to a type.
- `Variable` : a named object.

## Different styles of variable declaration

- **Oldschool/Conventional Explicit Style:** `type name = initial_value;`

```cpp
int variable_name = 0;
```

With this style of declaration, we explicitly declare the data type of our
variable and assign an initial value to it. Assigning an initial value is not
mandatory with this style of variable declaration, however, it is considered a
good practice to do so.

After you first declare a variable, you can't change its type at some later
point. However, you can copy the variable's value into another variable of a
different type. Such operations are called `type conversions`, which are
sometimes necessary but may incur data loss or incorrectness.

- **Modern Style with type inference:** `auto name = initial_value;`

```cpp
auto variable_name = 0;
```

Using the `auto` keyword, is similar to some other languages `let` keyword; it
instructs the compiler to deduce the type from the initilizer. In the case of
C++, this type inference is happening at compile-time.

- **Modern Style using `auto` with explicit Type:**
  `auto name = type(initial_value)`

```cpp
auto variable_name = int{0};
```

This style provides various benefits:

1. **Avoidance of Implicit Conversions**

Using this style, incorporates a feature called `uniform initialization`; you
explicitly specify the type of the variable on the right side of the assignment.
This form of initialization prevents implicit type conversions, reducing the
risk of unexpected behavior and potential data loss.

2. **Consistent Style**

Consistency in coding style is crucial for readability and maintainability. By
adopting a uniform style of variable declaration, you create a consistent
pattern that other developers can easily follow.

3. **Alignment with Modern Language Trends**

Many modern programming languages, place the type on the right side of the
variable name declaration. This style is often more intuitive, as it mirrors the
way we read and interpret code. By using this style, you make your code more
accessible to developers coming from other languages.

## Initialization

Initialization is the process of assigning an initial value to a variable when
it's created. In C++, you have several methods to perform initialization, each
with its own syntax and behavior.

- **Direct Initialization**

Direct initialization involves using the assignment operator `=` to assign a
value to a variable of specified type:

```cpp
double d1 = 2.3;
```

In this case, `d1` is directly initialized with the value `2.3`. This style of
initialization is straightforward and widely used in C++.

- **Uniform Initialization**

C++11 introduced uniform initialization using curly braces `{}` :

```cpp
double d1{2.3}
```

In this exaple, `d1` is uniformly initialized with the value `2.3`. You can also
, optionally, use the `=` :

```cpp
double d1 = {2.3};
```

Uniform initialization with curly braces is referred to as an initializer list.
It has some advantages, including preventing implicit conversions that may lead
to data loss or incorrect results. For instance:

```cpp
int i1 = 7.8;   // i1 becomes 7
int i2{7.8};    // error: floating-point to integer conversion
```

Here, `i1` is directly initialized with the value `7` due to implicit type
conversion, while `i2` triggers an error because uniform initialization prevents
such conversions.

## Scalar Data Types

A `Scalar Type` is a Type that holds a single value of a defined range. Scalars
include arithmetic types (integral or floating-point values), enumeration type
members, pointer types, char types, and booleans. Fundamental types are
typically scalar types.

### Integers

An integer is a number without a fractional component. The default integer type
is `int`. It can be `signed` (by default) or `unsigned`. A size modifier
specifies the width of the integer representation: `short`, `long`, `long long`

A `long` must be at least 32 bits, and a `long long` at least 64 bits.

**Fixed-Witdh Integers**

Fixed-width integers are integer types in C++ that have a specified, fixed
number of bits, ensuring a consistent size across different platforms. These
types are defined in the <cstdint> header and provide a predictable and portable
way to work with integers of specific sizes.

Here are some commonly used fixed-width integer types in C++:

- int8_t: A signed 8-bit integer.
- int16_t: A signed 16-bit integer.
- int32_t: A signed 32-bit integer.
- int64_t: A signed 64-bit integer.

These types guarantee a certain size and representation, making them useful for
scenarios where you need precise control over the number of bits used to store
an integer value. For example, when working with binary file formats or
networking protocols, you may require fixed-width integers to ensure data
consistency across different systems.

Similarly, there are corresponding unsigned fixed-width integer types:

- uint8_t: An unsigned 8-bit integer.
- uint16_t: An unsigned 16-bit integer.
- uint32_t: An unsigned 32-bit integer.
- uint64_t: An unsigned 64-bit integer.

Fixed-width integers are particularly important when writing cross-platform
code, as they ensure that integer types have consistent sizes regardless of the
underlying hardware architecture. This consistency helps prevent unexpected
behavior or compatibility issues when moving code between different systems.

### Floating-point types

Floating-point types in C++ are used to represent real numbers with fractional
parts. They are essential for tasks involving scientific computation, physics
simulations, financial calculations, and more. C++ provides three primary
floating-point types:

- `float` (Single precision floating point type, IEEE-754 binary32 format)
- `double` (Double precision floating point type, IEEE-754 binary64 format)
- `long double` (Extended precision floating point type, IEEE-754 binary128
  format)

  Floating-point numbers can represent a wide range of values, both large and
  small, and they can handle fractional parts. However, they are not suitable
  for representing exact values, especially when dealing with irrational numbers
  like π (pi) or numbers with repeating decimals. Floating-point arithmetic may
  also introduce rounding errors due to the limitations of the representation.

When working with floating-point types, it's essential to be aware of the
limitations and potential issues, such as comparing floating-point numbers for
equality (which can lead to unexpected results due to rounding errors). C++ also
provides functions like `std::isnan()` and `std::isinf()` to check for NaN
(Not-a-Number) and infinity values that can occur in floating-point
calculations.

### Character types

- `char` : is used to represent individual ASCII characters, such as letters,
  digits, and symbols.

```cpp
char grade = 'A';
```

- `signed char` : similar to `char` but explicitly signed. It can represent both
  positive and negative values within the range of a signed 8-bit integer.

```cpp
signed char temperature = -10;
```

- `unsigned char`: is an unsigned version of `char`, meaning it can only
  represent non-negative values. It's often used to handle binary data or
  byte-level manipulations.

```cpp
unsigned char bitmask = 0b00101011;
```

- `wchar_t` (Wide Character): The wchar_t type is used to represent wide
  character values that may be encoded in various formats. It is typically 2
  bytes on most systems (UTF-16 on Windows), but its size can vary depending on
  the platform. It's commonly used when working with wide strings, such as
  std::wstring, which can handle characters beyond the ASCII range.

**Fixed width UTF Character Types**

C++ introduced fixed-width character types to handle Unicode characters and
ensure consistent sizes across platforms. These types are essential for working
with UTF-8, UTF-16, and UTF-32 encoded characters:

- **UTF-16 Character**

`char16_t` (Type for UTF-16, required to be large enough to represent any UTF-16
code unit)

- **UTF-32 Character**

`char32_t` (Type for UTF-32, required to be large enough to represent any UTF-32
code unit)

- **UTF-8 Character**

`char8_t` (Type for UTF-8, required to be large enough to represent any UTF-8
code unit, same as `unsigned char`, `sizeof(char) == 1`)

### Boolean Type

The `boolean` type in C++ is used to represent values that can have one of two
logical states: `true` or `false`. It is a fundamental data type used in
decision-making, conditional statements, and logical operations. In C++, the
boolean type is represented by the `bool` keyword.

Here's how you can declare and use boolean variables in C++:

```cpp
bool isTrue = true;
bool isFalse = false;
```

`Boolean` variables are commonly used in logical expressions:

- `&&` (logical AND): Returns `true` if both operands are true.
- `||` (logical OR): Returns `true` if at least one operand is true.
- `!` (logical NOT): Returns the opposite of the operand's value. For example,
  `!true` is `false`, and `!false` is `true`.

`Boolean` values are often the result of comparison operations, such as:

    - `==` (equal to): Returns `true` if two values are equal.
    - `!=` (not equal to): Returns `true` if two values are not equal.
    - `<` (less than): Returns `true` if the left operand is less than the right operand.
    - `>` (greater than): Returns `true` if the left operand is greater than the right operand.
    - `<=`(less than or equal to): Returns `true` if the left operand is less than or equal to the right operand.
    - `>=` (greater than or equal to): Returns `true` if the left operand is greater than or equal to the right operand.

---

| Type          | Size            | Comment                                                                                                                                                                                                      |
| ------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| int           | 4 bytes (32bit) | The default choice for integral values.                                                                                                                                                                      |
| double        | 8 bytes (64bit) | The default choice for floating-point values.                                                                                                                                                                |
| bool          | 1 byte (8bit)   | Represents values that can be either true or false.                                                                                                                                                          |
| char          | 1 byte (8bit)   | Use for ASCII characters in older C-style strings or std::string objects that will never have to be converted to UNICODE.                                                                                    |
| wchar_t       | 2 bytes (16bit) | Represents "wide" character values that may be encoded in UNICODE format (UTF-16 on Windows, other operating systems may differ). wchar_t is the character type that's used in strings of type std::wstring. |
| unsigned char | 1 byte (8bit)   | C++ has no built-in byte type. Use unsigned char to represent a byte value.                                                                                                                                  |
| unsigned int  | 4 bytes (32bit) | Default choice for bit flags.                                                                                                                                                                                |
| long long     | 8 bytes (64bit) | Represents a much larger range of integer values.                                                                                                                                                            |

---

### The `size_t` type

The `size_t` type is an unsigned integer data type used to represent the sizes
of objects in memory, such as arrays, buffers, or the number of elements in a
container. It is defined in the C++ standard library as an
implementation-defined type. `size_t` is often used in contexts where you need
to express the size or length of data structures or memory regions. It is
guaranteed to be capable of representing the maximum possible size of an object
in the current environment.

### Pointer types

Pointer types in C++ are used to store memory addresses, allowing you to
manipulate memory directly. While we will delve into pointer types in detail in
the "Memory Management" chapter, here's a brief mention:

- **Pointer Variables:** Pointer variables store memory addresses. For example,
  `int* ptr` declares a pointer variable ptr that can store the memory address
  of an integer.

- **Dereferencing:** You can use the `*` operator to access the value stored at
  the memory address pointed to by a pointer. For example, `int x = *ptr;`
  assigns the value at the address stored in ptr to x.

- **Pointer Arithmetic:** Pointers can be manipulated using arithmetic
  operations like addition and subtraction. For instance, `ptr++` increments the
  pointer to point to the next memory location.

- **Dynamic Memory Allocation:** Pointers are essential for managing dynamically
  allocated memory using operators like `new` and `delete`.

While pointers are powerful tools for memory manipulation, they also require
careful handling to avoid issues like memory leaks and segmentation faults. We
will explore pointer types and their usage in more depth in the
`"Memory Management"` chapter.

### The `void` Type

The `void` type is a special type; you can't declare a variable of type `void`,
but you can declare a variable of type `void *` (pointer to `void`), which is
sometimes necessary when allocating raw (untyped) memory. However, pointers to
`void` aren't type-safe and their use is discouraged in modern C++. In a
function declaration, a `void` return value means that the function doesn't
return a value; using it as a return type is a common and acceptable use of
`void`. While the C language required functions that have zero parameters to
declare `void` in the parameter list, for example, `fn(void)`, this practice is
discouraged in modern C++; a parameterless function should be declared fn().

## Compound Types

`Compound Types` are types that aren't `scalar`. Compound types include array
types, function types, struct types, class types, union types, enumerations and
references.

In this chapter we will talk about `structs`, `enums` (enumerations) and
`unions` , which are considered `User-defined` Types: The compiler has no
built-in knowledge of a user-defined type. You specify what operations can be
performed on your type, and how it can be converted to other types.

### Structs

A struct (short for "structure") is a compound data type in C++ that allows you
to group multiple variables of different data types together under a single
name. Each member variable within a struct can have a unique data type, and
these members share the same memory location.

#### Declaring and Defining a Struct

You can declare and define a struct in C++ using the struct keyword, followed by
the struct's name and a list of member variables enclosed in curly braces.
Here's an example:

```cpp
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    ...
    // Create an instance of the 'Person' struct
    Person person1;

    // Assign values to its members
    person1.name = "John";
    person1.age = 30;
    person1.height = 175.5;

    ...
}
```

#### Accessing Struct Members

To access the members of a struct, you use the dot `.` operator followed by the
member's name. For example, `person1.name` is used to access the `name` member
of the `person1` struct.

#### Struct Size

The size of a struct is determined by the sum of the sizes of its individual
members, including any padding or alignment required by the compiler. For
example, if a struct contains an `int` (4 bytes), a `double` (8 bytes), and a
`char` (1 byte), its size will typically be at least 13 bytes (4 + 8 + 1).

#### Common Use Cases

Structs are used for various purposes in C++ and are especially valuable for
organizing related data into a single unit. Some common use cases for structs
include:

- **Data Structures:** Structs are often used to define data structures like
  linked lists, queues, stacks, and trees.

- **Composite Data:** When you need to group related data that belongs together
  into a single object, structs provide a convenient way to do so.

- **Passing Complex Data:** Structs can be used to pass complex data as function
  arguments or return values.

### Enums

Enums, short for enumerations, are a way to create named integral constants in
C++. They provide a convenient and more readable way to work with a set of
related integer values. There are two primary ways to define enums in C++:
traditional enums and enum classes.

#### Traditional Enums

Traditional enums are simple and have been part of C++ since its early days.
Here's how you define a traditional enum:

```cpp
// Define a traditional enum named 'Color'
enum Color {
    Red,
    Green,
    Blue,
    Yellow
};

int main() {
    // Declare a variable of type 'Color' and assign a value
    Color myColor = Blue;

    // Use 'switch' to work with enum values
    switch (myColor) {
        case Red:
            std::cout << "The color is Red." << std::endl;
            break;
        case Green:
            std::cout << "The color is Green." << std::endl;
            break;
        case Blue:
            std::cout << "The color is Blue." << std::endl;
            break;
        case Yellow:
            std::cout << "The color is Yellow." << std::endl;
            break;
        default:
            std::cout << "Unknown color." << std::endl;
    }

    return 0;
}
```

In this example, we've defined a traditional enum named Color, which consists of
four named constants: Red, Green, Blue, and Yellow. You can use these constants
to represent colors in your program.

#### Enum Classes (Strongly Typed Enums)

Enum classes, introduced in C++11, offer better type safety and encapsulation
compared to traditional enums. They are also known as strongly typed enums
because they don't implicitly convert to integers or other enum types. Here's
how you define an enum class:

```cpp
enum class Month {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    // Declare a variable of type 'Month' and assign a value
    Month currentMonth = Month::July;

    // Use 'switch' to work with enum class values
    switch (currentMonth) {
        case Month::January:
            std::cout << "It's January." << std::endl;
            break;
        case Month::February:
            std::cout << "It's February." << std::endl;
            break;
        // ... (other months)
        default:
            std::cout << "Invalid month." << std::endl;
    }

    return 0;
}
```

Key differences between traditional enums and enum classes:

- Enum classes are scoped; you must use the scope resolution operator `::` to
  access their values (e.g., `Month::January`).
- Enum classes do not implicitly convert to integers or other enum types,
  reducing the risk of unintended type conversions.
- Enum classes have better encapsulation, making it harder to accidentally mix
  enum values from different enum classes.
- Enum classes can be associated with an underlying integral type, allowing you
  to specify the size and range of values they can represent:

```cpp
// Define an enum class named 'Month' with an underlying type 'int'
enum class Month : int {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};
```

Keep in mind that you can choose from various integral types like `int`, `char`,
`short`, `long`, etc., depending on your requirements. Using an underlying type
for enum classes gives you more flexibility and control in managing your
program's data.

Enum classes are generally preferred for new code in C++ because they offer
improved type safety and maintainability.

### Unions

A union in C++ is a compound type that allows its members to share the same
memory location. This means that a union can only hold one value at a time, and
its size is determined by the largest member within it. Unions are useful when
you need to represent multiple types of data using the same memory location, but
only one type is used at any given time.

#### Union Declaration and Usage

To declare a `union`, you use the union keyword followed by the union's name and
a block that lists its member variables. Each member variable defines a type,
and all members share the same memory location.

```cpp
union MyUnion {
    int intValue;
    double doubleValue;
    char charValue;
};
```

You can access the members of a union using the member access operator `.`, just
like you would with a struct or class:

```cpp
MyUnion u;
u.intValue = 42;
std::cout << u.intValue; // Outputs: 42
```

#### Memory Allocation

Unions are designed to optimize memory usage because they allocate memory based
on the size of their largest member. In the example above, if you store an `int`
in the union, it will use enough memory to accommodate the largest type, which
is `double`. This might result in wasted memory for smaller types like `int` or
`char`. However, unions are useful when you need to switch between different
types without changing memory locations.

#### Handling Union Members

It's crucial to keep track of which member is currently active in the union
since C++ doesn't provide built-in mechanisms to do so. In other words, you need
to maintain a separate variable or mechanism to determine which type of data is
stored in the union at a particular time.

#### Encapsulation and Safety

Handling unions correctly can be error-prone because you must manually track
which member is in use. To improve safety and avoid mistakes, it's common to
encapsulate unions within classes or structs and provide member functions that
correctly handle the union's state. This approach ensures that you don't
accidentally access the wrong member.

### C++17 and Beyond: `std::variant`

Starting from C++17, the C++ Standard Library introduced `std::variant`, which
provides a safer and more convenient alternative to using unions directly.
`std::variant` allows you to store values of different types and provides
type-safe access to those values. It enforces type safety and eliminates the
need to manually track the active member.

Here's how the example with `std::variant` might look:

```cpp
#include <iostream>
#include <variant>
#include <string>

int main() {
    // Define a variant that can store either an integer or a string
    std::variant<int, std::string> data;

    // Store an integer in the variant
    data = 42;

    // Check the type and access the value
    if (std::holds_alternative<int>(data)) {
        int intValue = std::get<int>(data);
        std::cout << "Stored integer: " << intValue << std::endl;
    }

    // Store a string in the variant
    data = "Hello, Variant!";

    // Check the type and access the value
    if (std::holds_alternative<std::string>(data)) {
        std::string stringValue = std::get<std::string>(data);
        std::cout << "Stored string: " << stringValue << std::endl;
    }

    return 0;
}
```

In this example:

- We define a `std::variant` called `data` that can store either an `int` or a
  `std::string`.

- We store an integer (42) in the data variant.

- We check the type of data using `std::holds_alternative`. If it's an integer,
  we extract and print the integer value.

- Next, we store a `string` ("Hello, Variant!") in the same data variant.

- Again, we check the type using `std::holds_alternative`. If it's a string, we
  extract and print the string value.

Using `std::variant`, you get a more robust and type-safe solution for handling
multiple types within a single data structure, reducing the chances of runtime
errors.

## Literal Types

In C++, a literal type is a type whose objects can be constructed at
compile-time using literals. This means you can create objects of these types
directly by specifying their values in your code. Literal types are fundamental
for specifying constant values in your programs. In C++, there are several types
of literals, each corresponding to specific data types.

### Integer Literals

Integer literals represent whole numbers. They can be specified in various
bases:

- **Decimal**: Default base. Example: `42`
- **Octal**: Prefix with 0. Example: `052`
- **Hexadecimal**: Prefix with 0x or 0X. Example: `0x2A`
- **Binary**: Prefix with 0b or 0B. Example: `0b101010`

#### Integer Suffixes

You can append suffixes to integer literals to specify their type:

- `u` or `U` for `unsigned int`.
- `l` or `L` for `long`.
- `ll` or `LL` for `long long`.

Example: `123u`, `123ul`, `123LL`

### Floating-Point Literals

Floating-point literals represent real numbers. They can be specified in various
forms:

- Regular: Example: `3.14`
- Scientific Notation: Example: `4e2` (4 \* 10^2)

#### Floating-Point Suffixes

- `f` or `F` for `float`.
- `l` or `L` for `long double`.

Example: `3.14f`, `3.1415926535L`

### Character Literals

Character literals represent single characters and are enclosed in single
quotes. For example, `'A'` or `'9'`.

#### Character Escape Sequences

Some characters are represented using escape sequences, such as `'\n'` for a
newline character or `'\t'` for a tab character.

### Boolean Literals

Boolean literals represent the two truth values: `true` and `false`. These
literals are used in conditional expressions, comparisons, and control flow
statements.

### String Literals

String literals represent sequences of characters and are enclosed in double
quotes. For example, `"Hello, World!"`.

#### String Literal Types

In C++, string literals have an associated array type. For example, `"Hello"`
has the type `const char[6]` (including the null terminator), and `"World"` has
the type `const char[6]`.

### User-Defined Literals

C++ allows you to define custom literal operators for your types. This enables
you to create literals with custom meanings for your user-defined types.

```cpp
constexpr long double operator"" _km(long double x) {
    return x * 1000.0L;
}
```

In this example, the `_km` literal operator allows you to write `5.2_km` to
represent 5.2 kilometers.

Understanding literal types and how to use them is essential for writing clear,
concise, and expressive C++ code. Literal types are the foundation for
specifying constant values and expressing numeric and character data in your
programs.
