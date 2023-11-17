/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sameGramer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:52:45 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/18 01:59:58 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 변수의 정의
// #include <iostream>

// int main() {
// 	int i;
// 	char c;
// 	double d;
// 	float f;

// 	int arr[10];
// 	int *parr = arr;

// 	int *pi = &i;
// 	return 0;
// }

// C++ 의 for 문
// #include <iostream>

// int main() {
// 	int i;

// 	for (i = 0; i < 10; i++) {
// 		std::cout << i << std::endl;
// 	}
// 	return 0;
// }

/* 1 부터 10 까지 합*/
/* #include <iostream>

int main() {
	int i, sum = 0;

	for (i = 1; i <= 10; i++) {
		sum += i;
	}

	std::cout << "합은: " << sum << std::endl;
	return 0;
} */

// while 문 이용하기
#include <iostream>

int main() {
	int i, sum = 0;

	while (i <= 10)
	{
		/* code */
		sum += i;
		i++;
	}

	std::cout << "합은: " << sum << std::endl;
	return 0;
}