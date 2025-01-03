#include <iostream>
using namespace std;

int main() {
    int a = 0;
    const int *ptr = &a; //*ptr 상수화 : 가리키는 값을 변경 못함.

    a=1;
    //*ptr=2; 컴파일 오류
    
    int b = 0;
    int c = 1;
    int const *ptr2 = &b;
    
    b=1;
    //ptr = &c; //ptr 상수화 : 포인터 변수 자체를 상수화해서 변경 불가능.
}