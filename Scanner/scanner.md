# Detailed Lexical Analysis

## Notes
A scanner (or lexer) takes in the linear stream of characters and chunks them together into a series of something more akin to "words". In programming languages, each of these words is called a token. Some tokens are single characters, like `(` and `,`. Others may be several characters long, like numbers (123), string literals ("hi!"), and identifiers (min).

```mermaid
graph TD

    A[Source Code] --> B[Scanning]
    B --> C{Character}
    C --> |Whitespace| D[Ignore]
    C --> |Alphabetic| E[Start of Identifier or Keyword]
    C --> |Digit| F[Start of Number]
    C --> |Operator or Punctuation| G[Single Character Token]
    C --> |End of File| H[EOF Token]
    E --> I{Next Character}
    I --> |Alphabetic or Digit| E
    I --> |Non-Alphanumeric| J[End of Identifier or Keyword]
    J --> K[Check if Keyword]
    K --> |Yes| L[Keyword Token]
    K --> |No| M[Identifier Token]
    F --> N{Next Character}
    N --> |Digit| F
    N --> |Non-Digit| O[End of Number]
    O --> P[Number Token]
```
