#include <iostream>

using namespace std;

int sum_int(int operand1, int operand2) {
  return operand1 + operand2;
}

constexpr int sum_int_constexpr(int operand1, int operand2) {
  return operand1 + operand2;
}

int main() {
  //런타임에 함수 호출하고 9값을 반환
  int var1 = sum_int(4, 5); 
  int var2 = sum_int(var1, 10);
  int var3 = sum_int(var1, var2);

  //컴파일 시점에 함수 호출하고 상수 표현식으로 9 값을 직접 넣고 실행시킴.
  //함수 호출문이 상수 표현식으로 치환되면 컴파일 시간은 늘어나지만, 실행 시간은 줄어든다.
  constexpr int var11 = sum_int_constexpr(4, 5); 
  constexpr int var12 = sum_int_constexpr(var11, 10);
  constexpr int var13 = sum_int_constexpr(var11, var12);

  return 0;
}
