/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_09_meta2.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:46:26 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/06 16:33:36 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	TMP  소수
*/

// #include <iostream>

// template <int N>
// struct INT
// {
// 	static const int num = N;
// };

// template <typename a, typename b>
// struct add
// {
// 	typedef INT<a::num + b::num> result;
// };

// template <typename a, typename b>
// struct divide
// {
// 	typedef INT<a::num / b::num> result;
// };

// using one = INT<1>;
// using two = INT<2>;
// using three = INT<3>;

// template <typename N, typename d>
// struct check_div
// {
// 	// result 중에서 한 개라도 true 면 전체가 true
// 	static const bool result = (N::num % d::num == 0) ||
// 							   check_div<N, typename add<d, one>::result>::result;
// };

// template <typename N>
// struct _is_prime
// {
// 	static const bool result = !check_div<N, two>::result;
// };

// template <>
// struct _is_prime<two>
// {
// 	static const bool result = true;
// };

// template <>
// struct _is_prime<three>
// {
// 	static const bool result = true;
// };

// template <typename N>
// struct check_div<N, typename divide<N, two>::result>
// {
// 	static const bool result = (N::num % (N::num / 2) == 0);
// };

// template <int N>
// struct is_prime
// {
// 	static const bool result = _is_prime<INT<N>>::result;
// };

// int main()
// {
// 	std::cout << std::boolalpha;
// 	std::cout << "Is 2 prime ? :: " << is_prime<2>::result << std::endl;
// 	std::cout << "Is 10 prime ? :: " << is_prime<10>::result << std::endl;
// 	std::cout << "Is 11 prime ? :: " << is_prime<11>::result << std::endl;
// 	std::cout << "Is 61 prime ? :: " << is_prime<61>::result << std::endl;
// }

/*
	단위(Unit) 라이브러리
*/

#include <iostream>

template <int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0>
{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio
{
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add
{
	using type = Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_subtract
{
	using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_multiply
{
	using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type
{
};

template <class R1, class R2>
struct _Ratio_divide
{
	using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type
{
};

template <typename U, typename V, typename W>
struct Dim
{
	using M = U;
	using L = V;
	using T = W;

	using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_
{
	typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
				typename Ratio_add<typename U::L, typename V::L>::type,
				typename Ratio_add<typename U::T, typename V::T>::type>
		type;
};

template <typename U, typename V>
struct subtract_dim_
{
	typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
				typename Ratio_subtract<typename U::L, typename V::L>::type,
				typename Ratio_subtract<typename U::T, typename V::T>::type>
		type;
};

template <typename T, typename D>
struct quantity
{
	T q;
	using dim_type = D;

	quantity operator+(quantity<T, D> ,quant)
	{
		return quantity<T, D>(q + quant.q);
	}

	quantity operator-(quantity<T, D> ,quant)
	{
		return quantity<T, D>(q - quant.q);
	}

	quantity(T q) : q(q) {}
};
int main()
{
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(1);
	quantity<double, Dim<zero, one, zero>> meter(1);
	quantity<double, Dim<zero, zero, one>> second(1);

	// Good
	kg + kg;

	// Bad
	// kg + meter;
}