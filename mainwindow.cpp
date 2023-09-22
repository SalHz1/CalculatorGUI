#include "mainwindow.h"
#include "ui_mainwindow.h"

// Global variable
double firstNum;
bool userIsTypingSecondNumber = false;
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
    connect(ui->pushButtonPercent,SIGNAL(released() ),this,SLOT(unary_operation_pressed())  );
    //binary
    connect(ui->pushButtonAdd,SIGNAL(released() ),this,SLOT(binary_operation_pressed())  );
    connect(ui->pushButtonSubtract,SIGNAL(released() ),this,SLOT(binary_operation_pressed())  );
    connect(ui->pushButtonMultiply,SIGNAL(released() ),this,SLOT(binary_operation_pressed())  );
    connect(ui->pushButtonDivide,SIGNAL(released() ),this,SLOT(binary_operation_pressed())  );

    ui->pushButtonAdd->setCheckable(true);
    ui->pushButtonSubtract->setCheckable(true);
    ui->pushButtonMultiply->setCheckable(true);
    ui->pushButtonDivide->setCheckable(true);
    setFocusPolicy(Qt::StrongFocus);
    currentInput = "";
    setFocus();

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


    currentInput = button->text();
    labelNumber = currentInput.toDouble();
    newLabel = QString::number(labelNumber,'g',15);
    if( ( ui->pushButtonAdd->isChecked()
        || ui->pushButtonDivide->isChecked()
        || ui->pushButtonMultiply->isChecked()
        || ui->pushButtonSubtract->isChecked())
                && (!userIsTypingSecondNumber) )
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.') && button->text() == "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text() ).toDouble();
            newLabel = QString::number(labelNumber,'g',15);

        }
        //This appends the last number pressed to the current number
    }
    //Displays the newLabel number as a string into the label field
    ui->label->setText(newLabel);
}

void MainWindow::digit_pressed(const QString &digit)
{
    double labelNumber;
    QString newLabel;
    qDebug() << "A digit was pressed on the numpad so digit_pressed(const QString &) was called";
    currentInput += digit;
    labelNumber = currentInput.toDouble();
    newLabel = QString::number(labelNumber,'g',15);

    if( ( ui->pushButtonAdd->isChecked()
         || ui->pushButtonDivide->isChecked()
         || ui->pushButtonMultiply->isChecked()
         || ui->pushButtonSubtract->isChecked())
        && (!userIsTypingSecondNumber) )
    {
        labelNumber = digit.toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15);
    }
    else
    {
        if(ui->label->text().contains('.') && digit == "0")
        {
            newLabel = ui->label->text() + digit;
        }
        else
        {
            labelNumber = (ui->label->text() + digit ).toDouble();
            newLabel = QString::number(labelNumber,'g',15);

        }
        //This appends the last number pressed to the current number
    }
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
        ui->label->setText(newLabel);
    }
    if (button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

}

void MainWindow::on_pushButtonClear_released()
{
    ui->pushButtonAdd->setChecked(false);
    ui->pushButtonSubtract->setChecked(false);
    ui->pushButtonMultiply->setChecked(false);
    ui->pushButtonDivide->setChecked(false);
    userIsTypingSecondNumber = false;
    ui->label->setText("0");

}


void MainWindow::on_pushButtonEquals_released()
{
    double labelNumber,secondNumber;
    QString newLabel;
    secondNumber = ui->label->text().toDouble();
    if(ui->pushButtonAdd->isChecked())
    {
        labelNumber = firstNum + secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButtonAdd->setChecked(false); // Adding operation completed so set to false
        qDebug() << "Adding operation was completed";
    }
    else if(ui->pushButtonSubtract->isChecked())
    {
        labelNumber = firstNum - secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButtonSubtract->setChecked(false);
        qDebug() << "Subtraction operation was completed";

    }
    else if(ui->pushButtonDivide->isChecked())
    {
        labelNumber = firstNum / secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButtonDivide->setChecked(false);
        qDebug() << "Divide operation was completed";

    }
    else if(ui->pushButtonMultiply->isChecked())
    {
        labelNumber = firstNum * secondNumber;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButtonMultiply->setChecked(false);
        qDebug() << "Multiply operation was completed";

    }
    //if a user presses the equals button he is not currently typing another number
    userIsTypingSecondNumber = false;

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender(); //get the button pressed
    button->setChecked(true);// set whatever button is checked to true
    firstNum = ui->label->text().toDouble();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "in keyPressEvent";
    //Checking if number is between 0-9
    if(event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9 )
    {
        qDebug() << "Checking number between 0-9";
        QString digit = QString::number(event->key() - Qt::Key_0);
        digit_pressed(digit);
    }
    else if (event->key() == Qt::Key_Minus)
    {
        qDebug() << "minus button pressed";
    }
    else if (event->key() == Qt::Key_Plus)
    {
        qDebug() << "plus button pressed";
    }
    else if (event->key() == Qt::Key_Asterisk)
    {
        qDebug() << "multiply button pressed";
    }
    else if(event->key() == Qt::Key_Equal)
    {
        qDebug() << "Equals button pressed";
    }
    else if(event->key() == Qt::Key_Percent)
    {
        qDebug() << "Percent button pressed";
    }
    else if (event->key() == Qt::Key_Backspace)
    {
        qDebug() << "Backspace pressed.";
        backspace_pressed();
    }
}


void MainWindow::backspace_pressed()
{
    QString currentText = ui->label->text();
    if(!currentText.isEmpty() && currentText != "0" )
    {
        currentText.chop(1);
        if(currentText.isEmpty())
        {
            currentText = "0";
        }
        ui->label->setText(currentText);
        qDebug() << "Backspace deletion completed.";

    }
}

