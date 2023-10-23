#include <cstddef>
#include <cstdint>
int main() {

  int inch; // This declaration specifies that `inch` is of type `int` (Integer)

  // Declaration: a statement that introduces an entity into the program and
  //              specifies its type.

  // `type`:      defines a set of possible values and a set of operations
  // `oject`:     some memory that holds a value of some type
  // `value`:     a set of bits interpreted according to a type
  // `variable`:  a named object

  // Styles of variable declaration:

  int my_variable = 0;        // type variable_name = initial_value
  auto my_variable2 = 0;      // auto variable_name = initial_value
  auto my_variable3 = int(0); // auto variable_name = constructor(initial_value)
  auto my_variable4 = int{0}; // auto variable_name = constructor{initial_value}

  // auto: like `let` in other languages, it performs type inference
  // unlike many other languages, `auto` performs type inference at Compile-time

  // Initialization
  double d1 = 2.3;
  double d2{2.3};
  double d3 = {2.3}; // the = is optional with {...}
  // The {} notation (called initializer list) doesn't perform implicit
  // conversions that degrade information, for example:
  int i1 = 7.8; // i1 becomes 7
  // int i2{7.8}; // error: floating-point to integer conversion

  // Primitive Types:
  // Scalar VS Compound

  // Scalar:
  // integers, floating-point, booleans, characters

  // integer modifiers: short|long|long long, signed|unsigned
  // fixed-width integers: int32_t, etc
  // integer overflow behavior

  // floating-point: float|double|long double

  // char modifiers: signed|unsigned
  // fixed-width/UTF chars: wchar_t, char16_t, char32_t, char8_t

  // void | nullptr | size_t | ptrdiff_t

  // LITERALS
  int d = 42;       // decimal
  int o = 052;      // octal
  int x = 0x2a;     // hexadecimal
  int X = 0X2A;     // hexadecimalx
  int b = 0b101010; // binary
  // integer-suffixes
  // unsigned int
  auto i_suff = 123u;
  // long long
  auto ll_suff = 123123ll;
  auto llu_suff = 123123llu;
  // using ' for readability
  auto long_number = 123'456'789'000l;
  auto long_number2 = 1'000'000'000'000l;

  // floating-point literal | scientific notation
  auto fp_number = 3.14f;
  auto dprecision_number = 3.14'15'92;
  auto lprecision_number = 3.14'15'92l;
  auto scientific_notation_number = 4e2;
  auto earth_mass = 5.9736e24;
  auto smaller_than_one = 5e-2;

  // Numeric operations
  // division rules
  // modulo operator

  // CONSTANTS - Variables and mutability
  // `const`: The compiler enforces the promise not to change this value.
  //          Use this to ensure that data passed to functions, will not
  //          be altered, only read
  //
  // `constexpr`: To be evaluated at compile-time.
  //              Use this to specify constants
  //              allow placement of data in readonly memory
  //              performance optimization
  //              The value of a `constexpr` annotated variable
  //              must be calculated by the compiler
  //

  return 0;
}
