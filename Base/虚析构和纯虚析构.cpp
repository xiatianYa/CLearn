#include <iostream>
using namespace std;
#include <string>

class Animal {
    public:
    Animal() {
        cout << "Animal构造函数调用!" << endl;
    }

    //虚析构
    // virtual  ~Animal() {
    //     cout << "Animal析构函数调用" << endl;
    // }

    //纯虚析构
    virtual ~Animal() = 0;
    virtual void speak() = 0;
};

//纯虚析构
Animal::~Animal() {
    cout << "Animal纯虚析构函数调用" << endl;
}


class Cat: public Animal {
    public:
    Cat(string name) {
        cout << "Cat的构造函数" << endl;
        m_Name = new string(name);
    }
    virtual void speak() {
        cout << *m_Name << "Cat, speak!" << endl;
    }
    ~Cat() {
        if (m_Name != NULL) {
            cout << *m_Name << "Cat析构函数" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    string * m_Name;
};

void test01() {
    Animal *a = new Cat("Tom");
    a->speak();
    //父类的指针在析构时候 不会调用子类析构函数 导致子类如果有堆区属性 会导致内存泄漏
    delete a;
}

int main() {
    test01();
    return 0;
}

