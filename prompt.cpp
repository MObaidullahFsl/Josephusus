#include "prompt.h"
#include "ui_prompt.h"

#include "prompt.h"

prompt::prompt(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::prompt), // Make sure ui is initialized here
    imageLabel(new QLabel(this)),
    animation(new QPropertyAnimation(imageLabel, "geometry"))
{
    ui->setupUi(this);  // Now it should work without crashing

    // Load and set the image
    imageLabel->setPixmap(QPixmap(":/images/your_image.png")); // Ensure the path is correct
    imageLabel->setGeometry(this->width(), 100, 100, 100); // Start off-screen to the right

    // Configure the animation
    animation->setDuration(1000); // 1 second
    animation->setStartValue(imageLabel->geometry()); // Starting geometry (off-screen)
    animation->setEndValue(QRect(this->width() - 150, 100, 100, 100)); // Final on-screen position
    animation->setEasingCurve(QEasingCurve::InOutQuad); // Ease-in-out curve

    // Start the animation
    animation->start(QAbstractAnimation::DeleteWhenStopped);


}

int prompt::getN() const {
    return ui->nslider->value();  // Adjust for the actual name of your slider
}

int prompt::getK() const {
    return ui->kslider->value();  // Adjust for the actual name of your slider
}

int prompt::getdbug() const {
    return ui->dbug->checkState();  // Adjust for the actual name of your slider
}


prompt::~prompt()
{
    delete ui;
}

void prompt::on_buttonBox_accepted()
{
    qDebug() << "OK button clicked, accepted!";
    // Perform actions, such as saving data or processing user input
    this->accept();  // You can explicitly call accept() if needed
}


void prompt::on_buttonBox_rejected()
{

    qDebug() << "OK button clicked, accepted!";
    // Perform actions, such as saving data or processing user input
    this->reject();  // You can explicitly call accept() if needed
}


void prompt::on_nslider_valueChanged(int value)
{
      ui->nupdater->setText(QString::number(value));
}


void prompt::on_kslider_valueChanged(int value)
{
     ui->kupdater->setText(QString::number(value));
}


// void prompt::on_dbug_stateChanged(int arg1)
// {
//     if(dbug){
//         dbug = false;
//     }else
//         dbug = true;
// }

