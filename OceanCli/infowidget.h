#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class InfoWidget;
}

class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWidget(QWidget *parent = 0);
    ~InfoWidget();


private slots:
    void on_pushButton_clicked();
    void reset();

private:
    Ui::InfoWidget *ui;
    bool flags;
    QTimer *timeout;
};

#endif // INFOWIDGET_H
