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
class monster_a : public monster, character {
public:
  monster_a() {
    cout << "monster_a 클래스 생성자" << endl;
  };

  monster_a(int x, int y) : location{ x, y } { //위치 초기화
    cout << "monster_a 클래스 생성자 (매개변수 추가)" << endl;
  };

  void show_location() {
    cout << "위치(" << location[0] << " , " << location[1] << ")" << endl;
  };

private:
  int location[2]; //위치 배열
};

int main() {
  monster_a forest_monster;
  forest_monster.show_location(); //위치를 초기화하지 않아 쓰레기값 or (0,0)이 나온다.
  monster_a wood_monster(10, 25);
  wood_monster.show_location();

  return 0;
}