/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_06.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:12:28 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/26 02:34:12 by daehlee          ###   ########.fr       */
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

	기반 클래스와 파생 클래스에 둘 다 같은 이름의 함수가 정의 되어있음 어떻게 될까?

	사실 두 함수는 같은 이름이만(심지어 같은 인자), 다른 클래스에 정의되어 있는 것 이기 때문에 다른 함수로 취급된다.

	Deriver에 정의 되어있어, 함수를 호출 할 때 바로 앞에 있는 함수를 호출

	이런 것을 가리켜 오버라이딩이라고 한다.
	이 상황에서는 Derived의 what 함수가 Base 함수의 what 함수를 오버라이딩 한 것.
*/

/*
	protected
	public과 private에 중간 위치에 있는 접근 지시자를 지원.
	상속받는 클래스에서는 접근 간으하고 그 외의 기타 정보는 접근 불가능
	private : (부모님들한테 안가르쳐 주는) 자신만의 비밀번호
	protected : 집 현관문 비밀번호 (가족들은 알지만 그 외의 사람들은 접근 불가)
	public : 집 주소 (가족 뿐만이 아니라 다른 사람들도 알 수 있다.)
*/

/*
	public 형태로 상속 했을 경우, 기반 클래스이 접근 지시자들에 영향 없이 그대로 작동
	protected로 상속, 파생 클래스 입장에선 public은 protected로 바뀌고 나머지는 그대로 유지
	private로 상속, 파생 클래스 입장에선 모든 접근 지시자들이 private가 된다.
*/

/*
	is `- a` 와 `has - a`
	C++에서 상속들 도입한 이유 - 객체지향프로그래밍에서 추구하는 실제 객체의 추상화
	C++ 에선 상속이란 것을 도입함으로써, 클래스 사이에 관계를 표현 가능.
	모든 상속 관계는 is a 관계이다 ex) Manager is a Employee.
	이를 뒤바꾸면 성립되지 않는 다.

	상속의 또 다른 중요한 특징
	클래스가 파생되면 파생될 수 록 좀 더 특수화(구체화; specialize) 된다.
	반대로 기반 클래스로 거슬러 올라가면 올라갈수록 좀 더 일반화(Generalize)된다.

	클래스에 따라 is -a 대신 has -a 관계가 성립되기도 한다.
	ex) 자동차 -> 엔진, 브레이크 등등으로 이루어짐
	하지만 브레이크 is a 자동차? 불가능.
	이러할 경우 가진다의 의미를 갖는다.
	자동차 has a 엔진
*/

// #include <iostream>
// #include <string>

// class Base
// {
// 	std::string s;

// public:
// 	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

// 	void what() { std::cout << s << std::endl; }
// };
// class Derived : public Base
// {
// 	std::string s;

// public:
// 	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

// 	void what() { std::cout << s << std::endl; }
// };
// int main()
// {
// 	Base p;
// 	Derived c;

// 	std::cout << "=== 포인터 버전 ===" << std::endl;
// 	Base *p_c = &c;
// 	p_c->what();

// 	return 0;
// }

/*
	포인터 버전
	Derived 객체 c 를 Base 객체를 가리키는 포인터,
	Base* p_c = &c;

	불가능 하지 않나?
	간과하고 있는 사실. Derived는 Base를 상속 받는다.
	Derived 객체 c도 어떻게 보면 Base 객체이기 때문에 Base 객체를 가리키는 포인터가 c를 가리켜도 무방.
	하지만 Base를 가리키는 포인터이므로, Derived 객체의 Base에 해당하는 부분에 대한 정보 밖에 없다.

	이러한 형태의 캐스팅 (파생 클래스 -> 기반 클래스) 업 캐스팅
*/

/*
	다운 캐스팅
	반대로 Derived 포인터가 Base의 객체를 가리켰을 땐?
	가리키는 것은 Base이므로, Derived가 갖고 있는 함수를 실행할 수 없다.(해당 정보를 갖고 있지 않기 때문)
	이러한 문제점을 해결하기 위해 함부로 다운 캐스팅 하는 것을 금지.

	Derived* p_c 에 Base * 를 대입하면 안된다는 똑같은 오류가 발생합니다. 하지만 우리는 p_p 가 가리키는 것이 Base 객체가 아니라 Derived 객체라는 사실을 알고 있습니다. 그렇기 때문에 비록 Base * 포인터를 다운 캐스팅 함에도 불구하고 p_p 가 실제로는 Derived 객체를 가리키기 때문에

	Derived* p_c = p_p;
	를 해도 전혀 문제가 없습니다. 이를 위해서는 아래 처럼 강제적으로 타입 변환을 하면 된다.

	Derived* p_c = static_cast<Derived*>(p_p);
	비록 약간은 위험하지만 (만일 p_p 가 사실은 Derived 객체를 가리키지 않는다면?) 컴파일 오류를 발생시키지 않고 성공적으로 컴파일 할 수 있다.

	성공적으로 컴파일에 성공했다면 런타임 오류가 발생, 강제적으로 다운 캐스팅 하는 경우, 컴파일 타임에서 오류를 찾아내기 매우 힘들기 때문에,
	다운 캐스팅은 작동이 보장되지 않는 한 매우매우 권장하지 않는다.
*/

/*
	dynamic_cast
	캐스팅에 따른 오류를 미연에 방지하기 위해, C++에서 상속 관계에 있는 두 포인터들 간에 캐스팅을 해주는
	dynamic_cast 라는 것을 지원
	사용 방법은 static_cast 외 거의 동일

	Derived* p_c = dynamic_cast<Derived*>(p_p);

*/

