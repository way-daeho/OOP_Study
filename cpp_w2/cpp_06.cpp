/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:12:28 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/25 04:33:54 by daehlee          ###   ########.fr       */
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

/* #include <iostream>
#include <string>

int main()
{
	std::string s = "abc";
	std::string t = "def";
	std::string s2 = s;

	std::cout << s << " 의 길이 : " << s.length() << std::endl;
	std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << std::endl;

	if (s == s2)
	{
		std::cout << s << " 와 " << s2 << " 는 같다 " << std::endl;
	}
	if (s != t)
	{
		std::cout << s << " 와 " << t << " 는 다르다 " << std::endl;
	}
	return 0;
} */

/*
	C형식문자열이였을 경우 문자열을 비교하기 위해 strcmp함수 사용
	== 나 != 로 비교하는 것이 불가능 했음.(이는 문자열의 주소값을 비교하는 것이 였음)
	string  클래스는 == 와 != 연산자들을 모두 오버로딩해서 제대로 비교 수행 뿐 아니라, 크기 비교 >= <= 등도 수행 가능

*/

/*
	사원 관리 프로그램

	회사의 사원들의 월급을 계산해서 한달에 총 얼마나 되는 돈을 월급으로 지출해야하는가?

	각 사원들에 정보를 클래스로 만들어서 데이터를 보관
	사원들의 필요한 데이터는 이름, 나이, 직책과 직책의 순위에 해당하는 숫자값 (예를 들어 평사원이면 1, 대리면 2 이런 식)
*/

/* #include <iostream>
#include <string>
class Employee
{
	std::string name;
	int age;

	std::string position; // 직책 (이름)
	int rank;			  // 순위 (값이 클수록 높은 순위)

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee &employee)
	{
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() {}

	void print_info()
	{
		std::cout << name << " (" << position << " , " << age << ") ==> "
				  << calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay() { return 200 + rank * 50; }
};

class Manager
{
	std::string name;
	int age;

	std::string position; // 직책 (이름)
	int rank;			  // 순위 (값이 클 수 록 높은 순위)
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: year_of_service(year_of_service),
		  name(name),
		  age(age),
		  position(position),
		  rank(rank) {}

	// 복사 생성자
	Manager(const Manager &manager)
	{
		name = manager.name;
		age = manager.age;
		position = manager.position;
		rank = manager.rank;
		year_of_service = manager.year_of_service;
	}

	// 디폴트 생성자
	Manager() {}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info()
	{
		std::cout << name << " (" << position << " , " << age << ", "
				  << year_of_service << "년차) ==> " << calculate_pay() << "만원"
				  << std::endl;
	}
};

class EmployeeList
{
	int alloc_employee; // 할당한 총 직원 수

	int current_employee; // 현재 직원 수
	int current_manager;  // 현재 매니저 수

	Employee **employee_list; // 직원 데이터
	Manager **manager_list;	  // 매니저 데이터

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee)
	{
		employee_list = new Employee *[alloc_employee];
		manager_list = new Manager *[alloc_employee];

		current_employee = 0;
		current_manager = 0;
	}

	void add_employee(Employee *employee)
	{
		// alloc_employee 는 언제나 current_employee 보다 크다고 생각.
		employee_list[current_employee] = employee;
		current_employee++;
	}

	void add_manager(Manager *manager)
	{
		manager_list[current_manager] = manager;
		current_manager++;
	}

	int current_employee_num() { return current_employee; }

	void print_employee_info()
	{
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++)
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		for (int i = 0; i < current_manager; i++)
		{
			manager_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}

	~EmployeeList()
	{
		for (int i = 0; i < current_employee; i++)
		{
			delete employee_list[i];
		}
		for (int i = 0; i < current_manager; i++)
		{
			delete manager_list[i];
		}
		delete[] employee_list;
		delete[] manager_list;
	}
};

int main()
{
	EmployeeList emp_list(10);
	/* 	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
		emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

		emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
		emp_list.add_employee(new Employee("정준하", 43, "과장", 4));
		emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
		emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
		emp_list.add_employee(new Employee("길", 36, "인턴", -2)); */
/* 	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
} */

/*
	상속
	C++에선 다른 클래스의 내용을 그대로 포함할 수 있는 작업을 가능토록해준다. => 상속
	C++ 에선 상속을 통해 다른 클래스의 정보를 물려 받아서 사용할 수 있다.

	class Base {
		std::string s;

		public:
			Base() s("기반") { std::cout << "기반 클래스" << std::endl; }

			void what() { std:: cout << s << std::endl; }
	};

	// 주의 사항
	보통 부모 - 자식 클래스라고도 이야기 한다. 다만 자식이라는 단어 속에서 한 개의 부모만 갖는 의미가 담겨있는데,
	C++ 의 경우 여러 명의 부모를 가질 수 있어, 부모, 자식 클래스라 하기 보단, 기반, 파생 클래스라 부른 것이 낫다고 생각.

	기반 클래스( Base )를 물려받은 파생 ( Derived ) 클래스
	class Derived : public Base {
		std::string s;

		public:
			Derived() : Base(), s("파생") {
				std::cout << "파생 클래스" << std::endl;

				// Base 에서 what() 을 물려 받았으므로
				// Derived 에서 당연히 호출 가능하다.
				what();
			}
	}

	클래스 정의 부분으로 class Derived : public Base 와 같이 되어있음

	Derived가 Base 를 public 형식으로 상속 받겠다는 듯.

	Derived() : Base(), s("파생")
	초기화 리스트에서 Base 를 통해 기반의 생성자를 먼저 호출하게 됩니다. 참고로 기반 클래스의 생성자를 명시적으로 호출하지 않을 경우 기반 클래스의 디폴트 생성자가 호출됩니다.
*/