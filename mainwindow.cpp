#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sEdit=new SearchEdit();
    ui->myhLayout->addWidget(sEdit);

    myLine=new MyLineEdit();
    myLine->setSizeIncrement(120,50);
    ui->myhLayout->addWidget(myLine);
}

MainWindow::~MainWindow()
{
    delete ui;
}
