#include "polinom.h"
#include <cmath>
#include <exception>



TPolinom::TPolinom(number x, number y, number z)
    : a(x),b(y),c(z)
{
    printMode = EPrintMode::EPrintModeClassic;
}

std::ostream& operator<<(std::ostream& os,const TPolinom& p){
    if(p.printMode == EPrintMode::EPrintModeClassic){
        os << p.a << "x^2";
        if(p.b < 0){
            os << p.b << "x";
        }else{
            os << "+" << p.b << "x";
        }
        if(p.c < 0){
            os << p.c;
        }else{
            os << "+" << p.c;
        }
    }else{
        if(p.printMode == EPrintMode::EPrintModeCanonic){
            auto roots = p.getRoots();

            if(p.a != 1){
                os << p.a;
            }
            if(roots.first == 0){
                os << "x";
            }else{
                if(roots.first > 0){
                    os << "(x-" << roots.first << ")";
                }else{
                    os << "(x+" << -roots.first << ")";
                }
            }

            if(roots.second == 0){
                os << "x";
            }else{
                if(roots.second > 0){
                    os << "(x-" << roots.second << ")";
                }else{
                    os << "(x+" << -roots.second << ")";
                }
            }
        }
    }
    return os;
}

number TPolinom::value(const number& x) const{
    return a * x * x + b * x + c;
}

void TPolinom::setPrintMode(const EPrintMode& m){
    printMode = m;
}



std::pair<number,number> TPolinom::getRoots() const{
    number D = b * b - 4 * a * c;
    std::pair<number,number> roots ((-b + sqrt(D)) / (2 * a),(-b - sqrt(D)) / (2 * a));
    if(value(roots.first) != 0 || value(roots.second) != 0){
        throw std::runtime_error("The way of getting roots doesnt work for this data type");
    }
    return roots;
}



