#pragma once

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double a = 0.1;
    double b =  3.5;
    double h = 0.4;

private slots:

    void create_graf1();
    void create_graf2();
    void create_graf3();


private:
    Ui::MainWindow *ui;
};
