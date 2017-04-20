#include "tietokantadialog.h"
#include "ui_tietokantadialog.h"

TietokantaDialog::TietokantaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TietokantaDialog)
{
    ui->setupUi(this);
    this->show();
}

TietokantaDialog::~TietokantaDialog()
{
    delete ui;
}

void TietokantaDialog::on_pushButtonOK_clicked()
{
    this->close();
}

void TietokantaDialog::luoTable(QSqlTableModel &mTable)
{
    ui->tableView->setModel(&mTable);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}
