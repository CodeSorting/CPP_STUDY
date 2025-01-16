#include <iostream>
#include <string>
using namespace std;
/*
함수 원형
문자열의 pos 위치에서 len 길이만큼 대체하고, str 문자열로 교체합니다.
string
string& replace(size_t pos,size_t len,const string &str);
string& replace(const_iterator i1,const_iterator i2,const string &str);

substring
string& replace(size_t pos,size_t len,const string &str,size_t subpos,size_t sublen = npos);

c-string
string& replace(size_t pos,size_t len,const char *s);
string& replace(const_iterator i1,const_iterator i2,const char *s);
*/
int main() {
  //이 뒤 2개는 string
  string s = "Hello, World!";
  s.replace(7, 5, "Universe"); // "World"를 "Universe"로 교체
  cout << s << endl; // 출력: Hello, Universe!

  s = "Hello, World!";
  s.replace(s.begin() + 7, s.begin() + 12, "Universe"); // "World"를 "Universe"로 교체
  cout << s << endl; // 출력: Hello, Universe!

  //substring
  s = "Hello, World!";
  string replaceWith = "Beautiful Universe"; //U = 10번 인덱스
  s.replace(7, 5, replaceWith, 10, 8); // "World"를 "Universe"로 교체 (replaceWith의 10번 인덱스부터 8글자 사용 [10~17])
  cout << s << endl; // 출력: Hello, Universe!

  //이 뒤 2개는 c-style의 string
  s = "Hello, World!";
  s.replace(7, 5, "Universe"); // "World"를 "Universe"로 교체
  cout << s << endl; // 출력: Hello, Universe!

  s = "Hello, World!";
  s.replace(s.begin() + 7, s.begin() + 12, "Universe"); // "World"를 "Universe"로 교체
  cout << s << endl; // 출력: Hello, Universe!
  return 0;
}
