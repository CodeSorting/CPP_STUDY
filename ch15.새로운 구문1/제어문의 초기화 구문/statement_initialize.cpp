#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

constexpr int even = 0;
constexpr int odd = 1;

int main() {
  array<int, 5> data_array{47, 23, 58, 10, 36};
  //밑의 3개의 예시에서는 auto의 사용이유가 명확히 드러난다.

  // if 문에 초기화 구문 사용
  if (auto element = data_array[3]; element > 20 ) {
    cout << "네 번째 요소값은 20보다 큽니다." << endl;
  }
  else {
    cout << "네 번째 요소값은 20보다 작거나 같습니다." << endl;
  }

  // switch 문에 초기화 구문 사용
  switch (auto element = data_array[4] % 2 ; element) {
  case odd:
    cout << "다섯 번째 요소값은 홀수 입니다." << endl;
    break;
  case even:
    cout << "다섯 번째 요소값은 짝수 입니다." << endl;
    break;
  }

  // 범위 기반 for 문에 초기화 구문 사용
  /* warning이 뜸
  C++에서 for 문 안에 sort를 호출하면서 정렬을 수행하고 있다. 하지만 이 방식은 의도치 않은 부작용을 일으킬 가능성이 있다.
  sort는 data_array의 요소를 정렬하지만, 컴파일러는 이 호출의 결과를 for 루프와 연관짓지 않는다.
  즉, 컴파일러는 이 정렬 호출이 불필요하다고 간주하거나, 루프 내에서 사용되지 않는다고 경고를 발생시킬 수 있다.
  */
  for (sort(data_array.begin(), data_array.end()); auto&& element : data_array) {
    cout << element << ", ";
  }
  cout << endl;

  return 0;
}