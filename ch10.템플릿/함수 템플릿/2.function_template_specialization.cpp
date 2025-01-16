#include <iostream>
#include <string>

using namespace std;

template <typename T>
T data_sum(T operand1, T operand2) {
  return operand1 + operand2;
}
//템플릿 특수화 : 특정 데이터 형식만 다른 알고리즘으로 처리시킬 수 있다.
template <> //명시적 특수화 : 모든 템플릿 매개변수를 특정 데이터 형식으로 지정 (부분 특수화는 불가능->클래스 템플릿에서 가능)
double data_sum(double operand1, double operand2) {
  return  (int)operand1 + (int)operand2;
}

int main() {
  int data1 = 3, data2 = 5;
  double data3 = 4.5, data4 = 8.9;
  string data5 = "Hello, ", data6 = "World!";

  cout << "정수형 데이터 합: " << data_sum(data1, data2) << endl; //8(3+5)
  cout << "실수형 데이터 합: " << data_sum(data3, data4) << endl; //12(4+8)
  cout << "문자열 데이터 합: " << data_sum(data5, data6) << endl; //Hello, World!

  return 0;
}
