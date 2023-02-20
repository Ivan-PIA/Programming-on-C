#include "mainwindow.h"
#include "ui_mainwindow.h"
#define dt 10
#include <QtMath>
int k=0;
int p=0,m=0;

MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_7->setGeometry(0,0,950,720);
    ui->label_7->setPixmap(QPixmap("/home/ivan/photo/заставка.jpg"));
    ui->label_8->setGeometry(2000,0,701,451);
    ui->label_9->setGeometry(2000,0,1000,1000);
    ui->label_10->setGeometry(2000,0,350,100);
    ui->label_11->setGeometry(141,300,141,141);
}
 MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()

{   ui->label_7->setGeometry(2000,0,950,720);

    ui->label_6->setPixmap(QPixmap("/home/ivan/photo/fon2.jpg"));
    //ui->label->setGeometry(50,500,200,141);
    //ui->label_3->setGeometry(170,400,141,141);
    ui->label_3->setPixmap(QPixmap("/home/ivan/photo/еж1.png"));
    //ui->label_6->setGeometry(ui->label_6->geometry().x()+dt,0,1080,720);//fon for run
    if(ui->label_3->geometry().x()<750 && k==0)//не доехали до правого края
    {
    ui->label_3->setPixmap(QPixmap("/home/ivan/photo/еж1.png"));
    ui->label_3->setGeometry(ui->label_3->geometry().x()+dt,400,141,141);
    }
    else
    {
        timer->stop();

    k=1;
    ui->label_3->setPixmap(QPixmap("/home/ivan/photo/еж.png"));
    ui->label_3->setGeometry(ui->label_3->geometry().x()-dt,400,141,141);


    if(ui->label_3->geometry().x()<300)
        k=0; // доехали до левого края
    }

}

void MainWindow::onTimeout1()
{

    if(ui->label->geometry().x()<750 && m==0)//не доехали до правого края
    {
    ui->label->setPixmap(QPixmap("/home/ivan/photo/lala.png"));
    ui->label->setGeometry(ui->label->geometry().x()+dt,ui->label->geometry().y()+sin(ui->label->geometry().x())*25,200,141);
    }
    else
    {
        timer2->stop();
        ui->label_9->setGeometry(0,0,1000,1000);
        ui->label_8->setGeometry(190,300,701,451);
        ui->label_10->setGeometry(350,10,350,100);
        ui->label_3->setGeometry(400,300,141,141);
        ui->label_11->setGeometry(2000,300,141,141);

    m=1;
    //ui->label->setPixmap(QPixmap("/home/ivan/photo/11.png"));
    ui->label->setGeometry(ui->label->geometry().x()-10,ui->label->geometry().y()+sin(ui->label->geometry().x())*25,200,141);


    if(ui->label->geometry().x()<150)
        m=0; // доехали до левого края
    }

}
void MainWindow::onTimeout2(){


    if(ui->label_11->geometry().x()<750 && p==0)//не доехали до правого края
    {
    ui->label_11->setPixmap(QPixmap("/home/ivan/photo/bara1.png"));
    ui->label_11->setGeometry(ui->label_11->geometry().x()+dt,ui->label_11->geometry().y()+sin(ui->label_11->geometry().x())*25,200,141);
    }
    else
    {
        timer3->stop();


        ui->label_11->setPixmap(QPixmap("/home/ivan/photo/bara2.png"));


        p=1;
    }

}

void MainWindow::on_actionstart_triggered()
{
    timer=new QTimer(this);
    timer2=new QTimer(this);
    timer3=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(onTimeout1()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(onTimeout2()));
    timer->start(100);
    timer2->start(200);
    timer3->start(150);
}



void MainWindow::on_actionstop_triggered()
{
    timer->stop();
    timer2->stop();
    timer3->stop();
}


