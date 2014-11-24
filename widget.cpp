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

void Widget::changeColor()
{
    QString background_color;

    background_color = "background-color:rgb(";
    background_color += QString::number(position_r);
    background_color += ",";
    background_color += QString::number(position_g);
    background_color += ",";
    background_color += QString::number(position_b);
    background_color += ")";

    ui->widget->setStyleSheet(background_color);
}

void Widget::on_horizontalSlider_r_sliderMoved(int position)
{
    position_r = position;
    this->changeColor();
    ui->label_r_value->setText(QString::number(position));
}

void Widget::on_horizontalSlider_g_sliderMoved(int position)
{
    position_g = position;
    this->changeColor();
    ui->label_g_value->setText(QString::number(position));
}

void Widget::on_horizontalSlider_b_sliderMoved(int position)
{
    position_b = position;
    this->changeColor();
    ui->label_b_value->setText(QString::number(position));
}
