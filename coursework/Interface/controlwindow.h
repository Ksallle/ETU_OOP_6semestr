#pragma once

#ifndef TCONTROLWINDOW_H
#define TCONTROLWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QCloseEvent>
#include <QSpinBox>
#include <QLineEdit>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QString>

class TControlWindow : public QWidget
{
    Q_OBJECT

    QPushButton  *first_fuel_button, *second_fuel_button, *third_fuel_button,
                 *add_car_to_queue_button;

    QLabel *label, *label_numCars, *label_countFuel, *msg;

    QLCDNumber *num_fuel;

    QLineEdit *numCar;

    QSpinBox *countFuel;


public:
    TControlWindow(QWidget *parent = 0);
    ~TControlWindow();



protected:
    void closeEvent(QCloseEvent*);

private slots:
    void on_FirstFuelButton_clicked();
    void on_SecondFuelButton_clicked();
    void on_ThirdFuelButton_clicked();

public slots:
    void send_request();
    void check_for_correct();




signals:
    void closing();
    void send_controlWindow_request(QJsonObject request);

};

#endif // TCONTROLWINDOW_H
