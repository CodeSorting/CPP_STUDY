#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;
// wchar = wide 문자를 저장

int main() {
    wchar_t message_korean[] = L"안녕 월드야"; // wchar은 L을 문자열 앞에 써줘야함.
    _setmode(_fileno(stdout),_O_U16TEXT); // 윈도우 콘솔 창 유니코드 출력 모드 설정
    wcout<<message_korean<<'\n';
    
    return 0;
}