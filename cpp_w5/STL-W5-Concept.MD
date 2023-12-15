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