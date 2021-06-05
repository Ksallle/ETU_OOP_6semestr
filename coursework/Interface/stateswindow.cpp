#include "stateswindow.h"

TStatesWindow::TStatesWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Окно состояния");

     resize(611, 509);
     setMinimumSize(QSize(611, 509));
     setMaximumSize(QSize(611, 509));


     label_main = new QLabel(this);
     label_main->setGeometry(QRect(20, 10, 121, 16));
     label_main->setText("Бензоколонки АЗС:");

     label_rules1 = new QLabel(this);
     label_rules1->setGeometry(QRect(160, 10, 221, 41));

     label_rules2 = new QLabel(this);
     label_rules2->setGeometry(QRect(380, 10, 231, 31));


     // Первая колонка
     widget_station1 = new QWidget(this);
     widget_station1->setGeometry(QRect(20, 60, 161, 91));
     horizontalLayout_1 = new QHBoxLayout(widget_station1);
     label_station1 = new QLabel(widget_station1);
     label_station1->setText("Бензоколонка №1");

     horizontalLayout_1->addWidget(label_station1);

     horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_1->addItem(horizontalSpacer_1);

     verticalLayout_1 = new QVBoxLayout();

     queue_station1_left = new QLCDNumber(this);
     queue_station1_left->setDigitCount(2);

     verticalLayout_1->addWidget(queue_station1_left);

     queue_station1_right = new QLCDNumber(this);
     queue_station1_right->setDigitCount(2);

     verticalLayout_1->addWidget(queue_station1_right);

     horizontalLayout_1->addLayout(verticalLayout_1);
     // Первая колонка


     // Вторая колонка
     widget_station2 = new QWidget(this);
     widget_station2->setGeometry(QRect(20, 170, 161, 91));
     horizontalLayout_2 = new QHBoxLayout(widget_station2);
     label_station2 = new QLabel(widget_station2);
     label_station2->setText("Бензоколонка №2");

     horizontalLayout_2->addWidget(label_station2);

     horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_2->addItem(horizontalSpacer_2);

     verticalLayout_2 = new QVBoxLayout();
     queue_station2_left = new QLCDNumber(this);
     queue_station2_left->setDigitCount(2);

     verticalLayout_2->addWidget(queue_station2_left);

     queue_station2_right = new QLCDNumber(this);
     queue_station2_right->setDigitCount(2);

     verticalLayout_2->addWidget(queue_station2_right);

     horizontalLayout_2->addLayout(verticalLayout_2);
     // Вторая колонка


     // Третья колонка
     widget_station3 = new QWidget(this);
     widget_station3->setGeometry(QRect(20, 280, 161, 91));
     horizontalLayout_3 = new QHBoxLayout(widget_station3);
     label_station3 = new QLabel(widget_station3);
     label_station3->setText("Бензоколонка №3");

     horizontalLayout_3->addWidget(label_station3);

     horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_3->addItem(horizontalSpacer_3);

     verticalLayout_3 = new QVBoxLayout();
     queue_station3_left = new QLCDNumber(this);
     queue_station3_left->setDigitCount(2);

     verticalLayout_3->addWidget(queue_station3_left);

     queue_station3_right = new QLCDNumber(this);
     queue_station3_right->setDigitCount(2);

     verticalLayout_3->addWidget(queue_station3_right);

     horizontalLayout_3->addLayout(verticalLayout_3);
     // Третья колонка


     // Четвертая колонка
     widget_station4 = new QWidget(this);
     widget_station4->setGeometry(QRect(20, 390, 161, 91));
     horizontalLayout_4 = new QHBoxLayout(widget_station4);
     label_station4 = new QLabel(widget_station4);
     label_station4->setText("Бензоколонка №4");

     horizontalLayout_4->addWidget(label_station4);

     horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_4->addItem(horizontalSpacer_4);

     verticalLayout_4 = new QVBoxLayout();
     queue_station4_left = new QLCDNumber(this);
     queue_station4_left->setDigitCount(2);

     verticalLayout_4->addWidget(queue_station4_left);

     queue_station4_right = new QLCDNumber(this);
     queue_station4_right->setDigitCount(2);

     verticalLayout_4->addWidget(queue_station4_right);

     horizontalLayout_4->addLayout(verticalLayout_4);
     // Четвертая колонка


     // Пятая колонка
     widget_station5 = new QWidget(this);
     widget_station5->setGeometry(QRect(220, 60, 161, 91));
     horizontalLayout_5 = new QHBoxLayout(widget_station5);
     label_station5 = new QLabel(widget_station5);
     label_station5->setText("Бензоколонка №5");

     horizontalLayout_5->addWidget(label_station5);

     horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_5->addItem(horizontalSpacer_5);

     verticalLayout_5 = new QVBoxLayout();
     queue_station5_left = new QLCDNumber(this);
     queue_station5_left->setDigitCount(2);

     verticalLayout_5->addWidget(queue_station5_left);

     queue_station5_right = new QLCDNumber(this);
     queue_station5_right->setDigitCount(2);

     verticalLayout_5->addWidget(queue_station5_right);

     horizontalLayout_5->addLayout(verticalLayout_5);
     // Пятая колонка


     // Шестая колонка
     widget_station6 = new QWidget(this);
     widget_station6->setGeometry(QRect(220, 170, 161, 91));
     horizontalLayout_6 = new QHBoxLayout(widget_station6);
     label_station6 = new QLabel(widget_station6);
     label_station6->setText("Бензоколонка №6");

     horizontalLayout_6->addWidget(label_station6);

     horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_6->addItem(horizontalSpacer_6);

     verticalLayout_6 = new QVBoxLayout();
     queue_station6_left = new QLCDNumber(this);
     queue_station6_left->setDigitCount(2);

     verticalLayout_6->addWidget(queue_station6_left);

     queue_station6_right = new QLCDNumber(this);
     queue_station6_right->setDigitCount(2);

     verticalLayout_6->addWidget(queue_station6_right);

     horizontalLayout_6->addLayout(verticalLayout_6);
     // Шестая колонка


     // Седьмая колонка
     widget_station7 = new QWidget(this);
     widget_station7->setGeometry(QRect(220, 280, 161, 91));
     horizontalLayout_7 = new QHBoxLayout(widget_station7);
     label_station7 = new QLabel(widget_station7);
     label_station7->setText("Бензоколонка №7");

     horizontalLayout_7->addWidget(label_station7);

     horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_7->addItem(horizontalSpacer_7);

     verticalLayout_7 = new QVBoxLayout();
     queue_station7_left = new QLCDNumber(this);
     queue_station7_left->setDigitCount(2);

     verticalLayout_7->addWidget(queue_station7_left);

     queue_station7_right = new QLCDNumber(this);
     queue_station7_right->setDigitCount(2);

     verticalLayout_7->addWidget(queue_station7_right);

     horizontalLayout_7->addLayout(verticalLayout_7);
     // Седьмая колонка


     // Восьмая колонка
     widget_station8 = new QWidget(this);
     widget_station8->setGeometry(QRect(220, 390, 161, 91));
     horizontalLayout_8 = new QHBoxLayout(widget_station8);
     label_station8 = new QLabel(widget_station8);
     label_station8->setText("Бензоколонка №8");

     horizontalLayout_8->addWidget(label_station8);

     horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_8->addItem(horizontalSpacer_8);

     verticalLayout_8 = new QVBoxLayout();
     queue_station8_left = new QLCDNumber(this);
     queue_station8_left->setDigitCount(2);

     verticalLayout_8->addWidget(queue_station8_left);

     queue_station8_right = new QLCDNumber(this);
     queue_station8_right->setDigitCount(2);

     verticalLayout_8->addWidget(queue_station8_right);

     horizontalLayout_8->addLayout(verticalLayout_8);
     // Восьмая колонка


     // Девятая колонка
     widget_station9 = new QWidget(this);
     widget_station9->setEnabled(true);
     widget_station9->setGeometry(QRect(420, 120, 161, 91));
     horizontalLayout_9 = new QHBoxLayout(widget_station9);
     label_station9 = new QLabel(widget_station9);
     label_station9->setText("Бензоколонка №9");

     horizontalLayout_9->addWidget(label_station9);

     horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_9->addItem(horizontalSpacer_9);

     verticalLayout_9 = new QVBoxLayout();
     queue_station9_left = new QLCDNumber(this);
     queue_station9_left->setDigitCount(2);

     verticalLayout_9->addWidget(queue_station9_left);

     queue_station9_right = new QLCDNumber(this);
     queue_station9_right->setDigitCount(2);

     verticalLayout_9->addWidget(queue_station9_right);

     horizontalLayout_9->addLayout(verticalLayout_9);
     // Девятая колонка


     // Десятая колонка
     widget_station10 = new QWidget(this);
     widget_station10->setEnabled(true);
     widget_station10->setGeometry(QRect(410, 330, 171, 91));
     horizontalLayout_10 = new QHBoxLayout(widget_station10);
     label_station10 = new QLabel(widget_station10);
     label_station10->setText("Бензоколонка №10");

     horizontalLayout_10->addWidget(label_station10);

     horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     horizontalLayout_10->addItem(horizontalSpacer_10);

     verticalLayout_10 = new QVBoxLayout();
     queue_station10_left = new QLCDNumber(this);
     queue_station10_left->setDigitCount(2);

     verticalLayout_10->addWidget(queue_station10_left);

     queue_station10_right = new QLCDNumber(this);
     queue_station10_right->setDigitCount(2);

     verticalLayout_10->addWidget(queue_station10_right);

     horizontalLayout_10->addLayout(verticalLayout_10);
     // Десятая колонка


}

