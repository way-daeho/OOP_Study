# 10 - 3 C++ STL - 알고리즘(algorithm)
## 다룰 함수 들
- 람다 함수 (lambda function)
- 정렬 알고리즘
- 원소 삭제 알고리즘
- 원소 탐색 알고리즘

template <typename Iter>
void do_something(Iter begin, Iter end);

tempalate <typename Iter, typename Pred>
void do_something(Iter beginm Iter end, Pred pred);
와 같은 모양이다.

전자의 경우, 알고리즘을 수행할 반복자의 시작점과 끝점 바로 뒤를 받고, 후자의 경우 반복자는 동일하게 받되, '특정한 조건'을 추가 인자로 받게 된다.
### '특정한 조건'을 서술자(Predicate) 라고 부르며, Pred 에는 보통 bool 을 리턴하는 함수 객체(Functor) 를 전달 하게 된다.

## 정렬 (sort, stable_sort, partial_sort)
정렬 알고리즘에서 3 가지 종류의 함수를 지원한다.
1. sort : 일반적인 정렬 함수
2. stable_sort : 정렬을 하되 원소들 간의 순서를 보존.
만약 벡터에 [a, b] 순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a, b] 혹은 [b, a] 로 할 수 있다.
sort 의 경우 그 순서가 랜덤으로 정해짐.
stable_sort 의 경우 그 순서를 반드시 보존, 즉 컨테이너 상에서 [a,b] 순으로 있었다면 정렬 시에도 (크기가 같다면) [a, b]순으로 나오게 된다. -> 이 때문에 sort 보다 좀 더 느리다.
3. partial_sort : 배열의 일부분만 정렬한다.
----
sort(vec.begin(), vec.end());
sort 함수는 정렬한 원소의 시작 위치와, 마지막 위치 바로 뒤를 반복자로 받는다.
sort에 들어가는 반복자의 경우 반드시 임의접근 반복자(RandomAccessIterator) 타입을 만족해야한다.
벡터와 데크만 가능하고, 나머지 컨테이너는 sort 함수를 적용할 수 없다.
sort 함수는 기본적으로 오름차순으로 정렬해준다.
직접 만든 타입이였다면 단순히 operator < 를 반대로 바꿔준다면 오름차순 -> 내림차순.
대부분 알고리즘은 3 번째 인자로 특정한 조건을 전달한다고 했다.

struct int_compare {
	bool operator() (const int& a, const int& b) const { return a > b; }
};
위와 같이 함수 객체를 위한 구조체를 정의, 그 안에 opreator() 함수를 만들어주면 함수 객체 준비 완료.

std::sort(vec.begin(), vec.end(), int_compare());
함수객체를 전달하면 된다.
int 나 string 과 같은 기본 타입들은 모두 < 혹은 > 연산자들이 기본으로 내장.
굳이 귀찮게 함수 객체를 만들 필요 없다.

template <typename T>
struct greater_comp {
	bool operator() (const T& a, const T& b) const { return a > b; }
};
이러한게 있어 int, string 형 따로 만들 필요 없다.

functional 헤더에 다음과 같은 템플릿 클래스가 존재한다.

std::sort(vec.begin(), vec.end(), greater<int>());
greater 에 우리가 사용하고자 하는 타입을 넣게 되면 위와 같은 함수 객체를 자동으로 만들어준다.

### partial_sort 함수
partial_sort 일부만 정렬하는 함수
std::partial_sort(start, middle, end)
이 때 정렬을 [start, end) 전체 원소들 중에서 [start, middle) 까지 원소들이 전체 원소들 중에서 제일 작은 애들 순으로 정렬 시킨다.

std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
vec.begin() ~ vec.end() 까지 vec.begin() ~ vec.begin() + 3 까지 전체에서 가장 작은 애들만 순서대로 저장하고 나머지 위치는 상관 없다.

