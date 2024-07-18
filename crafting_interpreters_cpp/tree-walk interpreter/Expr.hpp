#pragma once

#include <memory>
#include <vector>
#include "Token.h"

class Assign;
class Binary;
class Call;
class Get;
class Grouping;
class Literal;
class Logical;
class Set;
class Super;
class This;
class Unary;
class Variable;

class Expr {
public:
    virtual ~Expr() = default;

    class Visitor {
    public:
        virtual void visitAssignExpr(const Assign &expr) = 0;
        virtual void visitBinaryExpr(const Binary &expr) = 0;
        virtual void visitCallExpr(const Call &expr) = 0;
        virtual void visitGetExpr(const Get &expr) = 0;
        virtual void visitGroupingExpr(const Grouping &expr) = 0;
        virtual void visitLiteralExpr(const Literal &expr) = 0;
        virtual void visitLogicalExpr(const Logical &expr) = 0;
        virtual void visitSetExpr(const Set &expr) = 0;
        virtual void visitSuperExpr(const Super &expr) = 0;
        virtual void visitThisExpr(const This &expr) = 0;
        virtual void visitUnaryExpr(const Unary &expr) = 0;
        virtual void visitVariableExpr(const Variable &expr) = 0;
    };

    virtual void accept(Visitor &visitor) const = 0;
};

using ExprPtr = std::shared_ptr<Expr>;


class Assign : public Expr {
public:
    Assign(std::shared_ptr<Token> name, ExprPtr value) : name(name), value(value) {}

    void accept(Visitor &visitor) const override {
        visitor.visitAssignExpr(*this);
    }

    const std::shared_ptr<Token> name;
    const ExprPtr value;
};


class Binary : public Expr {
public:
    Binary(ExprPtr left, std::shared_ptr<Token> op, ExprPtr right) : left(left), op(op), right(right) {}

    void accept(Visitor &visitor) const override {
        visitor.visitBinaryExpr(*this);
    }

    const ExprPtr left;
    const std::shared_ptr<Token> op;
    const ExprPtr right;
};


class Call : public Expr {
public:
    Call(ExprPtr callee, std::shared_ptr<Token> paren, std::vector<ExprPtr> arguments)
        : callee(callee), paren(paren), arguments(arguments) {}

    void accept(Visitor &visitor) const override {
        visitor.visitCallExpr(*this);
    }

    const ExprPtr callee;
    const std::shared_ptr<Token> paren;
    const std::vector<ExprPtr> arguments;
};


class Get : public Expr {
public:
    Get(ExprPtr object, std::shared_ptr<Token> name) : object(object), name(name) {}

    void accept(Visitor &visitor) const override {
        visitor.visitGetExpr(*this);
    }

    const ExprPtr object;
    const std::shared_ptr<Token> name;
};


class Grouping : public Expr {
public:
    Grouping(ExprPtr expression) : expression(expression) {}

    void accept(Visitor &visitor) const override {
        visitor.visitGroupingExpr(*this);
    }

    const ExprPtr expression;
};


class Literal : public Expr {
public:
    Literal(std::shared_ptr<void> value) : value(value) {}

    void accept(Visitor &visitor) const override {
        visitor.visitLiteralExpr(*this);
    }

    const std::shared_ptr<void> value;
};


class Logical : public Expr {
public:
    Logical(ExprPtr left, std::shared_ptr<Token> op, ExprPtr right) : left(left), op(op), right(right) {}

    void accept(Visitor &visitor) const override {
        visitor.visitLogicalExpr(*this);
    }

    const ExprPtr left;
    const std::shared_ptr<Token> op;
    const ExprPtr right;
};


class Set : public Expr {
public:
    Set(ExprPtr object, std::shared_ptr<Token> name, ExprPtr value) : object(object), name(name), value(value) {}

    void accept(Visitor &visitor) const override {
        visitor.visitSetExpr(*this);
    }

    const ExprPtr object;
    const std::shared_ptr<Token> name;
    const ExprPtr value;
};


class Super : public Expr {
public:
    Super(std::shared_ptr<Token> keyword, std::shared_ptr<Token> method) : keyword(keyword), method(method) {}

    void accept(Visitor &visitor) const override {
        visitor.visitSuperExpr(*this);
    }

    const std::shared_ptr<Token> keyword;
    const std::shared_ptr<Token> method;
};


class This : public Expr {
public:
    This(std::shared_ptr<Token> keyword) : keyword(keyword) {}

    void accept(Visitor &visitor) const override {
        visitor.visitThisExpr(*this);
    }

    const std::shared_ptr<Token> keyword;
};


class Unary : public Expr {
public:
    Unary(std::shared_ptr<Token> op, ExprPtr right) : op(op), right(right) {}

    void accept(Visitor &visitor) const override {
        visitor.visitUnaryExpr(*this);
    }

    const std::shared_ptr<Token> op;
    const ExprPtr right;
};


class Variable : public Expr {
public:
    Variable(std::shared_ptr<Token> name) : name(name) {}

    void accept(Visitor &visitor) const override {
        visitor.visitVariableExpr(*this);
    }

    const std::shared_ptr<Token> name;
};



// ******************EXPRESSIONS****************