#include <iostream>

using namespace std;
const int loop_count = 5;
const int change_count = 5;

class vending_machine {
public:
  vending_machine() : price{ 450, 390, 11340, 900, 150 } {}; //생성자
  void stack_drink() {}; //그냥 빈 함수수

  void sale_using_basic_lambda(int payments[], int changes[]) {
    for (int i = 0; i < loop_count; ++i) {
      cout << payments[i] << "원을 내고 " << price[i] << "원 짜리 음료를 선택했습니다." << endl;
      cout << "거슬러 받을 돈은 " << [&changes](int payment, int price)->int {
        int change = payment - price;
        changes[0] = change / 1000;
        change %= 1000;
        changes[1] = change / 500;
        change %= 500;
        changes[2] = change / 100;
        change %= 100;
        changes[3] = change / 50;
        change %= 50;
        changes[4] = change / 10;
        return payment - price;
      }(payments[i], price[i]) << "입니다." << endl;
      cout << "천원 짜리 " << changes[0] << "개, 오백원 짜리 " << changes[1] << "개, 백원 짜리 " << changes[2] << "개, ";
      cout << "오십원 짜리 " << changes[3] << "개, 십원 짜리" << changes[4] << "개로 받습니다." << endl;
    }
  };

private:
  int price[loop_count];
};

int main() {
  vending_machine vending_machine_object = vending_machine();
  /*
  구분	직접 초기화 (Direct)	복사 초기화 (Copy)
  문법	Parent p;	           Parent p = Parent();
  동작 방식	생성자를 호출하여 직접 초기화,	임시 객체를 생성 후 복사로 초기화
  최적화	불필요한 임시 객체 없음,	C++11 이후 대부분 최적화됨
  사용 제한	일부 경우 불가능,	일부 경우 더 제한적
  */
  int payments[loop_count] = { 1000, 500, 15000, 1000, 200 };
  int changes[change_count] = { 0, };

  cout << "람다 표현식 기본 사용" << endl;
  cout << "--------------------------------------------------------------------" << endl;
  vending_machine_object.sale_using_basic_lambda(payments, changes);
  return 0;
}
