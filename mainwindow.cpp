#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    create_graf1();
    create_graf2();
    create_graf3();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_graf1(){
    QVector<double> xt(10), yt(10);
    int i=0;
    for (double X = a; X < b; X += h){
        xt[i] =  X;
        yt[i] = (X*X)/(1+X);//Формула нашей функции
        i++;
    }
    i=0;
    xt[9] = b;
    yt[9] = (b*b)/(1+b);
    QVector<double> x(10), y(10);
    for (double X = a; X < b; X += h){
        x[i] = (600 / 3.4) * (xt[i] - a) + 0.4;
        y[i] = 400 - (400 / 2.722) * yt[i];
        i++;
    }
    x[9] = (600 / 3.4) * (xt[9] - a) + 0.4;
    y[9] = 400 - (400 / 2.722) * yt[9];
    ui->myGraf->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->myGraf->addGraph();
    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->myGraf->graph(0)->setData(x, y);
    //Подписываем оси Ox и Oy
    ui->myGraf->xAxis->setLabel("x");
    ui->myGraf->yAxis->setLabel("y");
    //Установим область, которая будет показываться на графике
    //Для оси Ox
    double minX = x[0], maxX = x[0];
    for (int i=0; i<=9; ++i){
        if (x[i]>minX) minX = x[i];
        if (x[i]<maxX) maxX = x[i];
        }
    ui->myGraf->xAxis->setRange(minX, maxX);
    double minY = y[0], maxY = y[0];
    for (int i=0; i<=9; ++i){
    if (y[i]<minY) minY = y[i];
    if (y[i]>maxY) maxY = y[i];
    }
    ui->myGraf->yAxis->setRange(minY, maxY);
    ui->myGraf->yAxis->setVisible(true);
    setVisible(true);
    ui->myGraf->replot();
}

void MainWindow::create_graf2(){
    QVector<double> xt(10), yt(10);
    int i=0;
    for (double X = a; X < b; X += h){
        xt[i] =  X;
        yt[i] = (X*X)/(1+X);
        i++;
    }
    i=0;
    xt[9] = b;
    yt[9] = (b*b)/(1+b);
    QVector<double> x(10), y(10);
    for (double X = a; X < b; X += h){
        x[i] = (600/3.4) * (xt[i] - a) + 0.4;
        y[i] = 0 - (400 / 0.009) * (yt[i]);
        i++;
    }
    x[9] = (600 / 3.4) * (xt[9] - a) + 0.4;
    y[9] = 0 - (400 / 0.009) * (yt[9]);
    ui->myGraf2->clearGraphs();//Если нужно, но очищаем все графики
    //Добавляем один график в widget
    ui->myGraf2->addGraph();
    ui->myGraf2->graph(0)->setData(x, y);
    ui->myGraf2->xAxis->setLabel("x");
    ui->myGraf2->yAxis->setLabel("y");
    ui->myGraf2->xAxis2->setVisible(true);
    double minX = x[0], maxX = x[0];
    for (int i=0; i<=9; ++i){
        if (x[i]>minX) minX = x[i];
        if (x[i]<maxX) maxX = x[i];
        }
    ui->myGraf2->xAxis->setRange(minX, maxX);
    ui->myGraf2->xAxis2->setRange(minX, maxX);
    ui->myGraf2->xAxis2->setVisible(true);
    ui->myGraf2->xAxis->setVisible(false);
    double minY = y[0], maxY = y[0];
    for (int i=0; i<=9; ++i){
    if (y[i]<minY) minY = y[i];
    if (y[i]>maxY) maxY = y[i];
    }
    ui->myGraf2->yAxis->setRange(minY,maxY);
    ui->myGraf2->yAxis->setVisible(true);
    setVisible(true);
    ui->myGraf2->replot();
}

void MainWindow::create_graf3(){
    QVector<double> xt(10), yt(10);
    int i=0;
    for (double X = a; X < b; X += h){
        xt[i] =  X;
        yt[i] = (X*X)/(1+X);
        i++;
    }
    i=0;
    xt[9] = b;
    yt[9] = (b*b)/(1+b);
    QVector<double> x(10), y(10);
    for (double X = a; X < b; X += h){
        x[i] = (600 / 3.4) * (xt[i] - a) + 0.4;
        y[i] = 200 - (400 / 2.713) * yt[i];
        i++;
    }
    x[9] = (600 / 3.4) * (xt[9] - a) + 0.4;
    y[9] = 200 - (400 / 2.713) * yt[9];
    ui->myGraf3->clearGraphs();
    ui->myGraf3->addGraph();
    ui->myGraf3->graph(0)->setData(x, y);
    ui->myGraf3->xAxis->setLabel("x");
    ui->myGraf3->yAxis->setLabel("y");
    double minX = x[i], maxX = x[i];
    for (int i=0; i<=9; ++i){
        if (x[i]>minX) minX = x[i];
        if (x[i]<maxX) maxX = x[i];
        }
    ui->myGraf3->xAxis->setRange(minX, maxX);
    double minY = y[0], maxY = y[0];
    for (int i=0; i<=9; ++i){
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    ui->myGraf3->yAxis->setRange(minY, maxY);
    ui->myGraf3->yAxis->setVisible(true);
    setVisible(true);
    ui->myGraf3->replot();
}

