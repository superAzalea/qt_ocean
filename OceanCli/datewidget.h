#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>

namespace Ui {
class DateWidget;
}

class DateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DateWidget(QWidget *parent = 0);
    ~DateWidget();
private slots:
    void update();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::DateWidget *ui;
    QTimer *timer;
};

#endif // DATEWIDGET_H
