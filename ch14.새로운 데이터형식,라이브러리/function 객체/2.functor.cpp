#include <iostream>

using namespace std;
//함자 : 함수 객체라고도 함. 함수 객체는 함수처럼 호출할 수 있는 객체를 말한다.
//밑에서는 bomb 구조체인데 함수처럼 호출할 수 있다.
//함수 포인터는 포인터로만 전달할 수 있지만, 함자는 객체이므로 객체,포인터,참조자 등 다양한 형태로 저장과 복사, 호출할 수 있다.
struct bomb {
  void operator()() {
    cout << "꽝!" << endl;
  }

  void operator()(int range) {
    cout << "반경 " << range << "m내 플레이어 공격!" << endl;
  }
};

int main() {
  bomb mine;

  mine();
  mine(30);

  return 0;
}