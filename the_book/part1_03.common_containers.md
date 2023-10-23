# Common Containers

In C++, we have a rich assortment of standardized containers at our disposal.
These containers are part of the Standard Template Library (STL) and provide
versatile and efficient options for managing and organizing data.

<font size="2"> _sidenote: In the context of programming, a container is a data
structure that holds and manages a collection of objects. It's like an organized
box for your data, allowing you to store, access, and manipulate elements
seamlessly._
</font>

In this chapter, we'll explore the diverse collection of containers that C++
offers:

- raw array
- std::array
- std::span
- std::vector
- std::string, std::string_view
- std::map
- std::tuple

## Raw array

A raw array, also known as a C-style array, is a fundamental data structure in
C++ and serves as a building block for more complex containers. It provides a
simple way to store a fixed-size collection of elements of the same type in a
contiguous block of memory. Unlike higher-level containers like the stl vectors
and arrays, raw arrays don't offer dynamic sizing or built-in operations for
managing their contents. Instead, they give you direct control over the memory
layout of your data.

Declaring a raw array is straightforwad. You specify the data type, followed by
the array's name, and the size of the array enclosed in square brackets:

```cpp
int my_array[5]; // Declare an integer array with 5 elements.
```

This creates an array that can hold five integers. Keep in mind that the size of
a raw array is fixed at compile time, and you cannot change it during runtime.

accessing elements in a raw array is done using zero-based indexing. For
example, to assign a value to the third element of the `my_array` declared
above, you'd do the following:

```cpp
my_array[2] = 42; // Assign the value 42 to the third element
```

But beware of array bounds; trying to access or modify elements beyond the
array's defined size can lead to undefined behavior or memory corruption.

```cpp
int my_array[5] = {1, 2, 3, 4, 5};
// Attempting to access an element beyond the array's bounds
int value = my_array[10]; // Out-of-bounds accessing
```

- ⚠️ In the example above, `my_array` is declared to have a size of 5. Accessing
  `my_array[10]` goes beyond the array's bounds and can lead to unpredictable
  behavior, memory corruption, or application crashes.

Raw arrays are a good choice when you know the exact number of elements you
need, and their size won't change throughout your program. They are also more
memory-efficient than dynamic containers since they don't carry the additional
functionality for resizing and management.

while raw arrays offer simplicity and efficiency, C++ provides higher-level
container types like `std::vector` and `std::array` to address more complex
scenarios.

## `std::array`

`std::array` is a safer and more feature-rich alternative to raw arrays. It is
part of the C++ Standard Library and offers several advantages over traditional
arrays. A `std::array` is a fixed-size container that provides bounds checking
and is compatible with standard algorithms, making it a popular choice for many
applications.

```cpp
std::array<data_type, size> my_array;
```

- data_type: the data type of the elements you want to store, e.g. `int, float`
  etc
- size: the number of elements the `std::array` can hold, and it must be defined
  at compile time

For example, declaring a `std::array` of 5 integers would look like this:

```cpp
std::array<int, 5> my_array;
```

And this is how you initialze a `std::array`:

```cpp
std::array<data_type, size> my_array = {elem1, elem2, elem3 ...};
```

One of the primary benefits of `std::array` is its safety features. It provides
automatic bounds checking, ensuring that you can't access elements outside the
valid range. If you try to access an out-of-bounds element, the program will
terminate with an error, preventing potential crashes or memory corruption.

Accessing elements in a `std::array` with bounds-checking is done usint the
`.at()` method:

```cpp
std::array<int, 3> numbers = {1, 2, 3};

try {
    int value = numbers.at(4); // Accessing an out-of-range element
    std::cout << value << std::endl;
} catch (const std::out_of_range& e) {
    std::cerr << "Out of range exception: " << e.what() << std::endl;
}
```

If you prefer not to have bounds checking and are confident that your code won't
access out-of-range elements, you can use the `[]` operator, which has no bounds
checking:

```cpp
int value = numbers[4]; // No bounds checking
```

`std::array` also has a `size()` member function that returns the number of
elements in the container, allowing you to loop through its contents without
worrying about managing the size.

