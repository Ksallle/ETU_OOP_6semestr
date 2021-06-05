#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>

#include "controlwindow.h"
#include "stateswindow.h"
#include "parameterswindow.h"
#include "common.h"


class TInterface : public QWidget
{
    Q_OBJECT

    QPushButton *parameters_button, *states_button, *control_button;

    TControlWindow* controlWindow;
    TStatesWindow* statesWindow;
    TParametersWindow* parametersWindow;

public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();

//    void setCurrentParameters(const TParametersData);

protected:
    void closeEvent(QCloseEvent*);

public slots:
    void parametersWindowOpen();
    void statesWindowOpen();
    void controlWindowOpen();

    void parametersWindowClosed();
    void statesWindowClosed();
    void controlWindowClosed();

//    void restoreParameters();

signals:
//    void parametersRequest(EEvents,void*);
//    void sendParameters(TParametersData);

};

#endif // TINTERFACE_H
