# Functions

Functions are fundamental in C++ programming, providing a structured way to
define and organize code. Functions allow you to encapsulate blocks of code,
making them reusable and easier to maintain.

## Functions Basics

In C++, functions are a primary mechanism for breaking down your code into
manageable pieces. Functions allow you to define a series of instructions that
can be executed as a single unit. This modular approach enhances code
reusability and maintainability. Here's a program that contains an example
function definition:

```cpp
#include <iostream>

void another_function();

int main() {
    std::cout << "Hello, from main!" << std::endl;

    another_function();
}

void another_function() {
    std::cout << "Another function." << std::endl;
}
```

<!-- TODO: Talk about why we need the declaration: The compiler reads top to bottom -->

### Function Declaration

In C++, you must declare a function before using it, and this requirement stems
from how the C++ compiler reads code from top to bottom. A funtion declaration
specifies the function's name, its return type (if any), and the number and
types of arguments it expects. Consider the following scenario:

```cpp
int main() {
    printNumber(42);
    return 0;
}


void printNumber(int number) {
    cout << "Number: " << number << endl;
}
```

In this example, the `printNumber` function is used in `main()`, but it's
defined after `main()`. If you attempt to compile this code as it is, you will
encounter a compilation error, as the compiler hasn't encountered a declaration
for `printNumber` when it first sees it in `main()`.

To resolve this, you can use a forward declaration. A forward declaration
provides a prototype for the function, allowing you to inform the compiler about
the function's existence before it's defined. Here's how you can modify the
code:

```cpp
// Forward declaration
void printNumber(int number);

int main() {
    printNumber(42);
    return 0;
}

// Definition of the function
void printNumber(int number) {
    cout << "Number: " << number << endl;
}
```

With the forward declaration, the compiler knows that there's a function named
`printNumber` with the specified signature, and you can call it in `main()`.
Later in the code, the function is fully defined. This approach resolves the
issue and allows the code to compile successfully.

### Function Definition

A function definition provides the actual implementation of the function,
including the block of code that will execute when the function is called:

```cpp
void another_function() {
    std::cout << "Another function." << std::endl;
}
```

### Arguments (Input Parameters)

We can define a function to have input parameters that enable callers to pass
concrete values as arguments into the function.

Here's an example:

```cpp
// function declaration
int add(int a, int b);

// function definition
int add(int a, int b) {
    return a + b;
}
```

The declaration of `add` has two arguments `a` and `b` of type `int`.

### Calling Functions

Once a function is declared and defined, you can call it from other parts of
your code to execute the defined actions. Calling a function involves specifying
the function name and providing any required arguments. If the function has a
return value, you can assign it to a variable or use it directly.

Here's an example:

```cpp
addition_result = add(1,1);
```

### Trailing Return Type

In C++, when declaring functions, you can use a trailing return type, especially
when the return type depends on the function's arguments or complex expressions.
The trailing return type syntax involves specifying the return type after the
function parameter list, following the `auto` keyword and the `->` operator.

Here's the general structure of a function declaration using a trailing return
type:

```cpp
auto function_name(argument_type1 arg1, argument_type2 arg2, ...) -> return_type {
    // Function body
    // ...
}
```

In this declaration:

- `auto` represents a placeholder for the return type, allowing you to use
  expressions or decltype to determine the return type.
- `function_name` is the name of the function.
- `argument_typeX` defines the data type of each function argument.
- `argX` is the name for each function argument.
- `return_type` specifies the actual return type of the function.

Here's an example using a trailing return type:

```cpp
auto multiply(int a, double b) -> decltype(a * b) {
    return a * b;  // Return the product of a and b
}
```

In this case, the trailing return type `-> decltype(a * b)` indicates that the
return type is deduced from the expression `a * b`. This allows you to create
more flexible functions with complex return types.

<font size="2"> _sidenote - `decltype` : In C++, decltype is an operator used to
determine the type of an expression or a variable. It can be helpful when
working with complex types or in cases where the type may not be immediately
apparent. The primary use of decltype is to deduce the type of an expression or
variable without evaluating it._

_`decltype` doesn't evaluate the expression, it simply determines the type based
on the epxression's structure._ _`common use cases:` trailing return types,
where the return type depends on a complex expression, templates and generic
programming._
</font>

### Function Overloading

