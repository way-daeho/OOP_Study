// #include <iostream>
// #include <vector>

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10); // 맨 뒤에 10 추가
// 	vec.push_back(20); // 맨 뒤에 20 추가
// 	vec.push_back(30); // 맨 뒤에 30 추가
// 	vec.push_back(40); // 맨 뒤에 40 추가

// 	for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
// 		std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
// 	}
// }

// 반복자 사용 예시
// #include <iostream>
// #include <vector>

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10);
// 	vec.push_back(20);
// 	vec.push_back(30);
// 	vec.push_back(40);

// 	// 전체 벡터를 출력하기
// 	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
// 		std::cout << *itr << std::endl;
// 	}

// 	std::vector<int>::iterator itr = vec.begin() + 2;
// 	std::cout << "3 번째 원소 :: " << *itr << std::endl;
// }

// #include <iostream>
// #include <vector>

// template <typename T>
// void print_vector(std::vector<T>& vec) {
// 	// 전체 벡터를 출력하기
// 	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
// 		std::cout << *itr << std::endl;
// 	}
// }

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10);
// 	vec.push_back(20);
// 	vec.push_back(30);
// 	vec.push_back(40);

// 	std::cout << "처음 벡터 상태" << std::endl;
// 	print_vector(vec);
// 	std::cout << "--------------------" << std::endl;

// 	// vec[2] 앞에 15 추가
// 	vec.insert(vec.begin() + 2, 15);
// 	print_vector(vec);

// 	std::cout << "--------------------" << std::endl;
// 	// vec[3] 제거
// 	vec.erase(vec.begin() + 3);
// 	print_vector(vec);
// }

// vector 에서 반복자로 erase 나 insert 함수를 사용할 때 주의해야할 
// #include <iostream>
// #include <vector>

// template <typename T>
// void print_vector(std::vector<T>& vec){
// 	// 전체 벡터를 출력하기
// 	std::cout << "[ ";
// 	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
// 		std::cout << *itr << " ";
// 	std::cout << "]";
// }
// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10);
// 	vec.push_back(20);
// 	vec.push_back(30);
// 	vec.push_back(40);
// 	vec.push_back(20);

// 	std::cout << "처음 벡터 상태" << std::endl;
// 	print_vector(vec);

// 	std::vector<int>::iterator itr = vec.begin();
// 	//std::vector<int>::iterator end_itr

// 	// for (; itr != vec.end(); itr++){
// 	// 	if (*itr == 20){
// 	// 		vec.erase(itr);
// 	// 		itr = vec.begin();
// 	// 	}
// 	// }

// 	for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
// 		if (vec[i] == 20) {
// 			vec.erase(vec.begin() + i);
// 			i--;
// 		}
// 	}
// 	// 처음으로 돌아가지 않고, 지운 위치부터 다음 위치를 찾게 하는 방법 -> erase 함수에만 반복자를 바로 만들어서 전달한다.
// 	// 하지만 권장하지 않는다. 기껏 원소에 접근하는 방식은 반복자를 사용하는 것으로 통일했는데, 이를 모두 깨버리고 그냥 기존의 배열처럼 정수형 변수로 원소에 접근하는 것이기 때문.
// 	std::cout << "값이 20 인 원소를 지운다!" << std::endl;
// 	print_vector(vec);
// }

// const_iterator
// #include <iostream>
// #include <vector>

// template <typename T>
// void print_vector(std::vector<T>& vec) {
// 	// 전체 벡터를 출력하기
// 	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
// 		std::cout << *itr << std::endl;
// }

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10);
// 	vec.push_back(20);
// 	vec.push_back(30);
// 	vec.push_back(40);

// 	std::cout << "초기 vec 상태" << std::endl;
// 	print_vector(vec);

// 	// itr 은 vec[2] 를 가리킨다.
// 	std::vector<int>::iterator itr = vec.begin() + 2;

// 	// vec[2] 의 값을 50으로 바꾼다.
// 	*itr = 50;

// 	std::cout << "-----------" << std::endl;
// 	print_vector(vec);

// 	std::vector<int>::const_iterator citr = vec.cbegin() + 2;

// 	// 상수 반복자가 가리키는 값은 바꿀 수 없다. 불가능!
// }

