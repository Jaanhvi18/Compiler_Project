#pragma once

enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, MODULO, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Increment and decrement tokens
    INCREMENT,DECREMENT,

    // Literals.
    IDENTIFIER, STRING, NUMBER,
    //accounting for decimals and try to continue reading after . intead of returning an integer
    FLOAT,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // Additional keywords
    // ASM, AUTO, BREAK, CASE, CATCH, CHAR, CONST, CONTINUE, DEFAULT, DELETE,
    // DO, DOUBLE, DYNAMIC_CAST, ENUM, EXPLICIT, EXPORT, EXTERN, FLOAT, FRIEND,
    // GOTO, INLINE, INT, LONG, MUTABLE, NAMESPACE, NEW, OPERATOR, PRIVATE, PROTECTED,
    // PUBLIC, REGISTER, REINTERPRET_CAST, SHORT, SIGNED, SIZEOF, STATIC, STATIC_CAST,
    // STRUCT, SWITCH, TEMPLATE, THIS, THROW, TRY, TYPEDEF, TYPEID, TYPENAME, UNION,
    // UNSIGNED, USING, VIRTUAL, VOID, VOLATILE, WCHAR_T,

    EOF_TOKEN
};
