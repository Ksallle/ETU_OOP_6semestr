#include "controlwindow.h"

TControlWindow::TControlWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Окно управления");

    resize(563, 187);
    setMinimumSize(QSize(563, 187));
    setMaximumSize(QSize(563, 187));

    label = new QLabel(this);
    label->setGeometry(QRect(10, 10, 161, 16));
    label->setText("Добавление машины на АЗС:");

    first_fuel_button = new QPushButton(this);
    first_fuel_button->setGeometry(QRect(160, 50, 101, 21));
    first_fuel_button->setText("Первое топливо");

    second_fuel_button = new QPushButton(this);
    second_fuel_button->setGeometry(QRect(160, 80, 101, 21));
    second_fuel_button->setText("Второе топливо");

    third_fuel_button = new QPushButton(this);
    third_fuel_button->setGeometry(QRect(160, 110, 101, 21));
    third_fuel_button->setText("Третье топливо");

    num_fuel = new QLCDNumber(this);
    num_fuel->setGeometry(QRect(270, 50, 31, 81));
    num_fuel->setDigitCount(1);

    add_car_to_queue_button = new QPushButton(this);
    add_car_to_queue_button->setGeometry(QRect(110, 150, 80, 21));
    add_car_to_queue_button->setText("Добавить");

    list_of_added_cars = new QListView(this);
    list_of_added_cars->setGeometry(QRect(320, 20, 221, 141));

    label_numCars = new QLabel(this);
    label_numCars->setGeometry(QRect(20, 40, 91, 16));
    label_numCars->setText("Номер машины");

    numCars = new QLineEdit(this);
    numCars->setGeometry(QRect(20, 60, 81, 20));

    label_countFuel = new QLabel(this);
    label_countFuel->setGeometry(QRect(20, 90, 121, 16));
    label_countFuel->setText("Количество топлива");

    countFuel = new QSpinBox(this);
    countFuel->setGeometry(QRect(20, 110, 42, 22));
    countFuel->setMinimum(1);

}

TControlWindow::~TControlWindow()
{
    delete first_fuel_button; delete second_fuel_button; delete third_fuel_button;
    delete add_car_to_queue_button;

    delete label; delete label_numCars; delete label_countFuel;

    delete num_fuel;

    delete list_of_added_cars;

    delete numCars;

    delete countFuel;

}

void TControlWindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}