/*
	Reverse iterator
*/

// #include <iostream>
// #include <vector>

// template <typename T>
// void print_vector(std::vector<T>& vec) {
// 	// 전체 벡터를 출력하기
// 	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
// 		std::cout << *itr << std::endl;
// }

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(10);
// 	vec.push_back(20);
// 	vec.push_back(30);
// 	vec.push_back(40);

// 	std::cout << "초기 vec 상태" << std::endl;
// 	print_vector(vec);

// 	std::cout << "역으로 vec 출력하기!" << std::endl;
// 	// itr 은 vec[2] 를 가리킨다.
// 	std::vector<int>::reverse_iterator r_iter = vec.rbegin();
// 	for (; r_iter != vec.rend(); r_iter++)
// 		std::cout << *r_iter << std::endl;

// }

// #include <iostream>
// #include <vector>

// int main()
// {
// 	std::vector<int> vec;
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);

// 	// 끝에서 부터 출력하기
// 	for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--)
// 		std::cout << vec[i] << std::endl;

// 	return 0;
// }

/*
	범위 기반 for 문
*/

// #include <iostream>
// #include <vector>

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);

// 	// range-based for 문
// 	for (int elem : vec) {
// 		std::cout << "원소 : " << elem << std::endl;
// 	}

// 	return 0;
// }

// #include <iostream>
// #include <vector>

// template <typename T>
// void print_vector(std::vector<T>& vec) {
// 	// 전체 벡터를 출력하기
// 	for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
// 		std::cout << *itr << std::endl;
// }

// template <typename T>
// void print_vector_range_based(std::vector<T>& vec) {
// 	// 전체 벡터를 출력하기
// 	for (const auto& elem : vec)
// 		std::cout << elem << std::endl;
// }

// int main() {
// 	std::vector<int> vec;
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);

// 	std::cout << "print_vector" << std::endl;
// 	print_vector(vec);
// 	std::cout << "print_vector_range_based" << std::endl;
// 	print_vector_range_based(vec);

// 	return 0;
// }

/*
	리스트
*/

// #include <iostream>
// #include <list>

// int main() {
// 	std::list<int> lst;

// 	lst.push_back(10);
// 	lst.push_back(20);
// 	lst.push_back(30);
// 	lst.push_back(40);

// 	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
// 		std::cout << *itr << std::endl;
// }

// #include <iostream>
// #include <list>

// template <typename T>
// void print_list(std::list<T>& lst) {
// 	std::cout << "[ ";
// 	// 전체 리스트를 출력하기 (이 역시 범위 기반의 for 문을 쓸 수 있다.)
// 	for (const auto& elem : lst) {
// 		std::cout << elem << " ";
// 	}
// 	std::cout << "]" << std::endl;
// }

// int main() {
// 	std::list<int> lst;

// 	lst.push_back(10);
// 	lst.push_back(20);
// 	lst.push_back(30);
// 	lst.push_back(40);

// 	std::cout << "처음 리스트의 상태 " << std::endl;
// 	print_list(lst);

// 	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
// 		// 만일 현재 원소가 20 이라면
// 		// 그 앞에 50 을 집어넣는다.
// 		if (*itr == 20)
// 			lst.insert(itr, 50);
// 	}

// 	std::cout << "값이 20 인 원소 앞에 50 을 추가" << std::endl;
// 	print_list(lst);

// 	for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
// 	{
// 		// 값이 30 인 원소를 삭제한다.
// 		if (*itr == 30){
// 			lst.erase(itr);
// 			break;
// 		}
// 	}

// 	std::cout << "값이 30 인 원소를 제거한다" << std::endl;
// 	print_list(lst);
// }

/*
	덱 (deque)
*/

#include <deque>
#include <iostream>

template <typename T>
void print_deque(std::deque<T>& dq) {
	// 전체 덱을 출력하기
	std::cout << "[ ";
	for (const auto& elem : dq) {
		std::cout << elem << " ";
	}
	std::cout << " ] " << std::endl;
}

int main() {
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);

	std::cout << "초기 dq 상태" << std::endl;
	print_deque(dq);

	std::cout << "맨 앞의 원소 제거" << std::endl;
	dq.pop_front();
	print_deque(dq);
}