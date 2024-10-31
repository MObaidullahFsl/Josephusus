#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QDialog>
#include<QtGui>
#include <QGraphicsScene>
#include<QTimer>
#include<queue>
namespace Ui {
class secwindow;
}

class secwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secwindow(int n,int k, int s ,QWidget *parent = nullptr);
    ~secwindow();
void killSoldier(QList<QGraphicsPixmapItem *> &soldiers, int index);

   // void redrawSoldiers(const QList<QGraphicsPixmapItem *> &soldiers,int n);
    QPixmap deadSoldierPixmap;

    bool timebool;
private:

    // logic members
    int n;
    int k;
    int s;
    std:: queue<int> q;
    QList<QGraphicsPixmapItem *> list;



    Ui::secwindow *ui;
    QGraphicsScene * scene;
    QTimer *timer;

    QList<QGraphicsPixmapItem *> arrangeSoldiers(int n);

    void timerfunc() ;
};

#endif // SECWINDOW_H
