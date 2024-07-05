# Compiler_Project

We will be proceeding with C++
using an automated test framework as we develop?

* Guides for Compiler/Interpreter Design
  - Crafting Interpreters: https://timothya.com/pdfs/crafting-interpreters.pdf
  - Crafting a Compiler in Rust: https://dev.to/simmypeet/crafting-a-compiler-in-rust-syntactic-analysis-5dia
  - Rust Compiler Tutorial Series: https://www.youtube.com/watch?v=GAU51Dqsp3Y&list=PLI1h1vRqlHLNZAa2BEM9uZ2GEvUNYDasO
  - Writing a Program Language in Rust: https://www.youtube.com/watch?v=WpOivQLjhJA&list=PLj_VrUwyDuXS4K3n7X4U4qmkjpuA8rJ76


* General Information and Theoretically Oriented Textbooks  
  - Computer Systems: A Programmers Perspective https://annas-archive.org/md5/ebb9004fe72f0da390bdef45026b2786
  - Introduction to Compilers and Language Design: https://www3.nd.edu/~dthain/compilerbook/compilerbook.pdf


* Decisions to make for language design
  - Static vs dynamic typing
  - Garbage collection vs no garbage collection
  - Language Inspiration (What languages do we want to use for inspiration?)



*First Steps:

1) background Info (Judah)
2) Rust Documentation (Judah and Jaanhvi)
3) Choosing a rust a compiler tutorial (Of the two tutorials) (Jaanhvi)
4) Following a rust compiler tutorial (Judah and Jaanhvi)

 
```mermaid
graph TD
    A[Source Code] --> B[Scanning]
    B --> C[Tokens]
    C --> D[Parsing]
    D --> E[Syntax Tree]
    E --> F[Analysis]
    F --> G[Intermediate Representation]
    G --> H[Optimizing]
    G --> I[Transpiling]
    H --> J[Code Generation]
    I --> J
    J --> K[Bytecode]
    J --> L[Machine Code]
    K --> M[Virtual Machine]
    L --> N[Executable]

    subgraph Compiler Stages
        B
        C
        D
        E
        F
        G
        H
        I
        J
    end
