#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
얕은 복사 : 주소값을 복사
깊은 복사 : 실제 값을 새 메모리 공간으로 복사 (copy)
*/
// 사람 정보를 담는 구조체
struct Person {
  string name;    // 이름
  int age;        // 나이
  float height;   // 키
  float weight;   // 몸무게
};

// 벡터에 저장된 사람 정보 출력 함수
void print_person_all(vector<Person>& vec) {
  for (vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
    cout << "이름: " << it->name << "\t > " << "나이: " << it->age << ", " << "키: " << it->height << ", " << "몸무게: " << it->weight << endl;
  }
}

int main() {
  // Person 구조체 배열 생성
  Person p[5] = {
      {"Brain", 24, 180, 70},
      {"Jessica", 22, 165, 55},
      {"James", 30, 170, 65},
      {"Tom", 12, 155, 46},
      {"Mary", 18, 172, 62}
  };

  // from_vector에 Person 배열 순서대로 넣기
  vector<Person> from_vector;
  from_vector.push_back(p[0]);
  from_vector.push_back(p[1]);
  from_vector.push_back(p[2]);
  from_vector.push_back(p[3]);
  from_vector.push_back(p[4]);

  // from_vector 출력
  cout << "-----from_vector-----" << endl;
  print_person_all(from_vector);
  cout << endl;

  //to_vector에 from_vector의 원소들 "깊은 복사" 수행
  vector<Person> to_vector;
  /*
  copy 원형 : temlate <class_InIt, class _OutIt> _CONSTEXPR20 _OutIt copy(_InIt _First, _InIt _Last, _OutIt _Dest);
  _First부터 _Last 전까지의 모든 원소를 _Dest부터 시작하는 곳에 복사한다.
  back_inserter(to_vector) = std::back_inserter는 C++ 표준 라이브러리의 어댑터 함수로,
  컨테이너의 끝에 요소를 추가하는 **반복자(iterator)**를 생성한다.
  이를 사용하면 컨테이너에 요소를 추가할 때 명시적으로 .push_back()을 호출하지 않아도 되고, 특히 표준 알고리즘과 함께 유용하게 활용된다.
  back_inserter가 없다면 to_vector의 크기를 미리 할당해야한다.
  vector<Person> to_vector(from_vector.size()); // 크기를 미리 할당
  copy(from_vector.begin(), from_vector.end(), to_vector.begin());
  */
  copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector));

  // 복사 후, to_vector 출력
  cout << "-----to_vector-----" << endl;
  print_person_all(to_vector);
  cout << endl;

  // from_vector의 첫 번째 요소 수정
  from_vector[0].name = "Chris";
  from_vector[0].age = 5;
  from_vector[0].height = 110;
  from_vector[0].weight = 20;

  // 수정 후, from_vector 출력
  cout << "-----from_vector-----" << endl;
  print_person_all(from_vector);
  cout << endl;

  // to_vector 출력 : to_vector은 새로운 메모리에 놓은 값이므로 from_vector이 변경되어도 to_vector은 변경되지 않는다.
  cout << "-----to_vector-----" << endl;
  print_person_all(to_vector);
  cout << endl;

  return 0;
}