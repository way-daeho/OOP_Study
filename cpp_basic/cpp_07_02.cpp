// 파일에서의 입출력
// #include <fstream>
// #include <iostream>
// #include <string>

// int main() {
// 	// 파일 읽기 준비
// 	std::ifstream in ("test.txt");
// 	std::string s;

// 	if (in.is_open()) {
// 		in >> s;
// 		std::cout << "입력 받은 문자열 :: " << s << std::endl;
// 	} else {
// 		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
// 	}
// 	return 0;
// }

/*
	is_open은 기존의 istream에는 없고 ifstream에서 상속 받으면서 추가된 함수
	파일이 열렸는지의 유무를 리턴

	in >> s;
	cin 을 사용하는 것 처럼 in 객체를 이용해서 파일로 부터 읽을 수 있다.
	(cin에서 >> 로 읽을 때 공백 문자가 나올 때 까지 읽었던 것처럼 여기서도 동일)

	ifstreeam 객체의 소멸자에서 자동적으로 close 해줌
*/

// 다만 close를 직접 해야 되는 경우도 있다.
// #include <fstream>
// #include <iostream>
// #include <string>

// int main() {
// 	//	파일 읽기 준비
// 	std::ifstream in ("test.txt");
// 	std::string s;

// 	if (in.is_open()) {
// 		in >> s;
// 		std::cout << "입력 받은 문자열 :: " << s << std::endl;
// 	} else {
// 		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
// 	}

// 	in.close();
// 	in.open("other.txt");

// 	if (in.is_open()) {
// 		in >> s;
// 		std::cout << "입력 받은 문자열 :: " << s << std::endl;
// 	} else {
// 		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
// 	}
	
// 	return 0;
// }

// 이진수로 읽기
#include <fstream>
#include <iostream>
#include <string>

int main () {
	// 파일 읽기 준비
	std::ifstream in("test.txt", std::ios::binary);
	std::string s;

	int x;
	if (in.is_open()) {
		in.read((char *)(&x), 4);
		std::cout << std::hex << x << std::endl;
	} else {
		std::cout << std::hex << x << std::endl;
	}

	return 0;
}