#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("");// This sets an empty application title, otherwise it will
    //display "MainWindow"
    //Numbers
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
    //Unary operators
    connect(ui->pushButtonplusMinus,SIGNAL(released() ),this,SLOT(unary_operation_pressed())  );

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
    if( !ui->label->text().contains('.') )
    {
        ui->label->setText(ui->label->text() + ".");

    }
}
void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        //ui->label->setText(newLabel);
    }

}
