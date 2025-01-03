#include <iostream>
#include <random>
using namespace std;

class character {
public:
  character() {
    cout << "character 클래스 생성자" << endl;
  };
  ~character() { //character의 소멸자 정의
    cout << "charactor 클래스 소멸자" << endl;
  }
};

class monster {
public:
  monster() {
    cout << "monster 클래스 생성자" << endl;
  };
    ~monster() { //monster의 소멸자 정의
    cout << "monster 클래스 소멸자" << endl;
  };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character { //monster->character->monster_a 순으로 생성, 소멸은 역순으로 호출
public:
  monster_a() {
    cout << "monster_a 클래스 생성자" << endl;
  };

  ~monster_a() {
    cout << "monster_a 클래스 소멸자" << endl;
  }
};

int main() {
  monster_a forest_monster;
  return 0;
}