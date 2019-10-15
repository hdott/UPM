#include "tempconversion.h"
#include "ui_tempconversion.h"

TempConversion::TempConversion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TempConversion)
{
    ui->setupUi(this);
}

TempConversion::~TempConversion()
{
    delete ui;
}

void TempConversion::on_pushButton_clicked()
{
    int option = 0;

    if (!ui->fahrenheit->isChecked() && !ui->celsius->isChecked()) {
        option = 1;
    }

    QString grade = ui->getGrade->text();

    if (grade.isEmpty()) {
        option = 2;
    }

    float gr = grade.toFloat();

    bool celsius,
            fahr;

    switch (option) {
    case 0:

        celsius = ui->celsius->isChecked();
        fahr = ui->fahrenheit->isChecked();

        if (fahr) {
            float rezultatFahrToCelsius = (gr  - 32) * 5 / 9;
            QString rezultat = QString::number(rezultatFahrToCelsius);
            ui->rezultat->setText(rezultat);
        } else if (celsius) {
            float rezultatCelsiusToFahr = (gr * 9) / 5 + 32;
            QString rezultat = QString::number(rezultatCelsiusToFahr);
            ui->rezultat->setText(rezultat);
        }
        break;
    case 1:
        ui->rezultat->setText("Nu a fost selectata nici o Optiune");
        break;
    case 2:
        ui->rezultat->setText("Gradele nu au fost Introduse!");
        break;
    default:
        break;
    }

}