```cpp
for (std::size_t i=0; i<my_array.size(); ++i) {
    // Access my_array[i]
}
```

### Iterating Through a `std::array`

Iterators are a crucial tool when working with containers like `std::array`.
They provide a way to traverse the elements in a container one by one, without
the need for array-style indexing. Here is how you can iterate through a
`std::array`:

```cpp
#include <iostream>
#include <array>

int main() {
    std::array<int, 4> numbers = {1, 2, 3, 4};

    // Using iterators to traverse the array
    for (std::array<int, 4>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}
```

You can also use a range-based for loop to make the code more concise and
readable:

```cpp
#include <iostream>
#include <array>

int main() {
    std::array<int, 4> numbers = {1, 2, 3, 4};

    // Using a range-based for loop
    for (const int& number : numbers) {
        std::cout << number << " ";
    }

    std::cout << stdendl;

    return 0;
}
```

## `std::vector`

In C++, the `std::vector` is a versatile and efficient standard-library
container used for dynamic arrays. It provides various methods for managing
elements and offers flexibility and performance.

### Creating a `std::vector`

To create a new `std::vector`, you don't need to specify its size upfront.
Here's how you can initialize it:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // Create an empty vector

    // Initialize the vector with values using push_back
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);

    // Alternatively, use this concise syntax to initialize directly:
    // std::vector<int> numbers = {5, 6, 7, 8};

    // Access and print vector elements
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, we first create an empty `std::vector` and then add elements
using the `push_back` method. You can also initialize the vector directly with
an initializer list using `{}`.

### Accessing Elements

Accessing elements in a vector can be done using indexing, similar to arrays, or
the `at()` method:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Accessing elements using indexing
    int first = numbers[0]; // First element using []
    int second = numbers.at(1); // Second element using at()

    std::cout << "The first element is: " << first << std::endl;
    std::cout << "The second element is: " << second << std::endl;

    return 0;
}
```

Remember that indexing with `[]` does not perform bounds checking, so you should
ensure the index is within the valid range. The `at()` method, however, provides
bounds checking and throws an exception if the index is out of range.

### Range-based `for` Loop

You can iterate over vector elements conveniently using range-based `for` loop:

```cpp
std::vector<int> numbers = {100, 32, 57};

// Iterate over vector elements using a range-based for loop
for (const int& num : numbers) {
    std::cout << num << " ";
}
std::cout << std::endl;
```

The range-based `for` loop simplifies the process of working with vector
elements.

### `emplace_back` vs. `push_back`

In C++, vectors offer two primary methods for adding elements: `emplace_back`
and `push_back`. Understanding the differences between these methods is
essential for efficient vector usage.

- `push_back` : is a method that adds a copy of the provided element to the end
  of the vector.

```cpp
std::vector<int> numbers;
int value = 42;
numbers.push_back(value); // A copy of 'value' is added to the vectors
```

With `push_back`, you pass an element to the function, which is then copied into
the vector. This copy operation may lead to additional overhead for complex or
user-defined types.

- `emplace_back` : In contrast, `emplace_back` constructs the element directly
  in the vector, eliminating the need for a copy operation. It is particularly
  useful when working with user-defined or complex types.

```cpp
std::vector<std::string> names;
names.emplace_back("Alice");
```

`emplace_back` takes constructor arguments for the element type. The vector
constructs the element in place, avoiding any intermediary copies. This can lead
to better performance and is especially beneficial for classes with custom
constructors.

So why would we ever use `push_back`?

1. **Simplicity**: When you're dealing with simple types, like fundamental data
   types (int, char, etc.), there's no significant advantage to using
   `emplace_back`. Using `push_back` is straightforward and easy to understand.

2. **When You Already Have an Object**: If you have an existing object that you
   want to add to the vector, using `push_back` is more straightforward. It's
   also suitable when you have an object already prepared and don't want to
   create a constructor call with `emplace_back`.

3. **Existing Object Ownership**: If you need to keep the original object
   separate and intend to modify the copy within the vector, `push_back` is more
   suitable. This preserves the original object for future use while providing a
   copy for the vector.

4. **Not Dealing with Complex Types**: For basic types, like fundamental data
   types, `push_back` is efficient enough. The performance difference between
   `push_back` and `emplace_back` in such cases is negligible.

So, while `emplace_back` is often preferred for complex or user-defined types,
`push_back` remains a valid and practical choice for more straightforward
situations. The choice between them depends on the specific requirements and
performance considerations of your code.

### `capacity` and `reserve`

When working with vectors, it's essential to grasp the concepts of `capacity()`
and `reserve()` :

- `capacity()` : This method returns the current storage capacity of the vector.
  It indicates how many elements the vector can hold without reallocation.

- `reserve()` : The `reserve()` function allows you to preallocate storage for
  the vector, ensuring it can hold a specified number of elements without the
  need for reallocation.

For example:

```cpp
std::vector<int> numbers;
numbers.reserve(100); // Reserves space for 100 elements
```

Reserving space can improve preformance, especially when you know the
approximate size of the data you intend to store in the vector. It reduces the
frequency of reallocation, which can be costly in terms of time and memory.

### Copying `std::vector`

You can copy `std::vector` objects easily using assignments and initializations:

```cpp
struct Entry {
    std::string title;
    std::string author;
    int year_published;
};

