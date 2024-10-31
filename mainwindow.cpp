#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "secondwindow.h" // Adjust the name as necessary

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_play_clicked()
{
   int n,k;
    showInputDialog(n,k);
// appear second window
      int s= rand() % n + 1;
    sec = new secwindow(n,k,s,this);
    sec->show();


}




