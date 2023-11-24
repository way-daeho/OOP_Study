/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:12:28 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/24 22:24:55 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	6 - 1 C++ 표준 문자열 & 부모의 것을 물려쓰자 - 상속

	C++ 표준 문자열 (std::string)
	상속 (inheritance)
	오버라이딩 (overriding)
	protected 키워드
*/

/*
	표준 `string` 클래스
	#include <iostream>
	#include <string>

	int main() {
  	// 표준이므로 std 안에string 이 정의되어 있습니다.
  	std::string s = "abc";

   	std::cout << s <<  std::endl;

  	return 0;
	}

	컴파일 결과 abc

	기본적으로 "abc" 컴파일러 상에서는 C 형식 문자열로 인식. 즉, 위 문장은 string 클래스의 인자를
	const char * 로 받는 생성자를 호출
	
*/