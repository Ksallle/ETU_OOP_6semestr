#include "application.h"
#include "number.h"
#include "polinom.h"
#include <iostream>


TApplication::TApplication()
{

}

int TApplication::exec(){
    number a = 1, b = 2, c = 1;
    while(true){
        int ch;
        ch = menu();
        switch (ch){
        case 1:
            do{
                std::cout << "a = ";
                std::cin >> a;
                if(a == 0){
                    std::cout << "coefficient \"a\" must not be 0" << std::endl;
                }
            }while(a == 0);
            std::cout << "b = ";
            std::cin >> b;
            std::cout << "c = ";
            std::cin >> c;
            break;
        case 2:
        {
            number x;
            std::cout << "x = ";
            std::cin >> x;
            TPolinom p(a,b,c);
            number v = p.value(x);
            std::cout << "p(" << x << ") = " << v << std::endl;
            break;
        }
        case 3:
        {
            TPolinom p(a,b,c);
            try{
                auto roots = p.getRoots();
                if(roots.first == roots.second){
                    std::cout << "x=" << roots.first << std::endl;
                }else{
                    std::cout <<"x1=" << roots.first << std::endl;
                    std::cout << "x2=" << roots.second << std::endl;
                }
            }catch(std::exception& e){
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 4:
        {
            TPolinom p(a, b, c);
            p.setPrintMode(EPrintMode::EPrintModeClassic);
            std::cout << p << std::endl;
            break;
        }
        case 5:
        {
            TPolinom p(a, b, c);
             p.setPrintMode(EPrintMode::EPrintModeCanonic);
             try{
                 p.getRoots();
                 std::cout << p << std::endl;
             }catch(std::exception& e){
                 std::cout << "Can't print cannonical form" << std::endl << e.what() << std::endl;
             }
            break;
        }
        case 0:
            return 0;
        default:
            std::cout << "unknown command" << std::endl;
            break;
        }
    }

}

int TApplication::menu()
{
    int ch;
    std::cout << "1 - coefficients" << std::endl;
    std::cout << "2 - value" << std::endl;
    std::cout << "3 - roots" << std::endl;
    std::cout << "4 - print(classic)" << std::endl;
    std::cout << "5 - print (canonical)" << std::endl;
    std::cout << "0 - exit" << std::endl;
    std::cin >> ch;
    return ch;
}


