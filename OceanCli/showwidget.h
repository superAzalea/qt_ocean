#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>


namespace Ui {
class ShowWidget;
}

class ShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWidget(QWidget *parent = 0);
    ~ShowWidget();
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowWidget *ui;
};

#endif // SHOWWIDGET_H
