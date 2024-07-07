# Checklist for Implementing a C++ Compiler

## 1. Lexical Analysis (Scanner)
- [ ] **Token Definitions:** : Each letter in a **String** is a token, while a string is a sequence of tokens 
  - [ ] Define tokens for basic math operators (`*`, `/`, `+`, `-`).
  - [ ] Define tokens for decimal whole numbers (`0` .. `9`).
  - [ ] Define token for end of input (EOF).

- [ ] **Token Scanner:**
  - [ ] Implement a function to read input and identify tokens.
  - [ ] Handle errors for unrecognized characters.

## 2. Grammar Definition
- [ ] **Backus-Naur Form (BNF):**
  - [ ] Define the grammar for expressions and numbers:
    - An expression can be:
    1. Just a number
    2. Two expressions separated by a '*' token
    3. Two expressions separated by a '/' token
    4. Two expressions separated by a '+' token
    5. Two expressions separated by a '-' token

The text emphasizes that the BNF definition of the grammar is recursive because an expression refers to other expressions. However, the recursion in defining an expression bottom-outs when it reaches a number, represented by the T_INTLIT token. This ensures that the recursion stops when a number is encountered.

In BNF terminology:
- "expression" and "number" are non-terminal symbols as they are defined by rules in the grammar.
- T_INTLIT and the four math operator tokens are terminal symbols as they are already recognized tokens in the language and are not further defined by rules.

This distinction between terminal and non-terminal symbols in BNF grammar is crucial for parsing and understanding the syntactic structure of a language.

## 3. Parser Implementation
- [ ] **Recursive Descent Parsing:**
  - [ ] Implement a function for parsing expressions (`binexpr`).
  - [ ] Implement a function for parsing primary factors (`primary`).
  - [ ] Implement token lookahead and handling.

- [ ] **Token to AST Node Mapping:**
  - [ ] Implement a function to map tokens to AST node operations (`arithop`).

## 4. Abstract Syntax Tree (AST)
- [ ] **AST Node Definition:**
  - [ ] Define the structure of AST nodes:
    ```c
    struct ASTnode {
      int op;                               // Operation
      struct ASTnode *left;                 // Left child
      struct ASTnode *right;                // Right child
      int intvalue;                         // Integer value for literals
    };
    ```

- [ ] **AST Node Creation:**
  - [ ] Implement functions to create different types of AST nodes:
    - [ ] Generic AST node 
    - [ ] Leaf AST node 
    - [ ] Unary AST node: Implement a **prefix !** to perform a **logical not**, and **-** to negate a number.
    - [ ] Decide on the order of traversal, i.e., **pre-order**, **in-order**, or **post-order** but I think we can go with the generic MATH traversal rules 

## 5. Semantic Analysis
- [ ] **Operator Precedence:**
  - [ ] Modify the parser to handle operator precedence correctly.

- [ ] **Expression Evaluation:**
  - [ ] Implement a function to interpret the AST and calculate expression values.

## 6. Error Handling
- [ ] **Syntax Errors:**
  - [ ] Implement error handling for unexpected tokens and syntax issues.
  - [ ] Maybe an abstract class/ interface that can be implemented/inherited by the classes that need error handling
  
- [ ] **Semantic Errors:**
  - [ ] Implement error handling for invalid operations (e.g., division by zero).

## 7. Driver Code
- [ ] **Main Function:**
  - [ ] Implement the main function to drive the compilation process:
    - [ ] Read input.
    - [ ] Call the parser.
    - [ ] Interpret the AST.
    - [ ] Print the result.
    - [ ] For the interactive CLI as well as a file as an input


## 8. Testing
- [ ] **Test Cases:**
  - [ ] Create test input files with various expressions.
  - [ ] Validate the output of the compiler against expected results.
  - [ ] Example test files and expected output:
    - `input01`: `2 + 3 * 5 - 8 / 3`
    - `input02`: `13 -6+ 4*5+08 / 3`
    - `input03`: `12 34 + -56 * / - - 8 + * 2`
    - `input04`: `23 + 18 - 45.6 * 2 / 18`
    - `input05`: `23 * 456abcdefg`

- [ ] **Automated Testing:**
    - [ ] Implement a testing framework to automate test execution.
    - [ ] Compare compiler output with expected results.
