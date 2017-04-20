#ifndef TIETOKANTADIALOG_H
#define TIETOKANTADIALOG_H

#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>

namespace Ui {
class TietokantaDialog;
}

class TietokantaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TietokantaDialog(QWidget *parent = 0);
    ~TietokantaDialog();
    void luoTable(QSqlTableModel &mTable);

private slots:
    void on_pushButtonOK_clicked();

private:
    Ui::TietokantaDialog *ui;
};

#endif // TIETOKANTADIALOG_H