std::vector<Entry> library = {
    {"A Tour of C++", "Bjarne Stroustrup", 2022},
    {"Applied Acoustics", "Dimitris Scarlatos", 2012}
};

std::vector<Entry> library2 = library;
```

When a vector is copied, it invloves copying its elements, resulting in separate
copies of every element in the new vector. Keep in mind that copying large
vectors can be expensive.

## `std::span` : A Safer Way to Handle Ranges

In C++, handling ranges of elements has often been a source of bugs, crashes,
and security issues. Passing raw pointers and relying on conventions to manage
the number of elements pointed to can lead to range errors. The introduction of
`std::span` (inspired by the GSL- Guidelines Support Library) in C++ helps
address this issue.

### What is `std::span`

A `std::span` is essentially a pair of a pointer to the first element and the
number of elements in a contiguous sequence. It doesn't own the elements it
points to. `std::span` provides safer and more convenient access to elements in
sequences stored in various ways, including vectors and built-in arrays.

### Benefits of `std::span`

- **Safety**: The use of `std::span` encourages safer programming practices by
  explicitly defining the range of element you intend to work with. This helps
  prevent range errors.

- **Readability**: `std::span` improves the readability of your code by
  specifying ranges explicitly, making it clear which elements you are
  accessing.

### Usage of `std::span`

```cpp
void modifyElements(std::span<int> elements) {
    for (auto& element: elements) {
        element *=2;
    }
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    // Create a span from the array
    std::span<int> spanFromArray{array};

    modifyElements(spanFromArray);

    // Elements in the array have been modified
    for (const int& element : spanFromArray) {
        std::cout << element << " ";
    }

    return 0;
}
```

In this example, we use `std::span` to explicitly define the range of elements
we want to modify, which in this case is the entire array. However, you can
choose a smaller range of values by specifying the beginning and end indices
when creating the `std::span`:

```cpp
int array[5] = {1,2,3,4,5};

// Create a span for a smaller range, from index 1 to 3 inclusive
std::span<int> spanFromArray(array + 1, 3);
```

### Notes on Range Checking

It's important to note that like raw pointers, `std::span` does not provide
built-in range checking. Out-of-range access is undefined behavior. Some
implementations may choose to implement range checking, but it's not guaranteed.
Therefore, it's crucial for developers to ensure that they're working with valid
ranges using `std::span`.

## Working with Strings and String-Views

Text manipulation is a fundamental aspect of many programs, and the C++ standard
library provides a robust set of tools to handle strings and text.

### `std::string`

C++ offers the `std::string` type to facilitate the handling of character
sequences. A string is a dynamic array of characters and supports a variety of
useful string operations.

```cpp
std::string first = "Hello, ";
std::string second = "world!";

// Concatenate strings using the + operator
std::string combined = first + second;
std::cout << combined << std::endl;

// Access individual characters using indexing
char first_character = combined[0];
std::cout << "First character: " << first_character << std::endl;

