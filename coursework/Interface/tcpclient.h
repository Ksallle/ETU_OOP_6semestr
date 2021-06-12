#pragma once

#ifndef TTCPCLIENT_H
#define TTCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>


class TTcpClient : public QTcpSocket
{
    Q_OBJECT
    bool connected;
public:
    TTcpClient(QHostAddress, quint16);

private slots:
    void connection();
    void disconnection();
    void reading();

public slots:
    void send(QByteArray);

signals:
    void recieve(QByteArray);
};

#endif // TTCPCLIENT_H
