#include "application.h"
#include "polinom.h"
#include "number.h"
#include <iostream>

using namespace std;

Application::Application()
{

}

int Application::exec() {
    int ch;
    number a = 1, b = 2 ,c = 1;

    while (true) {
        ch = menu();
        switch (ch) {
        case 1:
            cout << "a = ";
            cin >> a;
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
                for (int i = 0; i < roots.size(); i++) {
                    cout << roots[i] << endl;
                }
            }
            break;
        case 4:
            {
                Polinom p(a, b, c);
                p.setPrintMode(EPrintModeClassical);
                cout << p << endl;
            }
            break;
        case 5:
            {
                Polinom p(a, b, c);
                p.setPrintMode(EPrintModeCanonical);
                cout << p << endl;
            }
            break;
        case 0:
            return 0;
            break;
        default:
            break;
        }
    }
}

int Application::menu() {
    int ch;
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
