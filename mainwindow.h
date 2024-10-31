#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QInputDialog>
#include"secwindow.h"
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

    void showInputDialog(int &n, int &k) {
        bool ok;
        n = QInputDialog::getInt(this, "Input n", "Enter number of soldiers (n):", 10, 1, 50, 1, &ok);
        if (!ok) return;  // User canceled

         k = QInputDialog::getInt(this, "Input k", "Enter step count (k):", 3, 1, 5, 1, &ok);
        if (!ok) return;  // User canceled

        qDebug() << "Starting simulation with n:" << n << "k:" << k;
    }




private:
    Ui::MainWindow *ui;
    secwindow * sec;
};
#endif // MAINWINDOW_H
