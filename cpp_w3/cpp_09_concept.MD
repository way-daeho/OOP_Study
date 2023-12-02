## C++ 템플릿(Template)
사용자가 원하는 타입을 넣어주면 딱딱 알아서 코드를 찍어내는 틀
template <typename T>\
정의 되는 클래스에 대해 템플릿을 정의하고, 템플릿 인자로 T를 받게되며, T는 반드시 어떠한 타입의 이름을 명시\
템플릿 문장 아래 오는 것이 class Vector이므로 ,Vector 클래스에 대한 템플릿을 명시하는데, 만약에 밑에 오는 것이 함수일 경우 함수에 대한 템플시이  된다.\

template <class T>\
라고 쓰는 경우, 이는 정확히 typename T와 동일. class T라고 해서 T자리에 꼭 클래스가 와야하는건 아니다.\

### template <typename T> 와 template <class T> 는 정확히 같은 의미, 되도록이면 typename 키워드 사용

정의한 템플릿의 인자에 값을 전달하기 위해서는
### Vector<int> int_vec;
<> 안에 전달하려는 것을 명시해주면 된다.\
인자로 특정한 '값' 혹은 '객체'를 전달해왔지만, '타입' 그 자체를 전달한 적은 없었다. 하지만 템플릿을 통해 타입을 전달할 수 있게 된다.\
#### Vector<int> || Vector<std::string>
클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것을 클래스 템플릿 인스턴스화 (class template instantiation) 라고 한다.\

bool 데이터형은 1개 비트만으로 충분히 저장, C++ 기본으로 처리하는 단위가 1byte(8bits)

## 템플릿 특수화 (template specialization)
일부 경우에 대해서 따로 처리하는 것을 템플릿 특수화.\
template <typename A, typename B, typename C>
class test {};\
위와 같이 클래스 템플릿이 정의되어 있을 때\
template <typename B>\
class test<int, B, double> {};\
와 같은 방식으로 작성하면 된다.\
template <>\
class test <int, int, double> {};\
와 같이 써주면 모두 특수화 가능.\
한 가지 중요한 점은, 전달하는 템플릿 인자가 없더라도 특수화 하고 싶다면, template<> 라도 남겨줘야한다.

## 함수 템플릿 (Function template)
클래스 템플릿과 마찬가지로, 함수도 인스턴스화 되기 전 까지는 컴파일 시에 아무런 코드로 변환되지 않는다.\
템플릿 함수가 인스턴스화 되는 부분은 바로 코드에서 호출되는 부분. 클래스를 인스턴스화 할 때와 다르게 <> 하는 부분이 없다.\
기존 템플릿 max<int>(a,b) C++ 컴파일러는 생각보다 똑똑해서, a와 b의 타입을 보고 알아서 max (a, b)를 max<int> (a,b) 로 인스턴스화 해준다.

### 템플릿 메타프로그래밍(template metaprogramming)
컴파일 시에 모든 템플릿들이 인스턴스화 되다는 사실을 갖고 또 여러가지 흥미로운 코드를 작성할 수 있게 해줌.\

Comp1과 Comp2 모두 아무 것도 하지 않고 단순히 operator() 만 정의\
Comp1 과 Comp2 객체들은 bubble_sort 함수 안에서 if (!comp(cont[i], cont[j]))\
함수인양 사용된다.\
### 함수는 아니지만 함수 인 척을 하는 객체를 함수 객체(Function Object), 혹은 줄여서 Functor 라고 부른다.
Functor 덕분에, bubble_sort 함수 내에서 두 객체간의 비교를 사용자가 원하는 대로 할 수 있게 된다.\
Functor 를 사용하는 것이 여러 모로 훨씬 편리한 점이 많다. 일단, 클래스 자체에 여러가지 내부 state를 저장해서 비교자체가 복잡한 경우에도 손쉽게 사용자가 원하는 방식으로 만들어낼 수 있다.\
함수포인터로 함수를 받아서 처리한다면 컴파일러가 최적화를 할 수 없지만, Functor를 넘기게 되면, 컴파일러가 opreator() 자체를 인라인화 시켜서 매우 빠르게 작업을 수행할 수 있다.\

## 타입이 아닌 템플릿 인자 (non-type template arguments)
템플릿 인자로 타입만 받을 수 있는 것은 아니다.\
템플릿 인자로 전달 할 수 있는 타입들이 아래와 같이 제한 적이다.\
1. 정수 타입들(bool, char, int, long 등등). 당연히 float과 double은 제외
2. 포인터 타입
3. enum 타입
4. std::nullptr_t (널포인터)\

기존 C에서의 배열의 가장 큰 문제점은 함수에 배열을 전달할 때 배열의 크기에 대한 정보를 잃어버린다는 점\
템플릿 인자로 배열의 크기를 명시한다면, 위와 같은 문제를 해결 할 수 있다.\
std::array 를 통해 사용할 수 있다.\
std::array<int, 5> arr = {1, 2, 3, 4, 5};\
위 처럼 배열의 원소 타입과 크기를 템플릿 인자로 명시한 뒤에, 초기화만 해주면 된다.\
C에서 배열을 정의할 때 처럼 {} 를 이용해서 생성하며 된다.\
{}는 유니폼 초기화(Uniform initialization)이라 불리는 C++ 11에서 추가된 개념.\
arr은 런타임에서 동적으로 크기가 할당되는 것이 아니다. 마치 배열처럼 컴파일 시에 int 5개를 가지는 메모리를 갖고 스택에 할당된다.\
std::array를 받는 함수를 만들면 안된다. std::array<int, 5> 자체가 하나의 타입이기 때문에.\

void print_array(const std::array<int, 5>& arr)\
문제는 각 array 크기 별로 함수를 만들어줘야한다. -> 템플릿을 사용하여 해결\

## 디폴트 템플릿 인자
함수에 디폴트 인자를 지정할 수 있는 것처럼 템플릿도 디폴트 인자를 지정할 수 있다.\
template <typename T, int num = 5> 위 경우 num에 디폴트로 5가 전달\
타입 역시 디폴트로 지정이 가능\
template <typename T, typename Comp> -> template <typename T, typename Comp = Compare<T>>\
Comp로 디폴트 타입인 Compare<T>가 전달되어서 < 를 통해 비교 수행.
