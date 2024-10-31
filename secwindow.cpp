#include "secwindow.h"
#include "ui_secwindow.h"
#include <QGraphicsPixmapItem>
#include <QDebug>
#include<iostream>
#include<queue>
#include<stack>
#include <ctime>
#include <cmath>
#include <QDebug>
#include "logic.h"

secwindow::secwindow(int n,int k,int s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secwindow), n(n), k(k),s(s)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

  timer = new QTimer(this);

    // Connect the timer's timeout signal to your custom slot
    connect(timer, &QTimer::timeout, this, &secwindow::timerfunc);

    // Set the timer interval (e.g., 1000 ms for 1 second)



    list = arrangeSoldiers(n);




    for (int i = 1; i <= n; i++)
    {
        q.push(n - i + 1);
    }
    srand(time(0));

    timer->start(1000);

   /*  while (q.size() != 1)
     {
         qDebug() << "Turn of:" << s;
         int a = getnext(s, k, q);
         qDebug() << "killing: " << a;
         q = remove(a, q);
         killSoldier(list,a);

         printQueue(q);
         int sindex = getindex(s, q);
         int nextsindex = (++sindex) % q.size();

         s = getval(nextsindex, q);


     }

*/

}

QList<QGraphicsPixmapItem *> secwindow::arrangeSoldiers(int n) {
    QList<QGraphicsPixmapItem *> soldiers; // List to store all soldier items

    QPixmap soldierPixmap(":/icons/resources/soldier.png");
    QPixmap scaledSoldierPixmap = soldierPixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    int radius = 200;
    int centerX = 250, centerY = 250;

    float angle = 2 * M_PI / n;
    for (int i = 0; i < n; ++i) {
        float x = centerX + radius * cos(i * angle);
        float y = centerY + radius * sin(i * angle);

        // Create the soldier pixmap item
        QGraphicsPixmapItem *soldierItem = new QGraphicsPixmapItem(scaledSoldierPixmap);
        soldierItem->setPos(x, y);
        scene->addItem(soldierItem);
        soldiers.append(soldierItem); // Add soldier to the list

        // Create a text item to display the soldier's number
      //  QGraphicsTextItem *numberItem = new QGraphicsTextItem(QString::number(i + 1)); // Display soldier number (1-based)
       // numberItem->setPos(x +50, y + 50); // Position it slightly offset from the soldier image
       // numberItem->setDefaultTextColor(Qt::red); // Set text color to black
       // numberItem->setFont(QFont("Arial", 12, QFont::Bold)); // Set font style and size

       // scene->addItem(numberItem); // Add the text item to the scene
    }

    return soldiers; // Return the list of soldier items
}


secwindow::~secwindow()
{
    delete ui;
}



void secwindow::timerfunc()
{
    if(q.size() == 1){
        timer->stop();
    }
    if(q.size()!=1){
    qDebug() << "Turn of:" << s;
    int a = getnext(s, k, q);
    qDebug() << "killing: " << a;
    q = remove(a, q);
    killSoldier(list,a);

    printQueue(q);
    int sindex = getindex(s, q);
    int nextsindex = (++sindex) % q.size();

    s = getval(nextsindex, q);
}
}


void secwindow::killSoldier(QList<QGraphicsPixmapItem *> &soldiers, int index) {
    // Check if the index is valid
    qDebug()<<"index for deletion";
    if (index < 0 || index > soldiers.size()) {
        return; // Invalid index, do nothing
    }

       QPixmap deadPixmap(":/icons/resources/dead.png");
    QPixmap scaleddeadPixmap = deadPixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
       QGraphicsPixmapItem *deaditem = new QGraphicsPixmapItem(scaleddeadPixmap);

    // Get the soldier item to be killed

    QGraphicsPixmapItem *soldierItem = soldiers[index-1];

    // Change the soldier's pixmap to the dead soldier pixmap
    if (soldierItem->pixmap().toImage() == scaleddeadPixmap.toImage()) {
        qDebug() << "Already dead at"<<index;
    } else {
         soldierItem->setPixmap(scaleddeadPixmap);
    }



    // Optionally, you can also disable interactions or animations for dead soldiers
    // Example to disable selection
    //redrawSoldiers(list,n);

}

