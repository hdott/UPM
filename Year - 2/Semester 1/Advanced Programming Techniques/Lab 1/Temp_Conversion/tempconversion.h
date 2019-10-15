#ifndef TEMPCONVERSION_H
#define TEMPCONVERSION_H

#include <QMainWindow>

namespace Ui {
class TempConversion;
}

class TempConversion : public QMainWindow
{
    Q_OBJECT

public:
    explicit TempConversion(QWidget *parent = 0);
    ~TempConversion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TempConversion *ui;
};

#endif // TEMPCONVERSION_H