전체 원소의 개수가 N 개이고, 정렬하려는 부분의 크기가 M 이라면, partial_sort의 복잡도는 O(Nlog M)

100 명의 학생 중 상위 10 명의 학생의 성적순
sort X -> partial_sort()

### stable_sort
원소들 간의 순서를 보존하낟.
같은 age 라면 반드시 삽입된 순서, 즉 name 순으로 나올 것이다.(왜냐면 애초에 name 순으로 넣었기 때문.)
sort 함수의 경우 정렬 과정에서 원소들 간의 상대적 위치를 랜덤하게 바꿔버리지만. stable_sort 의 경우 그 순서를 처음에 넣었던 상태 그대로 유지함

이러한 제약 조건 때문에 stable_sort 는 그냥 sort 보다 좀 더 오래 걸린다.
C++ 표준에 따르면 sort 함수는 최악의 경우에서도 O(n log n) 이 보장, stable_sort 의 경우 최악의 경우  O(n (log n) ^ 2) 으로 작동한다.

## 원소 제거 (remove, remove_if)
대부분의 컨테이너에서는 원소를 제거하는 함수를 지원하고 있다.
std::vector<int> vec;
vec.erase(vec.begin() + 3);
vec[3]에 해당하는 원소를 제거하게 된다.

erase 함수는 2 가지 형태가 있다.
Iterator erase(Iterator pos);
Iterator erase(Iterator first, Iterator last);
 
전자의 경우 그냥 pos 가 가리키는 워놋를 벡터에서 지운다.
후자의 경우 first ~ last 사이에 있는 모든 원소들을 지우는 형태이다.

지우려는 원소를 만나면 뒤에 있는 원소들로 쉬프트 해준다.
자연스럽게 알고리즘이 끝나게 되면 해당하는 위치에 전 까지 3이 제외된 원소들로 채워져있다.

다시 말해, 반복이 끝나느 위치부터 벡터 맨 뒤 까지 제거해버리면 지우려는 원소가 삭제된 벡터만 남는다.
remove 함수는 원소의 이동만을 수행하지, 실제로 원소를 삭제하는 연산을 수행하지 않는다.
실제로 원소를 지우기 위해서는 반드시 erase 함수를 호출하여 실제로 원소를 지워줘야만 한다.

vec.erase(remove(vec.begin(), vec.end(), 3), vec.end());

remove 함수를 이용해서 값이 3인 원소들을 뒤로 보내고, 그 원소들을 벡터에서 삭제해버린다.
remove 함수의 경우 반복자의 타입이 ForwardIterator
벡터 뿐만이 아닌, 리스트 혹은 셋이나 맵에서도 모두 사용할 수 있다.

특정한 조건을 만족하는 원소들을 제거하기 위해 remove_if 함수를 사용한다.

remove_if 함수는 세 번째 인자로 조건을 섦여할 함수 객체를 전달 받는다.

함수 객체로 실제 함수를 전달할 수 있다.

### remove_if 에 조건 추가하기
remove_if 에 전달되는 함수 객체의 경우 이전의 호출에 의해 내부 상태가 달라지면 안된다.
함수 객체 안에 인스턴스 변수를 넣는 것은 원칙상 안된다.
그 이유 -> 실제로 구현 했을 떄, 해당 함수 객체가 여러번 복사될 수 있기 때문.
-> 물론 어떻게 구현하냐에 따라 다름.

함수 객체에는 절대로 특정 상태를 저장해서 이에 따라 결과가 달라지는 루틴을 짜면 안된다.

위 문제를 해결하는 한 가지 방법은 num_delete 를 객체 내부 변수가 아니라 외부 변수로 빼는 방법.
함수 객체에 내부 상태인 num_delete 의 주소값은 변하지 않기 때문에 문제될 것이 없다.

