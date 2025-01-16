# 튜플
C++ 언어에서는 함수는 기본적으로 한 가지 데이터 형식의 값만 반환할 수 있었다.<br>
만약 값을 여러개 반환하려면 구조체나 클래스의 객체로 반환해야 한다.<br>
최근 프로그래밍 언어에서는 컬렉션을 사용해 한 번에 많은 자료를 반환할 수 있게 되었다.<br>
이런 추세를 이용해 모던 C++도 튜플,구조적 바인딩 구문이 추가되었다.<br>
튜플은 list,array,map등과 사용법도 같다.<br>
**그러나 튜플은 다른 종류의 데이터 형식을 한 집합으로 묶을 수 있다.**<br>
std::tuple<자료형1,자료형2,...,자료형n> 튜플_이름;으로 선언한다.<br>

# 구조적 바인딩
튜플은 여러 데이터 형식을 한데 묶을 수 있지만 사용 방법이 복잡하고 함수 호출이 많아져서 번거롭다.<br>
구조적 바인딩으로 튜플의 사용성을 좋게 변경할 수 있다.<br>
구조적 바인딩은 특정 구조의 데이터 형식을 해체하여 낱낱의 변수에 저장하는 기능이다.<br>
구조적 바인딩의 대상은 배열이나 구조체, 튜플, 맵이 될 수 있다.<br>
해체한 원소는 auto [] 또는 const auto [] 처럼 대괄호로 둘러 쌓인 변수 집합에 저장된다.<br>
structured_binding.cpp에서 확인해보자.<br>

# 범위 기반 for
1. 데이터 집합 원소 복사 : for (auto 변수_이름 : 배열_또는 컨테이너) {} 값을 모두 복사해서 가져옴.<br>
2. 데이터 집합 원소 참조 : for (auto &변수_이름 : 배열_또는 컨테이너) {} 값을 참조하여 복사하지 않는다.<br>
3. 데이터 집합 원소 상수 참조 : for (const auto &변수_이름 : 배열_또는 컨테이너) {} 2번 처럼 가리키나 변경 불가능하다.<br>
4. 데이터 집합 원소 Rvalue 참조 : for (auto &&변수_이름 : 배열_또는 컨테이너) {} 원소값 참조 x 값으로 가져오지만 복사가 이루어지지 않고 Rvalue 참조를 이용한다.<br>

### Rvalue 참조란?
C++11부터 추가된 주요한 개념이다.<br>
std::forward,std::move를 봐도 되지만 여기서는 간략한 내용만 보자.<br>
R-value는 임시로 만들어지거나 특정 범위에서만 존재하는 값이다.<br>
따라서 R-value를 전달받아 사용하려면 반드시 사용하는 범위의 R-value나 L-value가 가리키는 메모리 영역에 복사하는 과정이 필요하다.<br>
하지만 많은 string,vector같은 객체의 R-value는 복사과정이 반복될 때 성능이 떨어진다.<br>
이런 단점을 보완하고자 R-value를 복사하지 않고 사용하는 범위(함수나 클래스 등)로 이동할 수 있도록 했다.<br>
즉, 이름 없는 객체인 R-value는 선언 범위를 벗어나면 소멸하는데 다른 범위에서도 사용할 수 있도록 해당 범위의 R-value로 이동하게 하는 방법이다.<br>
범위 기반 for문에서 auto &&로 전달된 R-value 참조는 1번 형태처럼 auto 변수 사용법은 같지만, 전달 과정에서 복사가 이루어지지 않아 속도가 더 빠르다.<br>

# 제어문의 초기화 구문(init-statement)
if나 switch,for 같은 제어문에서 사용할 변수를 제어문 외부에서 초기화하면 코드를 읽을 때 혼란스러울 수 있다.<br>
이를 보완하기 위해 초기화 구문이라는 문법을 사용한다.<br>
```
int element = get_conditional_value();
if (0!=element) {
    for (auto i=0;i<10;++i) {
        cout<<element<<endl;
    }
}
```
위의 예시처럼 분기문 근처에 element를 초기화하는 함수가 있다 하더라도 이후에 코드가 추가되면 분기문의 의미 파악이 어려워진다.<br>
그러므로 state_initialize.cpp처럼 초기화 구문을 이용하면 의미를 잘 파악할 수 있다.<br>
if와 switch문에서의 초기화 구문은 C++17에, 범위 기반 for문은 C++20에서 추가되었다.<br>
ex) if (auto element = data[3] + data[4];element>20) {}

