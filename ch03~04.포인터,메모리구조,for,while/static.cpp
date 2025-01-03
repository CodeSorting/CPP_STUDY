#include <iostream>
using namespace std;

int getNewID() {
    static int ID = 0; //함수를 여러번 실행해도 static은 한번만 초기화되므로 함수를 호출할 때마다 값이 1씩 증가한다.
    return ++ID;
}

int main() {
    cout<<"ID: "<<getNewID()<<endl;
    cout<<"ID: "<<getNewID()<<endl;
    cout<<"ID: "<<getNewID()<<endl;
    cout<<"ID: "<<getNewID()<<endl;
    cout<<"ID: "<<getNewID()<<endl;
    return 0;
}