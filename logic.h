#ifndef LOGIC_H
#define LOGIC_H

#include<iostream>
#include<queue>
#include<stack>
#include <ctime>
#include <cmath>
#include <QDebug>
#include"secwindow.h"
#include <QGraphicsPixmapItem>
using namespace std;
#include <QDebug>
#include <queue>
#include <stack>

void printQueue(std::queue<int> q) {
    std::stack<int> temp;

    // Move all elements from queue to stack
    while (!q.empty()) {
        temp.push(q.front());
        q.pop();
    }

    // Print elements from stack to maintain the original queue order
    QString output;
    while (!temp.empty()) {
        output += QString::number(temp.top()) + " ";
        temp.pop();
    }

    qDebug() << output.trimmed();
}


int getval(int index, queue<int> q) {

    int count = q.size() - 1;
    while (count != index) {
        q.pop();
        count--;
    }
    return q.front();

}


int getindex(int a, queue<int> b) {
    int count = 1;
    int size = b.size();
    while (b.front() != a) {
        b.pop();
        count++;
    }

    return (size - count);

}

int getnext(int s, int k, queue<int> q) {

    queue<int> temp;
    temp = q;
    int b = q.front();
    int size = q.size();
    int sindex = getindex(s, q);
    while (true) {
        if (k<size) {
            int b = temp.front();
            temp.pop();
            int bindex = getindex(b, q);

            int comparer = (bindex - sindex);
            if (bindex < sindex) {
                int temp = size - abs(comparer);
                comparer = temp;
            }


            if (comparer == k) {

                return b;
            }

        }
        else {
            k--;
        }



    }

}

queue<int> remove(int a, queue<int>q) {

    queue<int> temp;
    int count = 0;
    int size = q.size();
    while (count != size) {
        int b = q.front();
        if (b != a)
        {
            temp.push(b);
        }
        count++;
        q.pop();
    }

    return temp;
}

void josephus(int n, int k,QList<QGraphicsPixmapItem *> list_of_soliders) {

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(n - i + 1);
    }

    srand(time(0));
    int s= rand() % n + 1;

    while (q.size() != 1)
    {
        qDebug() << "Turn of:" << s;
        int a = getnext(s, k, q);
        qDebug() << "killing: " << a;
        q = remove(a, q);


        printQueue(q);
        int sindex = getindex(s, q);
        int nextsindex = (++sindex) % q.size();

        s = getval(nextsindex, q);


    }

}



#endif // LOGIC_H
