/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sameGramer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:52:45 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/18 22:43:59 by daehlee          ###   ########.fr       */
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
// #include <iostream>

// int main() {
// 	int i= 1, sum = 0;

// 	while (i <= 10)
// 	{
// 		/* code */
// 		sum += i;
// 		i++;
// 	}

// 	std::cout << "합은: " << sum << std::endl;
// 	return 0;
// }

/* 행운의 숫자 맞추기 */
// #include <iostream>
// int main() {
// 	int lucky_number = 3;
// 	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

// 	int user_input; // 사용자 입력

// 	while (1)
// 	{
// 		/* code */
// 		std::cout << "입력: ";
// 		std::cin >> user_input;
// 		if (lucky_number == user_input) {
// 			std::cout << "맞추셨습니다~~" << std::endl;
// 			break;
// 		} else {
// 			std::cout << "다시 생각해보세요~" << std::endl;
// 		}
// 	}
// 	return 0;
// }

// switch 문 이용하기
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int user_input;
	cout << "저의 정보를 표시해줍니다" << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> user_input;

	switch (user_input)
	{
	case 1:
		cout << "Ldh ! " << endl;
		break;
	case 2:
		cout << "24 살" << endl;
		break;
	case 3:
		cout << "남자" << endl;
		break;
	default:
		cout << "궁금한게 없군요~" << endl;
		break;
	}
	return 0;
}