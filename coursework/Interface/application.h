#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QApplication>
#include "interface.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TInterface* interfaceWindow;

public:
    TApplication(int,char**);
    ~TApplication();

public slots:

};

#endif // TAPPLICATION_H
