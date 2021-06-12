#include "application.h"

TApplication::TApplication(int argc, char** argv) : QApplication(argc,argv)
{
    interfaceWindow = new TInterface;
    interfaceWindow->show();

    client = new TTcpClient(QHostAddress::LocalHost, 10000);

    connect(client, SIGNAL(recieve(QByteArray)), this, SLOT(fromModel(QByteArray)));
    connect(interfaceWindow, SIGNAL(request(QJsonObject)), this, SLOT(toModel(QJsonObject)));
}

TApplication::~TApplication()
{
    delete interfaceWindow;
}

void TApplication::toModel(QJsonObject msg)
{
    QJsonDocument json_doc_answer;
    json_doc_answer.setObject(msg);
    QByteArray dataArray = json_doc_answer.toJson();

    client->send(dataArray);
}

void TApplication::fromModel(QByteArray msg)
{
    QJsonDocument jsonDoc_res = QJsonDocument::fromJson(msg);
    QJsonObject response = jsonDoc_res.object();

    interfaceWindow->update_windows(response);
}



