#include <iostream>
#include <tuple>
using namespace std;

const int monster_a_type = 0;
const int monster_b_type = 1;
const int monster_c_type = 2;

class monster {
public:
  int get_monster_type() { return monster_type; };

protected:
  int monster_type;

private:
  int location_x;
  int location_y;
};

//몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
public:
  monster_a() {
    monster_type = monster_a_type;
  };
};


//몬스터 B는 추상 클래스 Monster 클래스로부터 상속
class monster_b : public monster {
public:
  monster_b() {
    monster_type = monster_b_type;
  };
};


//몬스터 C는 추상 클래스 Monster 클래스로부터 상속
class monster_c : public monster {
public:
  monster_c() {
    monster_type = monster_c_type;
  };
};

// 몬스터 객체를 전달받아 특성을 튜플로 반환
tuple<int, string, int, int> get_monster_status(monster& monster_inst) {
  int monster_type = monster_inst.get_monster_type();
  string monster_name;
  int hp(100), power(100);

  switch (monster_type) {
  case monster_a_type:
    monster_name = "A 몬스터";
    hp += 10;
    break;
  case monster_b_type:
    monster_name = "B 몬스터";
    power += 20;
    break;
  case monster_c_type:
    monster_name = "C 몬스터";
    hp -= 10;
    power += 100;
    break;
  }
  // ① 튜플 생성
  return make_tuple(monster_type, monster_name, hp, power); //튜플을 생성하는 튜플 내장 함수
}

// 튜플의 원소 출력
void print_out_tuple(tuple<int, string, int, int> monster_status) {
  cout << get<1>(monster_status) << "(" 
      << get<0>(monster_status) << ") : hp(" 
      << get<2>(monster_status) << "), power(" 
      << get<3>(monster_status) << ")" << endl;
}

// tuple size 상관 없이 출력하는 소스 코드 cppreference.com 참조
// https://en.cppreference.com/w/cpp/utility/tuple/tuple_cat
template<class tuple_obj, std::size_t N>
struct print_out_tuple_second {
  static void show(const tuple_obj& t)
  {
    print_out_tuple_second<tuple_obj, N - 1>::show(t); //재귀
    std::cout << ", " << std::get<N - 1>(t);
  }
};

//size가 1일 때 출력하는 것.
template<class tuple_obj>
struct print_out_tuple_second<tuple_obj, 1> {
  static void show(const tuple_obj& t)
  {
    std::cout << std::get<0>(t);
  }
};

int main() {
  monster_a monster_a_inst;
  monster_b monster_b_inst;

  // make_tuple로 생성된 튜플을 반환 받아 튜플 객체에 대입
  tuple<int, string, int, int> monster_a_status = get_monster_status(monster_a_inst);
  // ② 복사 생성자로 튜플 생성
  tuple<int, string, int, int> monster_a_status_copy(monster_a_status);
  // ③ 유니폼 초기화로 튜플 생성
  tuple<int, string, int, int> monster_b_status_temp{monster_b_type, "B 몬스터 임시", 100, 100}; //유니폼 초기화는 {}이용
  // ④ auto 사용
  auto monster_b_status = get_monster_status(monster_b_inst);

  print_out_tuple(monster_a_status);
  print_out_tuple(monster_a_status_copy);
  print_out_tuple(monster_b_status_temp);

  // ⑤ 튜플의 원솟값 교환 : swap()이용. 튜플의 구성(데이터 형식과 개수)는 반드시 같아야 한다.
  swap(monster_b_status, monster_b_status_temp);
  cout << "튜플 내용 교환 후" << endl;
  print_out_tuple(monster_b_status_temp);

  // ⑥ 튜플 합치기 : tuple_cat()은 여러 튜플을 하나로 합쳐준다.
  auto monster_status_all = tuple_cat(monster_a_status, monster_b_status);//tuple<int, string, int, int, int, string, int, int>이다.
  cout << "tuple_cat 호출 이후 : { ";
  /*
  decltype(monster_status_all)
  decltype은 변수의 타입을 추론합니다.
  여기서 monster_status_all은 tuple_cat을 사용해 만들어진 튜플이므로 타입은 tuple<int, string, int, int, int, string, int, int>입니다.

  tuple_size<decltype(monster_status_all)>::value
  tuple_size는 튜플의 크기(원소 개수)를 컴파일 타임에 가져옵니다.
  여기서 monster_status_all의 크기는 8입니다.
  
  print_out_tuple_second<tuple_obj, N>::show(t)
  tuple_obj는 monster_status_all의 타입(tuple<int, string, ...>)이고,
  N은 튜플 크기(8)입니다.
  이 구조체는 N이 1이 될 때까지 재귀적으로 호출됩니다.
  */
  print_out_tuple_second<decltype(monster_status_all), tuple_size<decltype(monster_status_all)>::value>::show(monster_status_all);
  cout << "}" << endl;
  return 0;
}