#ifndef OPERATOR_H
#define OPERATOR_H
#include<string>
#include<math.h>
using namespace std;
class Operator {
public:
    Operator(string c, int numOprd, int pre) :m_symbol(c), m_numOprand(numOprd), m_precedence(pre) { }
    string symbol() const { return m_symbol; }
    int numOprand() const { return m_numOprand; }
    int precedence() const { return m_precedence; }
    virtual double get(double a, double b) const = 0;
    virtual ~Operator() {}
protected:
    const string m_symbol; // 运算符符号
    const int m_numOprand;  // 运算符目数
    const int m_precedence;
};

class Plus : public Operator { // 运算符+
public:
    Plus() :Operator("+", 2, 2) {}
    double get(double a, double b) const {
        return a + b;
    }
};

class Minus :public Operator { // 运算符-
public:
    Minus() :Operator("-", 2, 2) {}
    double get(double a, double b) const {
        return a - b;
    }
};

class Multiply :public Operator { // 运算符*
public:
    Multiply() :Operator("*", 2, 3) {}
    double get(double a, double b) const {
        return a * b;
    }
};


class Divide :public Operator { // 运算符/
public:
    Divide() :Operator("/", 2, 3) {}
    double get(double a, double b) const {
        if(b==0){throw string("error2");}
        return a / b;
    }
};


class Hash :public Operator { // 运算符#
public:
    Hash() :Operator("#", 1, 1) {}
    double get(double a, double b) const {
        return a; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Left :public Operator { // 运算符#
public:
    Left() :Operator("(", 0, 0) {}
    double get(double a, double b) const {
        return a; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Right :public Operator { // 运算符#
public:
    Right() :Operator(")", 0, 0) {}
    double get(double a, double b) const {
        return a; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Pow :public Operator { // 运算符#
public:
    Pow() :Operator("pow", 2, 4) {}
    double get(double a, double b) const {
        return pow(a,b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Mod :public Operator { // 运算符#
public:
    Mod() :Operator("%", 2, 3) {}
    double get(double a, double b) const {
        return int(a)%int(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Sin :public Operator { // 运算符#
public:
    Sin() :Operator("sin", 1, 5) {}
    double get(double a, double b) const {
        return sin(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};




class Cos :public Operator { // 运算符#
public:
    Cos() :Operator("cos", 1, 5) {}
    double get(double a, double b) const {
        return cos(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Tan :public Operator { // 运算符#
public:
    Tan() :Operator("tan", 1, 5) {}
    double get(double a, double b) const {
        if(b==(std::atan(1.0) * 4)/2)throw string("error2");
        return tan(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Sqrt :public Operator { // 运算符#
public:
    Sqrt() :Operator("sqrt", 1, 5) {}
    double get(double a, double b) const {
        return sqrt(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Log :public Operator { // 运算符#
public:
    Log() :Operator("log", 1, 5) {}
    double get(double a, double b) const {
        return log10(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Ln :public Operator { // 运算符#
public:
    Ln() :Operator("ln", 1, 5) {}
    double get(double a, double b) const {
        return log(b); // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Reciprocal :public Operator { // 运算符#
public:
    Reciprocal() :Operator("rec", 1, 5) {}
    double get(double a, double b) const {
        return 1/b; // 本身#不需要进行任何运算, 但是仍然需要返回值
    }
};

class Factorial :public Operator { // 运算符#
public:
    Factorial() :Operator("fact", 1, 5) {}
    double get(double a, double b) const {
        int i=0,sum=1;
        for(i=1;i<=(int)b;i++){
            sum*=i;
        }
        return sum;
    }
};

class Nagative :public Operator { // 运算符#
public:
    Nagative() :Operator("~", 1, 5) {}
    double get(double a, double b) const {
        return -b;
    }
};



class Equal :public Operator { //表达式结束符=
public:
    Equal() :Operator("=", 2, 0) {}
    double get(double a, double b) const {
        return a;
    }
};

#endif // OPERATOR_H