/*
	virtual 키워드
	컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 일을 가리켜서 동적 바인딩 (dynamic binding) 이라고 부른다.

	dynamic <-> static(정적)
	static binding 컴파일 타임에 어떤 함수가 호출될지 정해지는 것.(우리가 알고 있었던 함수가 해당)

	virtual 키워드가 붙은 함수를 가상 함수(virtual function)이라 부름.

	파생 클래스의 함수가 기반 클래스이 함수를 오버라이드 하기 위해서는 두 함수의 꼴이 정확히 같아야 한다.
*/

// #include <iostream>

// class Base
// {

// public:
// 	Base() { std::cout << "기반 클래스" << std::endl; }

// 	virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
// };
// class Derived : public Base
// {

// public:
// 	Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

// 	void what() { std::cout << "파생 클래스의 what()" << std::endl; }
// };
// int main()
// {
// 	Base p;
// 	Derived c;

// 	Base *p_c = &c;
// 	Base *p_p = &p;

// 	std::cout << " == 실제 객체는 Base == " << std::endl;
// 	p_p->what();

// 	std::cout << " == 실제 객체는 Derived == " << std::endl;
// 	p_c->what();

// 	return 0;
// }

/*
	override 키워드
	파생 클래스에서 기반 클래스의 가상 함수를 오버라이드 하는 경우, override 키워드를 통해 명시적으로 나타낼 수 있다.
	void what() override { std::cout << s << std::endl; }
*/

/* #include <iostream>
#include <string>

class Employee
{
protected:
	std::string name;
	int age;

	std::string position; // 직책 (이름)
	int rank;			  // 순위 (값이 클 수록 높은 순위)

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

	virtual void print_info()
	{
		std::cout << name << " (" << position << " , " << age << ") ==> "
				  << calculate_pay() << "만원" << std::endl;
	}
	virtual int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee
{
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank,
			int year_of_service)
		: year_of_service(year_of_service), Employee(name, age, position, rank) {}

	int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() override
	{
		std::cout << name << " (" << position << " , " << age << ", "
				  << year_of_service << "년차) ==> " << calculate_pay() << "만원"
				  << std::endl;
	}
};
class EmployeeList
{
	int alloc_employee;		  // 할당한 총 직원 수
	int current_employee;	  // 현재 직원 수
	Employee **employee_list; // 직원 데이터

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee)
	{
		employee_list = new Employee *[alloc_employee];
		current_employee = 0;
	}
	void add_employee(Employee *employee)
	{
		// 사실 current_employee 보다 alloc_employee 가 더
		// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		// 최대한 단순하게 생각해서 alloc_employee 는
		// 언제나 current_employee 보다 크다고 생각한다.
		// (즉 할당된 크기는 현재 총 직원수 보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
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

		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}
	~EmployeeList()
	{
		for (int i = 0; i < current_employee; i++)
		{
			delete employee_list[i];
		}
		delete[] employee_list;
	}
};
int main()
{
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));
	emp_list.print_employee_info();
	return 0;
} */

/*
	virtual 키워드를 이용하면, Employee* 가 가리키고 있음에도 불구하고 Manager면 Manager의 함수를
	Employee 면 Employee 의 함수를 잘 호출.

	하나의 메소드를 호출했음에도 불구하고 여러가지 다른 작업들을 하는 것을 바로 다형성(polymorphism) 이라 부른다.
*/

/*
	virtual 소멸자
	클래스의 상속을 사용함으로써 중요하게 처리해야 되는 부분 -> 상속 시에, 소멸자를 가상함수로 만들어야 한다.
*/

/*
#include <iostream>

class Parent {
	public:
		Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
		~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
	public:
		Child() : Parent() { std::cout<< "Child 생성자 호출" << std::endl; }
		~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main() {
	std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
	{ Child c; }
	std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
	{
		Parent *p = new Child();
		delete p;
	}
}

해당 방식으로 하면 Child 객체를 메모리에 동적 할당하고 소멸자를 해제해야하는데, 호출이 안되었기 때문에 메모리 누수가 발생한다.

해결 방법 기반 생성자 소멸자에 virtual 키워드를 붙힌다.
*/

/*
#include <iostream>

class Parent {
	public:
		Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
		virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
	public:
		Child() : Parent() { std::cout<< "Child 생성자 호출" << std::endl; }
		~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main() {
	std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
	{ Child c; }
	std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
	{
		Parent *p = new Child();
		delete p;
	}
}

Parent 소멸자는 호출되었는가? Child 소멸자를 호출하면서 '알아서' Parent 소멸자도 호출해주기 때문이다. (Child는 자신이 Parent를 상속 받는 다는 것을 알고 있다.)
반면 반대의 경우 있는지 없는지 모르므로, Child 소멸자를 호출해주지 못함 기반 생성자는 누구한테 상속해주는지 모르기 때문.
*/

/*
	레퍼런스도 된다.
	포인터 뿐만 아닌, 클래스의 레퍼런스여도 문제 없이 작동한다.
*/

// #include <iostream>

// class A
// {
// public:
// 	virtual void show() { std::cout << "Parent !" << std::endl; }
// };
// class B : public A
// {
// public:
// 	void show() override { std::cout << "Child!" << std::endl; }
// };

// void test(A &a) { a.show(); }
// int main()
// {
// 	A a;
// 	B b;
// 	test(a);
// 	test(b);

// 	return 0;
// }

/*
	가상 함수의 구현 원리

	자바의 경우 모든 함수들이 디폴트로 virtual 함수로 선언
	virtual로 만들어버린다고 해서 문제될 것이 전혀 문제 없다. -> 언제나 동적 바인딩이 제대로 동작하게 할 텐데?

	왜 C++ 에서는 사용자가 직접 virtual 키워드를 이용하게 했을까? -> 약간의 오버헤드 (overhead) 가 존재하기 때문.
*/