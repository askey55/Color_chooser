#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <stdlib.h>
#include <sstream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    position_r(0),
    position_g(0),
    position_b(0)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initialize()
{
    this->changeColor();
}

void Widget::changeColor()
{
    ui->widget->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(position_r).arg(position_g).arg(position_b));
}

void Widget::on_horizontalSlider_r_valueChanged(int value)
{
    position_r = value;
    this->changeColor();
    ui->label_r_value->setText(QString::number(value));
}

void Widget::on_horizontalSlider_g_valueChanged(int value)
{
    position_g = value;
    this->changeColor();
    ui->label_g_value->setText(QString::number(value));
}

void Widget::on_horizontalSlider_b_valueChanged(int value)
{
    position_b = value;
    this->changeColor();
    ui->label_b_value->setText(QString::number(value));
}
