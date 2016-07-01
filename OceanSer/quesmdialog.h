#ifndef QUESMDIALOG_H
#define QUESMDIALOG_H

#include <QDialog>

namespace Ui {
class QuesMDialog;
}

class QuesMDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QuesMDialog(QWidget *parent = 0);
    ~QuesMDialog();

private slots:
    void on_pushButton_2_clicked();




    void on_pushButton_3_clicked();

private:
    Ui::QuesMDialog *ui;
};

#endif // QUESMDIALOG_H
