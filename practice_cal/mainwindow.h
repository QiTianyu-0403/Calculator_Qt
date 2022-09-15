#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <calculator.h>
#include "QPushButton"
#include "QLineEdit"
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//signals:
    //void expression(const vector<string>& calcu);

public slots:

    void button_0();
    void button_1();
    void button_2();
    void button_3();
    void button_4();
    void button_5();
    void button_6();
    void button_7();
    void button_8();
    void button_9();
    void button_pi();
    void button_e();
    void button_dot();
    void button_plus();
    void button_minus();
    void button_multiply();
    void button_divide();
    void button_pow();
    void button_mod();
    void button_sin();
    void button_cos();
    void button_tan();
    void button_sqrt();
    void button_log();
    void button_ln();
    void button_reciprocal();
    void button_factorial();
    void button_nagative();
    void button_equal();
    void button_left();
    void button_right();
    void button_clear();
    void button_clearnum();
    void button_delete();

    void ButtonSquare();
    void Button10PowX();
    void ButtonExp();
    //void ButtonXPowY();
    void ButtonAbs();


private:

    QPushButton* m_0;
    QPushButton* m_1;
    QPushButton* m_2;
    QPushButton* m_3;
    QPushButton* m_4;
    QPushButton* m_5;
    QPushButton* m_6;
    QPushButton* m_7;
    QPushButton* m_8;
    QPushButton* m_9;
    QPushButton* m_pi;
    QPushButton* m_e;
    QPushButton* m_dot;
    QPushButton* m_plus;
    QPushButton* m_minus;
    QPushButton* m_multiply;
    QPushButton* m_divide;
    QPushButton* m_pow;
    QPushButton* m_mod;
    QPushButton* m_sin;
    QPushButton* m_cos;
    QPushButton* m_tan;
    QPushButton* m_sqrt;
    QPushButton* m_log;
    QPushButton* m_ln;
    QPushButton* m_reciprocal;
    QPushButton* m_factorial;
    QPushButton* m_nagative;
    QPushButton* m_equal;
    QPushButton* m_left;
    QPushButton* m_right;
    QPushButton* m_clear;
    QPushButton* m_clearnum;
    QPushButton* m_delete;

    QPushButton* m_pbuttonSquare;
    QPushButton* m_pbutton10PowX;
    QPushButton* m_pbuttonAbs;
    QPushButton* m_pbuttonExp;


    QLineEdit *m_in;
    QLineEdit *m_out;
    QLineEdit *m_history;
    Factory m_fact;
    Calculator m_cal;


};
#endif // MAINWINDOW_H
