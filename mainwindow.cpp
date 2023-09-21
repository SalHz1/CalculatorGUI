#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("");// This sets an empty application title, otherwise it will
    //display "MainWindow"


}

MainWindow::~MainWindow()
{
    delete ui;
}

