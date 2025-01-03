#include <iostream>
#include <array>

using namespace std;

class manage_data_structure {
public: //멤버 변수를 public으로 공개하면 어느 곳에서나 접근할 수 있다.
  manage_data_structure();
  int current_index;
  array<int, 10> data_queue;
};

manage_data_structure::manage_data_structure() :
  current_index(0), data_queue{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }{
}

int main(void) {
  int data;
  manage_data_structure data_structure;

  data_structure.current_index = -1; //인덱스를 직접 접근하게 하면 안된다.
  data = data_structure.data_queue[data_structure.current_index];
  cout << "Data [" << data_structure.current_index << "] : " << data << endl;

  return 0;
}