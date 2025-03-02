#include <iostream>
using namespace std;

class Building;
class GoodGay {
public:
    GoodGay();

    void visit() const;

    Building *building;
};

class Building {
    friend class GoodGay;
public:
    Building();
    string m_SittingRoom;
private:
    string m_BedRoom;
};

Building::Building() {
    m_SittingRoom = "SittingRoom";
    m_BedRoom = "BedRoom";
}

GoodGay::GoodGay() {
    //创建建筑位物
    building = new Building();
}

void GoodGay::visit() const {
    cout << "Friend->" << building->m_SittingRoom << endl;
    cout << "Friend->" << building->m_BedRoom << endl;
}

// void test01(){
//     GoodGay gg;
//     gg.visit();
// }

// int main() {
//     test01();
//     return 0;
// }