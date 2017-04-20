#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDate>
#include "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\BankSimul\pinkoodi\pinkoodi.h"
#include "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\BankSimul\Tietokanta\tietokanta.h"
#include "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\BankSimul\rfid\rfid.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void kortinLukeminen(QString card);

private slots:

    void on_pushButton_lueKortti_clicked();

    void on_pushButtonNosto_2_clicked();

    void on_pushButtonSaldo_2_clicked();

    void on_pushButtonTilitapahtumat_2_clicked();

    void on_pushButtonUlos_2_clicked();

    void on_pushButtonPeruuta_clicked();

    void on_pushButtonPeruutaSaldo_clicked();

    void on_pushButtonOkTilitapahtumat_clicked();

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

    void on_pushButton20_clicked();

    void on_pushButton40_clicked();

    void on_pushButton60_clicked();

    void on_pushButton80_clicked();

private:
    Ui::MainWindow *ui;

    QString korttiID;
    QString pinKoodi;
    QString saldoNaru;
    QString summa;

    Pinkoodi *koodinkysely;
    Tietokanta *tietokanta;
    Rfid *kortinlukija;

    int PIN;
    int nosto;
    double saldo;
};

#endif // MAINWINDOW_H
