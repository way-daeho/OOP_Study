/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noNameSpace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:52:11 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/18 01:52:13 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// namespace {
// 	// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 	// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
// int OnlyInThisFile() {}

// // 이 변수 역시 static int x 와 동일합니다.
// int only_in_this_file = 0;
// } // namespace

// int main(){
// 	OnlyInThisFile();
// 	only_in_this_file = 3;
// }

/*
int main(){
	std::cout << "hi" << std::endl
			  << "my name is "
			  << "Ldh" << std::endl;
}
출력값은 내가 예상했던거와 살짝 다르게 나왔다. 출력이 처음 만나는 std::endl에서 끝날 줄 알았다.
그 이유는 처음으로 cpp를 배울 때 줄바꿈 문자 형식으로 사용한다고 배워서 그런 거 같다.
결국 처음으로 cout을 사용하면 저자가 말한 std::cout << "출력할 문장" << .... 계속 끝날 때 까지 출력을 한다.
std::endl은 그저 화면에 출력해주는 '함수' 이므로 엔터 하나를 출력해주는 역할을 할 뿐이기 때문에, ';'이 나오기 전
문장들을 출력되서 나와진다.
*/