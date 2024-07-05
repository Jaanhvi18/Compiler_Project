# Intro and Plan
This Sub-directory contains my (judah) attempt to follow along with the "Crafting Interpreters" book in C++. This document additionally any external notes and documentation on the project not conveyed through code/comments

The book is divided into a walkthrough of a java and a C based implementation. Author notes in 1.3 that most major compilers (GCC, LLVM, Javascript VMs) are written in C++, an OOP language, The java approach taken by the texbook is a tree-walk interpreter, while the C implementation is a byte code compiler.



# Chapter 2

## Parts of a Language 

Source Code (string) -> Tokens 
    - Lexing/scanning

Process through which the stream of characters within the soruce file is converted into only the meaningful tokens of the language

Tokens -> Syntax Tree
    - Parsing

Imposes the grammar of the language unto our string of tokens to generate a nested structure. This stage outputs syntax errors


Static Analysis on Syntax Tree

    1) Binding/resolution. Links each identifier to it's definition, requires acceptable use of scope

    2) Type Checking, statically typed languages are type checked here, this book however implements a dynamically typed language


After analysis is complete the information can be appended to the syntax tree as attributes on the nodes. Alternatively it can be stored in a symbol table, where identifiers are linked to their data


### Intermediate Representations

The "front end" of a compiler is language specific, it (usually) only can process one language. The "back end" is concerned with the final architecture the program runs on.

In the middle is the intermediate representation. By having our front end generate an established intermediate representation, we can feed it to an existing backend compiler for whatever architecture we want to target


### Optimization

Optimization is done within the intermediate representation because it contains all of the necessary behavior in an easy to manipulate form. Optimization is a very, very deep rabbithole that this book doesn't really get into. Additionally, compile time optimization is more difficult for dynamically typed languages


### Code Generation

Backend side of the compiler process. We don't want to bother generating code for each instruction et, so instead we work with virtual machine code, often known as bytecode.


### Virtual Machine

Once you have bytecode, you can either treat it as another layer of Intermediate representation and convert it to native code for your architectures of choice, or you can write a Virtual machine that emulates your virtual architecture during runtime. This is slower than native code, because every line of bytecode is simulated at runtime each time it executes


### Runtime

Once an executable is generated, we need to provide services that handle additional concerns at runtime, such as garbage collecting and instanceof checking. The runtime often lives in the VM for languages that run on virtual machines.

## Alternate Routes


Single Pass Compilers: Compilers that generate code without intermediate representations. This leads to heavily restricted language designs. C and Pascal were designed in the time of strict memory limitations, meaning the compiler did not have the privilege of generating IR's. Lead to features such as forward decleration of functions


Tree-walk Interpreters: Method that executes the code right after parsing it to an AST. Interpreter parses the syntax tree one branch/leaf at a time and evaluates a node as it goes. Commonly used for student projects and little languages, not general-purpose languages that need to be fast


Transpiler: Translate your high level language to a similarly high level language, and then use the existing compile tools for that language


Just-in-Time Compilation: High Performance, high skill. When the program is loaded into bytecode, once the machine architecture is known, compile it for target architecture. Advanced systems look for performance critical points within the code and selectively optimize those sections



## Compilers and Interpreters

Compiling: An implementation technique where a source language is translated into another (often lower-level) form. When we generate machine code or byte code we are classically compiling. Compiling to C or Javascript are examples of transpiling. Compilers do not execute the outputed code

Interpreters: Takes source code as input and immediately executes it


- GCC and clang are compilers and not interpreters, they just generate executables
- The original Ruby implementation was just interpreted from the syntax tree, so it wasn't compiled
- With CPython, Python code is parsed into bytecode, which is then executed within the VM. First it is compiled into bytecode, and then from a user perspective it is directly interpreted. Thus CPython is an interpreter with a compiler



#  Chapter 3 : The Lox Language

the language described in the textbook is in the C family. Key features include that it is dynamically typed and that it provides automatic memory management.

The main methods of memory management are reference counting and tracing garbage collection. Most modern systems use a combination of both, but lean heavily towards the garbage collection side.


## Data Types

- We implement booleans as their own data types, rather than repurposing an existing type

- The only number type we support are the classic double-precision floating points

-We implement Strings, unclear how they are represented, as there is no reference to char types

-A null value named nil. Many good arguments to not include it in statically typed langauges, but has advantages for dynamically typed

## Expressions

- We support all the basic arithmetic divisions +, -, *, /, %
- additional support for comparison and equality (no type conversion)
- logical operators !, and, or


## Statements

While expressions produce values, statements produce effects

We implement the print statement as a language feature rather than a function because it allows us to verify our program's behavior before implementing functions. print evaluates the following expression and displays the result to the screen.

Expressions that end with semicolons are considered statements


## Variables

Variables are declared dynamically with var, omitting the initializer defaults the value to nil.

## Control Flow

We implement only If/else, while, and classic for loops
 - It would be fun to include match and for-each loops

## Functions

 Function Structures are fairly classically designed. However we do treat them as first class and allow nested functions. This combination creates some complication when exiting and returning from scope, meaning we can't just rely on the stack


## Classes

 The language provides limited Object Oriented Support.

 Objects are either classes (C++, Java, C#) or prototypes (Javascript)

 In class based languages objects are instances of classes, where the class definition contains the methods and inheritance chain, while the instance contains the non-static data.

 Prototype-languages have only objects, with no classes. each object contains states and methods, while objects are allowed to inherit from each other (delegate) objects. Most prototypical language writing devolves into writing classes anyway


 Lox takes the class based approach, and additionally treats classes as first class. Static/non-static memory are differentiated with Class.data vs this.data. We've even got inheritance!


 ## The Standard Library

 Lox has no standard functionality beyond print and clock. Literally nothing. That gives us a lot of room to play.


 # Tree-Walk Interpreter





