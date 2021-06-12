#include "parameterswindow.h"

TParametersWindow::TParametersWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Окно параметров");

    resize(350, 173);
    setMinimumSize(QSize(350, 173));
    setMaximumSize(QSize(350, 173));

    layoutWidget = new QWidget(this);
    layoutWidget->setGeometry(QRect(10, 110, 321, 41));

    horizontalLayout = new QHBoxLayout(layoutWidget);
    horizontalLayout->setContentsMargins(0, 0, 0, 0);

    accept_button = new QPushButton(this);
    accept_button->setText("Применить");

    horizontalLayout->addWidget(accept_button);


    layoutWidget1 = new QWidget(this);
    layoutWidget1->setGeometry(QRect(10, 20, 321, 71));

    verticalLayout = new QVBoxLayout(layoutWidget1);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    horizontalLayout_3 = new QHBoxLayout();

    label = new QLabel(layoutWidget1);
    label->setText("Количество бензоколонок на АЗС:");

    horizontalLayout_3->addWidget(label);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer);

    count_stations = new QSpinBox(this);
    count_stations->setMinimum(1);
    count_stations->setMaximum(10);

    horizontalLayout_3->addWidget(count_stations);

    verticalLayout->addLayout(horizontalLayout_3);

    horizontalLayout_2 = new QHBoxLayout();

    label_2 = new QLabel(layoutWidget1);
    label_2->setText("Максимальное количество машин в очереди:");

    horizontalLayout_2->addWidget(label_2);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_2->addItem(horizontalSpacer_2);

    count_cars = new QSpinBox(this);
    count_cars->setMinimum(1);

    horizontalLayout_2->addWidget(count_cars);

    verticalLayout->addLayout(horizontalLayout_2);

    connect(accept_button,SIGNAL(pressed()),this,SLOT(setParameters()));

}


TParametersWindow::~TParametersWindow()
{
    delete layoutWidget; delete layoutWidget1;

    delete accept_button;

    delete count_stations; delete count_cars;

    delete label; delete label_2;

    delete horizontalSpacer; delete horizontalSpacer_2;

    delete horizontalLayout; delete horizontalLayout_2; delete horizontalLayout_3;

    delete verticalLayout;
}


void TParametersWindow::setCurrentParameters(const TParametersData parameters)
{
    qDebug() << "TParametersWindow::setCurrentParameters";
    count_stations->setValue(parameters.countStations);
    count_cars->setValue(parameters.countCars);
}


void TParametersWindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}


void TParametersWindow::setParameters()
{
    qDebug() << "TParametersWindow::setParameters";
    TParametersData parameters;
    parameters.countStations = count_stations->value();
    parameters.countCars = count_cars->value();

    QJsonObject request;
    request.insert("type_window", "parametersWindow");
    request.insert("action", "add_parameters");
    request.insert("count_stations", parameters.countStations);
    request.insert("count_cars", parameters.countCars);

    emit send_parametersWindow_request(request);

}

