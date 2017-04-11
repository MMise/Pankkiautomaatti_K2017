#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = 0);
    ~tilitapahtumat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tilitapahtumat *ui;
};

#endif // TILITAPAHTUMAT_H
