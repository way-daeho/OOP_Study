/* 참조자의 도입 */
// #include <iostream>

// int change_val(int *p) {
// 	*p = 3;

// 	return 0;
// }

// int main() {
// 	int number = 5;

// 	std::cout << number <<std::endl;
// 	change_val(&number);
// 	std::cout << number << std::endl;
// }

// #include <iostream>

// int main() {
// 	int a = 3;
// 	int& another_a = a;

// 	another_a = 5;
// 	std::cout << "a : " << a << std::endl;
// 	std::cout << "another_a : " << another_a << std::endl;

// 	return 0;
// }

/* 함수 인자로 레퍼런스 받기 */
// #include <iostream>

// int change_val(int &p) {
// 	p = 3;

// 	return 0;
// }
// int main() {
// 	int number = 5;

// 	std::cout << number << std::endl;
// 	change_val(number);
// 	std::cout << number << std::endl;
// }

/* 참조자 이해하기 */

// #include <iostream>

// int main() {
// 	int x;
// 	int& y = x;
// 	int& z = y;

// 	x = 1;
// 	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

// 	y = 2;
// 	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

// 	z = 3;
// 	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
// }

// 리터럴이 무엇일까? -> 학습하기.

/* 레퍼런스의 배열과 배열의 레퍼런스 */
// #include <iostream>

// int main() {
// 	int arr[3] = {1, 2, 3};
// 	int(&ref)[3] = arr;

// 	ref[0] = 2;
// 	ref[1] = 3;
// 	ref[2] = 1;

// 	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
// 	return 0;
// }

/* 레퍼런스를 리턴하는 함수 */

/* 생각해보기
	문제 1. 레퍼런스가 메모리 상에 반드시 존재해야 하는 경우는 어떤 경우가 있을까요? 그리고 메모리 상에 존재할 필요가 없는 경우는 또 어떤 경우가 있을 까요? 
*/