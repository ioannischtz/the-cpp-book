

// Declaration VS Definition

// A function declaration gives the name of the function, the return type,
// and the number and types of the arguments to be supplied.
// aka "function signature"
//
// return_type function_name(arg1_type, arg2_type, ...etc);
// return_type function_name(arg1_type optional_arg1_name, ...etc);
void do_something(int); // int argument, return nothing
double sqrt(double);    // double argument, return double

// trailing return type
auto function_name(int arg1, int arg2) -> int;

// Function definition
// a block of reusable code.
// A function definition consists of the declaration and the function body,
// enclosed in curly braces {}
auto function_name(int arg1, int arg2) -> int { return arg1 + arg2; }

// constexpr
//              For a function to be usable in a `constexpr` context
//              it must be defined `constexpr` or ``
//              e.g.: constexpr double square(double x) {return x*x;}
//
//              a `constexpr` function can also be used with non constexpr
//              arguments, in which case it will be calculated at runtime
//
//              a `consteval` declared function will only be used for
//              evaluation at compile-time
//              e.g.: consteval double square2(double x) {return x*x;}
//              const double max3 = 1.4*square2(var); // ERROR

// Scope and Lifetime
//
// A function definition introduces a `Local scope`:
// A variable declared inside the function body has a scope that
// extends from its point of declaration to the end of the block
// Function arguments are also considered part of the local scope

int main() { return 0; }
