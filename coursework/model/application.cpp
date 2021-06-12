#include "application.h"

TApplication::TApplication(int argc, char** argv) : QCoreApplication(argc, argv)
{
    QString port(argv[1]);

    server = new TTcpServer(QHostAddress::LocalHost, 10000);


    connect(server, SIGNAL(recieve(int,QByteArray)), this, SLOT(clientRequest(int,QByteArray)));


}


TApplication::~TApplication()
{
    delete server;
}

void TApplication::makeResponse(int client_index, QJsonObject response)
{
    QJsonDocument jsonDoc_res;
    jsonDoc_res.setObject(response);
    QByteArray dataArray = jsonDoc_res.toJson();

    qDebug() << "MAKE RESPONSE";

    server->send(client_index, dataArray);
}

void TApplication::clientRequest(int client_index, QByteArray msg)
{

    qDebug() << "make response";
    QJsonDocument jsonDoc_req = QJsonDocument::fromJson(msg);

    QJsonObject request = jsonDoc_req.object();

    if (request["type_window"] == "controlWindow") {
        QJsonObject response;
        response["client_index"] = client_index;
        response["type_window"] = "statesWindow";
        response["action"] = "add_car";
        response["num_car"] = request["num_car"];
        response["count_fuel"] = request["count_fuel"];
        response["type_fuel"] = request["type_fuel"];

        azs->process_response(response);
    }

    if (request["type_window"] == "parametersWindow") {
        int count_cars = request["count_cars"].toInt();
        int count_stations = request["count_stations"].toInt();

        azs = new AZS(count_stations, count_cars);

        connect(azs, SIGNAL(send_model_response(int,QJsonObject)), this, SLOT(makeResponse(int,QJsonObject)));

        QJsonObject response;

        response["client_index"] = client_index;
        response["type_window"] = "statesWindow";
        response["action"] = "set_parameters";
        response["count_stations"] = count_stations;
        response["count_cars"] = count_cars;


        azs->process_response(response);
    }

}


