#include <iostream>

using namespace std;

template <typename U>
class caller {
public:
  caller() : object(nullptr) {};
  void set_object(U* obj_pointer) { object = obj_pointer; }
  void printout_friend_object() {
    cout << "(friend 클래스 템플릿 호출) 템플릿 형식 매개 변수 값 : " 
      << object->first << endl; //friend가 없었다면 first로 접근 불가
  }
private:
  U* object;
};

template <typename T = int> //템플릿 매개변수 기본값
class data_package {
public:
  data_package(T first) : first(first) {}
  friend caller<data_package>; //caller가 data_package클래스 템플릿을 쓸 경우에 접근할 수 있음.
private:
  T first;
};

int main() {
  caller<data_package<>> caller_int_obj;
  caller<data_package<string>> caller_string_obj;
  data_package<> template_inst1(5);
  data_package<string> template_inst2("클래스 템플릿 기본값");
  caller_int_obj.set_object(&template_inst1); //friend가 있어서 caller가 접근할 수 있게 함.
  caller_string_obj.set_object(&template_inst2);

  caller_int_obj.printout_friend_object();
  caller_string_obj.printout_friend_object();
}