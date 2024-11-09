#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QInputDialog>
#include"secwindow.h"
#include"prompt.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_play_clicked();

    void showInputDialog() {
        int n, k;
        prompt *dial = new prompt(this); // Create an instance of the prompt dialog
        if (dial->exec() == QDialog::Accepted) {  // Show the dialog modally and check if "Done" was pressed
            n = dial->getN();  // Get the value of n from the slider
            k = dial->getK();  // Get the value of k from the slider
            qDebug() << "Starting simulation with n:" << n << "k:" << k;

            srand(time(0));
            int s= rand() % n+1;
            sec = new secwindow(n,k,s,this);
            sec->show();

        } else {
            qDebug() << "Dialog canceled.";
        }
    }





private:
    Ui::MainWindow *ui;
    secwindow * sec;
};
#endif // MAINWINDOW_H
