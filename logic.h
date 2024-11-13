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


    while (!q.empty()) {
        temp.push(q.front());
        q.pop();
    }


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
    int count = 0;
    int size = b.size();

    while (b.front() != a && !b.empty()) {
        b.pop();
        count++;
    }

    return (size - count-1);

}

int getnext(int s, int k, queue<int> q) {

    queue<int> temp;
    temp = q;
    int b = q.front();
    int size = q.size();
    int sindex = getindex(s, q);

    int next = (sindex + k) % size;
    next = getval(next,q);

    return next;


}

queue<int> remove(int a, queue<int>q) {

    queue<int> temp;
    int count = 0;
    int size = q.size();
    while (!q.empty()) {
        if (q.front()!=a) {
            temp.push(q.front());
        }
        q.pop();
    }

    return temp;
}

void josephus(int n, int k) {

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(n - i + 1);
    }

    srand(time(0));
    int s = rand() % n + 1;

    printQueue(q);
    while (q.size() != 1)
    {
        cout << endl;
        cout << "Turn of:" << s;
        cout << endl;
        int a = getnext(s, k, q);

        int sindex = getindex(a,q);
        int nextsindex = (++sindex) % q.size();
        s = getval(nextsindex, q);
        cout << endl;
        cout << "killing: " << a;
        cout << endl;
        q = remove(a, q);



        printQueue(q);



    }

}




#endif // LOGIC_H
