#ifndef TCONTROLWINDOW_H
#define TCONTROLWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLCDNumber>
#include <QListView>
#include <QCloseEvent>
#include <QSpinBox>
#include <QLineEdit>

class TControlWindow : public QWidget
{
    Q_OBJECT

    QPushButton  *first_fuel_button, *second_fuel_button, *third_fuel_button,
                 *add_car_to_queue_button;

    QLabel *label, *label_numCars, *label_countFuel;

    QLCDNumber *num_fuel;

    QListView *list_of_added_cars;

    QLineEdit *numCars;

    QSpinBox *countFuel;


public:
    TControlWindow(QWidget *parent = nullptr);
    ~TControlWindow();


protected:
    void closeEvent(QCloseEvent*);

signals:
    void closing();

};

#endif // TCONTROLWINDOW_H
