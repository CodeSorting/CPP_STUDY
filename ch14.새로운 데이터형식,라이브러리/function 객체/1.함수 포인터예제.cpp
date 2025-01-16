#include <iostream>
using namespace std;

// 일반 함수
void myFunction(int a) {
    cout << "Function called with value: " << a << endl;
}

int main() {
    // 함수 포인터 선언 및 초기화
    void (*funcPtr)(int) = myFunction;

    // 함수 포인터를 통해 호출
    funcPtr(10); // Output: Function called with value: 10

    return 0;
}
/*
단점
1. 함수 시그니처(반환형과 매개변수)를 고정적으로 따라야 합니다.
2. 범용성이 떨어집니다.
*/