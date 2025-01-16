#include <iostream>
using namespace std;

// 매개변수 팩을 이용한 가변 인자 템플릿 – 말단 함수용
template<typename doll>
// 매개변수 팩의 마지막 인자를 연산 하기 위한 함수
void find_doll(doll doll_name) {
  cout << "'" << doll_name << "'(이)가 ";
  cout << "있습니다." << endl << endl;
}
/*
...: 가변 인자 팩을 "펼치기(expand)" 위한 기호이다.
폴드 표현식에서 팩 내 모든 인자에 대해 연산을 수행하는 역할을 한다.
*/
// 매개변수 팩을 이용한 가변 인자 템플릿 – 재귀 함수 용
template<typename doll, typename... dolls> //...를 매개변수 데이터 형식 뒤에 붙여서 매개변수 팩으로 선언한다.
// find_dell 함수 오버로딩
void find_doll(doll doll_name, dolls... doll_list) { //...를 매개변수 데이터 형식 뒤에 붙여서 매개변수 팩으로 선언한다.
  cout << "'" << doll_name << "' 안쪽에 ";
  // 재귀 호출
  find_doll(doll_list...); //처리한 인자를 제외한 매개변수 팩을 재귀 호출로 처리한다.(선언과 다르게 여기에서는 선언된 팩을 사용해준다.)

}

int main() {
  cout << "첫 번째 마트료시카 ";
  // 가변 인자로 함수 호출
  find_doll("대형", "중형", "소형");

  cout << "두 번째 마트료시카 ";
  // 가변 인자로 함수 호출
  find_doll("특대형", "대형", "중형", "소형", "극소형");
}