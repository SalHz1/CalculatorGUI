#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString currentInput;
private slots:
    void digit_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void binary_operation_pressed();
    void on_pushButtonEquals_released();
    void on_pushButtonClear_released();
    void backspace_pressed();
    void digit_pressed(const QString &);
    void binary_operation_pressed(char);
protected:
    void keyPressEvent(QKeyEvent *);

 };
#endif // MAINWINDOW_H