In C++, function overloading is a feature that allows you to define multiple
functions in the same scope with the same name but different parameters. The key
to function overloading is that the functions must have different parameter
lists. When you call an overloaded function, the compiler determines the
appropriate function to execute based on the number and types of arguments you
provide.

Here's an example of function overloading:

```cpp
#include <iostream>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    int result1 = add(3, 5);
    double result2 = add(2.5, 3.7);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}
```

## `constexpr`

The `constexpr` keyword was introduced in C++11 and further improved in C++14.
It stands for "constant expression" and can be applied to variables, functions,
and class constructors. `constexpr` plays a significant role in compile-time
evaluation, enabling more efficient and safer code.

### `constexpr` Variables

You can declare variables as `constexpr` to indicate that their values are
constant and, whenever possible, will be computed at compile time. A `constexpr`
variable must be initialized with a constant expression.

```cpp
constexpr int constantValue = 42; // A constexpr integer variable
```

`constexpr` variables can be used in places where a const integer is required,
such as in template arguments, array declarations, and more.

### `constexpr` Functions

Functions declared as `constexpr` are evaluated at compile time when called with
constant expressions as arguments. This can lead to more efficient code
execution and reduced memory usage. Here's how you can define a constexpr
function:

```cpp
constexpr double square(double x) {
    return x * x;
}
```

You can call a `constexpr` function with both constexpr and non-constexpr
arguments. When called with non-constexpr arguments, the function will be
computed at runtime. However, when called with `constexpr` arguments, the result
is guaranteed to be computed at compile time.

### `consteval` Functions

In C++20, the `consteval` keyword was introduced. It's used to declare functions
that are only allowed to be used for evaluation at compile time. These functions
are typically more restrictive than regular `constexpr` functions and are
intended for cases where compile-time evaluation is crucial:

```cpp
consteval double square2(double x) {
    return x * x;
}
```

Attempting to use a `consteval` function with non-constexpr arguments will
result in a compilation error.

`constexpr` and `consteval` are powerful tools for ensuring that your code can
be optimized for both runtime and compile time, depending on the context in
which it's used. They contribute to more efficient and safer C++ code.

# Control Flow

In C++, control flow allows you to make decisions and run code conditionally or
repeatedly. These fundamental constructs are present in most programming
languages and provide the means to control the execution of your code. C++
offers various tools for managing control flow, including conditional statements
and loops.

In this chapter, you'll explore the key control flow mechanisms in C++. You'll
learn how to make decisions using if statements and switch cases, enabling your
program to execute specific code based on different conditions. You'll also
delve into loops, allowing you to repeat actions until a particular condition is
met.

Just like in most programming languages, control flow is crucial in C++ to build
dynamic, responsive, and efficient applications. Let's begin by examining the
foundations of conditional statements in C++.

## `if` Statements

In C++, `if` statements are a fundamental tool for making decisions and
branching your code based on conditions. They allow you to specify different
blocks of code to execute, depending on whether a given condition is met.

Here's an example of using `if` statements:

```cpp
#include <iostream>

int main() {
    int number = 3;

    if (number < 5) {
        std::cout << "condition was true" << std::endl;
    } else {
        std::cout << "condition was false" << std::endl;
    }

    return 0;
}
```

In this example, we start with the `if` keyword, followed by the condition we
want to evaluate within the parentheses. The condition checks whether the
variable `number` has a value less than 5. If this condition is true, the code
inside the first set of curly braces will execute, displaying "condition was
true." If the condition is false, the code inside the `else` block will execute,
displaying "condition was false."

You can actually choose to omit the `else` part. If the condition in the `if`
statement is false and no `else` block is provided, the program will simply skip
the `if` block and proceed to the next part of the code.

Now, let's change the value of `number` to a value that makes the condition
false:

```cpp
int number = 7;
```

After running the program again, you will see the following output:

```bash
condition was false
```

In C++, the if statement condition can accept values that can be implicitly
converted to boolean. The condition is considered true if the value is not zero
and false if the value is zero. This means you can use integers and other types
in if conditions without explicitly converting them to boolean values. If the
value is zero, the condition is considered false, and if it's not zero, the
condition is considered true.

## Handling Multiple Conditions with `else if`

In C++, you can use multiple conditions by combining `if` and `else if`
expressions, allowing you to check multiple conditions in a sequence. Here's how
it works:

