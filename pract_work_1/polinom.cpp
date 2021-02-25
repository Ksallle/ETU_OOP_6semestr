#include "polinom.h"
#include <math.h>

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
        vector<number> roots = p.getRoots();
        if (roots.size() == 2) {
            if (p.a != 1)
                os << p.a;
            os << showpos << "(x" << -roots[0] << ")(x" << -roots[1] << ")" << noshowpos;
        }
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
    number d = b*b - 4*a*c;

    if (d == 0) {
        roots[0] = roots[1] = (-b - sqrt(d))/(2*a);
    }
    else if (d > 0) {
        roots[0] = (-b - sqrt(d))/(2*a);
        roots[1] = (-b + sqrt(d))/(2*a);
    }

    // If roots are not integer or discriminant is negarive
    if (value(roots[0]) != 0 || value(roots[1]) != 0 || d < 0) {
        roots.clear();
        cout << "This polynomial has no solution on the set of integers";
    }

    return roots;
}
