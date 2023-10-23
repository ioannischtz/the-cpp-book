# Programming a Guessing Game

In this chapter, we'll dive into the exciting world of C++ programming by
building a simple guessing game. You'll learn about random number generation,
user input handling, and the basics of control flow in C++. By the end of this
chpater, you'll have a fun and interactive game that challenges users to guess a
secret number with a specified range.

## Setting Up a New Project

1. **Clone the Project Template:** If you haven't already, navigate to the
   directory where you want to create your C++ projects. Open a terminal or
   command prompt and run the following command to clone the project template
   repository:

   ```bash
   git clone https://github.com/ioannischtz/cpp-project-template.git
   ```

2. **Change directory to the template:** Change your working directory to the
   cloned project template folder:

   ```bash
   cd cpp-project-template
   ```

3. **Create a New C++ Project File:** In the project template folder, navigate
   to the `app` directory. Create a new C++ source file for your guessing game
   project. You can name it `guessing_game_app.cpp`:

   ```bash
   cd app
   touch guessing_game_app.cpp
   ```

4. **Open and Edit your Project File:** Use your preferred code editor to open
   and edit the `guessing_game_app.cpp` file. You can start writing the C++ code
   for your guessing game in this file.

5. **Configure the CMakeLists.txt to include your project file:**

   ```
   # You can delete the following 2 lines, since they refer to the
   # example adder app
   add_executable(adder_app adder_app.cpp)
   target_link_libraries(adder_app PRIVATE adder)

   # Add your project file as follows:
   add_executable(guessing_game_app guessing_game_app.cpp)
   ```

6. **Configure and Build your Project:** After writing your code, configure and
   build your project by following these commands:

   ```bash
   cd ..
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

   This will prepare and build your new C++ guessing game project.

7. **Running your project:** Run your project's executable from the `build`
   directory:

   ```bash
   ./app/guessing_game_app
   ```

   With these steps, you've created a new C++ project for the guessing game
   within the cloned template. Now, you can focus on writing the code for your
   game in the `guessing_game_app.cpp` file.

## Processing a Guess

The first part of the guessing game program will ask for user input, process
that input, and check that the input is in the expected form. To start, we'll
allow the player to input a guess. Enter the following code into
`guessing_game_app.cpp`:

```cpp
#include <iostream>

int main() {
    std::cout << "Guess the number!" << std::endl;

    std::cout << "Please input your guess." << std::endl;

    auto guess_str = std::string();

    // Read line of input, until user presses `Enter`
    if (!std::getline(std::cin, guess_str)) {
      std::cerr << "Failed to read line" << std::endl;
      return 1;
    }

    auto guess = int32_t{0};
    // convert the string input to an int
    auto [ptr, err_code] = std::from_chars(
        guess_str.data(), guess_str.data() + guess_str.size(), guess);

    if (err_code == std::errc()) {
      std::cout << std::format("You guessed: {}\n", guess);
    } else {
      std::cout << "Error. Invalid input. Please enter a valid number."
                << std::endl;
    }

    return 0
}
```

This code contains a lot of information, so let's go over it line by line. To
obtain user input and then print the result as output, we need to `include` the
`iostream` library. The `iostream` library comes from the standard library known
as `std`:

```cpp
#include <iostream>
```

The `std` library is a rich collection of functions and classes that provide
essential functionality for C++ programs. It's a crucial part of the C++
programming language, and it covers a wide range of areas, including input and
output operations, data structures, algorithms, and more.

As you learned in the `Hello, Wrold!` chapter, we use `std::cout` to print
messages to the console. In this case, we display `"Guess the number!"` and
`"Please input your guess."`

### Storing Values with Variables

Next we'll create a _variable_ to store the user input, like this:

```cpp
auto guess_str = std::string();
```

We use the `auto` keyword (similarly to the `let` keyword in other languages),
to create the variable named `guess_str`. The `=` sign tells C++ we want to bind
something to the variable now. On the right side of the `=` sign is the value
that `guess_str` is bound to, which is the result of calling `std::string()`, a
function that returns a new instance of the `string` class. (The result of this
call is an empty string `""`). The `string` class is provided by the standard
library that is a growable UTF-8 encoded bit of text.

The `::` syntax in the `std::string` indicates that the `string` is part of the
`std` namespace. We will talk about namespaces at a later chapter.

### Receiving User Input

Recall that we included the input/output functionality from the standard library
with `#include <iostream>` on the first line of the program. Now we'll call the
`std::getline` function to read a line of input from the user. This function
takes two arguments: the first is `std::cin`, which represents the standard
input stream, and the second is `guess_str`, which is a reference to the
`std::string` variable where the input will be stored. (We'll talk about
references at a later chapter.)

