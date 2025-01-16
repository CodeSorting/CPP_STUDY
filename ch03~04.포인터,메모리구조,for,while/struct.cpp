#include <iostream>
using namespace std;

struct Person {
    std::string name;
    int age;
    float height;
    float weight;
};

void printPersonInfo(Person person[],int cnt) {
    for (int i=0;i<cnt;++i) {
        Person tmp = person[i];
        cout<<"name : "<<tmp.name<<endl;
        cout<<"age : "<<tmp.age<<endl;
        cout<<"height : "<<tmp.height<<endl;
        cout<<"weight : "<<tmp.weight<<endl;
        cout<<endl;
    }
}

int main() {
    Person person[3] = {
        {"Brain",24,180,70},
        {"Jessica",22,165,55},
        {"James",30,170,65}
    }; //초기화하기 싫으면 나중에 person[i].name = "example"처럼 해도 됨.
    printPersonInfo(person,3);
}