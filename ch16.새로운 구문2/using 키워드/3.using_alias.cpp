#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 기본 alias 정의
using String = std::string;

int main() {
    String name = "Alice"; // std::string 대신 String 사용
    cout << "Name: " << name << endl;
    return 0;
}