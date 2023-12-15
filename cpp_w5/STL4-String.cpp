/* 숫자들의 순위가 알파벳 보다 낮은 문자열
	Traits 가 어떻게 활용될까 ?
	Traits 클래스를 오버로딩해서 문자열 비교 시의 숫자들의 순위가 제일로 낮은 문자열 만들어 보기
 */

// #include <cctype>
// #include <iostream>
// #include <string>

// // char_traits 의 모든 함수들은 static 함수 입니다.
// struct my_char_traits : public std::char_traits<char>
// {
// 	static int get_real_rank(char c)
// 	{
// 		// 숫자면 순위를 엄청 떨어트린다.
// 		if (isdigit(c))
// 		{
// 			return c + 256;
// 		}
// 		return c;
// 	}

// 	static bool lt(char c1, char c2)
// 	{
// 		return get_real_rank(c1) < get_real_rank(c2);
// 	}

// 	static int compare(const char *s1, const char *s2, size_t n)
// 	{
// 		while (n-- != 0)
// 		{
// 			if (get_real_rank(*s1) < get_real_rank(*s2))
// 			{
// 				return -1;
// 			}
// 			if (get_real_rank(*s1) > get_real_rank(*s2))
// 			{
// 				return 1;
// 			}
// 			++s1;
// 			++s2;
// 		}
// 		return 0;
// 	}
// };

// int main()
// {
// 	std::basic_string<char, my_char_traits> my_s1 = "1a";
// 	std::basic_string<char, my_char_traits> my_s2 = "a1";

// 	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
// 			  << (my_s1 < my_s2) << std::endl;

// 	std::string s1 = "1a";
// 	std::string s2 = "a1";

// 	std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;
// }

/*
	(SSO - short string optimization)
*/
// #include <iostream>
// #include <string>

// /*
// 	이와 같이 new 를 전역 함수로 정의, 모든 new 연산자를 오버로딩 해버린다.
// 	(어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new 만 오버로딩됨)
// */
// void* operator new(std::size_t count) {
// 	std::cout << count << " bytes 할당 " << std::endl;
// 	return malloc(count);
// }

// int main() {
// 	std::cout << "s1 생성 --- " << std::endl;
// 	std::string s1 = "this is a pretty long sentence!!!";
// 	std::cout << "s1 크기 : " << sizeof(s1) << std::endl;

// 	std::cout << "s2 생성 --- " << std::endl;
// 	std::string s2 = "short sentence";
// 	std::cout << "s2 크기 : " << sizeof(s2) << std::endl;
// }

// #include <iostream>
// #include <string>
// using namespace std::literals;

// int main()
// {
// 	auto s1 = "hello"s;
// 	std::cout << "s1 길이 : " << s1.size() << std::endl;
// }

/* Raw string literal C++ 11 */
// #include <iostream>
// #include <string>

// int main() {
// 	std::string str = R"(asdfasdf
// 	이 안에는
// 	어떤 것들이 와도
// 	// 이런것도 되고
// 	#define halsdfsdljflsjf
// 	\n\n <---- Escape 안해도 됨
// 	)";

// 	std::cout << str;
// }

/* )"를 문자열 안에 넣어보자 */
// #include <iostream>
// #include <string>

// int main() {
// 	std::string str = R"foo(
// 	)"; <-- 무시됨
// 	)foo";

// 	std::cout << str;
// }

/* UTF-32 */
// #include <iostream>
// #include <string>

// int main()
// {
// 	// 1234567890 123 4 567
// 	std::u32string u32_str = U"이건 UTF-32 문자열 입니다";
// 	std::cout << u32_str.size() << std::endl;
// }

/* UTF-8 인코딩 */
// #include <iostream>
// #include <string>

// int main() {
// 	std::string str = u8"이건 UTF-8 문자열 입니다";
// 	std::cout << str.size() << std::endl;
// }

/* C++ 에서 UTF-8 문자열을 분석하는 방법 */
// #include <iostream>
// #include <string>

// int main()
// {
// 	std::string str = u8"이건 UTF-8 문자열 입니다";
// 	size_t i = 0;
// 	size_t len = 0;

// 	while (i < str.size())
// 	{
// 		int char_size = 0;

