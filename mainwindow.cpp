#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <QSound>

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
    // QSound *clickSound = new QSound(this);
    // clickSound->setSource(QUrl::fromLocalFile(":/sound/resources/click.wav"));  // Specify the path to your sound file
    // clickSound->setVolume(0.5f);  // Set volume (0.0 to 1.0)
    // clickSound->play();
    showInputDialog();
// appear second window



}





void MainWindow::on_pushButton_2_clicked()
{
    close();
}

