#include <iostream>
#include <string>
using namespace std;
//template <typename 템플릿 매개변수>
template <typename T>
T data_sum(T operand1, T operand2) {
  return operand1 + operand2;
}

int main() {
  int data1 = 3, data2 = 5;
  double data3 = 4.5, data4 = 8.9;
  string data5 = "Hello, ", data6 = "World!";
  char data7[] = "Hello, ", data8[] = "New World!";

  cout << "정수형 데이터 합: " << data_sum(data1, data2) << endl;
  cout << "실수형 데이터 합: " << data_sum(data3, data4) << endl;
  cout << "문자열 데이터 합: " << data_sum(data5, data6) << endl;

  // 사용할 수 없는 인자 예제
  //cout << "문자데이터 배열의 합:" << data_sum(data7, data8) << endl; //배열(포인터)를 덧셈할 수는 없음.
  cout << "문자데이터 배열의 합: " << data_sum<string>(data7, data8) << endl; //명시적으로 인지 시킴. char 배열 -> string으로 변환 후 함수 호출

  return 0;
}
