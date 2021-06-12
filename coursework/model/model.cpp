#include "model.h"


Station::Station(unsigned int number)
{
    this->number = number;

    buzy_left_side = false;
    buzy_right_side = false;

    if (this->number % 3 == 1)
    {
        fuel_left_side = 1;
        fuel_right_side = 2;
    }
    else if (this->number % 3 == 2)
    {
        fuel_left_side = 2;
        fuel_right_side = 3;
    }
    else if (this->number % 3 == 0)
    {
        fuel_left_side = 3;
        fuel_right_side = 1;
    }
}

Station::~Station()
{

}

void Station::car_fill(QJsonObject request)
{
    unsigned int type_fuel = request["type_fuel"].toInt();
    unsigned int count_fuel = request["count_fuel"].toInt();

    if (request["num_station"].toInt() == number) {
        if (fuel_left_side == type_fuel && buzy_left_side == false) {
            buzy_left_side = true;

            int time = count_fuel * 1000;

            request_refill_left.push_back(request);

            refueling_left_side->singleShot(time, this, SLOT(refueling_left_side_finish()));



        }
        else if (fuel_right_side == type_fuel && buzy_right_side == false) {
            buzy_right_side = true;

            int time = count_fuel * 1000;

            request_refill_right.push_back(request);

            refueling_left_side->singleShot(time, this, SLOT(refueling_right_side_finish()));

        }

        else if (fuel_left_side == type_fuel && buzy_left_side == true) {

            int time = 0;
            for (int i = 0; i < queue_left_side.size()-1; i++) {


                time += queue_left_side[i]["count_fuel"].toInt() * 1000;
            }

            request_refill_left.push_back(request);
            refueling_left_side->singleShot(time, this, SLOT(refueling_left_side_finish()));

            emit add_to_queue(request);
        }

        else if (fuel_right_side == type_fuel && buzy_right_side == true) {

            int time = 0;
            for (int i = 0; i < queue_right_side.size()-1; i++) {


                time += queue_right_side[i]["count_fuel"].toInt() * 1000;

            }

            request_refill_right.push_back(request);
            refueling_right_side->singleShot(time, this, SLOT(refueling_right_side_finish()));

            emit add_to_queue(request);
        }
    }
}

void Station::refueling_left_side_finish()
{
    buzy_left_side = false;
    QJsonObject response;



    response["num_car"] = request_refill_left[0]["num_car"];

    response["client_index"] = request_refill_left[0]["client_index"];
    response["action"] = "finish_refueling";
    response["num_station"] = request_refill_left[0]["num_station"];

    response["side"] = request_refill_left[0]["side"];

    request_refill_left.pop_front();

    emit finish_refueling(response);

}

void Station::refueling_right_side_finish()
{
    buzy_right_side = false;
    QJsonObject response;

    response["num_car"] = request_refill_right[0]["num_car"];

    response["client_index"] = request_refill_right[0]["client_index"];
    response["action"] = "finish_refueling";
    response["num_station"] = request_refill_right[0]["num_station"];

    response["side"] = request_refill_right[0]["side"];

    request_refill_right.pop_front();
    emit finish_refueling(response);
}

void Station::set_timer()
{
    refueling_left_side = new QTimer;
    refueling_right_side = new QTimer;

    QThread* thread_1 = new QThread;
    QThread* thread_2 = new QThread;

    refueling_left_side->moveToThread(thread_1);
    refueling_right_side->moveToThread(thread_2);

    thread_1->start();
    thread_2->start();
}



AZS::AZS(unsigned int count_stations, unsigned int count_cars)
{
    this->count_stations = count_stations;
    this->count_cars = count_cars;
    stations.resize(count_stations);
    for (int i = 0; i < stations.size(); i++) {

        stations[i] = new Station(i+1);

        QThread* thread = new QThread;

        stations[i]->moveToThread(thread);

        connect(thread, SIGNAL(started()), stations[i], SLOT(set_timer()));

        thread->start();

        connect(stations[i],SIGNAL(finish_refueling(QJsonObject)),this,SLOT(process_response(QJsonObject)));

        connect(this, SIGNAL(car_fill(QJsonObject)), stations[i], SLOT(car_fill(QJsonObject)));

        connect(stations[i], SIGNAL(add_to_queue(QJsonObject)), this, SLOT(process_response(QJsonObject)));



    }


}


AZS::~AZS()
{
    for (int i = 0; i < stations.size(); i++) {
        delete stations[i];
    }

}

void AZS::process_response(QJsonObject response)
{

    qDebug() << "PROCESS RESPONSE";
    if (response["action"].toString() == "add_car") {

        QJsonObject res = car_arrived(response);

        emit send_model_response(response["client_index"].toInt(), res);
    }

    else if (response["action"].toString() == "set_parameters") {

        QJsonObject res = set_parameters(response);

        emit send_model_response(response["client_index"].toInt(), res);
    }
    else if (response["action"].toString() == "finish_refueling") {

        QJsonObject res = finish_refueling(response);

        emit send_model_response(response["client_index"].toInt(), res);
    }

}

