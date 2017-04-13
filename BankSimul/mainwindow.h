#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\BankSimul\pinkoodi\pinkoodi.h"

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
public slots:


private:
    Ui::MainWindow *ui;
    QString korttiID;
    mainMenu *paavalikko;
    Pinkoodi *koodinkysely;
};

#endif // MAINWINDOW_H
