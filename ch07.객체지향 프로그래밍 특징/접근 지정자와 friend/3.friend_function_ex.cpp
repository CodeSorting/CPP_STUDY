#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // 프렌드 함수 선언
    friend void printWidth(Box b); //프렌드 함수는 전역함수인데 다만 friend 선언을 하면 해당 객체에 접근할 수 있게 해준다.
};

// 프렌드 함수 정의
void printWidth(Box b) {
    cout << "Box의 너비: " << b.width << endl; //private 멤버 변수인 width를 직접적으로 접근할 수 있다.
}

int main() {
    Box myBox(5.5);
    printWidth(myBox); // private 멤버인 width에 접근
    return 0;
}
/*
다른 예시
#include <iostream>
using namespace std;

class Account; // Forward declaration

class Bank {
public:
    // Bank 클래스의 함수 printAccountBalance를 Account 클래스의 프렌드 함수로 선언
    void printAccountBalance(const Account& account);
};

class Account {
private:
    double balance; // private 멤버 변수

public:
    Account(double b) : balance(b) {}

    // Bank 클래스의 printAccountBalance 함수에 접근 권한 부여
    friend void Bank::printAccountBalance(const Account& account);
};

// Bank 클래스의 멤버 함수 정의
void Bank::printAccountBalance(const Account& account) {
    cout << "Account 잔액: $" << account.balance << endl; //account 클래스의 private 멤버 변수 바로 접근
}

int main() {
    Account myAccount(5000.75); // Account 객체 생성
    Bank myBank;                // Bank 객체 생성

    // Bank 클래스의 함수로 Account의 private 멤버에 접근
    myBank.printAccountBalance(myAccount);

    return 0;
}
*/