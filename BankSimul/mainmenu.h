#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QDebug>
#include "rahannosto.h"
#include "saldontarkastus.h"
#include "tilitapahtumat.h"

namespace Ui {
class mainMenu;
}

class mainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainMenu(QWidget *parent = 0);
    ~mainMenu();
    void setData(const QString &kortinNumero);
public slots:
    void naytaNosto();
    void naytaSaldo();
    void naytaTapahtumat();

private slots:

    void on_pushButtonUlos_clicked();

private:
    Ui::mainMenu *ui;
    rahannosto *nostovalikko;
    saldontarkastus *saldovalikko;
    tilitapahtumat *tapahtumavalikko;
    QString korttiID;
};

#endif // MAINMENU_H
