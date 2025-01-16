#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec;

  for (int i = 0; i < 5; i++)
    vec.push_back(i);

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) //end = 마지막 원소의 다음
    cout << *it << endl;

  return 0;
}
