#ifndef PINKOODIMOOTTORIDIALOGI_H
#define PINKOODIMOOTTORIDIALOGI_H

#include <QDialog>
#include <QMainWindow>
#include <QDebug>

namespace Ui {
class pinkoodiMoottoriDialogi;
}

class pinkoodiMoottoriDialogi : public QDialog
{
    Q_OBJECT

public:
    explicit pinkoodiMoottoriDialogi(QWidget *parent = 0);
    ~pinkoodiMoottoriDialogi();

private:
    Ui::pinkoodiMoottoriDialogi *ui;
    QString pinKoodi;
signals:
    void passPin(QString pin);
public slots:
    //void klikattuOK();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButton0_clicked();

    void on_pushButtonC_clicked();

    void on_pushButtonOK_clicked();

};

#endif // PINKOODIMOOTTORIDIALOGI_H
