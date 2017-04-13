#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = 0);
    ~tilitapahtumat();
    void setData(const QString &kortinNumero);

private slots:
    void on_pushButton_clicked();

private:
    Ui::tilitapahtumat *ui;
    QString korttiID;
};

#endif // TILITAPAHTUMAT_H