### STL을 사용할 때 마다 외부에 클래스난 함수를 하나씩 만들어줘야 한다..
가장 이상적인 방법은 STL 알고리즘을 사용할 때 그안에 직접 써놓는다. -> 클래스 혹은 함수가 무엇을 하는지 궁금증이 발생할 수 있다!
vec.erase(std::remove_if(vec.begin(), vec.end(),
                         bool is_odd(int i) { return i % 2 == 1; }),
          vec.end());
		-> C++ 11 부터 위 방법을 해결
---
## 람다 함수(lambda function)
이름이 없는 함수 객체를 만들 수 없게(?) 있게 됐다. 익명의 함수 객체
람다 함수 정의 부
[](int i) -> bool { return i % 2 == 1; }
람다 함수는 위와 같은 꼴로 정의
[capture list] (받는 인자) -> 리턴 타입 { 함수 본체 }
return 타입을 생략한다면 컴파일러가 알아서 함수 본체에서 return 문을 보고 리턴 타입을 추측

리턴 타입을 생략할  경우
[capture list] (받는 인자) { 함수 본체 }

람다 함수도 함수 이기 때문에 자기 자신만의 스코프를 가진다. 따라서 일반적인 상황이라면 함수 외부에서 정의된 변수들을 사용할 수 없다.

람다 함수는 람다 함수 외부에 있는 변수에 접근 할 수 있다. -> 캡쳐 목록 (capture list) 을 사용하는 것.

캡쳐 목록에는 어떤 변수를 캡쳐할 지 써주면 된다.
람다 함 내에서 스코프 안에 있는 것 처럼 사용할 수 있게 된다.

&를 안붙히면 복사본을 얻게 되는데, 그 복사본의 형태는 const이다.
그렇다면 클래스의 멤버 함수안에서 람다를 사용할 때 멤버 변수들을 참조하려면 어떻게 해야할까?

객체에 종속되어 있는 멤버 변수를 사용하기 위해선 this를 사용한다. &를 사용할 경우 멤버 변수가 아닌 일반 변수로 생각한다.

this를 복사본으로 전달(this는 레퍼런스로 전달 할 수 없다) 함수 안에서는 this 를 이용해서 멤버 변수들을 참조해서 사용하면 된다.

#### 캡쳐 리스트의 사용 방법
1. [] : 아무것도 캡쳐 안함
2. [&a, b] : a는 레퍼런스로 캡쳐 b는 (변경 불가능한) 복사본으로 캡쳐
3. [&] : 외부의 모든 변수들을 레퍼런스로 캡쳐
4. [=] : 외부의 모든 변수들을 복사본으로 캡쳐

## 원소 수정하기 (transform)
원소들을 수정하는 함수들
transform 함수 꼴
transform (시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred)

* 주의해야할 점 *
저장하는 컨테이너의 크기가 원래의 컨테이너보다 최소한 같거나 커야 된다.

transform 함수로 for 문을 쓸 필요도 없어질 뿐더러, 이 코드에서 무슨 일을 하는지 더 간단 명료하게 나타낼 수 있다.

## 원소를 탐색하는 함수 (find, find_if, any_of, all_of 등등)
find 함수는 단순히
template <class InputIt, classT>
InputIt find(Input first, Input last, const T& value)
와 같이 생겼다. 
first 부터 last 까지 쭈르륵 순회함녀서 value와 같은 원소가 있는지 확인하고 있으면 이를 가리키는 반복자를 리턴한다.
반복자에 따라서 forward_iterator 면 앞에서 부터 찾고, reverse_iterator 이면 뒤에서 부터 거꾸로 찾는다.
컨테이너에 중복되는 값이 있더라도 가장 먼저 찾은 것을 리턴한다.

current = find(current, vec.end(), 3);
마지막으로 찾은 위치 바로 다음부터 게속 순차적으로 탐색해 나가면 컨테이너에서 값이 3인 원소들을 모두 찾을 수 있게 된다.

