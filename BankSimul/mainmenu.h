#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
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
public slots:
    void naytaNosto();
    void naytaSaldo();
    void naytaTapahtumat();

private:
    Ui::mainMenu *ui;
    rahannosto *nostovalikko;
    saldontarkastus *saldovalikko;
    tilitapahtumat *tapahtumavalikko;
};

#endif // MAINMENU_H
