/*
	셋 - set
*/
// #include <iostream>
// #include <set>

// template <typename T>
// void print_set(std::set<T>& s) {
// 	// 셋의 모든 원소들을 출력하기
// 	std::cout << "[ ";
// 	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
// 		std::cout << *itr << " ";
// 	std::cout << " ] " << std::endl;
// }

// int main() {
// 	std::set<int> s;
// 	s.insert(10);
// 	s.insert(50);
// 	s.insert(20);
// 	s.insert(40);
// 	s.insert(50);

// 	std::cout << "순서대로 정렬되서 나온다" << std::endl;
// 	print_set(s);

// 	std::cout << "20 이 s 의 원소인가요? :: ";
// 	auto itr = s.find(20);
// 	if (itr != s.end())
// 		std::cout << "Yes" << std::endl;
// 	else
// 		std::cout << "No" << std::endl;

// 	std::cout << "25 가  s 의 원소인가요? :: ";
// 	itr = s.find(25);
// 	if (itr != s.end())
// 		std::cout << "Yes" << std::endl;
// 	else
// 		std::cout << "No" << std::endl;
// }

/*	셋에는 중복된 원소들이 없다.*/
// #include <iostream>
// #include <set>

// template <typename T>
// void print_set(std::set<T>& s) {
// 	// 셋의 모든 원소들을 출력하기
// 	std::cout << "[ ";
// 	for (const auto& elem : s)
// 		std::cout << elem << " ";
// 	std::cout << " ] " << std::endl;
// }

// int main() {
// 	std::set<int> s;
// 	s.insert(10);
// 	s.insert(20);
// 	s.insert(30);
// 	s.insert(20);
// 	s.insert(10);

// 	print_set(s);
// }

/*
	내가 만든 클래스를 넣고 싶은데 주의해야할 점.
*/
// #include <iostream>
// #include <set>
// #include <string>

// template <typename T>
// void print_set(std::set<T>& s) {
//   // 셋의 모든 원소들을 출력하기
//   for (const auto& elem : s) {
//     std::cout << elem << " " << std::endl;
//   }
// }
// class Todo {
//   int priority;
//   std::string job_desc;

//  public:
//   Todo(int priority, std::string job_desc)
//       : priority(priority), job_desc(job_desc) {}

//   bool operator<(const Todo& t) const {
//     if (priority == t.priority) {
//       return job_desc < t.job_desc;
//     }
//     return priority > t.priority;
//   }

//   friend std::ostream& operator<<(std::ostream& o, const Todo& td);
// };

// std::ostream& operator<<(std::ostream& o, const Todo& td) {
//   o << "[ 중요도: " << td.priority << "] " << td.job_desc;
//   return o;
// }
// int main() {
//   std::set<Todo> todos;

//   todos.insert(Todo(1, "농구 하기"));
//   todos.insert(Todo(2, "수학 숙제 하기"));
//   todos.insert(Todo(1, "프로그래밍 프로젝트"));
//   todos.insert(Todo(3, "친구 만나기"));
//   todos.insert(Todo(2, "영화 보기"));

//   print_set(todos);

//   std::cout << "-------------" << std::endl;
//   std::cout << "숙제를 끝냈다면!" << std::endl;
//   todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
//   print_set(todos);
// }

/*
	외부 라이브러리랑 클래스 객체 셋 비교
*/
// #include <iostream>
// #include <set>
// #include <string>

// template <typename T, typename C>
// void print_set(std::set<T, C> &s)
// {
// 	// 셋의 모든 원소들을 출력하기
// 	for (const auto &elem : s)
// 	{
// 		std::cout << elem << " " << std::endl;
// 	}
// }

// class Todo
// {
// 	int priority;
// 	std::string job_desc;

// public:
// 	Todo(int priority, std::string job_desc)
// 		: priority(priority), job_desc(job_desc) {}

// 	friend struct TodoCmp;

// 	friend std::ostream &operator<<(std::ostream &o, const Todo &td);
// };