다만 find 계열의 함수들을 사용할 때 한 가지 주의할 점
만약 컨테이너에 기본적으로 find 함수를 지원한다면 이를 사용하는 것이 훨씬 빠름.
알고리즘 라이브러리에서의 find  함수는 그 컨테이너가 어떠한 구조를 갖고 있는지에 대한  정보가 하나도 없기 때문.

EX) set 의 경우, set 에서 사용하는 find 함수의 경우 O(log n) 으로 수행될 수 있는데,
그 이유는 셋 내부에서 원소들이 정렬되어 있기 때문.
unordered_set 의 경우 find 함수가 O(1)로 수행될 수 있는데, 그 이유는 unordered_set 내부에서 자체적으로 해시 테이블을 이용해서 원소들을 빠르게 탐색해 나갈 수 있기 때문.

하지만 알고리즘 라이브러리의 find 함수의 경우 이러한 추가 정보가 있는 것을 하나도 모른채 처음부터 하나씩 확인해 나가므로 평범한 O(n) 으로 처리된다.

find 함수를 지원하지 않는 컨테이너에서 find 함수를 사용할 것!

## any_of && all_of

1. any_of : 인자로 받은 범위안의 모든 원소들중에서 조건을 하나라도 충족하는 것이 있다면 true 리턴

2. all_of : 모든 원소들이 전부 조건을 충족해야 true를 리턴.

any_of 는 OR 연산과 비슷 all_of 는 AND 연산과 비슷

----
# 10 - 4 C++ 문자열의 모든 것 (string 과 string_view)
이번 강좌에서 다룰 것들
- basic_string
- 유니코드와 여러가지 인코딩 방식
- string_view

## basic_string
std::string 은 사실 basic_string 이라는 클래스 템플릿의 인스턴스화 버전

basic_string 의 정의
template <class CharT, class Traits = std::char_traits<CharT>,
		  class Allocator = std::allocator<CharT> >
class basic_string;

basic_string 은 CharT 타입의 객체들을 메모리에 연속적으로 저장하고, 여러가지 문자열 연산들을 지원해주는 클래스.
만약 CharT 자리에 char 이 오게 된다면, 우리가 생각하는 std::string이된다.

우리가 아는 string 말고도 총 5가지 종류의 인스턴스화 된 문자열들이 있다.


타입					정의								비고
std::string			   std::basic_string<char>			 
std::wstring		   std::basic_string<wchar_t>		  wchar_t 의 크기는 시스템마다 다름. 윈도우 -> 2바이트, 유닉스 -> 4바이트	
std::u8string		   std::basic_string<char8_t>		 C++20 에 새로 추가됌. char8_t -> 1바이트; UTF-8 문자열을 보관할 수 있음.
std::u16string		   std::basic_string<char16_t>		 char16_t 는 2바이트; UTF-16 문자열을 보관할 수 있음
std::u32string		   std::basic_string<char32_t>		 char32_t 는 4바이트; UTF-32 문자열을 보관할 수 있음


Traits는 주어진 CharT 문자들에 대해 기본적인 문자열 연산들을 정의해놓은 클래스 의미
주어진 문자열의 대소 비교를 어떻게 할 것인지, 주어진 문자열의 길이를 어떻게 잴 것인지 등등을 말한다.

basic_string 에 정의된 문자열 연산들은 사실 전부다 Traits의 기본적인 문자열 연산들을 갖고 정의.
문자열들을 어떻게 보관하는지에 대한 로직 -> basic_string 
문자열들을 어떻게 연산하는지에 대한 로직 -> Traits

로직을 분리한 이유>? -> basic_string 의 사용자에게 좀 더 자유를 부여.

Traits 가 어떻게 활용될까?

struct my_char_traits : public std::char_traits<char>

-> basic_string 의 Traits 에는 char_traits 에서 제공하는 모든 멤버 함수들이 구현된 클래스가 전달되어야한다.
(꼭 char_traits 를 상속 받을 필요는 없다.)

