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

    showInputDialog();
// appear second window



}




