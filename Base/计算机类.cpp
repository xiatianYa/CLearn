#include <iostream>
using namespace std;

class Calculator {
public:
    int getResult(string oper) const{
        if (oper == "+") {
            return m_Num1 + m_Num2;
        }
        if (oper == "-") {
            return m_Num1 - m_Num2;
        }
        if (oper == "*") {
            return m_Num1 * m_Num2;
        }
        if (oper == "/") {
            return m_Num1 / m_Num2;
        }
        return 0;
    }

    int m_Num1;
    int m_Num2;
};

//实现计算机抽象类
class AbstractCalculator {
public:
    virtual int getResult() {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//加法计算器类
class AddCalculator:public AbstractCalculator {
    public:
    int getResult() {
        return m_Num1 + m_Num2;
    }
};

//减法计算器类
class SubCalculator:public AbstractCalculator {
    public:
    int getResult() {
        return m_Num1 - m_Num2;
    }
};

//乘法计算器类
class MulCalculator:public AbstractCalculator {
    public:
    int getResult() {
        return m_Num1 * m_Num2;
    }
};


// void test01() {
//     Calculator calc;
//     calc.m_Num1 = 10;
//     calc.m_Num2 = 10;
//     cout << calc.getResult("+") << endl;
//     cout << calc.getResult("-") << endl;
//     cout << calc.getResult("*") << endl;
//     cout << calc.getResult("/") << endl;
// }
//
// void test02() {
//     AbstractCalculator *abc = new AddCalculator();
//     abc->m_Num1 = 10;
//     abc->m_Num2 = 10;
//     cout << abc->getResult() << endl;
// }
//
// int main() {
//     test01();
//     test02();
//     return 0;
// }
