#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> mySet; //내부적으로 이진 탐색 트리(Red-Black Tree)를 사용해 원소를 저장함.
  //set = 중복 허락 X -> multiset 쓰기

  // 값 삽입
  mySet.insert(5);
  mySet.insert(2);
  mySet.insert(8);

  // 값 5가 세트에 있는지 확인
  if (mySet.find(5) != mySet.end()) {
    cout << "5는 set에 저장되어 있음" << endl;
  }

  // 세트를 순회하며 값 출력
  for (auto it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << " "; //자동으로 오름차순 정렬되어있음. 연산자 오버로딩 <로 정렬 순서를 정할 수 있음.
  }
  cout << endl;

  // 세트의 크기 출력
  int size = mySet.size();
  cout << "set 크기: " << size << endl;

  return 0;
}
/*
내림차순 정렬
1.
// 사용자 정의 비교 함수
    auto comp = [](int a, int b) {
        return a > b; // 내림차순 정렬
    };

    // std::set에 비교 함수 전달
    set<int, decltype(comp)> mySet(comp);
2.
#include <iostream>
#include <set>
using namespace std;
// 사용자 정의 클래스
class MyClass {
public:
    int value;

    MyClass(int val) : value(val) {}

    // 연산자 < 오버로딩
    bool operator<(const MyClass& other) const {
        // 내림차순 정렬
        return value > other.value;
    }
};

int main() {
    // std::set에 MyClass 객체를 저장
    set<MyClass> mySet;

    // 요소 삽입
    mySet.insert(MyClass(10));
    mySet.insert(MyClass(5));
    mySet.insert(MyClass(20));

    // 요소 출력 (내림차순 정렬)
    for (const auto& elem : mySet) {
        cout << elem.value << " ";
    }

    return 0;
}
*/