// 		if ((str[i] & 0b11111000) == 0b11110000)
// 		{
// 			char_size = 4;
// 		}
// 		else if ((str[i] & 0b11110000) == 0b11100000)
// 		{
// 			char_size = 3;
// 		}
// 		else if ((str[i] & 0b11100000) == 0b11000000)
// 		{
// 			char_size = 2;
// 		}
// 		else if ((str[i] & 0b10000000) == 0b0000000)
// 		{
// 			char_size = 1;
// 		}
// 		else
// 		{
// 			std::cout << "이상한 문자 발견!" << std::endl;
// 			char_size = 1;
// 		}

// 		std::cout << str.substr(i, char_size) << std::endl;

// 		i += char_size;
// 		len++;
// 	}
// 	std::cout << "문자열의 실제 길이 : " << len << std::endl;
// }

/* UTF-16 */
// #include <iostream>
// #include <string>

// int main()
// {
// 	//                         1234567890 123 4 567
// 	std::u16string u16_str = u"이건 UTF-16 문자열 입니다";
// 	std::cout << u16_str.size() << std::endl;
// }
/* 한글 초성만 분리해내는 코드를 작성 */
// #include <iostream>
// #include <string>

// int main()
// {
// 	std::u16string u16_str = u"안녕하세용 모두에 코드에 오신 것을 환영합니다";
// 	std::string jaum[] = {"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",
// 						  "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ",
// 						  "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"};

// 	for (char16_t c : u16_str)
// 	{
// 		// 유니코드 상에서 한글의 범위
// 		if (!(0xAC00 <= c && c <= 0xD7A3))
// 		{
// 			continue;
// 		}
// 		// 한글은 AC00 부터 시작해서 한 초성당 총 0x24C 개 씩 있다.
// 		int offset = c - 0xAC00;
// 		int jaum_offset = offset / 0x24C;
// 		std::cout << jaum[jaum_offset];
// 	}
// }

/* 이모지 분류 */
// #include <iostream>
// #include <string>

// int main()
// {
// 	std::u16string u16_str = u"🍑🍒";
// 	std::cout << u16_str.size() << std::endl;
// }

/* string_view
	만일 어떤 함수에다 문자열을 전달할 때, 문자열 읽기 만 필요로 한다면 보통 const std::string& 으로 받던지 아니면 const char* 형태로 받게 됩니다.

하지만 각각의 방식은 문제점이 있습니다. 먼저 const string& 형태로 받을 경우
*/
// #include <iostream>
// #include <string>

// void *operator new(std::size_t count)
// {
// 	std::cout << count << " bytes 할당 " << std::endl;
// 	return malloc(count);
// }

// // 문자열에 "very" 라는 단어가 있으면 true 를 리턴함
// bool contains_very(const std::string &str)
// {
// 	return str.find("very") != std::string::npos;
// }

// int main()
// {
// 	// 암묵적으로 std::string 객체가 불필요하게 생성된다.
// 	std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
// 			  << std::endl;

// 	std::cout << contains_very("c++ string is not easy to use") << std::endl;
// }

/* string_view -> 소유하지 않고 읽기만 한다. */
// #include <iostream>
// #include <string>

// void *operator new(std::size_t count)
// {
// 	std::cout << count << "bytes 할당" << std::endl;
// 	return malloc(count);
// }

// // 문자열에 "very" 라는 단어가 있으면 true 를 리턴함
// bool contains_very(std::string_view str)
// {
// 	return str.find("very") != std::string_view::npos;
// }

// int main()
// {
// 	// string_view 생성 시에는 메모리 할당이 필요없다.
// 	std::cout << std::boolalpha << contains_very("c++ string is very easy to use")
// 			  << std::endl;

// 	std::cout << contains_very("c++ string is not easy to use") << std::endl;

// 	std::string str = "some long long long long long string";
// 	std::cout << "----------------------" << std::endl;
// 	std::cout << contains_very(str) << std::endl;
// }

// #include <iostream>
// #include <string>

// void *operator new(std::size_t count)
// {
// 	std::cout << count << " bytes 할당 " << std::endl;
// 	return malloc(count);
// }

// int main()
// {
// 	std::cout << "string -----" << std::endl;
// 	std::string s = "sometimes string is very slow";
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << s.substr(0, 20) << std::endl
// 			  << std::endl;

// 	std::cout << "string_view -----" << std::endl;
// 	std::string_view sv = s;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << sv.substr(0, 20) << std::endl;
// }