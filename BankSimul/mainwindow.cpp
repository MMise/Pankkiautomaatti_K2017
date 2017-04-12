#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    paavalikko = new mainMenu;
    this->setWindowTitle("BankSimul - Aloita");
    connect(ui->pushButton_lueKortti,SIGNAL(clicked(bool)),this,SLOT(naytaValikko()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::naytaValikko()
{
    paavalikko->show();
    this->close();
}
