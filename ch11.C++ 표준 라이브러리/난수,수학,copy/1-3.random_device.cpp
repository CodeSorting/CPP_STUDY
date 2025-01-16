#include <iostream>
#include <random>
using namespace std;

int main() {
  random_device rng; //random_device 클래스 : 하드웨어 엔트로피(시스템에서 발생하는 무작위성의 정도)로 난수를 생성한다.
  //random_device는 대체로 mt19937보다 느리다. 그래서 난수가 많을 때는 mt19937을 쓴다.
  //<random>에는 random_device 말고도 linear_congruential_engine,mersenne_twister_engine,subtract_with_carry_engine 등이 있다.
  for (int i = 0; i < 10; i++) {
    auto result = rng();
    cout << result << endl;
  }

  return 0;
}
