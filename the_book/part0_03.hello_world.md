# Hello, World!

Now that you've set up your C++ development environment, it's time to write your
first C++ program. It's customary when learning a new language to create a
simple program that prints the text "Hello, World!" to the screen, so we'll do
the same here!

## Creating a Project Directory

Before we write our first C++ program, let's create a directory to organize your
C++ projects. You can choose any location you prefer, but for this example,
we'll create a "hello_world" project directory in your home directory.

Open your terminal or command prompt and enter the following commands:

**For Linux, macOS, and PowerShell on Windows:**

```bash
$ mkdir ~/projects
$ cd ~/projects
$ mkdir hello_world
$ cd hello_world
```

**For Windows CMD:**

```bash
> mkdir "%USERPROFILE%\projects"
> cd /d "%USERPROFILE%\projects"
> mkdir hello_world
> cd hello_world
```

## Writing and Running a C++ Program

Now, create a new source file and name it "main.cpp." C++ source files typically
have the ".cpp" extension. Open the "main.cpp" file and enter the following
code:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

This code defines the main function, which is a special function in every C++
program. It's where your program starts executing. In this case, it prints
"Hello, World!" to the console using the std::cout stream.

Save the "main.cpp" file and go back to your terminal in the
"~/projects/hello_world" directory. Now, you can compile and run your C++
program.

**On Linux or macOS, use these commands:**

```bash
$ g++ main.cpp -o hello_world
$ ./hello_world
```

**On Windows, use these commands:**

```
> g++ main.cpp -o hello_world.exe
> hello_world.exe
```

Regardless of your operating system, you should see "Hello, World!" printed to
the console. If you encounter any issues, refer to the troubleshooting section
in the previous chapter for assistance.

Congratulations! You've successfully written and run your first C++ program.
You're now on your way to becoming a C++ programmer.

## Anatomy of a C++ Program

Let's break down the "Hello, World!" program you just created:

```cpp
#include <iostream>
```

This line includes the input/output stream library, which provides functinality
for input and output operations. It allows us to use the `std::cout` stream for
printing.

```cpp
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

These lines define the `main` function, which is the entry point of every C++
program. The `int` before main indicates that the function returns an integer.
In this case, it returns `0` to indicate successful program execution.

Inside the `main` function, we use `std::cout` to output the `"Hello, World!"`
message, and `std::endl` to insert a newline character.

With this basic understanding, you're ready to explore more C++ concepts and
build more complex programs.