// Modify characters using indexing
combined[7] = 'W'; // single quotes for single characters
std::cout << "Modified string: " << combined << std::endl;
```

In this example, we concatenate two strings, access characters using indexing
like we do in arrays, and modify the string in place. The `std::string` type
provides many more functions for various string manipulations, including finding
substrings, replacing text, and more.

**Side Note**:

- _`std::string` bears some similarities to a `std::vector<char>`, but there are
  good reasons why a separate container is used for strings. `std::string`
  includes a wide range of specialized member functions and behaviors tailored
  for character data._

- _`std::string` utilizes the `Short String Optimization` (SSO), which means
  that short strings are stored directly within the `std::string` object itself.
  Only longer strings are allocated on the heap. This optimization ensures that
  strings of typical length have minimal memory overhead._

### `std::string_view`

Sometimes you need to work with subdtrings or portions of a string without
making a copy. This is where `std::string_view` comes in. It's a lightweight
view into a character sequence and doesn't own the data.

```cpp
#include <iostream>
#include <string_view>

int main() {
    std::string text = "C++ Programming";

    // Create a string_view
    std::string_view view(text);

    // Use string_view to manipulate substrings
    std::string_view sub = view.substr(0, 3); // Get the first 3 characters
    std::cout << "Substring: " << sub << std::endl;

    // Modify the original string
    text[0] = 'P';
    std::cout << "Modified text: " << text << std::endl;

    // The string_view reflects the change
    std::cout << "Updated view: " << view << std::endl;

    return 0;
}
```

In this example, we create a `std::string_view` from a portion of the original
string, and changes in the original string are reflected in the view. This
allows for efficient access to substrings without the overhead of copying.

## Associative Arrays (Dictionaries) in C++

Associative arrays, often referred to as dictionaries in other programming
languages, are essential data structures that enable you to store key-value
pairs. These key-value associations allow for efficient retrieval and management
of data. In C++, when you need to store data as key-value pairs, two commonly
used containers are `std::map` amd `std::unordered_map`:

1. `std::map` : This is an ordered associative array, which means the keys are
   stored in a sorted order. It uses a balanced binary search tree, typically a
   red-black tree, to maintain this order. The keys can be of any comparable
   data type, and the values can be of any data type. Searching for an element
   in a `std::map` has a time complexity of `O(logN)`, making it efficient for
   small to medium-sized datasets.

2. `std::unordered_map` : This is an unordered associative array that stores
   key-value pairs in a hash table. The keys need to be hashable, and the values
   can be of any data type. Retrieving elements from an `std::unordered_map` is
   faster, with the possibility of time complexity of `O(1)` on average and
   `O(N)` in worst case, making it ideal for larger datasets.

### Usage Examples

#### `std::map`

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> team_scores;

    team_scores["Blue"] = 10;
    team_scores["Red"] = 50;

    return 0;
}
```

#### `std::unordered_map`

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> team_scores;

    team_scores["Blue"] = 10;
    team_scores["Yellow"] = 50;

    return 0;
}
```

In both examples, the key type is `std::string`, and the value type is `int`.

### Accsessing Values

Once you've inserted key-value pairs into an associative array, you can access
the values by using the keys. To do this, you can use the `[]` operator.

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> team_scores;

    team_scores["Blue"] = 10;
    team_scores["Yellow"] = 50;

    std::string team_name = "Blue";
    int score = team_scores[team_name]; // Accessing the score for the "Blue" team

    std::cout << "The score for " << team_name << " is: " << score << std::endl;

    return 0;
}
```

This code will display: "The score for Blue is: 10."

### `std::map` vs `std::unorderd_map`

while both `std::map` and `std::unorderd_map` allow you to store key-value
pairs, they have key differences in terms of performance characteristics and use
cases:

- `std::map` :

  - Ordered associative array: The keys are stored in a sorted order using a
    balanced binary search tree.
  - Time complexity for search operations: O(logN)
  - Ideal for small to medium-sized datasets or when you need to maintain a
    sorted order.

- `std::unordered_map` :
  - Unordered associative array: The keys are stored in a hash table.
  - Time complexity for search operations: O(1) average / O(N) worst case
  - Ideal for larger datasets or when you need fast retrieval without any
    specific order.

