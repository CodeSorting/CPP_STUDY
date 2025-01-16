#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1("Hello");
  cout << str1 << endl;

  cout << str1.length() << endl; //문자열의 길이 반환
  cout << str1.size() << endl; //해당 객체가 차지하는 메모리의 크기 (5 byte)
  //c++은 c언어와 다르게 \0이 문자열 끝에 붙지 않는다. string 클래스에서 문자열 길이를 직접 가지고 있기 때문이다.

  return 0;
}
