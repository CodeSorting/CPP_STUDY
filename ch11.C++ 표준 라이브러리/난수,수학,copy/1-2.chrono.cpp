#include <iostream>
#include <random>
#include <chrono>
using namespace std;

int main() {
  // 시드값 사용 : 현재 시각으로 이용
  auto curTime = chrono::system_clock::now(); //현재 시각 알기
  /*
  현재 시각(curTime)에서 **기준 시점(Epoch)**으로부터 경과한 시간을 반환함.
  "Epoch"은 1970년 1월 1일 00:00:00 UTC를 의미한다(유닉스 시간의 기준점).
  */
  auto duration = curTime.time_since_epoch();
  /*
  chrono::duration_cast는 duration을 특정 단위(예: 밀리초, 초, 나노초 등)로 변환하는 데 사용된다.
  아래 코드에서 duration_cast<chrono::milliseconds>(duration)는 경과 시간을 밀리초 단위로 변환한다.
  */
  auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();

  mt19937_64 mt_rand(millis);

  for (int i = 0; i < 10; i++) {
    cout << mt_rand() << endl;
  }

  return 0;
}