```cpp
#include <iostream>

int main() {
    int number = 6;

    if (number % 4 == 0) {
        std::cout << "Number is divisible by 4" << std::endl;
    } else if (number % 3 == 0) {
        std::cout << "Number is divisible by 3" << std::endl;
    } else if (number % 2 == 0) {
        std::cout << "Number is divisible by 2" << std::endl;
    } else {
        std::cout << "Number is not divisible by 4, 3, or 2" << std::endl;
    }

    return 0;
}
```

This program can take four different paths based on the conditions. When you run
it, you will see the following output:

```bash
Number is divisible by 3
```

In this program, each `if` and `else if` expression is checked in order, and the
code block associated with the first true condition is executed.

## The `switch` Statement

The `switch` statement is a control structure in C++ that provides an efficient
way to select one of many code blocks to be executed. It's often used when you
have a single expression that you want to compare to multiple values, each of
which can trigger different code to be executed.

Here's the basic syntax of the `switch` statement:

```cpp
switch (expression) {
    case constant1:
        // Code to execute when expression == constant1
        break;
    case constant2:
        // Code to execute when expression == constant2
        break;
    // Additional cases...
    default:
        // Code to execute when no case matches
}
```

Here's how it works:

1. The `switch` statement starts with the expression you want to evaluate (e.g.,
   an integer, character, or enumeration).

2. Inside the `switch` statement, you have one or more `case` labels, each
   followed by a constant value. These `case` labels define different possible
   values that the expression can have.

3. When the `switch` statement is executed, it evaluates the expression and
   compares it to the values in the `case` labels. If it finds a match, it
   executes the code block associated with that `case`. If no match is found,
   the code block associated with the default label (optional) is executed.

4. The `break` statement is used to exit the `switch` statement once a match is
   found. This prevents the code from falling through and executing the code
   blocks of subsequent `case` labels.

5. The `default` label, if provided, is executed when none of the `case` labels
   matches the expression.

## Repetition with Loops

It’s often useful to execute a block of code more than once. C++ provides
several types of loops: `for`, `while`, and `do-while`. Each of these loops has
its own use cases and syntax. Let's briefly explore each type of loop:

### The `for` loop:

```cpp
for (initialization; condition; update) {
    // Code to be repeated
}
```

- **initialization**: You set up any variables or conditions here before
  entering the loop.
- **condition**: The loop continues as long as this condition is true.
- **update**: An operation that changes the condition with each iteration,
  typically incrementing or decrementing a variable.

```cpp
for (int i = 0; i < 5; i++) {
        std::cout << "For loop iteration " << i << std::endl;
}
```

### The `while` loop

The `while` loop is used when you want to repeat a block of code as long as a
specified condition remains true.

```cpp
while (condition) {
    // Code to be repeated
}
```

The loop will execute as long as the condition remains true. If the condition is
initially false, the code inside the loop will never run.

```cpp
int j = 0;
while (j < 5) {
    std::cout << "While loop iteration " << j << std::endl;
    j++;
}
```

### The `do-while` loop

The `do-while` loop is similar to the `while` loop, but it guarantees that the
loop body runs at least once before checking the condition. This is useful when
you want to ensure that a piece of code runs before the condition is evaluated.

```cpp
do {
    // Code to be repeated
} while (condition);
```

The loop body is executed, and then the condition is checked. If the condition
is true, the loop continues; otherwise, it terminates.

```cpp
int k = 0;
do {
    std::cout << "Do-while loop iteration " << k << std::endl;
    k++;
} while (k < 5);
```

<font size=2> _sidenote: The choice of loop depends on the specific requirements
and style of your code._ </font>

## Summary

In this chapter, we covered essential concepts in C++: functions and control
flow. Functions are the building blocks of C++ programs, encapsulating logic and
enabling specific operations. We discussed function declaration, including
parameters and return types, and introduced trailing return types for flexible
declarations.

We explored if expressions, and multiple else if branches for handling various
conditions. The switch statement was introduced for more complex condition
handling.

In the upcoming chapters, we'll explore common C++ containers, like arrays,
vectors and maps, and discuss efficient ways to work with them. We'll also dive
into common Standard Template Library (STL) algorithms that simplify programming
tasks. These topics will enhance your C++ skills and help you write more
efficient code.
