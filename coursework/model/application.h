#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

#include "tcpserver.h"
#include "model.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT
    TTcpServer* server;

    AZS* azs;


public:
    TApplication(int, char**);
    ~TApplication();


public slots:
    void makeResponse(int, QJsonObject);
    void clientRequest(int,QByteArray);

signals:
    void request_to_model(QJsonObject);
};

#endif // APPLICATION_H
