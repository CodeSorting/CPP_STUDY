#include <iostream>
using namespace std;

/*
몬스터
1. 체력,공격력 있음
2. 공격을 받음
3. 공격을 함
4. 특수공격을 함
*/

class character {
    public:
    character() : hp(100),power(100) {};

    protected:
    int hp;
    int power;
};

class player : public character { //캐릭터의 한 종류인 플레이어
    public:
    player() {};
};

class monster { //몬스터 클래스
    public:
    monster(){};
    void get_damage(int _damage){};
    void attack(player target_player){};
    void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
    cout<<"기본 공격 : 데미지 - 10hp"<<endl;
}

//기본 몬스터 클래스 상속(다중상속)
class monster_a : public monster, character {
    public:
    //상속 받은 함수 오버라이딩
    void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
    cout<<"인텡글 공격 : 데미지 - 15hp"<<endl;
}

//기본 몬스터 클래스 상속
class monster_b : public monster, character {
    public:
    //상속 받은 함수 오버라이딩
    void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
    cout<<"가상 공격 : 데미지 - 0hp"<<endl;
}

//기본 몬스터 클래스 상속
//다형성 : 상속 받은 클래스들이 부모와 다른 다양한 특성을 가지는 것
class monster_c : public monster, character {
    public:
    //상속 받은 함수 오버라이딩
    void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
    cout<<"강력 뇌전 공격 : 데미지 - 100hp"<<endl;
}

int main() {
    player player_1;

    monster_a forest_monster;
    monster_b tutorial_monster;
    monster_c boss_monster;

    cout<<"몬스터 총 공격"<<endl;
    forest_monster.attack_special(player_1);
    tutorial_monster.attack_special(player_1);
    boss_monster.attack_special(player_1);
    
    return 0;
}