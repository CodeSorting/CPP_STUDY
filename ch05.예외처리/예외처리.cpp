#include <iostream>
using namespace std;

void real_noexcept() noexcept { // 예외를 던지지 않음을 명시
    cout<<"real"<<endl;
}

void terminate() {
    cout<<"END"<<endl;
}

int main() {
    try { // 이 안에서 예외 발생시 catch 문으로 넘어감.
        int input;
        cin>>input;
        if (input>0) {
            cout<<"throw 1"<<endl;
            throw 1;
            cout<<"after throw 1"<<endl;
        }
        else if (input<0) {
            cout<<"throw -1.0f"<<endl;
            throw -1.0f;
            cout<<"after throw -1.0f"<<endl;
        }
        else if (input==0) {
            cout<<"throw Z"<<endl;
            throw 'Z';
            cout<<"after throw Z"<<endl;
        }
    }
    catch (int a) {
        cout<<a<<endl;
    }
    catch (float b) {
        cout<<b<<endl;
    }
    catch (...) { //나머지 예외 받기
        cout<<"catch all"<<endl;
    }
    /*
    만약에 종료 처리할 catch를 못 찾는다면 종료 처리 함수를 지정할 수도 있다.
    set_terminate(terminate);
    이렇게 지정하고 예외가 발생하면 종료 처리를 해당 함수 이름으로 진행한다.
    */
}