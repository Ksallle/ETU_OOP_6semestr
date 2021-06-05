#include "application.h"

TApplication::TApplication(int argc, char** argv) : QApplication(argc,argv)
{
    interfaceWindow = new TInterface;
    interfaceWindow->show();
}

TApplication::~TApplication()
{
    delete interfaceWindow;
}

