#include <iostream>
using namespace std;

class bank {
private:
  int safe; //금고
  string bank_name;

public:
  bank(string name) : bank_name(name) { safe = 0; };  //기본 생성자  
  ~bank() {};
  void use_counter(int _in, int _out);  //입출금 창구 함수 
};

void bank::use_counter(int _in, int _out) { //사실 safe에서는 this->safe,bank *const this가 생략된 것임. 컴파일 할때 자동적으로 추가됨.
  safe += _in;
  safe -= _out;
  cout << bank_name << " 처리 - 입금: " << _in << ", 출금: " << _out << endl;
}

int main() {
  bank rich_bank("부유한 은행"), global_bank("세계적 은행");
  rich_bank.use_counter(10, 10); //user_counter(&rich_bank,10,10);임.
  global_bank.use_counter(20, 5);
  return 0;
}