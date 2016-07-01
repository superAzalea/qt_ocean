#ifndef CONTACTORWIDGET_H
#define CONTACTORWIDGET_H

#include <QWidget>

namespace Ui {
class contactorWidget;
}

class contactorWidget : public QWidget
{
    Q_OBJECT


public:
    explicit contactorWidget(QWidget *parent = 0);
    ~contactorWidget();
    friend void hiden();

private:
    Ui::contactorWidget *ui;
};

#endif // CONTACTORWIDGET_H
