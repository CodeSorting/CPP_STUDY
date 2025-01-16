#include <iostream>
#include <string>
using namespace std;

void check_found(string::size_type n) {
  if (n == string::npos) { //찾지 못하면 string::npos라는 상수 반환
  //npos는 static const size_t npos = -1;로 정의되어 있음.
    cout << "not found" << endl;
  }
  else {
    cout << "found index: " << n << endl;
  }
}

int main() {
  string::size_type n; //문자열의 크기를 나타내는 형식(부호 없는 정수)
  string str = "This is an example of a standard string.";

  // 문자열 시작 지점부터 "example" 탐색
  n = str.find("example");
  check_found(n);

  // 문자열 시작 지점부터 "is" 탐색
  n = str.find("is");
  check_found(n);

  // 문자열 내 index 위치 4부터 "is" 탐색
  n = str.find("is", 4);
  check_found(n);

  // 문자열 시작 지점부터 'h' 탐색
  n = str.find('h');
  check_found(n);

  // 문자열 시작 지점부터 'k' 탐색
  n = str.find('k');
  check_found(n);

  return 0;
}
