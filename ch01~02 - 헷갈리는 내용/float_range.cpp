#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    float float_value = 9.87654321f; // 뒤에 f = float
    double double_value = 9.87654321987654321; // 기본 = double
    long double long_double_value = 9.87654321987654321l; // 뒤에 l = long double
    cout<<setprecision(numeric_limits<float>::digits10 + 1)<<float_value<<'\n';
    cout<<setprecision(numeric_limits<double>::digits10 + 1)<<double_value<<'\n';
    cout<<setprecision(numeric_limits<long double>::digits10 + 1)<<long_double_value<<'\n';
    /*
    출력 결과
    9.876543
    9.876543219876543
    9.87654321987654321
    */
    return 0;
}