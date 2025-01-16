#include <iostream>
using namespace std;

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    // Car 클래스를 프렌드로 선언 : Car이 Engine으로 접근할 수 있음.
    friend class Car;
};

class Car {
public:
    void showEngineDetails(Engine e) {
        cout << "엔진 마력: " << e.horsepower << " HP" << endl; // Engine의 private 멤버에 접근 가능
    }
};

int main() {
    Engine myEngine(150);
    Car myCar;
    myCar.showEngineDetails(myEngine); // Engine 클래스의 private 멤버 사용
    return 0;
}