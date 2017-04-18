#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
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
    void naytaValikko();
    void setPin(QString str);

private slots:
    void on_pushButtonTESTI_clicked();

private:
    Ui::MainWindow *ui;
    QString korttiID;
    QString pinKoodi;
    mainMenu *paavalikko;
    Pinkoodi *koodinkysely;
    //Tietokanta *tietokanta;
    int PIN;
};

#endif // MAINWINDOW_H
