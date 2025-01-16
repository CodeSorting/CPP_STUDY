#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);

  vector<int>::const_iterator const_it = vec.cbegin();
  cout << *const_it << endl;

  ++const_it; //const여도 가리키는 곳은 변경할 수 있다.
  cout << *const_it << endl;

  const_it = vec.cend();
  --const_it;
  cout << *const_it << endl;
  //const형은 *const_it = 100처럼 가리키는 것의 값을 변경할 수는 없다.
  return 0;
}