이를 가장 간편히 만들기 위해선 그냥 char_traits 를 상속 받은 후, 필요한 부분만 새로 구현.

char_trait 에 정의되는 함수들은 모두 static 함수들
그 이유는 char_traits 의 존재 이유를 생각해보면 당연한데, Traits 는 문자와 문자열들 간에 간단한 연산을 제공해주는 클래스, 굳이 데이터를 저장할 필요가 없기 때문.(이를 보통 Stateless 하다고 한다.)

일반적인 char 들을 다루는 char_traits<char> 에서 우리가 바꿔줘야할 부분은 대소 비교하는 부분뿐

### 짧은 문자열 최적화 (SSO)
메모리 할당하는 작업 -> 시간을 꽤나 잡아 먹는다.

basic_string 이 저장하는 문자열의 길이는 천차 만별. 매번 모든 문자열을 동적으로 메모리를 할당 받는 다고 하면, 굉장히 비효율적.

따라서, basic_string 의 제작자들은 짧은 길이 문자열의 경우 따로 문자 데이터를 위한 메모리를 할당하는 대신에 그냥 객체 자체에 저장해버린다.
이를 짧은 문자열 최적화(SSO - short string optimization) 이라 부른다.

new 의 경우 클래스 외부의 험수로 정의, 새로 new 연산자 정의 new 의 경우 위와 같이 클래스 외부의 함수로 정의하게 된다면 모든 new 연산자들이 위 함수를 사용하게 된다. 반면에 클래스 내에 멤버 함수로 new를 정의하게 된다면, 해당 객체를 new 로 생성할 때 해당 함수가 호출된다.

대부분의 주류 C++ 라이브러리 들은 어떤 방식이든 SSO 를 사용하고 있다.

## 문자열 리터럴 정의하기
C 에서 문자열 리터럴을 정의하기 위해선 아래와 같이 했다.
const char* s = "hello";
// 혹은
char s[] = "hello";

위 두 s 모두 "hello" 라는 문자열을 보관
C++ 의 경우
auto str = "hello"
를 하면 str는 string? -> X
C++ 에서는 C와 마찬가지로 str의 타입은 const char * 로 정의된다.
string str = "hello" or auto str = "hello"s;
"" 뒤에 s를 붙여주면 auto가 string으로 추론

std::string operator"" s(const char *str, std::size_t len);
처럼 정의
"hello"s 컴파일 과정에서 operator""s("hello", 5); 로 바뀌게 된다.
해당 리터럴 연산자를 사용하기 위해선 std::string_literals 네임 스페이스를 사용해야한다.

리터럴 연산자는 문자열 리터럴 뿐 아니라 정수나 부동 소수점 리터럴들 역시 사용 가능.

#### 그 외의 여러가지 리터럴 정의 방법
C++ 에는 "" 말고도 문자열 리터럴을 정의하는 몇 가지 방법이 더 있다.
std::string str = "hello"; // char []
std::wstring wstr = L"hello" // wchar_t[]

C+11 에 추가된 유용한 기능 Raw string literal 생김
R"()" 안에 오는 문자들은 모두 문자 그대로 char 배열 안에 들어가게 된다.
한가지 문제는 닫는 괄호 )" 를 문자열 안에 넣을 수 없다는 점인데, 이는 구분 문자를 추가함으로써 해결할수 있다.

Raw string 문법을 정확히 살펴보자면
R"/* delimiter */( /* 문자열 */ )/* delimiter */"

## C++ 에서 한글 다루기
인코딩(Encoding)
동일하게 4 바이트를 사용하는 대신에, 어떤 문자는 1 바이트, 어떤 건 2바이트 등등의 길이로 저장
- UTF-8 : 문자를 최소 1 부터 최대 4 바이트로 표현(즉 문자마다 길이가 다르다!)
- UTF-16 : 문자를 2 혹은 4 바이트로 표현한다.
- UTF=32 : 문자를 4 바이트로 표현한다.
UTF-32 의 경우 모든 문자들을 4 바이트로 할당하기 때문에 다루기가 매우 간단

