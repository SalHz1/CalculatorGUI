#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("");// This sets an empty application title, otherwise it will
    //display "MainWindow"
    connect(ui->pushButton_num0,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num1,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num2,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num3,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num4,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num5,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num6,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num7,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num8,SIGNAL(released() ),this,SLOT(digit_pressed() ) );
    connect(ui->pushButton_num9,SIGNAL(released() ),this,SLOT(digit_pressed() ) );

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_pressed()
{

    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    //This appends the last number pressed to the current number
    labelNumber = (ui->label->text() + button->text()).toDouble();
    //Casts double to a string since it is what will be displayed
    newLabel = QString::number(labelNumber,'g',15);
    //Displays the newLabel number as a string into the label field
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

