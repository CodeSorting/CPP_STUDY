#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    // 람다식을 사용해 짝수만 출력
    cout << "짝수만 출력: ";
    //for_each는 algorithm 헤더 파일의 함수다. (a,b,c) a~b까지 하나하나씩 c를 실행함
    for_each(numbers.begin(), numbers.end(), [](int num) {
        if (num % 2 == 0) {
            cout << num << " ";
        }
    });

    cout << endl;
    return 0;
}