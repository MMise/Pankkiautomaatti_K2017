#ifndef RAHANNOSTO_H
#define RAHANNOSTO_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class rahannosto;
}

class rahannosto : public QDialog
{
    Q_OBJECT

public:
    explicit rahannosto(QWidget *parent = 0);
    ~rahannosto();
    void setData(const QString &kortinNumero);

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

    void on_pushButton20_clicked();

    void on_pushButton40_clicked();

    void on_pushButton60_clicked();

    void on_pushButton80_clicked();

    void on_pushButton_clicked();

private:
    Ui::rahannosto *ui;
    QString summa;
    QString korttiID;
    int nosto;
};

#endif // RAHANNOSTO_H