std::u32string u32_str = U"이건 UTF-32 문자열 입니다";
u32string C++ 에서 UTF-32로 인코딩된 문자열을 보관하는 타입, "" 앞에 붙은 U 는 해당 문자열 리터럴이 UTF-32

### UTF-8 인코딩
UTF-32 방식의 인코딩은 다루기에 직관적, 자주 사용되는 인코딩 방식은 아님.
모든 문자에 4 바이트 씩 할당하는 것이 매우 비효율적.
현재 웹 상에서 많이 사용되는 UTF-8

""앞에 u8 을 써주면 된다. 대부분의 시스템의 경우 굳이 u8 을 안붙여도 파일의 형식이 UTF-8일 것.
UTF-8 인코딩 방식이 문자들에 최소 1바이트 부터 최대 4바이트 까지 지정.
UTF-8 인코딩 방식의 문자열은 char 원소들로 보관, 어떤 문자는 char 1 개 만으로 충분, 어떤 원소는 char 2, 3, 4개 까지 필요로 한다.

앞서 위에 있는 UTF-8 인코딩 방식을 살펴보면, 4 바이트로 인코딩되는 문자들은 첫 번째 바이트가 11110xxx 꼴입니다. 11111000 과 AND 연산을 했을 때 11110000 이 나오는 비트 형태는 11110xxx 형태 밖에 없으므로 성공적으로 분류를 하고 있다고 알 수 있습니다.

 char_size 만큼을 읽어서 인코딩 된 문자를 정확하게 출력할 수 있습니다.

물론 UTF-8 형식의 문자열을 저장햇다고 해서 basic_string 의 정의된 연산들을 사용할 수 없는 것은 아닙니다. size() 를 제외한 다른 모든 연산들은 문자열의 인코딩 방식과 무관합니다. 예를 들어서 문자열에서 원하는 글자를 검색하는 것은 인코딩과 무관하게 수행할 수 있습니다.

UTF-8 문자 그대로 한글 문자열을 다루는 것은 불편합니다. 특히 영문자와 섞여 있을 경우 알파벳은 1 바이트지만 한글은 3 바이트로 해석되기 때문에 반복자를 통해서 문자들을 순차적으로 뽑아내기 힘들지요. 하지만 UTF-16 인코딩 방식을 사용하면 이야기가 달라집니다.

### UTF-16 인코딩
UTF-16 인코딩은 최소 단위가 2 바이트 입니다. 따라서 UTF-16 으로 인코딩 된 문자열을 저장하는 클래스인 u16string 도 원소의 타입이 2 바이트 (char16_t) 입니다.

 UTF-16 인코딩 방식으로는 대부분의 문자들이 2 바이트로 인코딩
 이모지나 이집트 상형문자와 같이 유니코드 상 높은 번호로 매핑되어 있는 애들은 4 바이트로 인코딩

 C++ 에는 요즘 나온 Go언어 처럼 인코딩된 문자열을 언어 단에서 간단히 처리할 수 있는 방법은 없다.

 가장 편한 방법은 UTF-32 인코딩으로 바꿔버리는 것, 단 메모리 사용량을 매우 증가시킴

UTF-CPP 라는 C++에서 여러 방식으로 인코딩된 문자열을 쉽게 다룰 수 있게 도와주는 라이브러리가 있다.

## string_view
만일 어떤 함수에다 문자열을 전달할 때, 문자열 읽기 만 필요로 한다면 보통 const std::string& 으로 받던지 아니면 const char* 형태로 받게 됩니다.

하지만 각각의 방식은 문제점이 있습니다. 먼저 const string& 형태로 받을 경우

