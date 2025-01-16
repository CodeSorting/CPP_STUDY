#include <iostream>
#include <string>
using namespace std;

int main() {
  string str1("Hello");
  cout << str1 << endl;

  cout << str1[0] << endl; //배열처럼 표현 가능(오버로딩 되어있음.)
  cout << str1[1] << endl;
  cout << str1[2] << endl;
  cout << str1[3] << endl;
  cout << str1[4] << endl;

  return 0;
}
