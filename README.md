# The C++ Book

Welcome to the public repository for  "The C++ Book" project. This repository contains the chapters in markdown format, the source code examples, and additional resources aimed at providing
a companion guide for the book. "The C++ Book" draws heavy inspiration from "The Rust Book", in fact it tries to act as a direct port when possible.

## Table of Contents

1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Project Structure](#project-structure)
4. [Example Code](#example-code)
5. [Chapter Exercises](#chapter-exercises)
6. [Contributing](#contributing)

## Introduction

This project aims to provide a companion guide for those who have experience with "The Rust Book" and are interested in learning C++. We are on a journey to port the principles and concepts of Rust to the world of C++ programming, highlighting similarities and differences.

If you haven't already, you can find "The Rust Book" [here](https://doc.rust-lang.org/book/).

## Getting Started

To start exploring the C++ companion to "The Rust Book," follow these steps:

1. Clone or fork this repository to your local machine.

2. Navigate to the chapter or exercise you're interested in. You'll find code examples, exercises, and additional resources.

3. Follow the instructions provided in the book to practice and experiment with C++ code.

4. Engage with the community: Feel free to ask questions, share insights, or contribute your own examples and exercises.

## Project Structure

The project is structured as follows:

- [app](app)
  - Contains C++ application files, including part-specific examples.
- [build](build)
  - The build directory for compilation and tests.
- [cmake](cmmake)
  - CMake configuration files and Catch2 testing framework setup.
- [include](include)
  - Header files for the 'adder' library.
- [src](src)
  - The 'adder' library source code.
- [tests](tests)
  - Test files and Catch2 unit tests for the 'adder' library.
- [ext](ext)
  - External libraries, including Catch2 testing framework.
- [the_book](the_book)
  - Markdown files mirroring the structure of "The Rust Book" with notes and guides for each chapter.

## Example Code

Throughout the project, you'll find code examples that bridge the concepts from "The Rust Book" to C++. These examples are organized in the `app` directory, with each part-specific example in its own subdirectory.

## Chapter Exercises

Each chapter of the companion guide includes exercises designed to reinforce your understanding of C++ concepts and best practices. You can find exercise solutions and contribute your own solutions in the `app` directory.

## Contributing

We welcome contributions from the C++ community and those interested in porting concepts from Rust to C++. If you have improvements to suggest, C++ examples, exercises, or insights to share, please follow these guidelines:

1. Fork this repository.

2. Create a new branch for your contributions: `git checkout -b feature/your-feature-name`.

3. Commit your changes: `git commit -am 'feat:Add a new example for Part X'`.

4. Push to your branch: `git push origin feature/your-feature-name`.

5. Create a Pull Request, detailing your changes and the rationale behind them.

6. Engage in discussions and iterate on your contributions with feedback from the community.

We look forward to your contributions, and together we aim to make C++ programming more accessible for those transitioning from Rust to C++. Happy coding!