! If `std::gerline` fails to read a line(for example, if there's an error with
input), we rint an error message to `std::err` (the standard error stream) and
return an error code (`1` in this case) to indicate that something went wrong.

### Converting User Input

After obtaining the user's input as a string, we need to convert it to a numeric
type (in this case, `int32_t`) to work with it:

```cpp
auto guess = uint32_t{0};
// convert the string input to an int
auto [ptr, err_code] = std::from_chars(
    guess_str.data(), guess_str.data() + guess_str.size(), guess);
```

We declare an `auto` variable guess of type `int32_t` to store the user's guess
as an integer.

We use the `std::from_chars` function to convert the stringinput in `guess_str`
into an integer value stored in `guess`. This function also returns a
pointer(`ptr`) and an error code (`err_code`).

#### Handling potential failure

We handle the potential failure by checking the `err_code` against
`std::errc()`, indicating that the conversion was successful and the input is a
valid number. If it's valid, we print the user's guess. If the conversion
fails(for example, if the user enters non-numeric input), we print an error
message and exit the program:

```cpp
if (err_code == std::errc()) {
     std::cout << std::format("You guessed: {}\n", guess);
   } else {
     std::cout << "Error. Invalid input. Please enter a valid number."
               << std::endl;
     return 1;
   }
```

In this code we also introduce `std::format` from the `<format>` standard
library. Make sure to include it at the top of the file:

```cpp
#include <format>
```

`std::format` is a modern C++ feature introduced in C++20, and its used here to
format the output in a more convenient and type-safe way. It allows us to
replace placeholders `{}` with the values we want to insert into the string. In
this case, we're inserting the user's guess into the string.

### Testing the First Part

Let's test the first part of the guessing game.

Compile the code: In your terminal make sure you navigate to the project
directory (where your `guessing_game_app.cpp` is located) if you're not already
there:

```bash
cd path/to/your/project/directory
```

Next, compile your code using CMake and the following commands:

```bash
cd build
cmake ..
cmake --build .
```

This prepares and builds your C++ guessing game project.

Now Run the Program: After successful compilation, you can run your program from
the `build` directory:

```bash
./app/guessing_game_app
```

You should see the following output:

```bash
Guess the number!
Please input your guess.
```

- Input a guess: Enter a number as your guess and press Enter. For example:

```bash
42
```

Your input will be processed, and you will see the message confirming your
guess:

```bash
You guessed: 42
```

At this point, the first part of the game is complete. You can successfully
obtain user input from the keyboard and display it in the console.

## Generating a Random Secret Number

Next, we need to generate a secret number that the user will try to guess. The
secret number should be different every time so the game is fun to play more
than once. We'll use a random number between 1 and 100 so the game isn't too
difficult. We will include the `random` standard library:

```cpp
#include <random>
```

```cpp
auto rd = std::random_device();
auto gen = std::mt19937(rd());
auto distribution = std::uniform_int_distribution<int32_t>(1, 100);
auto secret_number = uint32_t{distribution(gen)};
```

### Overview

```cpp
auto rd = std::random_device();
```

This line creates a `std::random_device` object named `rd`. It's used to obtain
random numbers suitable for seeding other random number generators.

```cpp
auto gen = std::mt19937(rd());
```

Here, we initialize a Mersenne Twister random number generator (`std::mt19937`)
named `gen`. It's seeded with the value obtained from the `rd()` function call,
ensuring randomness.

```cpp
auto distribution = std::uniform_int_distribution<int32_t>(1, 100);
```

This line defines a uniform integer distribution
(`std::uniform_int_distribution`) named `distribution`. It's used to generate
random integers between 1 and 100 (inclusive). Each integer in this range has an
equal chance of being generated.

```cpp
auto secret_number = int32_t{distribution(gen)};
```

Finally, we use the `distribution` to generate a random number within the
desired range (1 to 100) and assign it to the `secret_number` variable. This
ensures that `secret_number` contains a random value for further use.

As a helper during developing the program, we also add a line that prints the
random number to the console, to be able to test it. We will delete it from the
final version:

```cpp
...

auto secret_number = int32_t{distribution(gen)};

std::cout << std::format("The secret number is: {}\n", secret_number);

...
```