# 람다 표현식
람다 표현식은 함수를 단순하게 만들고 로직 이해를 쉽게 해준다.<br>
인라인 함수로 만들어 성능을 최적화하거나<br>
함수와 달리 작성된 범위에서만 실행되므로 부수적인 코드(예외처리 등)를 쓸 필요가 없다.<br>
다음은 예시다.<br>
```
changes는 외부 변수 캡쳐,payment,price는 인자 목록, int는 반환형식이다.
[&changes] (int payment,int price) -> int {
    int change = payment-price;
    changes[0] = change / 1000;
    change %= 1000;
    return payment-price;
} (payment[i],price[i]) //payment[i],price[i]는 호출부(인자) -> 바깥의 payment[i],price[i]를 각각 대응해 payment,price로 내부에서 쓰겠다는 말이다.
```
#### 람다를 함수 객체로 사용하기<br>
함수 객체는 다른 함수나 객체에 매개변수로 전달할 수 있다. 그런데 변수를 캡쳐했을 때는 범위를 벗어나서<br>
뎅글링 포인터(dangling pointer)가 될 수 있으므로 람다 표현식을 인자로 전달할 때는 변수를 캡쳐하지 않는게 좋다.<br>
밑의 예는 위와는 달리 선언과 동시에 사용되는 것이 아닌 함수 객체를 이용해 호출한다.<br>

```
auto calcu_changes = [&changes] (int payment,int price) -> int {
    int change = payment-price;
    changes[0] = change / 1000;
    change %= 1000;
    return payment-price;
};
..
calcu_changes(payments[i], price[i]);
```
#### 람다 표현식에서 this 포인터 사용하기
람다 표현식에서 클래스의 멤버 변수를 사용하고자 할 때 this 포인터를 캡쳐할 수 있다.<br>
'='이나 '&'로 전체 변수를 캡쳐하면 this 포인터도 함께 캡쳐된다.<br>
캡처한 변수를 사용할 때는 this를 명시하면 된다.<br>
```
cout<<[&](int payment)->int {
        int change = payment - this->price[i];
        changes[0] = change / 1000;
        change %= 1000;
        changes[1] = change / 500;
        change %= 500;
        changes[2] = change / 100;
        change %= 100;
        changes[3] = change / 50;
        change %= 50;
        changes[4] = change / 10;
        return payment - this->price[i];
    }(payments[i])
```

참고로 외부 변수 캡쳐 방법에는 여러가지가 있다.<br>
[=] : 선언부 범위의 모든 변수를 읽기 전용으로 사용<br>
[&] : 선언부 범위의 모든 변수를 참조형식으로 읽기,쓰기 모두 사용<br>
[변수1] : 변수1을 읽기 전용으로 사용<br>
[&변수1, 변수2] : 변수1은 참조, 변수2는 읽기 전용으로 사용<br>
[=,&변수1] : 선언부 범위의 모든 변수는 읽기 전용, 그러나 변수1만 예외로 참조로 사용<br>
[&,변수1] : 선언부 범위의 모든 변수는 참조 전용, 그러나 변수1만 예외로 읽기로 사용<br>

#### mutable 키워드
'='처럼 외부 변수를 가져와도 변경은 하지 않고 싶고,<br>
그러나 '&'처럼 쓰기 기능은 가지고 싶을 때 mutable을 쓴다.<br>
mutable 키워드를 이용하면 람다 표현식 내에서는 변경할 수 있지만, 외부 변수에는 영향을 미치지 않도록 변수가 복사된다.<br>
```
[&changes] (int payment,int price) mutable throw() -> int { //여기서 throw는 람다 표현식을 감싸는 try,catch 구문에 예외를 전한다.
    int change = payment-price;
    changes[0] = change / 1000;
    change %= 1000;
    return payment-price;
} (payments[i],price[i])
```