## A dive into `std::tuple`

C++ provides a versatile container, `std::tuple`, which is designed for storing
multiple values as a single entity. With `std::tuple`, you can group different
types of data together and easily access and manipulate them.

- **Heterogeneous Storage**: `std::tuple` can store values of different types
  within a single object. This makes it ideal for bundling disparate data that
  belongs together logically.
- **Indexing**: Elements in a `std::tuple` are accessed using zero-based
  indexing as follows:

```cpp
std::get<0>(my_tuple); // accessing the first element
```

- **Compile-time Size**: The size of a `std::tuple` is determined at compile
  time, making it a suitable choice when you know the number of types of
  elements you want to store.
- **Flexible and Efficient**: `std::tuple` is known for its flexibility and
  efficiency. It allows you to mix and match data types while maintaining
  performance.

### Creating and Using `std::tuple`

Creatin a `std::tuple` is straightforward. You can declare one by specifying the
types of its elements in angle brackets:

```cpp
#include <tuple>

int main() {
    std::tuple<int, double, std::string> my_tuple(42, 3.14, "Hello, World.");

    int value1 = std::get<0>(my_tuple);
    int value2 = std::get<1>(my_tuple);
    int value3 = std::get<2>(my_tuple);

    return 0;
}
```

### Returning Multiple Values from a Function

One of the most compelling use cases for `std::tuple` is returning multiple
values from a function. Before `std::tuple`, this task often involved using
output parameters or user-defined structs. With `std::tuple`, you can simplify
this process:

```cpp
std::tuple<int, double> computeValues() {
    int int_val = 42;
    double double_val = 3.14;
    return std::make_tuple(int_val, double_val);
}

int main() {
    // ...
    auto result = computeValues();
    int int_val = std::get<0>(result);
    int double_val = std::get<1>(result);
    // ...
    return 0;
}
```

### Destructuring a `std::tuple`

Destructuring is a powerful feature in C++ that simplifies code when dealing
with `std::tuple` or other structured data. It allows you to extract and assign
the elements of a `std::tuple` to individual variables, making your code more
readable and easier to work with.

Destructuring, in the context of `std::tuple`, refers to the process of breaking
down a tuple into its individual elements and assigning them to named variables.

```cpp
using Red = int;
using Green = int;
using Blue = int;
using Alpha = int;

using color = std::tuple<Red,Green,Blue,Alpha>;

const color getCrimsonColor() {
    return std::make_tuple(220,20,60,1);
}

int main() {
    // ...
    const color crimson = getCrimsonColor();

    const auto [red,green,blue,alpha] = crimson; //if you want to access the elements
    // Now 'red', 'green', 'blue', and 'alpha' hold the values from the 'color' tuple
    // ...
}
```

### Potential Downsides and Alternatives

While `std::tuple` provides convenience, it may not always be the cleanest
choice:

- **Lack of Descriptive Names**: `std::tuple` elements are accessed by their
  positions, making it less readable compared to named structs members.
- **Less Type Safety**: In `std::tuple`, you can combine any types, which can
  lead to type mismatches at runtime.

For scenarios where readability and strong typing are crucial, consider using
user-defined types/structs:

```cpp
struct Point {
    int x;
    int y;
};

Point createPoint() {
    Point p;
    p.x = 10;
    p.y = 20;
    return p;
}
```

### Combining Data Sets

`std::tuple` also provides a handy utility called `std::tuple_cat`. It allows
you to concatenate multiple `std::tuple` instances, merging their elements into
a single `std::tuple`. This is particularly useful when you have data stored in
separate tuples and need to combine them:

```cpp
#include <tuple>

int main() {
    std::tuple<int, double> tuple1(42, 3.14);
    std::tuple<std::string, char> tuple2("Hello", 'C');

    auto combined = std::tuple_cat(tuple1, tuple2);

    // ...
    return 0;
}
```

The `combined` tuple now contains elements from both `tuple1` and `tuple2`,
making it a convenient tool for handling data from parallel execution or
combining results from different sources.
