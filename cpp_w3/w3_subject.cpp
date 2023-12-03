/*
	9 - 1 코드를 찍어내는 틀 - C++ 템플릿(template)
*/

/*
	문제 1
	template 을 사용해서 이전에 만들어 놓았던 Excel 프로젝트 코드를 깔금하게 만들어보세요.
*/

/*
	문제 2
	위 Vector로 2차원, 3차원 배열등을 똑같이 만들어 낼 수 있을까?
*/

/*
	문제 3
	컴파일러가 마법 처럼 템플릿 인자에 타입을 정해준다고 하지만 사실은 어떤 타입으로 추측
	할지 결정하는 일련의 규칙들이 있다. 링크를 통해 내용을 확인하라.
*/

/*
	9 - 3 템플릿 메타 프로그래밍 (Template Meta programming)
*/

/*
	문제 1
	N 번째 피보나치 수를 나타내는 TMP를 만들어보아라. 참고로 피보나치 수는, N 번째 항이 N - 1
	번째 항과 N - 2 번째 항의 합으로 정의되는 수이다.

	int main() {
		std::cout << "5 번째 피보나치 수 :: " << fib<5>::result << std::endl;
	}
*/

// #include <iostream>

// template <int N>
// struct fib
// {
// 	static const int result = fib<N - 1>::result + fib<N - 2>::result;
// };

// template <>
// struct fib<0>
// {
// 	static const int result = 0;
// };

// template <>
// struct fib<1>
// {
// 	static const int result = 1;
// };

// int main()
// {
// 	std::cout << "5 번째 피보나치 수 :: " << fib<5>::result << std::endl;
// }

/*
	문제 2
	TMP를 사용해서 어떤 수가 소수인지 아닌지를 판별하는 프로그램을 만들어보세요. 참고로
	이 문제는 다음 강좌에서 다룰 예정입니다!

	int main()
	{
		std::cout << bollalpha;
		std::cout << "Is prime ? ::  " << is_prime<2>::result << std::endl;
		std::cout << "Is prime ? ::  " << is_prime<10>::result << std::endl;

		std::cout << "Is prime ? ::  " << is_prime<11>::result << std::endl;
		std::cout << "Is prime ? ::  " << is_prime<61>::result << std::endl;

	}
*/