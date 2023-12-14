// #include <algorithm>
// #include <iostream>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << *begin << " ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(6);
// 	vec.push_back(4);
// 	vec.push_back(7);
// 	vec.push_back(2);

// 	std::cout << "정렬 전 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// 	std::sort(vec.begin(), vec.end());

// 	std::cout << "정렬 후 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// }

// #include <algorithm>
// #include <iostream>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << *begin << " ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }

// struct int_compare
// {
// 	bool operator()(const int &a, const int &b) const { return a > b; }
// };

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(6);
// 	vec.push_back(4);
// 	vec.push_back(7);
// 	vec.push_back(2);

// 	std::cout << "정렬 전 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// 	std::sort(vec.begin(), vec.end(), int_compare());

// 	std::cout << "정렬 후 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// }

/* partial_sort 함수 */
// #include <algorithm>
// #include <iostream>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << *begin << " ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(6);
// 	vec.push_back(4);
// 	vec.push_back(4);
// 	vec.push_back(7);
// 	vec.push_back(2);

// 	std::cout << "정렬 전 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// 	std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());

// 	std::cout << "정렬 후 ----" << std::endl;
// 	print(vec.begin(), vec.end());
// }

/* stable_sort */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// struct User
// {
// 	std::string name;
// 	int age;

// 	User(std::string name, int age) : name(name), age(age) {}

// 	bool operator<(const User &u) const { return age < u.age; }
// };

// std::ostream &operator<<(std::ostream &o, const User &u)
// {
// 	o << u.name << " , " << u.age;
// 	return o;
// }

// int main()
// {
// 	std::vector<User> vec;
// 	for (int i = 0; i < 100; i++)
// 	{
// 		std::string name = "";
// 		name.push_back('a' + i / 26);
// 		name.push_back('a' + i % 26);
// 		vec.push_back(User(name, static_cast<int>(rand() % 10)));
// 	}

// 	std::vector<User> vec2 = vec;

// 	std::cout << "정렬 전 ----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::sort(vec.begin(), vec.end());

// 	std::cout << "정렬 후 ----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "stable_sort 의 경우 ---" << std::endl;
// 	std::stable_sort(vec2.begin(), vec2.end());
// 	print(vec2.begin(), vec2.end());
// }

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상테 -----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 값이 3 인 원소 제거 ---" << std::endl;
// 	vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
// 	print(vec.begin(), vec.end());
// }

/* remove_if 함수 */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// struct is_odd
// {
// 	bool operator()(const int &i) { return i % 2 == 1; }
// };

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상태 -----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 홀수인 원소 제거 ---" << std::endl;
// 	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
// 	print(vec.begin(), vec.end());
// }

/* 	remove_if 함수 조건 주기 */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// struct is_odd
// {
// 	int num_delete;

// 	is_odd() : num_delete(0) {}

// 	bool operator()(const int &i)
// 	{
// 		if (num_delete >= 2)
// 			return false;

// 		if (i % 2 == 1)
// 		{
// 			num_delete++;
// 			return true;
// 		}

// 		return false;
// 	}
// };
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상태 ------" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 홀수인 원소 앞의 2개 제거 ---" << std::endl;
// 	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
// 	print(vec.begin(), vec.end());
// }

/* 객체 내부 변수가 아닌 외부 변수로 뺀다! */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// struct is_odd
// {
// 	int *num_delete;

// 	is_odd(int *num_delete) : num_delete(num_delete) {}

// 	bool operator()(const int &i)
// 	{
// 		if (*num_delete >= 2)
// 			return false;

// 		if (i % 2 == 1)
// 		{
// 			(*num_delete)++;
// 			return true;
// 		}

// 		return false;
// 	}
// };
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상태 ------" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 홀수인 원소 앞의 2개 제거 ---" << std::endl;
// 	int num_delete = 0;
// 	vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd(&num_delete)),
// 			  vec.end());
// 	print(vec.begin(), vec.end());
// }

/* 람다 함수 */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }
// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상태 -----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 홀수인 원소 제거 ---" << std::endl;
// 	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) -> bool
// 							 { return i % 2 == 1; }),
// 			  vec.end());
// 	print(vec.begin(), vec.end());
// }

/* 람다 함수 -> 캡쳐 목록 */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 보는 vec 상태 -----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터에서 홀수인 원소 ---" << std::endl;
// 	int num_erased = 0;
// 	vec.erase(std::remove_if(vec.begin(), vec.end(), [&num_erased](int i)
// 							 {
// 		if (num_erased >= 2)
// 			return false;
// 		else if (i % 2 == 1){
// 			num_erased++;
// 			return true;
// 		}
// 		return false; }),
// 			  vec.end());
// 	print(vec.begin(), vec.end());
// }

/* transform 함수 */
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "처음 vec 상태 -----" << std::endl;
// 	print(vec.begin(), vec.end());

// 	std::cout << "벡터 전체에 1 을 더한다" << std::endl;
// 	std::transform(vec.begin(), vec.end(), vec.begin(), [](int i)
// 				   { return i + 1; });
// 	print(vec.begin(), vec.end());
// }

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <string>
// #include <vector>

// template <typename Iter>
// void print(Iter begin, Iter end)
// {
// 	while (begin != end)
// 	{
// 		std::cout << "[" << *begin << "] ";
// 		begin++;
// 	}
// 	std::cout << std::endl;
// }

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(5);
// 	vec.push_back(3);
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	// vec2 에는 6 개의 0 으로 초기화 한다.
// 	std::vector<int> vec2(6, 0);

// 	std::cout << "처음 vec 과 vec2 상태 ------" << std::endl;
// 	print(vec.begin(), vec.end());
// 	print(vec2.begin(), vec2.end());

// 	std::cout << "vec 전체에 1 을 더한 것을 vec2 에 저장 -- " << std::endl;
// 	std::transform(vec.begin(), vec.end(), vec2.begin(),
// 				   [](int i)
// 				   { return i + 1; });
// 	print(vec.begin(), vec.end());
// 	print(vec2.begin(), vec2.end());
// }

/* 원소를 탐색하는 함수 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end)
{
	while (begin != end)
	{
		std::cout << "[" << *begin << "] ";
		begin++;
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	auto result = std::find(vec.begin(), vec.end(), 3);
	std::cout << "3 은 " << std::distance(vec.begin(), result) + 1 << " 번째 원소"
			  << std::endl;
}