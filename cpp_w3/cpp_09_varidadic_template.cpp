/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_09_varidadic_template.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:59:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/03 15:54:33 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	가변 길이 템플릿
*/

// #include <iostream>

// template <typename T>
// void print(T arg) { // 1번
// 	std::cout << arg << std::endl;
// }

// template <typename T, typename... Types>
// void print(T arg, Types... args) { // 2번
// 	std::cout << arg << ", ";
// 	print(args...);
// }

// int main() {
// 	print(1, 3.1, "abc");
// 	print(1, 2, 3, 4, 5, 6, 7);
// }

/*
	임의의 개수의 문자열을 합치는 함수

	std::string concat;
	concat.reserve(s1.size() + s2.size() + s3.size()); // 여기서 할당 1번 수행
	concat.append(s1);
	concat.append(s2);
	concat.append(s3);

	std::string concat = Strcat(s1, "abc", s2, s3);
*/

// 첫 번째 시도 -> 문제점 std::string의 operator+를 매번 호출하는 셈
// #include <iostream>
// #include <string>

// template <typename String>
// std::string StrCat(const String &s)
// {
// 	return std::string(s);
// }

// template <typename String, typename... Strings>
// std::string StrCat(const String &s, Strings... strs)
// {
// 	return std::string(s) + StrCat(strs...);
// }

// int main()
// {
// 	// std::string 과 const char *을 혼합해서 사용 가능하다.
// 	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
// 						" ", std::string("sentence"));
// }

// 두 번째 시도
// #include <cstring>
// #include <iostream>
// #include <string>

// size_t GetStringSize(const char *s) { return strlen(s); }

// size_t GetStringSize(const std::string &s) { return s.size(); }

// template <typename String, typename... Strings>
// size_t GetStringSize(const String &s, Strings... strs)
// {
// 	return GetStringSize(s) + GetStringSize(strs...);
// }

// void AppendToString(std::string *concat_str) { return; }

// template <typename String, typename... Strings>
// void AppendToString(std::string *concat_str, const String &s, Strings... strs)
// {
// 	concat_str->append(s);
// 	AppendToString(concat_str, strs...);
// }

// template <typename String, typename... Strings>
// std::string StrCat(const String &s, Strings... strs)
// {
// 	// 먼저 합쳐질 문자열의 총 길이를 구한다.
// 	size_t total_size = GetStringSize(s, strs...);

// 	// reserve 를 통해 미리 공간을 할당해 놓는다.
// 	std::string concat_str;
// 	concat_str.reserve(total_size);

// 	concat_str = s;
// 	AppendToString(&concat_str, strs...);

// 	return concat_str;
// }

// int main()
// {
// 	// std::string 과 const char * 을 혼합해서 사용 가능하다.
// 	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
// 						" ", std::string("sentence"));
// }

/*
	sizeof...
*/

// #include <iostream>

// // 재귀 호출 종료를 위한 베이스 케이스
// int sum_all() { return 0; }

// template <typename... Ints>
// int sum_all(int num, Ints... nums)
// {
// 	return num + sum_all(nums...);
// }

// template <typename... Ints>
// double average(Ints... nums)
// {
// 	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
// }

// int main()
// {
// 	// (1 + 4 + 2 + 3 + 10) / 5
// 	std::cout << average(1, 4, 2, 3, 10) << std::endl;
// }

// #include <iostream>

// template <typename... Ints>
// int sum_all(Ints... nums)
// {
// 	return (... + nums);
// }

// int main()
// {
// 	// 1 + 4 + 2 + 3 + 10
// 	std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;
// }

/* 이항 Fold의 예시 */
// #include <iostream>

// template <typename Int, typename... Ints>
// Int diff_from(Int start, Ints... nums)
// {
// 	return (start - ... - nums);
// }

// int main()
// {
// 	// 100 - 1 - 4 - 2 - 3 - 10
// 	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;
// }

// #include <iostream>

// class A
// {
// public:
// 	void do_something(int x) const
// 	{
// 		std::cout << "Do something with " << x << std::endl;
// 	}
// };

// template <typename T, typename... Ints>
// void do_many_things(const T &t, Ints... nums)
// {
// 	// 각각의 인자들에 대해 do_something 함수들을 호출한다.
// 	(t.do_something(nums), ...);
// }
// int main()
// {
// 	A a;
// 	do_many_things(a, 1, 3, 2, 4);
// }