#include "interface.h"

TInterface::TInterface(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Основное окно");

    resize(200, 250);
    setMinimumSize(QSize(200, 250));
    setMaximumSize(QSize(200, 250));

    parametersWindow = nullptr;
    statesWindow = nullptr;
    controlWindow = nullptr;

    parameters_button = new QPushButton(this);
    parameters_button->setGeometry(QRect(40, 40, 121, 31));
    parameters_button->setText("Параметры");

    states_button = new QPushButton(this);
    states_button->setGeometry(QRect(40, 110, 121, 31));
    states_button->setText("Состояние");

    control_button = new QPushButton(this);
    control_button->setGeometry(QRect(40, 180, 121, 31));
    control_button->setText("Управление");

    connect(parameters_button,SIGNAL(pressed()),this,SLOT(parametersWindowOpen()));
    connect(states_button,    SIGNAL(pressed()),this,SLOT(statesWindowOpen()));
    connect(control_button,   SIGNAL(pressed()),this,SLOT(controlWindowOpen()));


}

TInterface::~TInterface()
{
    delete parameters_button;
    delete states_button;
    delete control_button;
}

void TInterface::closeEvent(QCloseEvent* event)
{
    if (parametersWindow != nullptr) {
        disconnect(parametersWindow,SIGNAL(closing()),this,SLOT(parametersWindowClosed()));
        parametersWindow->close();
    }
    if (statesWindow != nullptr) {
        disconnect(statesWindow,SIGNAL(closing()),this,SLOT(statesWindowClosed()));
        statesWindow->close();
    }
    if (controlWindow != nullptr) {
        disconnect(controlWindow,SIGNAL(closing()),this,SLOT(controlWindowClosed()));
        controlWindow->close();
    }
    event->accept();
}


void TInterface::parametersWindowOpen()
{
    qDebug() << "Parameters Window open";
    if (parametersWindow == nullptr) {
        parametersWindow = new TParametersWindow;

        connect(parametersWindow, SIGNAL(closing()), this, SLOT(parametersWindowClosed()));

        connect(parametersWindow, SIGNAL(send_parametersWindow_request(QJsonObject)), this, SLOT(formRequest(QJsonObject)));


        parametersWindow->show();
    }

}

void TInterface::statesWindowOpen()
{
    qDebug() << "States Window open";
    if (statesWindow == nullptr) {
        statesWindow = new TStatesWindow;

        connect(statesWindow, SIGNAL(closing()),this,SLOT(statesWindowClosed()));

        statesWindow->show();
    }

}

void TInterface::controlWindowOpen()
{
    qDebug() << "Control Window open";
    if (controlWindow == nullptr) {
        controlWindow = new TControlWindow;

        connect(controlWindow, SIGNAL(closing()),this,SLOT(controlWindowClosed()));

        connect(controlWindow, SIGNAL(send_controlWindow_request(QJsonObject)), this, SLOT(formRequest(QJsonObject)));


        controlWindow->show();
    }

}

void TInterface::update_windows(QJsonObject response)
{
    if (response["type_window"].toString() == "statesWindow") {
        statesWindow->update_states(response);
    }
}

void TInterface::parametersWindowClosed()
{
    qDebug() << "Parameters Window closed";
    disconnect(parametersWindow,SIGNAL(closing()),this,SLOT(parametersWindowClosed()));
    parametersWindow = nullptr;
}

void TInterface::statesWindowClosed()
{
    qDebug() << "States Window closed";
    disconnect(statesWindow,SIGNAL(closing()),this,SLOT(statesWindowClosed()));
    statesWindow = nullptr;
}

void TInterface::controlWindowClosed()
{
    qDebug() << "Control Window closed";
    disconnect(controlWindow,SIGNAL(closing()),this,SLOT(controlWindowClosed()));
    controlWindow = nullptr;
}

void TInterface::formRequest(QJsonObject req)
{
    qDebug() << "TInterface::formRequest";
    emit request(req);
}