// struct TodoCmp
// {
// 	bool operator()(const Todo &t1, const Todo &t2) const
// 	{
// 		if (t1.priority == t2.priority)
// 		{
// 			return t1.job_desc < t2.job_desc;
// 		}
// 		return t1.priority > t2.priority;
// 	}
// };

// std::ostream &operator<<(std::ostream &o, const Todo &td)
// {
// 	o << "[ 중요도: " << td.priority << "] " << td.job_desc;
// 	return o;
// }

// int main()
// {
// 	std::set<Todo, TodoCmp> todos;

// 	todos.insert(Todo(1, "농구 하기"));
// 	todos.insert(Todo(2, "수학 숙제 하기"));
// 	todos.insert(Todo(1, "프로그래밍 프로젝트"));
// 	todos.insert(Todo(3, "친구 만나기"));
// 	todos.insert(Todo(2, "영화 보기"));

// 	print_set(todos);

// 	std::cout << "---------------" << std::endl;
// 	std::cout << "숙제를 끝냈다면!" << std::endl;
// 	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
// 	print_set(todos);
// }

// #include <iostream>
// #include <map>
// #include <string>

// template <typename K, typename V>
// void print_map(std::map<K, V> &m)
// {
// 	// 맵의 모든 원소들을 출력하기
// 	for (auto itr = m.begin(); itr != m.end(); ++itr)
// 	{
// 		std::cout << itr->first << " " << itr->second << std::endl;
// 	}
// }

// int main()
// {
// 	std::map<std::string, double> pitcher_list;

// 	// 맵의 insert 함수는 pair 객체를 인자로 받는다.
// 	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
// 	pitcher_list.insert(std::pair<std::string, double>("해커", 2.93));

// 	pitcher_list.insert(std::pair<std::string, double>("피어밴드", 2.95));

// 	// 타입을 지정하지 않아도 간단히 std::make_pair 함수로
// 	// std::pair 객체를 만들 수 있다.

// 	pitcher_list.insert(std::make_pair("차우찬", 3.04));
// 	pitcher_list.insert(std::make_pair("장원준", 3.05));
// 	pitcher_list.insert(std::make_pair("헥터", 3.09));

// 	// 혹은 insert 를 안쓰더라도 [] 로 바로
// 	// 원소를 추가할 수 있다.
// 	pitcher_list["니퍼트"] = 3.56;
// 	pitcher_list["박종훈"] = 3.76;
// 	pitcher_list["캘리"] = 3.90;

// 	print_map(pitcher_list);

// 	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
// }

/*
	find 함수를 이용해서 안전하게 키에 대응되는 값을 찾는 방법
*/
// #include <iostream>
// #include <map>
// #include <string>

// template <typename K, typename V>
// void print_map(const std::map<K, V> &m)
// {
// 	// kv 에는 맵의 key 와 value 가 std::pair 로 들어갑니다.
// 	for (const auto &kv : m)
// 	{
// 		std::cout << kv.first << " " << kv.second << std::endl;
// 	}
// }

// template <typename K, typename V>
// void search_and_print(std::map<K, V> &m, K key)
// {
// 	auto itr = m.find(key);
// 	if (itr != m.end())
// 	{
// 		std::cout << key << " --> " << itr->second << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << key << "은(는) 목록에 없습니다" << std::endl;
// 	}
// }

// int main()
// {
// 	std::map<std::string, double> pitcher_list;

// 	pitcher_list["오승환"] = 3.58;

// 	print_map(pitcher_list);
// 	std::cout << "-----------------" << std::endl;

// 	search_and_print(pitcher_list, std::string("오승환"));
// 	search_and_print(pitcher_list, std::string("류현진"));
// }

/*
	맵도 셋 처럼 중복된 값 무시
*/
#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::map<K, V> &m)
{
	// kv 에는 맵의 key 와 value 가 std::pair 로 들어갑니다.
	for (const auto &kv : m)
	{
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

int main()
{
	std::map<std::string, double> pitcher_list;

	// 맵의 insert 함수는 std::pair 객체를 인자로 받습니다.
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.93));

	print_map(pitcher_list);

	// 2.23 이 나올까 2.93 이 나올까?
	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
}