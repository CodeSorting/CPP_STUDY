#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;

  for (int i = 0; i < 3; i++)
    vec.push_back(i);
  // rbegin : 맨 마지막 원소, rend : 맨 앞 원소의 앞, ++연산은 이전 위치를 가리키게 함.
  for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++) 
    cout << *it << endl;

  return 0;
}
