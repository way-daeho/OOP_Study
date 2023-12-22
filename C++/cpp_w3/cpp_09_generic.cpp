/*
	std::array가 어떻게 구현되었는지 만들어 보자!
*/
// #include <iostream>

// template <typename T, unsigned int N>
// class Array
// {
// 	T data[N];

// public:
// 	// 배열을 받는 레퍼런스 arr
// 	Array(T (&arr)[N])
// 	{
// 		for (int i = 0; i < N; i++)
// 			data[i] = arr[i];
// 	}

// 	T *get_array() { return data; }

// 	unsigned int size() { return N; }

// 	void print_all()
// 	{
// 		for (int i = 0; i < N; i++)
// 		{
// 			std::cout << data[i] << ", ";
// 		}
// 		std::cout << std::endl;
// 	}
// };

// int main()
// {
// 	int arr[3] = {1, 2, 3};

// 	// 배열 Wrapper 클래스
// 	Array<int, 3> arr_w(arr);

// 	arr_w.print_all();
// }

/*
	이건 무슨 내용일까..?
*/
// #include <iostream>
// #include <typeinfo>

// template <int N>
// struct Int
// {
// 	static const int num = N;
// };

// template <typename T, typename U>
// struct add
// {
// 	typedef Int<T::num + U::num> result;
// };

// int main()
// {
// 	typedef Int<1> one;
// 	typedef Int<2> two;

// 	typedef add<one, two>::result three;

// 	std::cout << "Addtion result : " << three::num << std::endl;
// }

/*
	템플릿 메타 프로그래밍(Template Meata Programming - TMP)
*/

/* 컴파일 타임 팩토리얼 계산 */
// #include <iostream>
// template <int N>
// struct Factorial
// {
// 	static const int result = N * Factorial<N - 1>::result;
// };

// template <>
// struct Factorial<1>
// {
// 	static const int result = 1;
// };

// int main()
// {
// 	std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
// }

/*
	두 수 의 최대공약수 구하는 방법 유클리드 호제법
*/

// int gcd(int a, int b)
// {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }

// // TMP로 변환
// #include <iostream>

// template <int X, int Y>
// struct GCD
// {
// 	static const int value = GCD<Y, X % Y>::value;
// };

// template <int X>
// struct GCD<X, 0>
// {
// 	static const int value = X;
// };

// int main()
// {
// 	std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;
// }

/*
	Ratio 클래스 구현
*/

// #include <iostream>
// #include <typeinfo>

// template <int X, int Y>
// struct GCD
// {
// 	static const int value = GCD<Y, X % Y>::value;
// };

// template <int X>
// struct GCD<X, 0>
// {
// 	static const int value = X;
// };

// template <int N, int D = 1>
// struct Ratio
// {
// 	typedef Ratio<N, D> type;
// 	static const int num = N; // 분자
// 	static const int den = D; // 분모
// };

// template <class R1, class R2>
// struct _Ratio_add
// {
// 	typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
// };

// template <class R1, class R2>
// struct Ratio_add : _Ratio_add<R1, R2>::type
// {
// };

// int main()
// {
// 	typedef Ratio<2, 3> rat;
// 	typedef Ratio<3, 2> rat2;
// 	typedef Ratio_add<rat, rat2> rat3;

// 	std::cout << rat3::num << " / " << rat3::den << std::endl;

// 	return 0;
// }

// #include <iostream>

// template <int X, int Y>
// struct GCD
// {
// 	static const int value = GCD<Y, X % Y>::value;
// };

// template <int X>
// struct GCD<X, 0>
// {
// 	static const int value = X;
// };

// template <int N, int D = 1>
// struct Ratio
// {
// private:
// 	const static int _gcd = GCD<N, D>::value;

// public:
// 	typedef Ratio<N / _gcd, D / _gcd> type;
// 	static const int num = N / _gcd;
// 	static const int den = D / _gcd;
// };
// template <class R1, class R2>
// struct _Ratio_add
// {
// 	using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
// };

// template <class R1, class R2>
// struct Ratio_add : _Ratio_add<R1, R2>::type
// {
// };

// template <class R1, class R2>
// struct _Ratio_subtract
// {
// 	using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
// };

// template <class R1, class R2>
// struct Ratio_subtract : _Ratio_subtract<R1, R2>::type
// {
// };

// template <class R1, class R2>
// struct _Ratio_multiply
// {
// 	using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
// };

// template <class R1, class R2>
// struct Ratio_multiply : _Ratio_multiply<R1, R2>::type
// {
// };

// template <class R1, class R2>
// struct _Ratio_divide
// {
// 	using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
// };

// template <class R1, class R2>
// struct Ratio_divide : _Ratio_divide<R1, R2>::type
// {
// };

// int main()
// {
// 	using r1 = Ratio<2, 3>;
// 	using r2 = Ratio<3, 2>;

// 	using r3 = Ratio_add<r1, r2>;
// 	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

// 	using r4 = Ratio_multiply<r1, r3>;
// 	std::cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << std::endl;
// }