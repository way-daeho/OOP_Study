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
컴파일 시에 모든 템플릿들이 인스턴스화 되다는 사실을 갖고 또 여러가지 흥미로운 코드를 작성할 수 있게 해줌.