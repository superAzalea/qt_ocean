#ifndef STATISTICDIALOG_H
#define STATISTICDIALOG_H

#include <QDialog>

namespace Ui {
class statisticDialog;
}

class statisticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statisticDialog(QWidget *parent = 0);
    ~statisticDialog();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::statisticDialog *ui;
};

#endif // STATISTICDIALOG_H
