#include <iostream>
#include <functional>
#include <string>
using namespace std;

/*
C++에서는 함수포인터,함자,람다까지, 객체를 함수처럼 활용하는 다양한 방법이 있다.
모던 C++에서는 다양한 호출 객체를 통일된 형식으로 사용할 수 있도록 function 클래스를 제공한다.
function은 클래스 템플릿으로 정의되어있으므로 function으로 선언한 객체에는 함수,함자,람다 그리고 클래스의 멤버 함수를 저장하고 호출할 수 있다.
*/
void function_pointer(int input) {
  cout << "함수 포인터 대상 함수 : " << input << endl;
}

struct functor {
  void operator()(char functor_prefix) {
    cout << "함자 : " << functor_prefix << endl;
  }
};

class class_object {
public:
  class_object(string init_string) : class_object_name(init_string) {} //생성자

  void std_function_call_member(string contents) { //함수
    cout << "클래스 멤버 함수 객체화 (" << class_object_name << ") : " << contents << endl;
  }

private:
  string class_object_name;
};

int main() {
  class_object class_obj("호출 객체를 가지고 있는 클래스"); //클래스 객체
  functor functor_obj; //구조체

  function<void(int)> func_pointer = function_pointer; //함수 포인터. function<void(반환값)(매개변수가 int)>
  function<void(functor&, char)> functor_func = &functor::operator(); //함자. function<void(반환값)(functor 구조체, 매개변수가 char)>
  function<void(double)> lambda_func = 
    [](double input) { cout << "람다 함수 : " << input << endl; }; //람다 -> 나중에 배움.
  function<void(class_object&, string)> member_func = &class_object::std_function_call_member; //클래스 객체. ()을 안 썼다.

  func_pointer(10);
  functor_func(functor_obj, 'A');
  lambda_func(0xa8);
  member_func(class_obj, "출력");

  return 0;
}