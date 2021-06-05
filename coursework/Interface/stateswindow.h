#ifndef TSTATESWINDOW_H
#define TSTATESWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCloseEvent>

class TStatesWindow : public QWidget
{
    Q_OBJECT

    QLabel *label_station1, *label_station2, *label_station3, *label_station4, *label_station5,
           *label_station6, *label_station7, *label_station8, *label_station9, *label_station10,
           *label_main, *label_rules1, *label_rules2;

    QWidget *widget_station1, *widget_station2, *widget_station3, *widget_station4, *widget_station5,
            *widget_station6, *widget_station7, *widget_station8, *widget_station9, *widget_station10;

    QLCDNumber *queue_station1_left, *queue_station1_right,
               *queue_station2_left, *queue_station2_right,
               *queue_station3_left, *queue_station3_right,
               *queue_station4_left, *queue_station4_right,
               *queue_station5_left, *queue_station5_right,
               *queue_station6_left, *queue_station6_right,
               *queue_station7_left, *queue_station7_right,
               *queue_station8_left, *queue_station8_right,
               *queue_station9_left, *queue_station9_right,
               *queue_station10_left, *queue_station10_right;

    QHBoxLayout *horizontalLayout_1, *horizontalLayout_2, *horizontalLayout_3, *horizontalLayout_4, *horizontalLayout_5,
                *horizontalLayout_6, *horizontalLayout_7, *horizontalLayout_8, *horizontalLayout_9, *horizontalLayout_10;

    QVBoxLayout *verticalLayout_1, *verticalLayout_2, *verticalLayout_3, *verticalLayout_4, *verticalLayout_5,
                *verticalLayout_6, *verticalLayout_7, *verticalLayout_8, *verticalLayout_9, *verticalLayout_10;

    QSpacerItem *horizontalSpacer_1, *horizontalSpacer_2, *horizontalSpacer_3, *horizontalSpacer_4, *horizontalSpacer_5,
                *horizontalSpacer_6, *horizontalSpacer_7, *horizontalSpacer_8, *horizontalSpacer_9, *horizontalSpacer_10;



public:
    TStatesWindow(QWidget *parent = nullptr);
    ~TStatesWindow();

protected:
    void closeEvent(QCloseEvent*);

signals:
    void closing();

};

#endif // TSTATESWINDOW_H
