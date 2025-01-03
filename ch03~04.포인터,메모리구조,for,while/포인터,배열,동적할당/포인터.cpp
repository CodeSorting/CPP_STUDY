#include <iostream>
using namespace std;

int main() {
    char char_value = 'A';
    char *char_pointer = &char_value;
    cout<<(void *)char_pointer<<' '<<*char_pointer<<endl;
    /*
    char_pointer가 char* 타입일 때 발생하는 깨짐 현상은,
    cout이 이를 문자열의 시작으로 해석하여 출력하려 하기 때문입니다.
    이때, 그 주소에 시작하는 문자열이 실제로는 정상적으로 끝나는 문자열이 아닐 수 있기 때문에,
    cout은 문자열을 끝없이 출력하거나, 잘못된 메모리 영역을 읽어들이게 되어 깨진 출력이 발생합니다.
    */
    *char_pointer = 'B';
    cout<<"변경 사항:"<<char_value<<endl;

    int multi = 123;
    int *a1 = &multi;
    int **a2 = &a1;
    int ***a3 = &a2;
    cout<<a1<<' '<<*a1<<'\n'; //char가 아니라 걍 주소 출력됨.
    cout<<a2<<' '<<**a2<<'\n';
    cout<<a3<<' '<<***a3<<'\n';
    cout<<endl;
    
    //배열
    int array[5] = {1,2,3,4,5};
    for (int i=0;i<5;++i) {
        cout<<array+i<<' '<<*(array+i)<<endl; //그냥 array = 배열의 첫 주소
    }
    cout<<endl;
    for (int i=0;i<5;++i) {
        cout<<&array[i]<<' '<<array[i]<<endl; //&array[i] = array + i이다.
    }
}