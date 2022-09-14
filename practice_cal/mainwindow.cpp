#include "mainwindow.h"
#include <QLayout>
#include <QVector>
#include <QString>
#include <QToolTip>
#include <QStackedLayout>
string text;
string g_strText;

vector<string> calcu;
string history;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Factory::RegisterClass<Hash> reg_Hash("#");
    REGISTRAR(Plus,"+")
    REGISTRAR(Minus,"-")
    REGISTRAR(Multiply,"*")
    REGISTRAR(Divide,"/")
    REGISTRAR(Equal,"=")
    REGISTRAR(Pow,"^")
    REGISTRAR(Mod,"%")
    REGISTRAR(Sin,"sin")
    REGISTRAR(Tan,"tan")
    REGISTRAR(Cos,"cos")
    REGISTRAR(Sqrt,"sqrt")
    REGISTRAR(Log,"log")
    REGISTRAR(Ln,"ln")
    REGISTRAR(Reciprocal,"rec")
    REGISTRAR(Factorial,"fact")
    REGISTRAR(Nagative,"~")
    REGISTRAR(Left,"(")
    REGISTRAR(Right,")")
    REGISTRAR(Square, "x^2")
    REGISTRAR(Abs, "|x|")
    REGISTRAR(Exp, "exp(x)")

    m_0=new QPushButton("0",this);
    m_1=new QPushButton("1",this);
    m_2=new QPushButton("2",this);
    m_3=new QPushButton("3",this);
    m_4=new QPushButton("4",this);
    m_5=new QPushButton("5",this);
    m_6=new QPushButton("6",this);
    m_7=new QPushButton("7",this);
    m_8=new QPushButton("8",this);
    m_9=new QPushButton("9",this);
    m_pi=new QPushButton("pi",this);
    m_e=new QPushButton("e",this);
    m_dot=new QPushButton(".",this);
    m_plus=new QPushButton("+",this);
    m_minus=new QPushButton("-",this);
    m_multiply=new QPushButton("*",this);
    m_divide=new QPushButton("/",this);
    m_pow=new QPushButton("^",this);
    m_mod=new QPushButton("Mod",this);
    m_sin=new QPushButton("sin",this);
    m_cos=new QPushButton("cos",this);
    m_tan=new QPushButton("tan",this);
    m_sqrt=new QPushButton("sqrt",this);
    m_log=new QPushButton("log",this);
    m_ln=new QPushButton("ln",this);
    m_reciprocal=new QPushButton("1/x",this);
    m_factorial=new QPushButton("n!",this);
    m_nagative=new QPushButton("+/-",this);
    m_equal=new QPushButton("=",this);
    m_left=new QPushButton("(",this);
    m_right=new QPushButton(")",this);
    m_clear=new QPushButton("AC",this);
    m_clearnum=new QPushButton("CE",this);
    m_delete=new QPushButton("<——",this);

    m_pbuttonSquare = new QPushButton("x^2", this);
    m_pbuttonAbs = new QPushButton("|x|", this);
    m_pbuttonExp = new QPushButton("exp(x)", this);
    //m_pbuttonSquare = new QPushButton(" ", this);
    //m_pbuttonSquare = new QPushButton(" ", this);

    m_in=new QLineEdit(this);
    m_out=new QLineEdit(this);
    m_history=new QLineEdit(this);
    m_in->setReadOnly(true);
    m_in->setAlignment(Qt::AlignRight);
    m_in->setFrame(false);
    m_out->setReadOnly(true);
    m_out->setAlignment(Qt::AlignRight);
    m_out->setFrame(false);
    m_history->setReadOnly(true);
    m_history->setAlignment(Qt::AlignRight);
    m_history->setFrame(false);


    m_clear->setStyleSheet("color:blue");
    m_clearnum->setStyleSheet("color:blue");
    m_delete->setStyleSheet("color:blue");

    m_0->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_4->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_5->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_6->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_7->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_8->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_9->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_pi->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_e->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_plus->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_minus->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_multiply->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_divide->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_pow->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_mod->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_sin->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_cos->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_tan->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_sqrt->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_log->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_ln->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_reciprocal->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_factorial->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_nagative->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_equal->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_left->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_right->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_dot->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_clear->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_clearnum->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_delete->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    //m_in->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    //m_out->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


    m_0->setShortcut(QKeySequence(Qt::Key_0));
    m_1->setShortcut(QKeySequence(Qt::Key_1));
    m_2->setShortcut(QKeySequence(Qt::Key_2));
    m_3->setShortcut(QKeySequence(Qt::Key_3));
    m_4->setShortcut(QKeySequence(Qt::Key_4));
    m_5->setShortcut(QKeySequence(Qt::Key_5));
    m_6->setShortcut(QKeySequence(Qt::Key_6));
    m_7->setShortcut(QKeySequence(Qt::Key_7));
    m_8->setShortcut(QKeySequence(Qt::Key_8));
    m_9->setShortcut(QKeySequence(Qt::Key_9));
    m_e->setShortcut(QKeySequence(Qt::Key_E));
    m_clear->setShortcut(QKeySequence(Qt::Key_C));
    m_dot->setShortcut(QKeySequence(Qt::Key_Period));
    m_plus->setShortcut(QKeySequence(Qt::Key_Plus));
    m_minus->setShortcut(QKeySequence(Qt::Key_Minus));
    m_multiply->setShortcut(QKeySequence(Qt::Key_Asterisk));
    m_divide->setShortcut(QKeySequence(Qt::Key_Slash));
    m_equal->setShortcut(QKeySequence(Qt::Key_Equal));
    m_left->setShortcut(QKeySequence(Qt::Key_ParenLeft));
    m_right->setShortcut(QKeySequence(Qt::Key_ParenRight));
    m_delete->setShortcut(QKeySequence(Qt::Key_Backspace));

    m_in->setFixedHeight(50);
    m_out->setFixedHeight(50);
    m_history->setFixedHeight(30);
    m_0->setFixedHeight(30);
    m_1->setFixedHeight(30);
    m_2->setFixedHeight(30);
    m_3->setFixedHeight(30);
    m_4->setFixedHeight(30);
    m_5->setFixedHeight(30);
    m_6->setFixedHeight(30);
    m_7->setFixedHeight(30);
    m_8->setFixedHeight(30);
    m_9->setFixedHeight(30);
    m_pi->setFixedHeight(30);
    m_e->setFixedHeight(30);
    m_plus->setFixedHeight(30);
    m_minus->setFixedHeight(30);
    m_multiply->setFixedHeight(30);
    m_divide->setFixedHeight(30);
    m_pow->setFixedHeight(30);
    m_mod->setFixedHeight(30);
    m_sin->setFixedHeight(30);
    m_cos->setFixedHeight(30);
    m_tan->setFixedHeight(30);
    m_sqrt->setFixedHeight(30);
    m_log->setFixedHeight(30);
    m_ln->setFixedHeight(30);
    m_reciprocal->setFixedHeight(30);
    m_factorial->setFixedHeight(30);
    m_nagative->setFixedHeight(30);
    m_equal->setFixedHeight(30);
    m_equal->setFixedWidth(156);
    m_left->setFixedHeight(30);
    m_right->setFixedHeight(30);
    m_dot->setFixedHeight(30);
    m_clear->setFixedHeight(30);
    m_clearnum->setFixedHeight(30);
    m_delete->setFixedHeight(30);

    //m_0->setStyleSheet("QPushButton{font-family:'宋体';font-size:32px;color:rgb(0,0,0,255);}\QPushButton{background-color:rgb(170,200,50)}\ QPushButton:hover{background-color:rgb(50, 170, 200)}");
    QFont num_font;
    num_font.setFamily("黑体");
    num_font.setPointSize(18);
    num_font.setWeight((QFont::Weight)50);
    m_0->setFont(num_font);
    m_1->setFont(num_font);
    m_2->setFont(num_font);
    m_3->setFont(num_font);
    m_4->setFont(num_font);
    m_5->setFont(num_font);
    m_6->setFont(num_font);
    m_7->setFont(num_font);
    m_8->setFont(num_font);
    m_9->setFont(num_font);
    QFont opr_font;
    opr_font.setFamily("黑体");
    opr_font.setPointSize(10);
    opr_font.setWeight((QFont::Weight)20);
    m_pi->setFont(opr_font);
    m_e->setFont(opr_font);
    m_plus->setFont(opr_font);
    m_minus->setFont(opr_font);
    m_multiply->setFont(opr_font);
    m_divide->setFont(opr_font);
    m_clear->setFont(opr_font);
    m_log->setFont(opr_font);
    m_ln->setFont(opr_font);
    m_mod->setFont(opr_font);
    m_sin->setFont(opr_font);
    m_cos->setFont(opr_font);
    m_tan->setFont(opr_font);
    m_sqrt->setFont(opr_font);
    m_delete->setFont(opr_font);
    m_reciprocal->setFont(opr_font);
    m_factorial->setFont(opr_font);
    m_clearnum->setFont(opr_font);
    m_nagative->setFont(opr_font);
    m_left->setFont(opr_font);
    m_right->setFont(opr_font);
    m_dot->setFont(opr_font);
    m_pow->setFont(opr_font);
    QFont line1_font;
    line1_font.setFamily("黑体");
    line1_font.setPointSize(10);
    line1_font.setWeight((QFont::Weight)20);
    m_history->setFont(line1_font);
    m_in->setFont(line1_font);
    QFont line2_font;
    line2_font.setFamily("黑体");
    line2_font.setPointSize(30);
    line2_font.setWeight((QFont::Weight)50);
    m_out->setFont(line2_font);




    QHBoxLayout *bottom_1=new QHBoxLayout;
    bottom_1->addWidget(m_reciprocal);
    bottom_1->addWidget(m_factorial);
    bottom_1->addWidget(m_clear);
    bottom_1->addWidget(m_clearnum);
    bottom_1->addWidget(m_delete);

    QHBoxLayout *pboxlayoutRow1 = new QHBoxLayout;
    pboxlayoutRow1->addWidget(m_pbuttonSquare);
    pboxlayoutRow1->addWidget(m_pbuttonAbs);
    pboxlayoutRow1->addWidget(m_pbuttonExp);

    QHBoxLayout *bottom_2=new QHBoxLayout;
    bottom_2->addWidget(m_mod);
    bottom_2->addWidget(m_log);
    bottom_2->addWidget(m_ln);
    bottom_2->addWidget(m_e);
    bottom_2->addWidget(m_pow);

    QHBoxLayout *bottom_3=new QHBoxLayout;
    bottom_3->addWidget(m_sqrt);
    bottom_3->addWidget(m_left);
    bottom_3->addWidget(m_right);
    bottom_3->addWidget(m_pi);
    bottom_3->addWidget(m_plus);

    QHBoxLayout *bottom_4=new QHBoxLayout;
    bottom_4->addWidget(m_sin);
    bottom_4->addWidget(m_7);
    bottom_4->addWidget(m_8);
    bottom_4->addWidget(m_9);
    bottom_4->addWidget(m_minus);

    QHBoxLayout *bottom_5=new QHBoxLayout;
    bottom_5->addWidget(m_cos);
    bottom_5->addWidget(m_4);
    bottom_5->addWidget(m_5);
    bottom_5->addWidget(m_6);
    bottom_5->addWidget(m_multiply);

    QHBoxLayout *bottom_6=new QHBoxLayout;
    bottom_6->addWidget(m_tan);
    bottom_6->addWidget(m_1);
    bottom_6->addWidget(m_2);
    bottom_6->addWidget(m_3);
    bottom_6->addWidget(m_divide);

    QHBoxLayout *bottom_7=new QHBoxLayout;
    bottom_7->addWidget(m_nagative);
    bottom_7->addWidget(m_dot);
    bottom_7->addWidget(m_0);
    bottom_7->addWidget(m_equal);



    QVBoxLayout *bottom=new QVBoxLayout;
    bottom->addLayout(bottom_1);
    bottom->addLayout(pboxlayoutRow1);
    bottom->addLayout(bottom_2);
    bottom->addLayout(bottom_3);
    bottom->addLayout(bottom_4);
    bottom->addLayout(bottom_5);
    bottom->addLayout(bottom_6);
    bottom->addLayout(bottom_7);

    QVBoxLayout *top=new QVBoxLayout;
    top->addWidget(m_history);
    top->addWidget(m_in);
    top->addWidget(m_out);
    QVBoxLayout *mainbox=new QVBoxLayout;
    mainbox->addLayout(top);
    mainbox->addLayout(bottom);

    QWidget* widget=new QWidget(this);
    widget->setLayout(mainbox);
    this->setCentralWidget(widget);
    setWindowTitle("齐天宇的Calculator");



    connect(m_0,&QPushButton::clicked,this,&MainWindow::button_0);
    connect(m_1,&QPushButton::clicked,this,&MainWindow::button_1);
    connect(m_2,&QPushButton::clicked,this,&MainWindow::button_2);
    connect(m_3,&QPushButton::clicked,this,&MainWindow::button_3);
    connect(m_4,&QPushButton::clicked,this,&MainWindow::button_4);
    connect(m_5,&QPushButton::clicked,this,&MainWindow::button_5);
    connect(m_6,&QPushButton::clicked,this,&MainWindow::button_6);
    connect(m_7,&QPushButton::clicked,this,&MainWindow::button_7);
    connect(m_8,&QPushButton::clicked,this,&MainWindow::button_8);
    connect(m_9,&QPushButton::clicked,this,&MainWindow::button_9);
    connect(m_pi,&QPushButton::clicked,this,&MainWindow::button_pi);
    connect(m_e,&QPushButton::clicked,this,&MainWindow::button_e);
    connect(m_dot,&QPushButton::clicked,this,&MainWindow::button_dot);
    connect(m_plus,&QPushButton::clicked,this,&MainWindow::button_plus);
    connect(m_minus,&QPushButton::clicked,this,&MainWindow::button_minus);
    connect(m_multiply,&QPushButton::clicked,this,&MainWindow::button_multiply);
    connect(m_divide,&QPushButton::clicked,this,&MainWindow::button_divide);
    connect(m_pow,&QPushButton::clicked,this,&MainWindow::button_pow);
    connect(m_mod,&QPushButton::clicked,this,&MainWindow::button_mod);
    connect(m_sin,&QPushButton::clicked,this,&MainWindow::button_sin);
    connect(m_cos,&QPushButton::clicked,this,&MainWindow::button_cos);
    connect(m_tan,&QPushButton::clicked,this,&MainWindow::button_tan);
    connect(m_sqrt,&QPushButton::clicked,this,&MainWindow::button_sqrt);
    connect(m_log,&QPushButton::clicked,this,&MainWindow::button_log);
    connect(m_ln,&QPushButton::clicked,this,&MainWindow::button_ln);
    connect(m_reciprocal,&QPushButton::clicked,this,&MainWindow::button_reciprocal);
    connect(m_factorial,&QPushButton::clicked,this,&MainWindow::button_factorial);
    connect(m_nagative,&QPushButton::clicked,this,&MainWindow::button_nagative);
    connect(m_equal,&QPushButton::clicked,this,&MainWindow::button_equal);
    connect(m_left,&QPushButton::clicked,this,&MainWindow::button_left);
    connect(m_right,&QPushButton::clicked,this,&MainWindow::button_right);
    connect(m_clear,&QPushButton::clicked,this,&MainWindow::button_clear);
    connect(m_clearnum,&QPushButton::clicked,this,&MainWindow::button_clearnum);
    connect(m_delete,&QPushButton::clicked,this,&MainWindow::button_delete);

    connect(m_pbuttonSquare, &QPushButton::clicked, this, &MainWindow::ButtonSquare);
    connect(m_pbuttonAbs, &QPushButton::clicked, this, &MainWindow::ButtonAbs);
    connect(m_pbuttonExp, &QPushButton::clicked, this, &MainWindow::ButtonExp);

    //connect(this,&MainWindow::expression,&m_cal,&Calculator::doIt);
    //connect(&m_cal,&Calculator::sendresult,m_out,&QLineEdit::setText);

}

