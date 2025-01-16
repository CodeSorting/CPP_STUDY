# 형식을 추론하는 auto
모던 C++에서는 형식 추론을 말할 때 형식 연역(type deduction)이라는 단어를 쓴다.<br>
auto는 형식 연역을 할 수 있는 형식 지정자(type specifier)이다.<br>
정확히는 placeholder type specifier이다.<br>
auto로 선언한 변수에 초기화되는 데이터를 통해서 형식을 연역(추론)한다.<br>
그러나 제약사항이 4가지가 있다.<br>
1. auto 변수는 반드시 선언과 함께 초기화되어야 한다.
2. 함수에서 매개변수의 형식 지정자로 사용할 수 없다.
3. 구조체나 클래스의 멤버 변수로 사용할 수 없다.
4. auto 변수를 반환하는 함수는 dctltype을 사용해야 한다.
auto는 컴파일 시점에 데이터를 보고 추론할 수 없으면 오류가 발생한다.<br>
또한 auto는 컴파일 시간을 늘려주기 때문에 필요할 때만 써야한다.<br>

# 형식을 추출하는 decltype
decltype은 auto와 비슷한데 변수 선언뿐만 아니라 함수 템플릿이나 클래스 템플릿에서 반환값의 형식을 연역하는데도 쓰인다.<br>
```
template<typename T, typename TT>
auto mix_template(T t,TT tt) -> decltype(t + u) {
    return t * tt;
}
```

# enum 열거형
C++98에서 부터 쓰였지만 C++11에서 변경사항이 있었다.<br>
가장 큰 변화는 열거한 데이터의 형식을 지정할 수 있게 되었다.<br>
enum_usage.cpp를 보면 enum class, enum struct가 있는데 이게 있는 이유는 enum 값이 중복 될 수도 있으니 <br>
그걸 막기 위해 네임스페이스를 enum에도 도입시켰다.<br>

# 수학 상수
#include <numbers>에 있다. using namespace std::numbers;<br>
e,pi,inv_pi(1/pi),sqrt2,sqrt3,ln2,ln10,phi(황금비),egamma(오일러 마스케로니 상수) 등등이 있다.<br>

# 널 포인터 nullptr
C++ 이전에는 컴파일러마다 NULL이나 null값을 정의해서 사용했다.<br>
기존의 null은 특히 (void*)0으로 정의된 경우가 많았다.<br>
따라서 정수나 불리언 등 다양한 데이터 형식으로 변환할 수 있었기 때문에 버그가 많았다.<br>
그래서 nullptr을 만들었다.<br>
널 포인터를 나타내는 리터럴이므로 다른 데이터 형식으로 변환할 수 없다.<br>
nullptr로 컴파일러 종류가 달라도 가독성을 높이고 잠재적 오류 가능성을 줄일 수 있다.<br>

# 2진수 리터럴
16진수 = 0x or 0X<br>
2진수 = 0b or 0B

# constexpr
constexpr은 변수나 함수를 컴파일 시점에 상수 표현식으로 만들어 준다.<br>
const와 값 변경이 불가능하는 유사점이 있다.<br>
그러나 const는 값이 런타임에 결정되지만 constexpr은 컴파일 시점에 결정된다.<br>
constexpr 변수 예시로 compile_time_and_runtime.cpp를 보면 함수를 호출하는건 런타임 시기이므로 constexpr로 변수를 만들면 에러가 난다.<br>
const는 변수를 상수로 변환해 읽기만 가능하지만,constexpr은 변수를 상수 표현식으로 치환한다.<br>
따라서 변수를 사용할 때는 차이가 없지만, 함수를 사용할 때는 큰 차이를 보인다.
constexpr 함수 예시로 constexpr_function.cpp를 보면 함수를 컴파일러가 호출하고 반환하여 값을 넣는다.<br>

# function 객체
**std::function**은 C++ 표준 라이브러리에서 제공하는 범용 함수 래퍼이다. 함수 포인터, 람다, 함수 객체 등 다양한 호출 대상들을 하나의 인터페이스로 캡슐화합니다.<br>
특징<br>
1. 매우 유연하고 범용적입니다.
2. 호출 대상이 동적으로 결정될 수 있습니다.

# 스마트 포인터
C++에서는 메모리를 직접 관리하기 때문에 메모리 효율적이다.<br>
원래는 auto_ptr로 메모리를 자동 관리하려 했지만 여러가지 문제로 C++17부터는 제외되었다.<br>
최근에는 unique_ptr,shared_ptr,weak_ptr 등 다양한 스마트 포인터를 제공한다.<br>
여기서는 unique_ptr(C++13부터 가능)을 살펴본다.<br>
unique_ptr에서는 메모리 사용 범위를 벗어나면 메모리를 자동으로 해제한다.<br>
normal_ptr.cpp,unique_ptr.cpp의 차이를 한번 보자.<br>

## RAII 디자인 패턴
Resource Acquisition Is Initialization의 앞 글자를 따서 만든 단어로, '리소스 할당은 초기화다.'라고 직역할 수 있다.<br>
RAII 패턴의 핵심은 리소스가 필요할 때 이미 할당되어 있고 리소스가 필요 없어질 때 객체와 함께 해제되어<br>
객체 내 변숫값이 객체와 함께 일정하게 유지되는 클래스 불변성(class invariant)이다.<br>
RAII의 주요 특징은 **동적으로 할당된 메모리가 생성된 범위를 벗어나면 자동으로 해제**되는 것이다.<br>
지역 변수와 달리 동적 메모리는 힙 영역에 할당되므로 직접 해제하지 않으면 프로그램이 종료되어도 할당된 상태로 남아있는 메모리 누수가 발생한다.<br>
스마트 포인터는 지역 변수의 특징과 동적 메모리의 특징을 혼합해서 사용한다.<br>
지역 변수가 생성될 때 동적 메모리를 할당하고 지역 변수가 해제될 때 할당된 동적 메모리를 해제한다.<br>
관리 방법은 동적 메모리 할당과 해제를 관리하는 클래스를 지역 변수로 만들어서 사용한다.<br>
**클래스의 생성자에서 동적 메모리 할당을, 소멸자에서 메모리를 해제**하면 된다.<br>
