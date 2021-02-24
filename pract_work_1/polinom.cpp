#include "polinom.h"

Polinom::Polinom(number a, number b, number c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

ostream& operator << (ostream& os, Polinom& p) {
    // classical form of representation of a polynomial
    if (p.printMode == EPrintModeClassical)
        os << p.a << "x^2" << showpos << p.b << "x" << p.c << noshowpos;

    // canonical form of representation of a polynomial
    else {

    }

    return os;
}

number Polinom::value(number x) {
    return a*x*x + b*x + c;
}

void Polinom::setPrintMode(EPrintMode m) {
    printMode = m;
}

vector<number> Polinom::getRoots() {
    vector<number> roots(2);
    return roots;
}
