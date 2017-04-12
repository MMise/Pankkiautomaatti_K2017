#ifndef SALDONTARKASTUS_H
#define SALDONTARKASTUS_H

#include <QDialog>

namespace Ui {
class saldontarkastus;
}

class saldontarkastus : public QDialog
{
    Q_OBJECT

public:
    explicit saldontarkastus(QWidget *parent = 0);
    ~saldontarkastus();

private slots:
    void on_pushButton_clicked();

private:
    Ui::saldontarkastus *ui;
};

#endif // SALDONTARKASTUS_H
