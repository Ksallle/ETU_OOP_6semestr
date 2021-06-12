#pragma once

#ifndef TPARAMETERSWINDOW_H
#define TPARAMETERSWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QCloseEvent>
#include <QJsonObject>

#include "../common/common.h"

class TParametersWindow : public QWidget
{
    Q_OBJECT

    QWidget *layoutWidget, *layoutWidget1;

    QPushButton *accept_button;

    QSpinBox *count_stations, *count_cars;

    QLabel *label, *label_2;

    QSpacerItem *horizontalSpacer, *horizontalSpacer_2;

    QHBoxLayout *horizontalLayout, *horizontalLayout_2, *horizontalLayout_3;

    QVBoxLayout *verticalLayout;


public:
    TParametersWindow(QWidget *parent = 0);
    ~TParametersWindow();

    void setCurrentParameters(const TParametersData);

protected:
    void closeEvent(QCloseEvent*);

public slots:
    void setParameters();

signals:
    void closing();
    void send_parametersWindow_request(QJsonObject);

};

#endif // TPARAMETERSWINDOW_H
