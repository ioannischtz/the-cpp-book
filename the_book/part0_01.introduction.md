# Introduction

Welcome to "The C++ Programming Language," a journey through the intricate world
of C++. C++, like Rust, empowers programmers to craft software with precision,
combining high-level ergonomics and low-level control. This book is your gateway
to harnessing the power of C++, exploring the language as defined by the modern
C++20 standard.

## Who C++ Is For

C++ is a versatile language, catering to a diverse audience of programmers, each
with their unique motivations:

### 1. Teams of Developers:

C++ stands as the bedrock of choice for countless companies, both large and
agile, across diverse sectors. It has earned its reputation as the go-to
language for mission-critical tasks, where robustness, performance, and
scalability are paramount. From crafting efficient command line tools and
powering web services to handling the intricate demands of DevOps tooling and
controlling embedded devices, C++ has consistently delivered unparalleled
reliability. It is the silent engine behind audio and video processing, the
backbone of Fintech, the driving force in bioinformatics, and the trusted
technology in search engines. With its versatility, C++ has forged its path into
IoT applications, machine learning, and even the core components of web browsers
like Chrome. For enterprises that demand the best in speed and stability, C++ is
the language of choice, ensuring that the software driving their operations
remains dependable and efficient.

### 2. Students:

C++ serves as an educational gateway to systems concepts. It welcomes those
curious about topics like operating systems development. This book, among
others, strives to make systems concepts more accessible, even to programming
newcomers.

### 3. Open Source Community:

C++ warmly welcomes open source enthusiasts who are passionate about
contributing to developer tools and libraries. Your expertise and dedication are
invaluable to C++'s evolution and expansion. Whether you're building powerful
libraries, crafting efficient frameworks, or optimizing critical components, C++
provides a robust platform for your open source endeavors. Join the vibrant
community of C++ developers and help drive the language forward, ensuring that
it remains a top choice for both open source projects and commercial software
alike.

### 4. Performance Enthusiasts and Stability Advocates:

C++ stands as the language of choice for individuals who demand top-tier
performance and unwavering stability in their code. If you're someone who values
both speed and reliability, C++ offers a powerful solution. C++ excels not only
in executing code swiftly but also in enabling you to write programs
efficiently. Its robust compiler checks ensure code stability through feature
enhancements and refactoring. Unlike languages without such checks, where legacy
code can be fragile and daunting to modify, C++ strives for zero-cost
abstractions. In essence, it empowers you to write safe code that remains
lightning-fast, making it the preferred language for those who prioritize both
performance and dependability.

## Who This Book Is For

This book assumes you possess experience in another programming language but
refrains from making assumptions about which one. Our goal is to make the
material accessible to a wide range of programming backgrounds. We don't delve
deeply into the fundamentals of programming or the philosophy of code. If you're
entirely new to programming, consider starting with an introductory programming
book tailored to beginners.

## How to Use This Book

In general, we recommend reading this book sequentially, from start to finish.
Later chapters build upon concepts introduced in earlier ones. While some
chapters provide high-level concepts, others delve into specifics. You'll find
two types of chapters here: concept chapters and project chapters.

Concept chapters focus on introducing fundamental aspects of C++. In project
chapters, we roll up our sleeves and build small programs, applying the
knowledge you've gained. For those eager to dive right into coding, Chapter 2 is
a hands-on introduction to writing a program in C++, where you'll create a
number guessing game.

Chapter 3 explores C++ features with parallels in other programming languages,
while Chapter 4 delves into C++'s memory management, essential for mastering the
intricacies of the language. You'll also explore features such as classes,
interfaces achieved through virtual member functions, lifetimes, and many other
fundamental concepts that will enrich your understanding of the language.

As you continue through the book, you'll gain a comprehensive understanding of
these C++ features, along with many other critical aspects of the language.

### Interpreting Compiler Error Messages and Understanding Code Examples

An essential aspect of mastering C++ is becoming proficient at interpreting and
addressing compiler error messages. These messages serve as valuable guides on
your journey to writing functional code. Throughout this book, you'll encounter
numerous code examples. It's worth noting that not all examples will compile
successfully. We intentionally include examples that may generate compiler
errors to illustrate specific concepts or challenges.

When experimenting with code examples, remember that encountering compilation
errors is a part of the learning process. Be sure to read the surrounding text
to understand whether an example is intentionally designed to illustrate a
particular point. To help you interpret the status of code examples, we use a
symbol system similar to the one below:

| Symbol | Meaning                                                                      |
| ------ | ---------------------------------------------------------------------------- |
| ❓     | This code may produce compilation errors.                                    |
| ⁉️      | This code may result in unexpected behavior.                                 |
| ‼️      | This code might trigger runtime exceptions.                                  |
| ✅     | This code should compile successfully and demonstrates a functional concept. |

In most situations, we provide guidance on resolving any compilation errors and
lead you to the correct version of code when needed.