## Comparing the Guess to the Secret Number

Now that we have user input and a random number, we can compare them. That step
is shown below:

```cpp
// Check if the guess is within the valid range
    if (guess < 1 || guess > 100) {
      std::cout << "Error: Please enter a number between 1 and 100."
                << std::endl;
      return 1;
    }

    // Compare the guess with the secret number
    if (guess < secret_number) {
      std::cout << "Too small!" << std::endl;
    } else if (guess > secret_number) {
      std::cout << "Too big!" << std::endl;
    } else {
      std::cout << "You win!!" << std::endl;
    }
```

First, we check if the user's guess is within the valid range (between 1 and
100). If it's not within this range, we display an error message and return a
non-zero value(1) to indicate an error condition.

Next, we compare the user's guess with the secret number to determine if the
guess is too small, too big, or equal to the secret number. If the guess is too
small, we print `"Too small!"`, if it is too big, we print `"Too big!"`. If the
guess is equal to the secret number, we print `"You win!"` to indicate a
successful guess.

This code snippet handles the basic logic of comparing the user's input to the
secret umber and providing feedback on the comparison.

## Allowing Multiple Guesses with Looping

The `while` keyword is used to create a loop with the following syntax:

```cpp
while(boolean expression) {
   // do something
}
```

The code within the `{}` of the `while` will keep executing as along as the
boolean expression is `true`. In our case, we want our game to continuously ask
the user for input until he wins. It is also a smoother experience, if we allow
the user to provide a new input if she/he makes a mistake, instead of exiting
the program:

```cpp
while (true) {
    std::cout << "Please input your guess." << std::endl;

    auto guess_str = std::string();
    // Read line of input, until user presses `Enter`
    if (!std::getline(std::cin, guess_str)) {
      std::cerr << "Failed to read line" << std::endl;
      return 1;
    }

    auto guess = int32_t{0};
    // convert the string input to an int
    auto [ptr, err_code] = std::from_chars(
        guess_str.data(), guess_str.data() + guess_str.size(), guess);

    if (err_code == std::errc()) {
      std::cout << std::format("You guessed: {}\n", guess);
    } else {
      std::cout << "Error. Invalid input. Please enter a valid number."
                << std::endl;
      continue;
    }

    // Check if the guess is within the valid range
    if (guess < 1 || guess > 100) {
      std::cout << "Error: Please enter a number between 1 and 100."
                << std::endl;
      continue;
    }

    // Compare the guess with the secret number
    if (guess < secret_number) {
      std::cout << "Too small!" << std::endl;
    } else if (guess > secret_number) {
      std::cout << "Too big!" << std::endl;
    } else {
      std::cout << "You win!!" << std::endl;
      break;
    }
  }
```

As you can see, we've moved everything from the guess input prompt onward into a
`while(true)` loop. The `true` argument in the `while` has effectively created
an infinite loop. The program could now potentially ask for another guess
forever. In this case, the user could always interrupt the program by using the
keyboard shortcut `cntrl-c`. But there is another way:

#### Quitting After a Correct Guess

The game can actually quit when the user wins via the `break` statement:

```cpp
...
   } else {
      std::cout << "You win!!" << std::endl;
      break;
    }
```

Adding a break line after `You win!!` makes the program exit the loop when the
user guesses the secret number correctly. Exiting the loop also means exiting
the program, because after the loop the only code left is `return 0`.

#### Handling Invalid Input

Similarly, rather than exiting the program when the user inputs a non-number, we
can make the game ignore the current loop iteration, so the user can continue
guessing. We can do that via the `continue` keyword, which tells the program to
go to the next iteration of the `while` loop and ask another guess:

```cpp
...

if (err_code == std::errc()) {
      std::cout << std::format("You guessed: {}\n", guess);
    } else {
      std::cout << "Error. Invalid input. Please enter a valid number."
                << std::endl;
      continue;
    }
...
```

```cpp
...

   if (guess < 1 || guess > 100) {
      std::cout << "Error: Please enter a number between 1 and 100."
                << std::endl;
      continue;
    }

...
```

## Summary

This project served as a hands-on introduction to various fundamental concepts
in C++ programming. You've explored aspects such as user input handling, random
number generation, conditional statements, loops, and basic error checking.
These are foundational skills that will form the basis for more complex C++
programming tasks.

In the upcoming chapters, you’ll learn about these concepts in more detail.
