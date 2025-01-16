#include <iostream>
using namespace std;

enum class weapon : int { gun, arrow, machine_gun };

class monster {
public:
  weapon weapon_type;
};

struct weapon_class {
  //외부에 선언된 열거형을 내부에 사용 선언
  using enum weapon;
};

int main() {
  monster monster_obj; //클래스 객체
  weapon_class weapon_obj; //구조체 변수

  monster_obj.weapon_type = weapon::gun; //클래스 객체 = weapon 클래스의 gun
  monster_obj.weapon_type = weapon_obj.arrow; //클래스 객체 = 구조체 변수의 arrow
  monster_obj.weapon_type = weapon_class::machine_gun; //클래스 객체 : 구조체 자체의 machine_gun
  //열거형 사용을 구조체나 클래스 내부에 using으로 선언하면
  //비록 외부에 정의된 열거형이라도 내부에 정의된 열거형처럼 사용할 수 있어서 소스 코드에서 논리관계를 쉽게 파악할 수 있다.
 
  return 0;
}