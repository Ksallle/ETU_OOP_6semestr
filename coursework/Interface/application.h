#pragma once

#ifndef TAPPLICATION_H
#define TAPPLICATION_H

#include <QApplication>
#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include "interface.h"
#include "tcpclient.h"

class TApplication : public QApplication
{
    Q_OBJECT

    TInterface* interfaceWindow;

    TTcpClient *client;

public:
    TApplication(int,char**);
    ~TApplication();

public slots:
    void fromModel(QByteArray);
    void toModel(QJsonObject);

};

#endif // TAPPLICATION_H
