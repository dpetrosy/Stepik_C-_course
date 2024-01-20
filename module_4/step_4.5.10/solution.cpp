#include <iostream>

struct PrintVisitor : Visitor
{
    void visitNumber(Number const* number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const* bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << ")";
        std::cout << " " << bop->get_op() << " ";
        std::cout << "(";
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};
