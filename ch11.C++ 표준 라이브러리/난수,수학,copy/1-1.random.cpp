#include <iostream>
#include <random>
using namespace std;

int main() {
  mt19937_64 mt_rand; //std::mt19937 사용. 64bit인 std::mt19937_64도 있다.

  for (int i = 0; i < 10; i++) {
    cout << mt_rand() << endl; //시드가 없으므로 매 실행마다 출력이 동일할 수 있다.
  }

  return 0;
}
