#include "calculator.h"
#include "operatorfactory.h"
// 读取操作数
double Calculator::readNum(const vector<string> &calcu,size_t &i) {
    //string t;
    while (isNum(calcu,i)){
        if(calcu[i]=="pi")return (std::atan(1.0) * 4);
        else if(calcu[i]=="e"){
            double e=1.0,n=1.0;
            int i=1;
            while(1/n>1e-10){
                e+=1/n;
                i++;
                n=i*n;
             }
        return e;
         }
    int dot=0;
    for(size_t j=0;j<calcu[i].size();j++){
        if(calcu[i][j]=='.')dot+=1;
        }
    if(dot>1)throw string("error1");
    return stod(calcu[i]);
    }
}

int Calculator::isRight(const vector<string>& calcu){
    int is=1,left=0,right=0;
    for(size_t i=0;i<calcu.size();i++){
        if((i!=0 && i!=calcu.size()-2)&&(calcu[i]=="+"||calcu[i]=="-"||calcu[i]=="*"||calcu[i]=="/"||calcu[i]=="^"||calcu[i]=="%")){
            if(calcu[i+1]=="+"||calcu[i+1]=="-"||calcu[i+1]=="*"||calcu[i+1]=="/"||calcu[i+1]=="^"||calcu[i+1]=="%"){
            is=0;
            return is;
            }
            if(!(calcu[i-1][0]>='0'&&calcu[i-1][0]<='9'||calcu[i-1][0] == '.'||calcu[i-1][0]=='e'||calcu[i-1]=="pi"||calcu[i-1]==")")){
                is=0;return is;
            }
            if(calcu[i+1]==")"){
                is=0;return is;
            }

        }
        if((i==0||i==calcu.size()-2)&&(calcu[i]=="+"||calcu[i]=="-"||calcu[i]=="*"||calcu[i]=="/"||calcu[i]=="^"||calcu[i]=="%")){
            is=0;return is;
        }
        if(calcu[i]=="("){
            left+=1;
            if(i!=0){
                if(calcu[i-1][0]>='0'&&calcu[i-1][0]<='9'||calcu[i-1][0] == '.'||calcu[i-1][0]=='e'||calcu[i-1]=="pi"){
                    is=0;
                    return is;
                }
            }
        }
        if(calcu[i]==")"){
            if(right<left)
                right+=1;
            else {is=0;return is;}
            if(i!=calcu.size()-2){
                if(calcu[i+1][0]>='0'&&calcu[i+1][0]<='9'||calcu[i+1][0] == '.'||calcu[i+1][0]=='e'||calcu[i+1]=="pi"){
                    is=0;
                    return is;
                }
            }
        }
    }//for
    if(left!=right)is=0;
    return is;
}

// 动作, 使用运算符栈和操作数栈顶的元素进行计算
void Calculator::calculate() {
    // 操作数出栈并传入Operator进行计算, 在此只考虑单目和双目运算符
    double a[2] = { 0 };
    for (auto i = 0; i < m_opr.top()->numOprand(); ++i) {
        a[i] = m_num.top();
        m_num.pop();
    }
    m_num.push(m_opr.top()->get(a[1], a[0]));
    m_opr.pop();
}



double Calculator::doIt(const vector<string>& calcu){
    if(isRight(calcu)==0) throw string("error");
    else{
    for(size_t i=0;i<calcu.size();i++){
        if (isNum(calcu,i)){
                m_num.push(readNum(calcu,i));
        }
        else{
            auto oo=Factory::create(calcu[i]);
            if(oo->symbol()=="(")m_opr.push(Factory::create("#"));
            else if(oo->symbol()==")"){
                while(m_opr.top()->symbol()!="#")calculate();
                m_opr.pop();
            }
            else{
                while(oo->precedence()<=m_opr.top()->precedence()){
                    if(m_opr.top()->symbol()=="#")break;
                    calculate();
                }
                if(oo->symbol()!="=")m_opr.push(oo);
            }
        }
    }
    double result=m_num.top();
    m_num.pop();
    return result;

}
}
