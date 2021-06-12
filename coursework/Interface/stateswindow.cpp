#include "stateswindow.h"

TStatesWindow::TStatesWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Окно состояния");

    resize(621, 382);
    setMinimumSize(QSize(621, 382));
    setMaximumSize(QSize(621, 382));

    label_num_gas_station = new QLabel(this);
    label_num_gas_station->setGeometry(QRect(150, 20, 151, 16));
    label_num_gas_station->setText("Количество колонок:");

    label_num_max_cars_in_queue = new QLabel(this);
    label_num_max_cars_in_queue->setGeometry(QRect(15, 60, 301, 16));
    label_num_max_cars_in_queue->setText("Максимальное количество машин в очереди:");

    label_num_cars_is_refueling = new QLabel(this);
    label_num_cars_is_refueling->setGeometry(QRect(315, 40, 331, 16));
    label_num_cars_is_refueling->setText("Автомобилей в данный момент заправляются:");


    num_gas_stations = new QLCDNumber(this);
    num_gas_stations->setGeometry(QRect(270, 10, 31, 41));
    num_gas_stations->setDigitCount(2);
    num_gas_stations->setSegmentStyle(QLCDNumber::Flat);

    num_max_cars_in_queue = new QLCDNumber(this);
    num_max_cars_in_queue->setGeometry(QRect(270, 50, 31, 41));
    num_max_cars_in_queue->setDigitCount(2);
    num_max_cars_in_queue->setSegmentStyle(QLCDNumber::Flat);

    num_cars_is_refueling = new QLCDNumber(this);
    num_cars_is_refueling->setGeometry(QRect(575, 30, 31, 41));
    num_cars_is_refueling->setDigitCount(2);
    num_cars_is_refueling->setSegmentStyle(QLCDNumber::Flat);




    table = new QListWidget(this);
    table->setGeometry(QRect(10, 110, 601, 261));




}

TStatesWindow::~TStatesWindow()
{
    delete label_num_gas_station; delete label_num_max_cars_in_queue;
    delete label_num_cars_is_refueling;


    delete num_gas_stations; delete num_max_cars_in_queue;
    delete num_cars_is_refueling;


    delete table;

}

void TStatesWindow::update_states(QJsonObject response)
{
    if (response["action"].toString() == "add_car") {

        QString num_car = response["num_car"].toString();
        int count_fuel = response["count_fuel"].toInt();
        int type_fuel = response["type_fuel"].toInt();
        int num_station = response["num_station"].toInt();
        QString side = response["side"].toString();

        QString string = "На заправку приехала машина с номером " + num_car + ", с потребностью в " + QString::number(count_fuel) + " литр. " +
                QString::number(type_fuel) + "-го типа топлива.";
        QString string2 = "Подъехала на " + QString::number(num_station) + " колонку с ";

        if (side == "left") {
            string2 += "левой стороны.";
        }
        else {
            string2 += "правой стороны.";
        }

        cars_is_refueling++;

        num_cars_is_refueling->display(cars_is_refueling);

        addText(string);
        addText(string2);
    }

    else if (response["action"].toString() == "set_parameters") {
        int count_cars = response["count_cars"].toInt();
        int count_stations = response["count_stations"].toInt();

        num_gas_stations->display(count_stations);
        num_max_cars_in_queue->display(count_cars);

        QString string = "АЗС создана с " + QString::number(count_stations) + " колонками " +
                " и максимальным количеством машин в очереди равном " + QString::number(count_cars);

        addText(string);
    }

    else if (response["action"].toString() == "finish_refueling") {
        QString num_car = response["num_car"].toString();
        int count_fuel = response["count_fuel"].toInt();
        int type_fuel = response["type_fuel"].toInt();
        int num_station = response["num_station"].toInt();
        QString side = response["side"].toString();

        QString string = "С заправки уехала машина с номером " + num_car;
        QString string2 = "Уехала с " + QString::number(num_station) + " колонки с ";

        if (side == "left") {
            string2 += "левой стороны.";
        }
        else {
            string2 += "правой стороны.";
        }

        cars_is_refueling--;
        num_cars_is_refueling->display(cars_is_refueling);


        addText(string);
        addText(string2);
    }

    else if (response["action"].toString() == "add_car_to_queue") {
        QString num_car = response["num_car"].toString();
        int count_fuel = response["count_fuel"].toInt();
        int type_fuel = response["type_fuel"].toInt();
        int num_station = response["num_station"].toInt();
        QString side = response["side"].toString();

        QString string = "На заправку приехала машина с номером " + num_car + ", с потребностью в " + QString::number(count_fuel) + " литр. " +
                QString::number(type_fuel) + "-го типа топлива.";

        QString string2 = "Встала в очередь на " + QString::number(num_station) + " колонку с ";

        if (side == "left") {
            string2 += "левой стороны.";
        }
        else {
            string2 += "правой стороны.";
        }

    }

}

void TStatesWindow::addText(QString string)
{
    row++;
    table->insertItem(row, string);
}

void TStatesWindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}


