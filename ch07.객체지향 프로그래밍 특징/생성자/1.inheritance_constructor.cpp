#include <iostream>
#include <random>
using namespace std;

class character {
public:
  character() {
    cout << "character 클래스 생성자" << endl;
  };
};

class monster {
public:
  monster() {
    cout << "monster 클래스 생성자" << endl;
  };
};

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character { //다중 상속에서 monster_a 객체를 생성하면 상속 받은 순서대로 생성자를 출력함.
public:
  monster_a() {
    cout << "monster_a 클래스 생성자" << endl;
  };
};

int main() {
  monster_a forest_monster;
  return 0;
}