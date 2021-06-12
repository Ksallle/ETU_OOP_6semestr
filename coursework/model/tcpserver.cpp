#include "tcpserver.h"


TTcpServer::TTcpServer(QHostAddress host,quint16 port) : QTcpServer()
{
    qDebug() << "Start server";
    listen(QHostAddress::Any,port);
    qDebug() << "Server listening" << host << "port" << port;
    connect((QTcpServer*)this, SIGNAL(newConnection()), this, SLOT(connection()));
}


TTcpServer::~TTcpServer()
{
    disconnect((QTcpServer*)this, SIGNAL(newConnection()), this, SLOT(connection()));
    foreach (QTcpSocket* socket, clients)
    {
        disconnect((QAbstractSocket*)socket, SIGNAL(disconnected()), this, SLOT(disconnection()));

        disconnect((QAbstractSocket*)socket, SIGNAL(readyRead()), this, SLOT(reading()));
    }
}


void TTcpServer::connection()
{
    QTcpSocket* socket;
    while (hasPendingConnections())
    {
        socket = nextPendingConnection();
        clients.append(socket);

        connect((QAbstractSocket*)socket, SIGNAL(disconnected()), this, SLOT(disconnection()));

        connect((QAbstractSocket*)socket, SIGNAL(readyRead()), this ,SLOT(reading()));

        qDebug()<<"connection"<<clients.size();

        emit clientno(clients.size());
    }
}


void TTcpServer::disconnection()
{
    QTcpSocket* socket = (QTcpSocket*)sender();

    int index = clients.indexOf(socket);

    if (index >= 0)
        clients.removeAt(index);

    if ((index == 0) && (clients.size() > 0))
        emit clientno(1);

    qDebug()<<"disconnection client"<<index<<clients.size();
}


void TTcpServer::reading()
{
    QTcpSocket* socket = (QTcpSocket*)sender();

    int index = clients.indexOf(socket);

    if (index >= 0)
    {
        QByteArray msg;

        msg = (clients.at(index))->readAll();

        qDebug()<<"reading";


        emit recieve(index,msg);
    }
}


void TTcpServer::send(int index, QByteArray msg)
{
    if (index >= 0)
    {
        qDebug()<<"send";
        clients.at(index)->write(msg);
    }
}


void TTcpServer::sendAll(QByteArray msg)
{
    for (int index=0;index<clients.count();index++)
    {
        qDebug()<<"send all";
        clients.at(index)->write(msg);
    }
}
