#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1("Hello");
  str1.append(" World!"); //문자열 끝에 새로운 문자 추가
  cout << str1 << endl; //Hello World!

  string str2("Hello");
  str2.append(" World!", 6, 1); //(추가할 문자열, 문자열 시작 인덱스, 문자 개수)
  cout << str2 << endl; //Hello!

  return 0;
}
