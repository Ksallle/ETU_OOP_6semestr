#pragma once

#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include <QThread>
#include <deque>


class Station : public QObject
{
    Q_OBJECT

public:
    Station(unsigned int);
    ~Station();

    bool buzy_left_side;
    bool buzy_right_side;

    unsigned int fuel_left_side;
    unsigned int fuel_right_side;

    unsigned int number;


    std::deque<QJsonObject> queue_left_side;
    std::deque<QJsonObject> queue_right_side;

private:
    QTimer* refueling_left_side;
    QTimer* refueling_right_side;

    std::deque<QJsonObject> request_refill_left;
    std::deque<QJsonObject> request_refill_right;



    QThread* thread_refueling_left_side;
    QThread* thread_refueling_right_side;

public slots:
    void car_fill(QJsonObject);
    void refueling_left_side_finish();
    void refueling_right_side_finish();
    void set_timer();

signals:
    void finish_refueling(QJsonObject);
    void add_to_queue(QJsonObject);
};




class AZS : public QObject
{
    Q_OBJECT

public:
    AZS(unsigned int, unsigned int);
    ~AZS();




private:
    QVector<Station*> stations;

    unsigned int count_stations = 0;
    unsigned int count_cars = 0;



public slots:
    QJsonObject car_arrived(QJsonObject);
    QJsonObject set_parameters(QJsonObject);
    QJsonObject finish_refueling(QJsonObject);
    void process_response(QJsonObject);

signals:
    void send_model_response(int client_index, QJsonObject response);
    void car_fill(QJsonObject);

};




#endif // MODEL_H
