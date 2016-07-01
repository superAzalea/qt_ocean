#ifndef LOGOWIDGET_H
#define LOGOWIDGET_H

#include <QWidget>

namespace Ui {
class LogoWidget;
}

class LogoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogoWidget(QWidget *parent = 0);
    ~LogoWidget();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::LogoWidget *ui;
};

#endif // LOGOWIDGET_H
