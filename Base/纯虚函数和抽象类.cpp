#include <iostream>
using namespace std;

class Base {
public:
    //虚构函数
    //只要有一个纯虚函数,这个类就称为抽象类
    //抽象类特点
    //1.无法实例化对象
    virtual void func() = 0;
};

class Son: public Base {
    public:
    void func() {
        cout << "func Son" << endl;
    }
};

// void test01() {
//     Base *base = new Son;
//     base->func();
// }
//
// int main() {
//     test01();
// }