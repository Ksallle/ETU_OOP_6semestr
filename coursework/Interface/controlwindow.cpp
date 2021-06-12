#include "controlwindow.h"

TControlWindow::TControlWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Окно управления");

    resize(320, 187);
    setMinimumSize(QSize(320, 187));
    setMaximumSize(QSize(320, 187));

    msg = new QLabel(this);
    msg->setGeometry(QRect(10, 170, 301, 20));
    msg->setAlignment(Qt::AlignCenter);
    msg->setText("");

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
    add_car_to_queue_button->setGeometry(QRect(120, 150, 80, 21));
    add_car_to_queue_button->setText("Добавить");

    label_numCars = new QLabel(this);
    label_numCars->setGeometry(QRect(20, 40, 91, 16));
    label_numCars->setText("Номер машины");

    numCar = new QLineEdit(this);
    numCar->setGeometry(QRect(20, 60, 81, 20));

    label_countFuel = new QLabel(this);
    label_countFuel->setGeometry(QRect(20, 90, 121, 16));
    label_countFuel->setText("Количество топлива");

    countFuel = new QSpinBox(this);
    countFuel->setGeometry(QRect(20, 110, 42, 22));
    countFuel->setMinimum(1);

    connect(first_fuel_button, SIGNAL(clicked()), this, SLOT(on_FirstFuelButton_clicked()));
    connect(second_fuel_button, SIGNAL(clicked()), this, SLOT(on_SecondFuelButton_clicked()));
    connect(third_fuel_button, SIGNAL(clicked()), this, SLOT(on_ThirdFuelButton_clicked()));
    connect(add_car_to_queue_button, SIGNAL(clicked()), this, SLOT(check_for_correct()));
}

TControlWindow::~TControlWindow()
{
    delete first_fuel_button; delete second_fuel_button; delete third_fuel_button;
    delete add_car_to_queue_button;

    delete label; delete label_numCars; delete label_countFuel;

    delete num_fuel;

    delete numCar;

    delete countFuel;

}

void TControlWindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}

void TControlWindow::on_FirstFuelButton_clicked()
{
    num_fuel->display(1);
}

void TControlWindow::on_SecondFuelButton_clicked()
{
    num_fuel->display(2);

}

void TControlWindow::on_ThirdFuelButton_clicked()
{
    num_fuel->display(3);

}

void TControlWindow::send_request()
{
    QJsonObject request;
    request.insert("type_window", "controlWindow");
    request.insert("action", "add_car");
    request.insert("num_car", numCar->text());
    request.insert("count_fuel", countFuel->value());
    request.insert("type_fuel", num_fuel->value());





    emit send_controlWindow_request(request);
}

void TControlWindow::check_for_correct()
{
    qDebug() << "Try to send request";
    if (numCar->text().isEmpty() == false && num_fuel->value() != 0 && countFuel->value() != 0) {
        send_request();
        qDebug() << "Send request";
        numCar->setText("");
        countFuel->setValue(0);
        num_fuel->display(0);
    }
    else {
        msg->setText("Дозаполните форму");
    }
}
