#ifndef STATISTICANALYZE_H
#define STATISTICANALYZE_H

#include <QDialog>

namespace Ui {
class statisticAnalyze;
}

class statisticAnalyze : public QDialog
{
    Q_OBJECT

public:
    explicit statisticAnalyze(QWidget *parent = 0);
    ~statisticAnalyze();

private slots:
    void on_pushButton_8_clicked();

private:
    Ui::statisticAnalyze *ui;
};

#endif // STATISTICANALYZE_H
