#include <iostream>

using namespace std;

class character {
public:
  character() : hp(100), power(100) {};

protected:
  int hp;
  int power;
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
  player() {};
};

//기본 Monster 클래스
class monster {
public:
  monster() {};

protected:
  void get_damage(int _damage) {};
  void attack(player target_player) {};
  void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
  cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
  //부모 클래스에서 protected로 선언된 get_damage 함수 접근 범위 변경
  using monster::get_damage;
private:
  //상속받은 함수 오버라이딩 
  void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
  cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_b : public monster, character {
  /* using을 사용안할 경우
public:
  void take_damage(int damage) {
    get_damage(damage);  // 부모 클래스의 protected 멤버 함수 호출
  }
  */
private:
  //상속받은 함수 오버라이딩 
  void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
  cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

int main() {
  monster_a mon_1;
  monster_b mon_2;

  mon_1.get_damage(100);
  // 아래 코드는 오류가 발생합니다.
  //mon_2.get_damage(100); //protected이니 monster_b 클래스 선언 내부에서만 접근 가능. main()에서 접근 불가능.
  //따라서 쓸거면 using을 쓰거나 monster_b 클래스 선언 내부에서 다른 함수를 만들어 이 get_damage를 실행하게 해야함.

  return 0;
}