#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>
#include <vector>

using namespace std;

enum EPrintMode {
    EPrintModeClassical,
    EPrintModeCanonical
};

class Polinom
{
    number a, b, c;
    EPrintMode printMode;
public:
    Polinom(number a, number b, number c);
    friend ostream& operator << (ostream&, Polinom&);
    number value(number x);
    void setPrintMode(EPrintMode m);
    vector<number> getRoots();
};

#endif // TPOLINOM_H
