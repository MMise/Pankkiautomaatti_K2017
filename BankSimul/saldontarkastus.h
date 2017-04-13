#ifndef SALDONTARKASTUS_H
#define SALDONTARKASTUS_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class saldontarkastus;
}

class saldontarkastus : public QDialog
{
    Q_OBJECT

public:
    explicit saldontarkastus(QWidget *parent = 0);
    ~saldontarkastus();
    void setData(const QString &kortinNumero);

private slots:
    void on_pushButton_clicked();

private:
    Ui::saldontarkastus *ui;
    QString korttiID;
};

#endif // SALDONTARKASTUS_H
