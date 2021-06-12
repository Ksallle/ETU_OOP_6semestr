#pragma once

#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>

#include "controlwindow.h"
#include "stateswindow.h"
#include "parameterswindow.h"
#include "../common/common.h"


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
    void update_windows(QJsonObject response);


protected:
    void closeEvent(QCloseEvent*);

private slots:
    void parametersWindowOpen();
    void statesWindowOpen();
    void controlWindowOpen();



public slots:
    void parametersWindowClosed();
    void statesWindowClosed();
    void controlWindowClosed();
    void formRequest(QJsonObject);



signals:
    void request(QJsonObject);

};

#endif // TINTERFACE_H
