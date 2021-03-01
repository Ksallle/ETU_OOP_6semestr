#ifndef TPOLINOM_H
#define TPOLINOM_H
#pragma once

#include "number.h"
#include <iostream>
#include <utility>

enum class EPrintMode{
    EPrintModeClassic,
    EPrintModeCanonic,
};


class TPolinom
{
private:
    const number a, b, c;
    EPrintMode printMode;
public:
    TPolinom(number x, number y, number z);
    friend std::ostream& operator<<(std::ostream& os,const TPolinom& p);
    number value(const number& x) const;
    void setPrintMode(const EPrintMode& m);
    std::pair<number,number> getRoots() const;
};

#endif // TPOLINOM_H
