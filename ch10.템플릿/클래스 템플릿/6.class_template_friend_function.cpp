#include <iostream>

using namespace std;

template <typename T = int>
class data_package {
public:
  data_package(T first) : first(first) {}

  friend void printout_friend_element(data_package<T>& data_object) {
    cout << "(friend 함수) 템플릿 매개변수 값 : " 
      << data_object.first << endl; //friend로 인해서 템플릿 매개변수를 그대로 사용할 수 있다. 이 함수는 전역에서 접근할 수 있으며,
      //친구가 된 data_package 클래스의 비공개 멤버에 접근할 수 있다.
  }

private:
  T first;
};

int main() {
  data_package<> template_inst1(5);
  data_package<string> template_inst2("클래스 템플릿 기본값");

  printout_friend_element(template_inst1); // template_inst1.printout_friend_element(template_inst1)으로 안해도 된다.
  printout_friend_element(template_inst2); // (friend = 전역함수 but 해당 객체의 private 변수에만 접근할 수 있도록 해주는 것이다.)
}