TStatesWindow::~TStatesWindow()
{
    delete label_station1; delete label_station2; delete label_station3; delete label_station4; delete label_station5;
    delete label_station6; delete label_station7; delete label_station8; delete label_station9; delete label_station10;

    delete widget_station1; delete widget_station2; delete widget_station3; delete widget_station4; delete widget_station5;
    delete widget_station6; delete widget_station7; delete widget_station8; delete widget_station9; delete widget_station10;

    delete queue_station1_left; delete queue_station1_right; delete queue_station2_left; delete queue_station2_right;
    delete queue_station3_left; delete queue_station3_right; delete queue_station4_left; delete queue_station4_right;
    delete queue_station5_left; delete queue_station5_right; delete queue_station6_left; delete queue_station6_right;
    delete queue_station7_left; delete queue_station7_right; delete queue_station8_left; delete queue_station8_right;
    delete queue_station9_left; delete queue_station9_right; delete queue_station10_left; delete queue_station10_right;

    delete horizontalLayout_1; delete horizontalLayout_2; delete horizontalLayout_3; delete horizontalLayout_4;
    delete horizontalLayout_5; delete horizontalLayout_6; delete horizontalLayout_7; delete horizontalLayout_8;
    delete horizontalLayout_9; delete horizontalLayout_10;

    delete verticalLayout_1; delete verticalLayout_2; delete verticalLayout_3; delete verticalLayout_4;
    delete verticalLayout_5; delete verticalLayout_6; delete verticalLayout_7; delete verticalLayout_8;
    delete verticalLayout_9; delete verticalLayout_10;

    delete horizontalSpacer_1; delete horizontalSpacer_2; delete horizontalSpacer_3; delete horizontalSpacer_4;
    delete horizontalSpacer_5; delete horizontalSpacer_6; delete horizontalSpacer_7; delete horizontalSpacer_8;
    delete horizontalSpacer_9; delete horizontalSpacer_10;
}

void TStatesWindow::closeEvent(QCloseEvent* event)
{
    emit closing();
    event->accept();
}
