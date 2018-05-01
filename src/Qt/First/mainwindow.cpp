#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


int k=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMesseges(int k, int x)
{
    if(k>=x)
    QMessageBox::warning(this,"Нахуй!","Пошел нахуй!");
}
int MainWindow::kPlusPlus(int k)
{
    return ++k;
}
void MainWindow::on_pushButton_clicked()
{
    //ui->MainWindow->
    ui->statusBar->showMessage("Нахуй!");
    //QMessageBox::warning(this,"Нахуй!","Пошел нахуй!");
    showMesseges(k,2);
    k=kPlusPlus(k);

}