MainWindow::~MainWindow()
{
    delete m_0;
    delete m_1;
    delete m_2;
    delete m_3;
    delete m_4;
    delete m_5;
    delete m_6;
    delete m_7;
    delete m_8;
    delete m_9;
    delete m_pi;
    delete m_e;
    delete m_dot;
    delete m_plus;
    delete m_minus;
    delete m_multiply;
    delete m_divide;
    delete m_pow;
    delete m_mod;
    delete m_sin;
    delete m_cos;
    delete m_tan;
    delete m_sqrt;
    delete m_log;
    delete m_ln;
    delete m_reciprocal;
    delete m_factorial;
    delete m_nagative;
    delete m_clear;
    delete m_clearnum;
    delete m_delete;
    delete m_equal;
    delete m_left;
    delete m_right;
    delete m_in;
    delete m_out;
    delete m_history;
}

void MainWindow::button_0(){
    text+="0";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='0';
        else calcu.push_back("0");
    }
    else calcu.push_back("0");
}

void MainWindow::button_1(){
    text+="1";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='1';
        else calcu.push_back("1");
    }
    else calcu.push_back("1");
}

void MainWindow::button_2(){
    text+="2";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='2';
        else calcu.push_back("2");
    }
    else calcu.push_back("2");
}

void MainWindow::button_3(){
    text+="3";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='3';
        else calcu.push_back("3");
    }
    else calcu.push_back("3");
}

