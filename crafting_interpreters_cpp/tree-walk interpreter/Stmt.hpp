#pragma once

#include <memory>
#include <vector>
#include "Token.h"
#include "Expr.hpp"

class Block;
class ClassStmt; // Adding forward declaration for ClassStmt
class Expression;
class Function;
class If;
class Print;
class Return;
class Var;
class While;

class Stmt {
public:
    virtual ~Stmt() = default;

    class Visitor {
    public:
        virtual void visitBlockStmt(const Block &stmt) = 0;
        virtual void visitClassStmt(const ClassStmt &stmt) = 0;
        virtual void visitExpressionStmt(const Expression &stmt) = 0;
        virtual void visitFunctionStmt(const Function &stmt) = 0;
        virtual void visitIfStmt(const If &stmt) = 0;
        virtual void visitPrintStmt(const Print &stmt) = 0;
        virtual void visitReturnStmt(const Return &stmt) = 0;
        virtual void visitVarStmt(const Var &stmt) = 0;
        virtual void visitWhileStmt(const While &stmt) = 0;
    };

    virtual void accept(Visitor &visitor) const = 0;
};

using StmtPtr = std::shared_ptr<Stmt>;

class Block : public Stmt {
public:
    Block(const std::vector<StmtPtr> &statements) : statements(statements) {}

    void accept(Visitor &visitor) const override {
        visitor.visitBlockStmt(*this);
    }

    const std::vector<StmtPtr> statements;
};

class Expression : public Stmt {
public:
    Expression(ExprPtr expression) : expression(expression) {}

    void accept(Visitor &visitor) const override {
        visitor.visitExpressionStmt(*this);
    }

    const ExprPtr expression;
};

class Function : public Stmt {
public:
    Function(std::shared_ptr<Token> name, std::vector<std::shared_ptr<Token>> params, std::shared_ptr<Block> body)
        : name(name), params(params), body(body) {}

    void accept(Visitor &visitor) const override {
        visitor.visitFunctionStmt(*this);
    }

    const std::shared_ptr<Token> name;
    const std::vector<std::shared_ptr<Token>> params;
    const std::shared_ptr<Block> body;
};

class If : public Stmt {
public:
    If(ExprPtr condition, StmtPtr thenBranch, StmtPtr elseBranch = nullptr)
        : condition(condition), thenBranch(thenBranch), elseBranch(elseBranch) {}

    void accept(Visitor &visitor) const override {
        visitor.visitIfStmt(*this);
    }

    const ExprPtr condition;
    const StmtPtr thenBranch;
    const StmtPtr elseBranch; // Can be nullptr if there's no else branch
};

class Print : public Stmt {
public:
    Print(ExprPtr expression) : expression(expression) {}

    void accept(Visitor &visitor) const override {
        visitor.visitPrintStmt(*this);
    }

    const ExprPtr expression;
};

class Return : public Stmt {
public:
    Return(std::shared_ptr<Token> keyword, ExprPtr value)
        : keyword(keyword), value(value) {}

    void accept(Visitor &visitor) const override {
        visitor.visitReturnStmt(*this);
    }

    const std::shared_ptr<Token> keyword;
    const ExprPtr value;
};

class Var : public Stmt {
public:
    Var(std::shared_ptr<Token> name, ExprPtr initializer)
        : name(name), initializer(initializer) {}

    void accept(Visitor &visitor) const override {
        visitor.visitVarStmt(*this);
    }

    const std::shared_ptr<Token> name;
    const ExprPtr initializer;
};

class While : public Stmt {
public:
    While(ExprPtr condition, StmtPtr body)
        : condition(condition), body(body) {}

    void accept(Visitor &visitor) const override {
        visitor.visitWhileStmt(*this);
    }

    const ExprPtr condition;
    const StmtPtr body;
};

// ClassStmt here ----> fix this 
class ClassStmt : public Stmt {
public:
    ClassStmt(std::shared_ptr<Token> name, std::shared_ptr<Variable::Expr> superclass, std::vector<std::shared_ptr<Function>> methods)
        : name(name), superclass(superclass), methods(methods) {}

    void accept(Visitor &visitor) const override {
        visitor.visitClassStmt(*this);
    }

    const std::shared_ptr<Token> name;
    const std::shared_ptr<Variable::Expr> superclass;
    const std::vector<std::shared_ptr<Function>> methods;
};

