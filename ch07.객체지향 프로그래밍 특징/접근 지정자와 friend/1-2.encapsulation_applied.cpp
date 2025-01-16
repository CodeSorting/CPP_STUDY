#include <iostream>
#include <array>

using namespace std;

class manage_data_structure {
public:
  manage_data_structure();
  int get_current_index() { return current_index; };
  void set_current_index(int new_index);
  int get_array_value() { return data_queue[current_index]; };
private:
  int current_index;
  array<int, 10> data_queue;
};

//생성자
manage_data_structure::manage_data_structure() : 
  current_index(0), data_queue{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
{
}

void manage_data_structure::set_current_index(int new_index) {
  if (new_index < 0 || new_index >= 10)
    return;

  current_index = new_index;
}

int main(void) {
  int data, index;
  manage_data_structure data_structure;

  //이처럼 클래스 안의 멤버 변수는 큰일이 없다면 private로 놓고 getter,setter로 놓는게 좋다.
  data_structure.set_current_index(-1); //범위 안이 아니라 바로 return 됨.(0 그대로)
  index = data_structure.get_current_index();
  data = data_structure.get_array_value();
  cout << "Data [" << index << "] : " << data << endl;

  return 0;
}