#include <iostream>

using namespace std;

template <typename Type1, typename Type2>
class data_package {
public:
  data_package(Type1 first, Type2 second) : first(first), second(second) {} //생성자자
  void print_out_element() {
    cout << "첫 번째 요소: " << first << 
      ", 두 번째 요소: " << second << endl;
  }
private:
  Type1 first;
  Type2 second;
};

int main() {
  data_package<int, double> template_inst1(5, 10.5);
  data_package<string, int> template_inst2("문자열", 10);
  //data_package template_inst3("문자열", 10); c++17부터는 클래스 템플릿에서 형식 추론이 된다.

  template_inst1.print_out_element();
  template_inst2.print_out_element();
}

