#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initialize();

private slots:
    void on_horizontalSlider_r_valueChanged(int value);

    void on_horizontalSlider_g_valueChanged(int value);

    void on_horizontalSlider_b_valueChanged(int value);

private:
    Ui::Widget *ui;
    int position_r;
    int position_g;
    int position_b;
    void changeColor();
};

#endif // WIDGET_H
