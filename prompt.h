#ifndef PROMPT_H
#define PROMPT_H

#include <QDialog>
#include <QLabel>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QEasingCurve>

namespace Ui {
class prompt;
}

class prompt : public QDialog
{
    Q_OBJECT

public:
    explicit prompt(QWidget *parent = nullptr);

        ~prompt();


    Ui::prompt *ui;
    QLabel *imageLabel; // Declare imageLabel as a pointer
    QPropertyAnimation *animation; // Declare animation as a pointer
    int getN() const;  // Getter for the value of n from the slider
    int getK() const;  // Getter for the value of k from the slider


private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_nslider_valueChanged(int value);
    void on_kslider_valueChanged(int value);
};

#endif // PROMPT_H
