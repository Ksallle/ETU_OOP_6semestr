#pragma once

#ifndef TSTATESWINDOW_H
#define TSTATESWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QListWidget>
#include <QCloseEvent>
#include <QJsonObject>

class TStatesWindow : public QWidget
{
    Q_OBJECT

    QLabel *label_num_gas_station, *label_num_max_cars_in_queue,
           *label_num_cars_is_refueling;


    QLCDNumber *num_gas_stations, *num_max_cars_in_queue,
               *num_cars_is_refueling;


    QListWidget *table;

    unsigned int row = -1;

    int cars_is_refueling = 0;


public:
    TStatesWindow(QWidget *parent = 0);
    ~TStatesWindow();

    void update_states(QJsonObject response);
    void addText(QString);

protected:
    void closeEvent(QCloseEvent*);

signals:
    void closing();

};

#endif // TSTATESWINDOW_H