void MainWindow::button_4(){
    text+="4";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='4';
        else calcu.push_back("4");
    }
    else calcu.push_back("4");
}

void MainWindow::button_5(){
    text+="5";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='5';
        else calcu.push_back("5");
    }
    else calcu.push_back("5");
}

void MainWindow::button_6(){
    text+="6";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='6';
        else calcu.push_back("6");
    }
    else calcu.push_back("6");
}

void MainWindow::button_7(){
    text+="7";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='7';
        else calcu.push_back("7");
    }
    else calcu.push_back("7");
}

void MainWindow::button_8(){
    text+="8";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='8';
        else calcu.push_back("8");
    }
    else calcu.push_back("8");
}

void MainWindow::button_9(){
    text+="9";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='9';
        else calcu.push_back("9");
    }
    else calcu.push_back("9");
}

void MainWindow::button_pi(){
    text+="pi";
    calcu.push_back("pi");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_e(){
    text+="e";
    calcu.push_back("e");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_dot(){
    text+=".";
    m_in->setText(QString::fromStdString(text));
    if(calcu.size()>0){
        bool pr=0;
        for(size_t i=0;i<calcu[calcu.size()-1].size();i++){
            char a=calcu[calcu.size()-1][i];
            if(!((a>='0'&&a<='9')||a=='.'))pr=1;
        }
        if(pr==0)calcu[calcu.size()-1]+='.';
        else calcu.push_back(".");
    }
    else calcu.push_back(".");
}

void MainWindow::button_plus(){
    text+="+";
    calcu.push_back("+");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_minus(){
    text+="-";
    calcu.push_back("-");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_multiply(){
    text+="*";
    calcu.push_back("*");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_divide(){
    text+="/";
    calcu.push_back("/");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_pow(){
    text+="^";
    calcu.push_back("^");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_mod(){
    text+="%";
    calcu.push_back("%");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_sin(){
    text+="sin(";
    calcu.push_back("sin");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_cos(){
    text+="cos(";
    calcu.push_back("cos");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_tan(){
    text+="tan(";
    calcu.push_back("tan");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_sqrt(){
    text+="sqrt(";
    calcu.push_back("sqrt");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_log(){
    text+="log(";
    calcu.push_back("log");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_ln(){
    text+="ln(";
    calcu.push_back("ln");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_reciprocal(){
    text+="rec(";
    calcu.push_back("rec");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_factorial(){
    text+="fact(";
    calcu.push_back("fact");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_nagative(){
    text+="-";
    calcu.push_back("~");
    m_in->setText(QString::fromStdString(text));
}



void MainWindow::button_equal(){
    text+="=";
    string b;
    QString c;
    calcu.push_back("=");
    double hist;
    m_in->setText(QString::fromStdString(text));
    try {
       hist=m_cal.doIt(calcu);
       m_out->setText(QString::number(hist));
       history=text;
       history+=c.setNum(hist).toStdString();
    } catch (string a) {
        m_out->setText(QString::fromStdString(a));
        QToolTip::showText(m_in->mapToGlobal(QPoint(100, 0)), "输入格式错误！");
        m_in->setStyleSheet("QLineEdit{border:1px solid red }");
    }
}


void MainWindow::button_left(){
    text+="(";
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));

}

void MainWindow::button_right(){
    text+=")";
    calcu.push_back(")");
    m_in->setText(QString::fromStdString(text));

}

void MainWindow::button_clear(){
    m_in->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
    string s,r;
    r+='0';
    text=s;
    m_in->setText(QString::fromStdString(text));
    m_out->setText(QString::fromStdString(r));
    m_history->setText(QString::fromStdString(history));
    calcu.clear();
}

void MainWindow::button_clearnum(){
    m_in->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
    size_t t=0;
    if(calcu.size()>0&&(calcu[calcu.size()-1][0]>='0'&&calcu[calcu.size()-1][0]<='9'||calcu[calcu.size()-1][0] == '.'||calcu[calcu.size()-1][0]=='e'||calcu[calcu.size()-1]=="pi")){
        t=calcu[calcu.size()-1].size();
        calcu.pop_back();
    }
    for(size_t i=0;i<t;i++){
        text.pop_back();
    }
          m_in->setText(QString::fromStdString(text));
}

void MainWindow::button_delete(){
    m_in->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
    string s;
    if(text.size()>0){
        if(calcu[calcu.size()-1]=="pi"||calcu[calcu.size()-1]=="sin"||calcu[calcu.size()-1]=="cos"||calcu[calcu.size()-1]=="tan"||calcu[calcu.size()-1]=="sqrt"||calcu[calcu.size()-1]=="fact"||calcu[calcu.size()-1]=="rec"||calcu[calcu.size()-1]=="log"||calcu[calcu.size()-1]=="ln"){
            for(size_t i=0;i<text.size()-calcu[calcu.size()-1].size();i++){
                s+=text[i];
            }
        }
        else{
            for(size_t i=0;i<text.size()-1;i++){
                s+=text[i];
            }
        }
        text=s;
        m_in->setText(QString::fromStdString(text));
        if(calcu[calcu.size()-1].size()>1){
            if(calcu[calcu.size()-1]=="pi"||calcu[calcu.size()-1]=="sin"||calcu[calcu.size()-1]=="cos"||calcu[calcu.size()-1]=="tan"||calcu[calcu.size()-1]=="sqrt"||calcu[calcu.size()-1]=="fact"||calcu[calcu.size()-1]=="rec"||calcu[calcu.size()-1]=="log"||calcu[calcu.size()-1]=="ln")calcu.pop_back();
            else calcu[calcu.size()-1].pop_back();
        }
        else {
            calcu.pop_back();
        }
    }
}

void MainWindow::ButtonSquare()
{
    QString qstrTextSrc;
    QString qstrTextDst;
    qstrTextSrc = m_in->text();
    double dResult = qstrTextSrc.toDouble();
    dResult = dResult * dResult;
    QTextStream(&qstrTextDst) << dResult;
    m_out->setText(qstrTextDst);
}

void MainWindow::ButtonAbs()
{
    text+="rec(";
    calcu.push_back("rec");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}

void MainWindow::ButtonExp()
{
    text+="rec(";
    calcu.push_back("rec");
    calcu.push_back("(");
    m_in->setText(QString::fromStdString(text));
}
//m_in->setStyleSheet("QLineEdit{border:1px solid gray border-radius:1px}");
//string s;
//if(text.size()>0){
    //for(size_t i=0;i<text.size()-1;i++){
      //  s+=text[i];
    //}
    //text=s;
    //m_in->setText(QString::fromStdString(text));
    //if(calcu[calcu.size()-1].size()>1){
        //if(calcu[calcu.size()-1]=="pi")calcu.pop_back();
      //  calcu[calcu.size()-1].pop_back();
    //}
    //else {
    //    calcu.pop_back();
  //  }
//}
