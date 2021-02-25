#include "application.h"
#include "polinom.h"
#include "number.h"
#include <iostream>
#include <conio.h>

using namespace std;

number a = 1, b = 2 ,c = 1;

Application::Application()
{

}

int Application::exec() {
    int ch;

    while (true) {
        ch = menu();
        switch (ch) {
        case 1:
            cout << "a = ";
            cin >> a;
            while (a == 0) {
                cout << "You write a = 0! It's impossible. Please, write a different value" << endl;
                cout << "a = ";
                cin >> a;
            }
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            break;
        case 2:
            {
                number x;
                cout << "x = ";
                cin >> x;
                Polinom p(a, b, c);
                number v = p.value(x);
                cout << "p(" << x << ") = " << v << endl;
            }
            break;
        case 3:
            {
                Polinom p(a, b, c);
                vector<number> roots;
                roots = p.getRoots();
                if (roots.size() == 0)
                    break;
                else if (roots[0] == roots[1]) {
                    cout << "x1 = x2 = " << roots[0] << endl;
                }
                else {
                    for (int i = 0; i < 2; i ++)
                        cout << "x" << i << " = " << roots[i] << endl;
                }
            }
            break;
        case 4:
            {
                Polinom p(a, b, c);
                p.setPrintMode(EPrintModeClassical);
                cout << p;
            }
            break;
        case 5:
            {
                Polinom p(a, b, c);
                p.setPrintMode(EPrintModeCanonical);
                cout << p;
            }
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
        getch();
    }
}

int Application::menu() {
    int ch;
    system("cls");
    cout << "Current polynomial: ";
    cout << a << "x^2" << showpos << b << "x" << c << noshowpos << endl << endl;
    cout << "1 - coefficients" << endl;
    cout << "2 - value" << endl;
    cout << "3 - roots" << endl;
    cout << "4 - print(classic)" << endl;
    cout << "5 - print(canonic)" << endl;
    cout << "0 - exit" << endl;
    cout << "> ";
    cin >> ch;
    return ch;
}
