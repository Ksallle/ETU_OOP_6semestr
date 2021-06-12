#pragma once

#ifndef TTCPSERVER_H
#define TTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>


class TTcpServer : public QTcpServer
{
    Q_OBJECT
    QVector<QTcpSocket*> clients;

public:
    TTcpServer(QHostAddress, quint16);
    ~TTcpServer();

private slots:
    void connection();
    void disconnection();
    void reading();

public slots:
    void send(int,QByteArray);
    void sendAll(QByteArray);

signals:
    void clientno(int);
    void recieve(int,QByteArray);

};

#endif // TTCPSERVER_H
