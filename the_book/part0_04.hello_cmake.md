# Hello, CMake!

In this chapter, we'll introduce you to CMake, a powerful and versatile build
system, and guide you through setting up your C++ development environment using
our custom CMake-based project template. CMake simplifies the build process for
C++ projects and allows for cross-platform compatibility.

## Brief Overview of CMake

CMake is an open-source, cross-platform build system that helps you manage the
build process for C++ projects. It provides a unified and efficient way to
configure, build, and test your applications on various platforms and compiler
toolchains. With CMake, you can easily generate platform-specific build files
(e.g., Makefiles, Visual Studio projects) from a single CMake configuration,
making it an essential tool for C++ developers. In this chapter, we'll explore
how CMake streamlines the development workflow for C++ projects. Let's get
started!

### 1. Clone the project template

Clone the Project Template: If you haven't already, navigate to the directory
where you want to create your C++ projects. Open a terminal or command prompt
and run the following command to clone the project template repository:

```bash
$ git clone https://github.com/ioannischtz/cpp-project-template.git
```

### 2. Navigate to the cloned repository:

```bash
$ cd cpp-project-template
```

### 3. Build the Project Using CMake:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

This will compile the project and create the necessary executables.

### 4. Run the Example Program:

```bash
./app/adder_app
```

## Understandeing the Project Structure

The project template follows a structured directory layout:

```
cpp-project-template/
│
├── app/
│   ├── adder_app.cpp
│   ├── CMakeLists.txt
│   └── hello_world_app.cpp
│
├── build/
│   └── ... (build files)
│
├── cmake/
│   ├── Catch.cmake
│   └── CatchAddTests.cmake
│
├── ext/
│   └── catch2/
│       └── catch.hpp
│
├── include/
│   └── adder/
│       └── adder.hpp
│
├── src/
│   ├── adder.cpp
│   └── CMakeLists.txt
│
├── tests/
│   ├── adder_t.cpp
│   ├── CMakeLists.txt
│   └── tests.cpp
│
├── CMakeLists.txt
│
├── LICENSE
│
└── README.md
```

- `app/`: Contains C++ application source files.
- `build/`: Contains build-related files and executables.
- `cmake/`: Contains CMake scripts for configuring the project.
- `ext/`: Contains external dependencies, such as Catch2.
- `include/`: Contains header files for your C++ project.
- `src/`: Contains source files for libraries or modules.
- `tests/`: Contains unit test files.
- `CMakeLists.txt`: The main CMake configuration file for the entire project.

**Running Tests with Catch2**

The project template includes Catch2, a testing framework for C++. A basic
example can be found in the tests/ directory. We will add more tests as we
progress through the book.

**Next steps**

With the C++ project template set up, we can use it as a starting point for our
C++ projects while working through the book. You are encouraged to customize and
expand upon it as you progress.

In the upcoming chapters, you'll dive deeper into C++ concepts, data structures,
and more. Happy coding.
