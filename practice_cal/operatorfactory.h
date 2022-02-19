#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H
#include<string>
#include<map>
#include<functional>
#include<memory>
#include"operator.h"


// 注册Object的宏声明
#define REGISTRAR(T, Key)  Factory::RegisterClass<T> reg_##T(Key);//构造函数：函数名：参数

using namespace std;

class Factory {
public:
    template<typename T>
    struct RegisterClass {//嵌套类，用起来比较方便，相当于在一个大类里实现一个小的功能
        RegisterClass(string opr) {
            Factory::ms_operator.emplace(opr, [] {return make_shared<T>(); });//向map中插入：关键字为string,值为用lambda初始化的function对象
        }//lamda表达式结构清晰，可读性强，代码可以重用//////构造表的时候不需要指针值，所以应用lama。
    };

    static shared_ptr<Operator> create(string opr) {
        auto it = ms_operator.find(opr);
        if (it != ms_operator.end())
            return it->second();//返回的相当于上面的lamda表达式
    }
    //private:
    static map<string, function<shared_ptr<Operator>()>> ms_operator; // 存储已注册运算符名及对应构建函数指针的map
};                     //函数对象

#endif // OPERATORFACTORY_H
