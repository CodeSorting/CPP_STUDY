#include <iostream>
#include <functional>
using namespace std;

// 함수
void myFunction(int a) {
    cout << "Function called with value: " << a << endl;
}

// 함수 객체
struct MyFunctor {
    void operator()(int a) const {
        cout << "Functor called with value: " << a << endl;
    }
};

int main() {
    // std::function 객체에 다양한 호출 대상 할당
    function<void(int)> func;

    func = myFunction;   // 일반 함수
    func(10);            // Output: Function called with value: 10

    func = MyFunctor();  // 함수 객체
    func(20);            // Output: Functor called with value: 20

    func = [](int a) {   // 람다 표현식
        cout << "Lambda called with value: " << a << endl;
    };
    func(30);            // Output: Lambda called with value: 30

    return 0;
}