QJsonObject AZS::car_arrived(QJsonObject request)
{
    QString num_car = request["num_car"].toString();
    int type_fuel = request["type_fuel"].toInt();
    int count_fuel = request["count_fuel"].toInt();

    QJsonObject response;

    qDebug() << "Car arrived with need to fill " << type_fuel << " type fuel " << count_fuel << " fuel";

    for (int i = 0; i < stations.size(); i++) {   // когда машина приехала, проходим по всем колонкам

        if (stations[i]->fuel_left_side == type_fuel || stations[i]->fuel_right_side == type_fuel) {  // если у колонки есть походящий бензин слева или справа

            if (stations[i]->fuel_left_side == type_fuel) { // если подходящий бензин слева

                if (stations[i]->buzy_left_side == false) { // если слева колонка не занята
                    qDebug() << "Car arrived to " << i+1 << " station from left side";

                    response["client_index"] = request["client_index"].toInt();
                    response["type_window"] = "statesWindow";
                    response["action"] = "add_car";
                    response["num_car"] = num_car;
                    response["count_fuel"] = count_fuel;
                    response["type_fuel"] = type_fuel;
                    response["num_station"] = i+1;
                    response["side"] = "left";
                    response["queue"] = false;
                    stations[i]->queue_left_side.push_back(response);

                    emit car_fill(response);

                    break;
                }
                else if (stations[i]->buzy_left_side == true) { // если слева колонка занята
                    response["client_index"] = request["client_index"].toInt();
                    response["type_window"] = "statesWindow";
                    response["action"] = "add_car_to_queue";
                    response["num_car"] = num_car;
                    response["count_fuel"] = count_fuel;
                    response["type_fuel"] = type_fuel;
                    response["num_station"] = i+1;
                    response["side"] = "left";
                    response["queue"] = true;
                    stations[i]->queue_left_side.push_back(response);

                    emit car_fill(response);
                }
            }
            else if (stations[i]->fuel_right_side == type_fuel) { // если подходящий бензин справа

                if (stations[i]->buzy_right_side == false) { // если справа колонка не занята
                    qDebug() << "Car arrived to " << i+1 << " station from right side";

                    response["client_index"] = request["client_index"].toInt();
                    response["type_window"] = "statesWindow";
                    response["action"] = "add_car";
                    response["num_car"] = num_car;
                    response["count_fuel"] = count_fuel;
                    response["type_fuel"] = type_fuel;
                    response["num_station"] = i+1;
                    response["side"] = "right";
                    response["queue"] = false;
                    stations[i]->queue_right_side.push_back(response);

                    emit car_fill(response);

                    break;

                }
                else if (stations[i]->buzy_right_side == true) { // если справа колонка занята
                    response["client_index"] = request["client_index"].toInt();
                    response["type_window"] = "statesWindow";
                    response["action"] = "add_car_to_queue";
                    response["num_car"] = num_car;
                    response["count_fuel"] = count_fuel;
                    response["type_fuel"] = type_fuel;
                    response["num_station"] = i+1;
                    response["side"] = "right";
                    response["queue"] = true;
                    stations[i]->queue_right_side.push_back(response);

                    emit car_fill(response);
                }
            }
        }
    }

    return response;
}

QJsonObject AZS::set_parameters(QJsonObject request)
{
    int count_stations = request["count_stations"].toInt();
    int count_cars = request["count_cars"].toInt();

    qDebug() << "Set parameters: " << count_stations << " stations; " << count_cars << " cars";

    QJsonObject response;
    response["client_index"] = request["client_index"].toInt();
    response["type_window"] = "statesWindow";
    response["action"] = "set_parameters";
    response["count_stations"] = count_stations;
    response["count_cars"] = count_cars;


    return response;
}

QJsonObject AZS::finish_refueling(QJsonObject request)
{
    int number = request["number"].toInt();
    QString side = request["side"].toString();

    qDebug() << "AZS::finish_refueling.  Station " << number+1 << " refill auto from " << side << " side";
    QJsonObject response;
    response["client_index"] = request["client_index"].toInt();
    response["type_window"] = "statesWindow";
    response["action"] = "finish_refueling";
    response["num_station"] = request["num_station"];
    response["num_car"] = request["num_car"];
    response["side"] = request["side"];

//    if (side == "left") {
//        stations[response["num_station"].toInt()]->queue_left_side.pop_front();
//    }

//    else if (side == "right") {
//        stations[response["num_station"].toInt()]->queue_right_side.pop_front();
//    }


    return response;
}

