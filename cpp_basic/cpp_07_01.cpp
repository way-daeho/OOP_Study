// 주의할 점
// #include <iostream>
// using namespace std;

// int main () {
// 	int t;
// 	while (true) {
// 		std::cin >> t;
// 		std::cout << "입력 :: " << t << std::endl;
// 		if (t == 0) break;
// 	}
// }

// 해결 방안
// #include <iostream>
// #include <string>

// int main() {
// 	int t;
// 	while (std::cin >> t)
// 	{
// 		/* code */
// 		std::cout << "입력 :: " << t << std::endl;
// 		if (t == 0) break;
// 	}
// }

// #include <iostream>
// #include <string>

// int main() {
// 	int t;
// 	std::cin >> t; // 고의적으로 문자를 입력하면 failbit 가 켜진다.
// 	std::cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다." << std::endl;
// 	std::string s;
// 	std::cin >> s;
// }

// 문제 해결 방법
// #include <iostream>
// #include <string>

// int main() {
// 	int t;
// 	while (true) {
// 		std::cin >> t;
// 		std::cout << "입력 :: " << t << std::endl;
// 		if (std::cin.fail()) {
// 			std::cout << "제대로 입력해주세요" << std::endl;
// 			std::cin.clear(); // 플래그을 초기화 하고
// 			std::cin.ignore(100, '\n'); // 개행문자가 나올 때 까지 무시한다
// 		}
// 		if (t == 1) break;
// 	}
// }

// 형식 플래그와 조작자
// #include <string>
// #include <iostream>

// int main() {
// 	int t;
// 	while (true) {
// 		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
// 		std::cin >> t;
// 		std::cout << "입력 :: " << t <<std::endl;
// 		if (std::cin.fail()) {
// 			std::cout << "제대로 입력해주세요" << std::endl;
// 			std::cin.clear(); // 플래그들을 초기화 하고 std::inc.ignore(100, 'n'); 개행문자가 나올 때 까지 무시.
// 		}
// 		if (t == 0) break;
// 	}
// }

// 조작자의 사용
// #include <iostream>
// #include <string>

// int main() {
// 	int t;
// 	while (true) {
// 		std::cin >> std::hex >> t;
// 		std::cout << "입력 :: " << t << std::endl;
// 		if (std::cin.fail()) {
// 			std::cout << "제대로 입력해주세요" << std::endl;
// 			std::cin.clear(); // 플래그들을 초기화 하고
// 			std::cin.ignore(100, 'n'); // 개행문자가 나올 때 까지 무시한다.
// 		}
// 		if (t == 0)  break;
// 	}
// }

// 	streambuf
// #include <iostream>
// #include <string>

// int main() {
// 	std::string s;
// 	std:: cin >> s;

// 	// 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (이 때는 움직이지 않음)
// 	char peek = std::cin.rdbuf() -> snextc();
// 	if (std::cin.fail()) std::cout << "Failed";
// 	std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
// 	std::cin >> s;
// 	std::cout << "다시 읽으면 : " << s << std::endl;
// }

// snextc 함수가 스트림 위치 지정자를 한 칸 전진시키므로, 공백 문자를 띄어넘고 w를 가리키게 된다.
// 이 때 snextc 함수는 스트림 위치 지정자를 건드리지 않기 때문에, world 전체가 나오게 된다.