#include <iostream>
using namespace std;

class AbstractDrinking {
    public:
    //煮
    virtual void Boil() = 0;

    //冲泡
    virtual void Brew() = 0;

    //倒入
    virtual void PourInCup() = 0;

    //加入辅料
    virtual void PourSomething() = 0;

    //制作
    void makeDrink() {
        Boil();
        Brew();
        PourInCup();
        PourSomething();
        cout << "Drinking the drink" << endl;
    }
};

//咖啡
class Coffee : public AbstractDrinking {
public:
    void Boil() {
        cout << "Biol 农夫山泉" << endl;
    }

    void Brew() {
        cout << "冲泡咖啡" << endl;
    }

    void PourInCup() {
        cout << "倒入杯子" << endl;
    }

    void PourSomething() {
        cout << "加入辅料" << endl;
    }
};

//茶
class Tea: public AbstractDrinking {
public:
    void Boil() {
        cout << "Biol 矿泉水" << endl;
    }

    void Brew() {
        cout << "冲泡茶" << endl;
    }

    void PourInCup() {
        cout << "倒入杯子" << endl;
    }

    void PourSomething() {
        cout << "加入辅料" << endl;
    }
};

//工作
void doWork(AbstractDrinking * abs) {
    abs->makeDrink();
    delete abs;
}

// void test01() {
//     //制作咖啡
//     doWork(new Coffee);
//     //制作茶
//     doWork(new Tea);
// }
//
// int main() {
//     test01();
//     return 0;
// }
