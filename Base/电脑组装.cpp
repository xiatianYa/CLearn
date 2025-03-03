#include <iostream>
using namespace std;
#include <string>

class Cpu {
    public:
    //查询的计算函数
    virtual void calculate() = 0;
};

class Gpu {
public:
    //查询的计算函数
    virtual void display() = 0;
};

class Memory {
public:
    //查询的计算函数
    virtual void storage() = 0;
};

//电脑类
class Computer {
public:
    Computer(Cpu * cpu, Gpu * gpu,Memory * memory) {
        this->cpu = cpu;
        this->gpu = gpu;
        this->memory = memory;
    }

    void work() {
        cpu->calculate();
        gpu->display();
        memory->storage();
    }
    ~Computer() {
        if (cpu != nullptr) delete cpu;
        if (gpu != nullptr) delete gpu;
        if (memory != nullptr) delete memory;
    }
private:
    Cpu * cpu; //Cpu
    Gpu * gpu; //显卡
    Memory * memory; //内存条
};

//具体厂商
class IntelCpu: public Cpu {
public:
    virtual void calculate() {
        cout << "Intel CPU 开始计算" << endl;
    }
};

class IntelGpu: public Gpu {
public:
    virtual void display() {
        cout << "Intel Gpu 开始显示" << endl;
    }
};

class IntelMemory: public Memory {
public:
    virtual void storage() {
        cout << "Intel Memory 开始纯粹" << endl;
    }
};

class AmdCpu: public Cpu {
public:
    virtual void calculate() {
        cout << "Amd CPU 开始计算" << endl;
    }
};

class AmdGpu: public Gpu {
public:
    virtual void display() {
        cout << "Amd Gpu 开始显示" << endl;
    }
};

class AmdMemory: public Memory {
public:
    virtual void storage() {
        cout << "Amd Memory 开始纯粹" << endl;
    }
};

void test01() {
    //第一台电脑
    Cpu * cpu01 = new IntelCpu();
    Gpu * gpu01 = new IntelGpu();
    Memory * memory01 = new IntelMemory();
    Computer * computer01 = new Computer(cpu01, gpu01, memory01);
    computer01->work();
    //第二台
    Cpu * cpu02 = new AmdCpu();
    Gpu * gpu02 = new AmdGpu();
    Memory * memory02 = new AmdMemory();
    Computer * computer02 = new Computer(cpu02, gpu02, memory02);
    computer02->work();
}

int main() {
    test01();
    return 0;
}
