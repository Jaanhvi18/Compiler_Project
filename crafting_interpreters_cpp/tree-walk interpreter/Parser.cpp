#include "Parser.h"


ExprPtr Parser::expression() {
    return equality();
}

ExprPtr Parser::equality() {
    ExprPtr expr = comparison();
    while (match({BANG_EQUAL, EQUAL_EQUAL})) {
        TokenPtr oprtr = previous();
        ExprPtr right = comparison();
        expr = (new Binary(expr,oprtr,right));
    }
}