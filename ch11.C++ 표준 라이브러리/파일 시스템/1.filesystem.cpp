#include <iostream>
#include <string>
#include <filesystem> // 파일 시스템 헤더 파일 C++17부터 사용 가능!
#include <fstream>    // 파일 입출력 헤더 파일
using namespace std;

namespace fs = filesystem;

int main() {
  // 1. 디렉터리 생성 : 지정된 경로에 디렉터리를 생성한다. 필요하면 중간 단계의 디렉터리도 생성한다.
  fs::create_directories("MyDirectory");

  // 2. 파일 생성 및 쓰기 : ofstream(파일 출력 스트림)을 사용하여 파일에 내용을 쓰고 난 후 outFile.close()로 파일을 제대로 닫는다.
  ofstream outFile("MyDirectory/myFile.txt");
  outFile << "Hello, FileSystem Library!" << endl;
  outFile.close();

  // 3. 디렉터리 내의 파일 확인 : 디렉터리 반복자(directory_iterator)를 생성하고 범위 기반 for문으로 모든 원소를 대상으로 반복한다.
  cout << "Files in MyDirectory:\n";
  for (const fs::directory_entry& entry : fs::directory_iterator("MyDirectory")) {
    if (entry.is_regular_file()) {
      cout << entry.path().filename() << endl;
    }
  }

  // 4. 파일 읽기 : ifstream을 이용해 파일을 열고(inFile()) 각 줄을 읽어 그 내용을 화면에 출력한다.(getline(inFile,line)) 그리고 파일을 닫는다.(close())
  ifstream inFile("MyDirectory/myFile.txt");
  string line;
  while (getline(inFile, line)) {
    cout << line << endl;
  }
  inFile.close();

  // 5. 파일 및 디렉터리 삭제 : 디렉터리, 하위 디렉터리, 디렉터리 안의 파일까지 삭제한다.
  fs::remove_all("MyDirectory");

  return 0;
}
/*
출력 내용

Files in MyDirectory:
"myFile.txt"
Hello, FileSystem Library!
*/