문제는 contains_very 함수에 문자열 리터럴을 전달한다면 (이는 const char*), 인자는 string 만 받을 수 있기 때문에 암묵적으로 string 객체가 생성된다는 점입니다. 따라서 위 출력 결과 처럼 불필요한 메모리 할당이 발생한 것을 볼 수 있습니다.

그렇다면 contains_very 함수를 const char* 형태의 인자로 받도록 바꾸면 안될까요? 그렇다면 두 가지 문제가 발생합니다.

먼저 string 을 함수에 직접 전달할 수 없고 c_str 함수를 통해 string 에서 const char* 주소값을 뽑아내야 합니다.

const char* 로 변환하는 과정에서 문자열의 길이에 대한 정보를 읽어버리게 됩니다. 만일 함수 내부에서 문자열 길이 정보가 필요 하다면 매 번 다시 계산해야 합니다.

이러한 연유로, contains_very 함수를 합리적으로 만들기 위해서는 const string& 을 인자로 받는 오버로딩 하나, 그리고 const char* 을 인자로 받는 오버로딩 하나를 각각 준비해야 한다는 문제점이 있었습니다.

위와 같은 문제는 C++17 에서 string_view 가 도입됨으로써 해결

string_view 는 문자열을 읽기 만 하는 클래스
string_view 는 문자열을 소유하고 있지 않다.
즉, 어딘가 존재하는 문자열을 참조해서 읽기만 하는 것.
string_view	가 현재 보고 있는 문자열이 소멸된다면 정의되지 않은 작업(Undefined behavior) 이 발생

/* 주의 사항*/
string_view 는 문자열을 소유하고 있지 않기 때문에 현재 읽고 있는 문자열이 소멸되지 않은 상태인지 주의해야한다.

문자열을 소유하지 않고 읽기만 한다는 특성 때문에 string_view 객체 생성시에 메모리 할당이 불필요
-> 그냥 읽고 있는 문자열의 시작 주소값만 복사하면 되기 때문.
string 이나 const char *을 전달하더라도 메모리 할당이 발생하지 않는다.

const char* 을 인자로 받았을 때에 비해 string 의 경우 문자열 길이가 그대로 전달되므로 불필요한 문자열 길이 계산을 할 필요가 없다.
const char* 에서 string_view 를 생성하면서 문자열 길이를 한 번만 계산하면 되므로 효율적
string_view 에서 제공하는 연산들은 당연히도 원본 문자열을 수정하지 않는 연산들 입니다. 대표적으로 find 와 부분 문자열을 얻는 substr 을 들 수 있습니다. 특히 string 의 경우 substr 이 실제로 부분 문자열을 새로 생성해야 하기 때문에 
O(n) 으로 수행되지만, string_view 의 경우 substr 로 또다른 view 를 생성하므로 
O(1) 로 매우 빠르게 수행됩니다.

-----
# 뭘 배웠지?
std::string 은 basic_string 의 char 을 인자로 갖는 템플릿 인스턴스화 버전입니다. 그 외에도 u8string, u16string, u32string 이 있고 각각은 UTF-8, UTF-16, UTF-32 으로 인코딩 된 문자열을 보관할 수 있습니다.

std::char_traits 를 사용해서 사용자가 원하는 기능을 가진 문자열을 생성할 수 있습니다.

유니코드는 전세계의 모든 문자들을 컴퓨터에서 표현하고자 각각의 문자에 대해 고유의 코드를 부여한 것입니다. 코드 그대로 그냥 저장하려면 4 바이트가 필요한데, 이는 매우 비효율적이므로 여러가지 인코딩 을 통해서 크기를 줄일 수 있습니다. 하지만 이 때문에 문자별로 인코딩 되는 길이가 다르다는 문제점이 있습니다.

string_view 를 통해서 불필요한 복사를 막고 const char* 과 const string& 사이에서 깔끔하게 처리할 수 있습니다.