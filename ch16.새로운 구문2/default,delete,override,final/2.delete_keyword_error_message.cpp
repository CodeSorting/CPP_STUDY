#include <iostream>

using namespace std;

class monster {
public:
  void create_monster() = delete;
  //void create_monster_() {}; // delete 키워드를 사용하지 않고 제거
};

int main() {
  monster monster_sample;

  // 아래 두 줄은 오류가 발생합니다.
  monster_sample.create_monster(); //삭제된 함수로 뜬다.
  monster_sample.create_monster_(); //클래스에서 정의되지 않은 함수라고 뜬다.
  return 0;
}