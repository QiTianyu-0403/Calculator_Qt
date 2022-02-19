#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>
#include <memory>
#include "operator.h"
#include "stack.h"
#include"operatorfactory.h"
#include<QObject>
class Calculator{

private:
    Stack<double> m_num; // 数字栈
    Stack<shared_ptr<Operator>> m_opr; // 运算符栈
    double readNum(const vector<string> &calcu,size_t &i); 	// 读取操作数
    bool isNum(const vector<string> &calcu,size_t &i) { // 判断字符是否为数字
        return calcu[i][0] >= '0' && calcu[i][0] <= '9' || calcu[i][0] == '.'||calcu[i][0]=='e'||calcu[i]=="pi";
    }
    void calculate();
    int isRight(const vector<string>& calcu);
public:
    Calculator() { m_opr.push(make_shared<Hash>()); }
public:
    double doIt(const vector<string>& calcu);
//signals:
    //void sendresult(const QString& text);
};

#endif // CALCULATOR_H
