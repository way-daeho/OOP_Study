/*
// new와 delete 의 사용
#include <iostream>

int main(){
	int *p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;
	return 0;
}
*/

/* new로 배열 할당하기 */

// #include <iostream>

// int main() {
// 	int arr_size;
// 	std::cout << "array size : ";
// 	std::cin >> arr_size;
// 	int *list = new int[arr_size];
// 	for (int i = 0; i < arr_size; i++){
// 		std::cin >> list[i];
// }
// for (int i = 0; i < arr_size; i++)
// {
// 	std::cout << i << "th element of list : " << list[i] << std::endl;
// }
// delete[] list;
// return 0;
// }

/* 돌아온 마이펫
	동물 구조체
	이름, 나이, 체력, 배부른 정도, 깨끗한 정도의 값을 가짐
	동물 구조체의 포인터 배열을 만들어서 사용자가 동물을 추가할 때 마다 하나씩 생성
	play라는 함수를 만들어서 동물의 상태를 변경하고 show_stat 함수를 만들어서 지정하는 동물의 상태를 출력'
	1 턴이 지날 때 마다 동물의 상태를 변경
*/

// #include <iostream>

// typedef struct  Animal
// {
// 	/* data */
// 	char name[30]; // 이름
// 	int age; // 나이

// 	int health; // 체력
// 	int food; // 배부른 정도
// 	int clean; // 깨끗한 정도
// }Animal;

// void create_animal(Animal *animal) {
// 	std::cout << "동물의 이름? ";
// 	std::cin >> animal->name;

// 	std::cout << "동물의 나이? ";
// 	std::cin >> animal->age;

// 	animal->health = 100;
// 	animal->food = 100;
// 	animal->clean = 100;
// }

// void play(Animal *animal) {
// 	animal->health += 10;
// 	animal->food -=20;
// 	animal->clean -= 30;
// }

// void one_day_pass(Animal *animal) {
// 	// 하루가 지나면
// 	animal->health -= 10;
// 	animal->food -= 30;
// 	animal->clean -= 20;
// }

// void show_stat(Animal *animal) {
// 	std::cout << animal->name << "의 상태" << std::endl;
// 	std::cout << "체력	: " << animal->health << std::endl;
// 	std::cout << "배부름 : " << animal->food << std::endl;
// 	std::cout << "청결	: " << animal->clean << std::endl;
// }

// int main() {
// 	Animal *list[10];
// 	int animal_num = 0;

// 	for (;;) {
// 		std::cout << "1. 동물 추가하기" << std::endl;
// 		std::cout << "2. 놀기" << std::endl;
// 		std::cout << "3. 상태 보기" << std::endl;

// 	int input;
// 	std::cin >> input;

// 	switch (input) {
// 	int play_with;
// 	case 1:
// 		list[animal_num] = new Animal;
// 		create_animal(list[animal_num]);

// 		animal_num++;
// 		break;
// 	case 2:
// 		std::cout << "누구랑 놀게? : ";
// 		std::cin >> play_with;

// 		if (play_with < animal_num) play(list[play_with]);

// 		break;

// 	case 3:
// 		std::cout << "누구껄 보게? : ";
// 		std::cin >> play_with;
// 		if (play_with < animal_num) show_stat(list[play_with]);
// 		break;
// 	}

// 	for (int i = 0; i != animal_num; i++)
// 		one_day_pass(list[i]);
// 	}
// 	for (int i = 0; i != animal_num; i++)
// 		delete list[i];
// }

/* 클래스 == 객체의 '설계도'
	클래스를 이용해 만들어진 객체 == 인스턴스 */

// #include <iostream>

// class Animal {
// 	private:
// 	int food;
// 	int weight;

// 	public:
// 		void set_animal(int _food, int _weight) {
// 			food = _food;
// 			weight = _weight;
// 		}
// 		void increase_food(int inc) {
// 			food += inc;
// 			weight += (inc / 3);
// 		}
// 		void view_stat() {
// 			std::cout << "이 동물의 food   : " << food << std::endl;
// 			std::cout << "이 동물의 weight : " << weight << std::endl;
// 		}
// }; // 세미콜론 잊지 말자!

// int main() {
// 	Animal animal;
// 	animal.set_animal(100, 50);
// 	animal.increase_food(30);

// 	animal.view_stat();
// 	return 0;
// }

/*
	C++에서 클래스를 이용해서 만들어진 객체 -> 인스턴스
	인스턴스 변수 : 클래스 내에 선언된 변수
	객체 생성 시 마다 매번 새로운 변수가 생성됨
	클래스 변수와 달리 공유되지않음.
*/
/* 함수의 오버로딩 */
// #include <iostream>

// void print(int x) { std::cout << "int : " << x <<std::endl; }
// void print(double x) { std::cout << "double : " << x <<std::endl; }

// int main() {
// 	int a = 1;
// 	char b = 'c';
// 	double c = 3.2f;

// 	print(a);
// 	print(b);
// 	print(c);

// 	return 0;
// }

/*
	C++ 컴파일러에서 함수를 오버 로딩하는 과정은 다음과 같다.
	1 단계 : 자신과 타입이 정확히 일치하는 함수를 찾는다.
	2 단계 : 정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
	- char unsigned char, short 는  int로 변환된다.
	- unsingned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
	- float 은 double로 변환
	- enum 은 int 로 변환된다.
	3 단계 : 위와 같이 변환해도 일치하는 것이 없다면 아래의 좀 더 포괄적인 형 변환을 통해 일치하는 함수를 찾는다.
	- 임의의 숫자타입은 다른 숫자 타입으로 변환 된다. (ex. float -> int)
	- enum 도 임의의 숫자 타입으로 변환된다. (enum -> double)
	- 0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
	- 포인터는 void 포인터로 변환된다.
	4 단계 : 유저 정의된 타입 변환으로 일치하는 것을 찾는다.
	만약에 컴파일러가 위 과정을 통하더라도 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우에는
	모호하다라고 판단해서 오류를 발생
*/

/* Date 클래스 */
// #include <iostream>

// class Date
// {
// 	int year_;
// 	int month_; // 1 부터 12 까지.
// 	int day_;	// 1 부터 31 까지.

// public:
// 	void SetDate(int year, int month, int date);
// 	void AddDay(int inc);
// 	void AddMonth(int inc);
// 	void AddYear(int inc);

// 	// 해당 월의 총 일 수를 구한다.
// 	int GetCurrentMonthTotalDays(int year, int month);

// 	void ShowDate();
// };

// void Date::SetDate(int year, int month, int day)
// {
// 	year_ = year;
// 	month_ = month;
// 	day_ = day;
// }

// int Date::GetCurrentMonthTotalDays(int year, int month)
// {
// 	static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 	if (month != 2)
// 		return (month_day[month - 1]);
// 	else if (year % 4 == 0 && year % 100 != 0)
// 		return (29);
// 	else
// 		return (28);
// }

// void Date::AddDay(int inc)
// {
// 	while (true)
// 	{
// 		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

// 		if (day_ + inc <= current_month_total_days)
// 		{
// 			day_ += inc;
// 			return;
// 		}
// 		else
// 		{
// 			inc -= (current_month_total_days - day_ + 1);
// 			day_ = 1;
// 			AddMonth(1);
// 		}
// 	}
// }

// void Date::AddMonth(int inc) {
// 	AddYear((inc + month_ - 1) / 12);
// 	month_ = month_ + inc % 12;
// 	month_ = (month_ == 12 ? 12 : month_ % 12);
// }

// void Date::AddYear(int inc) { year_ += inc; }

// void Date::ShowDate() {
// 	std::cout << "오늘은" << year_ << " 년" << month_ << " 월" << day_ << " 일 입니다" << std::endl;
// }

// int main() {
// 	Date day;
// 	day.SetDate(2011, 3, 1);
// 	day.ShowDate();

// 	day.AddDay(30);
// 	day.ShowDate();

// 	day.AddDay(2000);
// 	day.ShowDate();

// 	day.SetDate(2012, 1, 31);
// 	day.AddDay(29);
// 	day.ShowDate();

// 	day.SetDate(2012, 8 ,4);
// 	day.AddDay(2500);
// 	day.ShowDate();
// 	return 0;
// }

/* 생성자 */
// #include <iostream>

// class Date
// {
// 	int year_;
// 	int month_; // 1 부터 12 까지.
// 	int day_;	// 1 부터 31 까지.

// public:
// 	void SetDate(int year, int month, int date);
// 	void AddDay(int inc);
// 	void AddMonth(int inc);
// 	void AddYear(int inc);

// 	// 해당 월의 총 일수를 구한다.
// 	int GetCurrentMonthTotalDays(int year, int month);

// 	void ShowDate();

// 	Date(int year, int month, int day)
// 	{
// 		year_ = year;
// 		month_ = month;
// 		day_ = day;
// 	}
// };

// void Date::AddYear(int inc) { year_ += inc; }
// void Date::ShowDate()
// {
// 	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다 " << std::endl;
// }
// int main()
// {
// 	Date day(2011, 3, 1);
// 	day.ShowDate();
// 	day.AddYear(10);
// 	day.ShowDate();
// 	return 0;
// }

// 디폴트 생성자 정의해보기
// #include <iostream>
// class Date {
// int year_;
// int month_; // 1 부터 12 까지.
// int day_; // 1 부터 31 까지.
// public:
// void ShowDate();
// Date() {
// year_ = 2012;
// month_ = 7;
// day_ = 12;
// }
// };
// void Date::ShowDate() {
// std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
// << " 일 입니다 " << std::endl;
// }
// int main() {
// Date day = Date();
// Date day2;
// day.ShowDate();
// day2.ShowDate();
// return 0;
// }

/* 생성자 오버로딩 */
// #include <iostream>

// class Date {
// 	int year_;
// 	int month_; // 1 부터 12 까지.
// 	int day_; // 1 부터 31 까지.

// 	public:
// 		void ShowDate();

// 		Date() {
// 			std::cout << "기본 생성자 호출!" << std::endl;
// 			year_ = 2012;
// 			month_ = 7;
// 			day_ = 12;
// 		}

// 		Date(int year, int month, int day) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			year_ = year;
// 			month_ = month;
// 			day_ = day;
// 		}
// 		// Date 클래스에 여러가지 생성자들을 추가 -> 가능한 이유. 함수의 오버로딩 || 메소드 오버로딩
// 		Date(int year) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			year_ = year;
// 		}

// 		Date(int month) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			month_ = month;
// 		}

// 		Date(int day) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			day_ = day;
// 		}

// 		Date(int year, int month) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			year_ = year;
// 			month_ = month;
// 		}

// 		Date(int year, int day) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			year_ = year;
// 			day_ = day;
// 		}

// 		Date(int month, int day) {
// 			std::cout << "인자 3 개인 생성자 호출!" << std::endl;
// 			month_ = month;
// 			day_ = day;
// 		}
// };

// void Date::ShowDate() {
// 	std::cout << "오늘은" << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다 " << std::endl;
// }

// int main() {
// 	Date day = Date();
// 	Date day2(2023, 11, 19);

// 	day.ShowDate();
// 	day2.ShowDate();

// 	return (0);
// }

/* 복사 생성자와 소멸자 */
// #include <iostream>

// class Marine {
// 	int hp; // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	int damage; // 공격력
// 	bool is_dead;

// 	public:
// 		Marine(); // 기본 생성자
// 		Marine(int x, int y); // x, y 좌표에 마린 생성

// 		int attack(); // 데미지를 리턴
// 		void be_attacked(int damage_earn); // 입는 데미지
// 		void move(int x, int y); // 새로운 위치

// 		void show_status(); // 상태를 보여준다.
// };
// Marine::Marine() {
// 	hp = 50;
// 	coord_x = coord_y = 0;
// 	damage = 5;
// 	is_dead = false;
// }
// Marine::Marine(int x, int y) {
// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// }
// void Marine::move(int x, int y) {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return (damage); }
// void Marine::be_attacked(int damage_earn) {
// 	hp -= damage_earn;
// 	if (hp <= 10) is_dead = true;
// }
// void Marine::show_status() {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }

// int main() {
// 	Marine marine1(2, 3);
// 	Marine marine2(3, 5);

// 	marine1.show_status();
// 	marine2.show_status();

// 	std::cout << std::endl << "마린1 이 마린2 를 공격! "<< std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }
// int main() {
// 	Marine* marines[100];
// 	marines[0] = new Marine(2, 3);
// 	marines[1] = new Marine(3, 5);

// 	marines[0]->show_status();
// 	marines[1]->show_status();

// 	std::cout << std::endl << "마린1 이 마린2 를 공격! "<< std::endl;

// 	marines[0]->be_attacked(marines[1]->attack());

// 	marines[0]->show_status();
// 	marines[1]->show_status();

// 	delete marines[0];
// 	delete marines[1];
// }

/* 마린 이름 만들기 */
// #include <iostream>
// #include <string.h>
// class Marine
// {
// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	int damage;			  // 공격력
// 	bool is_dead;
// 	char *name; // 마린 이름

// public:
// 	Marine();									   // 기본 생성자
// 	Marine(int x, int y, const char *marine_name); // 이름까지 지정
// 	Marine(int x, int y);						   // x, y 좌표에 마린 생성

// 	int attack();					   // 데미지를 리턴
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// };
// Marine::Marine()
// {
// 	hp = 50;
// 	coord_x = coord_y = 0;
// 	damage = 5;
// 	is_dead = false;
// 	name = NULL;
// }
// Marine::Marine(int x, int y, const char *marine_name)
// {
// 	name = new char[strlen(marine_name) + 1];
// 	strcpy(name, marine_name);

// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// }
// Marine::Marine(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// 	name = NULL;
// }
// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return (damage); }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 10)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine : " << name << " ***" << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }

// int main()
// {
// 	Marine *marines[100];
// 	marines[0] = new Marine(2, 3, "Marine 2");
// 	marines[1] = new Marine(1, 5, "Marine 1");
// 	marines[0]->show_status();
// 	marines[1]->show_status();
// 	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marines[0]->be_attacked(marines[1]->attack());
// 	marines[0]->show_status();
// 	marines[1]->show_status();
// 	delete marines[0];
// 	delete marines[1];
// }

/* 소멸자 */
// #include <iostream>
// #include <string.h>
// class Marine
// {
// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	int damage;			  // 공격력
// 	bool is_dead;
// 	char *name; // 마린 이름

// public:
// 	Marine();									   // 기본 생성자
// 	Marine(int x, int y, const char *marine_name); // 이름까지 지정
// 	Marine(int x, int y);						   // x, y 좌표에 마린 생성
// 	~Marine();

// 	int attack();					   // 데미지를 리턴
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// };
// Marine::Marine()
// {
// 	hp = 50;
// 	coord_x = coord_y = 0;
// 	damage = 5;
// 	is_dead = false;
// 	name = NULL;
// }
// Marine::Marine(int x, int y, const char *marine_name)
// {
// 	name = new char[strlen(marine_name) + 1];
// 	strcpy(name, marine_name);

// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// }
// Marine::Marine(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// 	hp = 50;
// 	damage = 5;
// 	is_dead = false;
// 	name = NULL;
// }
// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return (damage); }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 10)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine : " << name << " ***" << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }
// Marine::~Marine() {
// 	std::cout << name << " 의 소멸자 호출! " << std::endl;
// 	if (name != NULL)
// 		delete[] name;
// } // 생성자가 클래스 이름과 똑같이 생겼다면 소멸자는 그 앞에 ~만 붙히면 된다.
// int main()
// {
// 	Marine *marines[100];
// 	marines[0] = new Marine(2, 3, "Marine 2");
// 	marines[1] = new Marine(1, 5, "Marine 1");
// 	marines[0]->show_status();
// 	marines[1]->show_status();
// 	std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marines[0]->be_attacked(marines[1]->attack());
// 	marines[0]->show_status();
// 	marines[1]->show_status();
// 	delete marines[0];
// 	delete marines[1];
// }

/* 복사 생성자
	T(const T& a); 복사 생성자의 표준적인 정의
	다른  T의 객체 a를 상수 레퍼런스로 받는 다.
	a 가 const 이기 때문에 복사 생성자 내부에서 a의 데이터를 변경할 수 없고,
	오직 새롭게 초기화 되는 인스턴스 변수들에게 '복사'만 할 수 있게 된다.

	a의 인스턴스 변수들에 접근해서 객체의 값들을 초기화 할 수 있지만, a의 값 자체는 변경할 수 없다.

	T a = (1, 1);
	T b(a);
	T c = b; -> T c(b); 와 동일하게 해서. (복사 생성자 호출) <- 아주 특별한 경우.
	c = b라고 할 경우, 평범한 대입 연산.
	** 인자로 받는 변수의 내용을 함수 내부에서 바꾸지 않는다면 앞에 const를 붙여주는 것이 바람직하다. **

	디폴트 복사 생성자의 한계
	만약 인스턴스의 문자열이 존재한다면? -> 문자열을 복사한다.
	방식은 원래 인스턴스가 갖고 있는 문자열의 주소를 같이 가르키기 때문에(레퍼런스의 한계)
	본래의 인스턴스가 먼저 delete를 하면 그 다음에 복사 생성자로 생성된 인스턴스가 해제하려고 할 때,
	이미 해제한 메모리를 해제하려고 한다는 오류문이 출력될 것 이다.

	얕은 복사와 깊은 복사
	복사 생성자에서 그대로 복사해서 사용해도 되는 값들은 복사. -> 얕은 복사
	그 외에 문제가 발생할 수 있는 name과 같은 문자열들은 따로 메모리를 할당하며 그 내용만 복사 -> 깊은 복사
	=> 해당 방법으로 소멸자에서도 메모리 해제 시 각기 다른 메모미를 해제하는 것 이기 때문에 전혀 문제가 발생하지 않는다.
	*/
// 포토캐논
/* #include <string.h>

#include <iostream>

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	public:
		Photon_Cannon(int x, int y);
		Photon_Cannon(const Photon_Cannon& pc);

		void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}
int main() {
	Photon_Cannon pc1(3, 3);
	Photon_Cannon pc2(pc1);
	Photon_Cannon pc3 = pc2;  // 복사 생성자는 오직 '생성'시에 호출된다.

	pc1.show_status();
	pc2.show_status();
} */

/* 디폴트 복사 생성자의 한계
	해결 방법 -> 얕은 복사(shallow copy)를 통해 디폴트 복사, 깊은 복사(delete할 때 이미 해제된 메모리엔 접근 X, 사용자가 직접 복사 생성자 생성*/
/* #include <string.h>

#include <iostream>

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char	*name;

	public:
		Photon_Cannon(int x, int y);
		Photon_Cannon(int x, int y, const char *cannon_name);
		Photon_Cannon(const Photon_Cannon& pc);
		~Photon_Cannon();

		void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출! " << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon() {
	if (name) delete[] name;
}

Photon_Cannon::Photon_Cannon(int x, int y) {
	std::cout << "생성자 호출 !" << std::endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}
int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1;

	pc1.show_status();
	pc2.show_status();
} */

/* 생성자의 초기화 리스트
	생성자 호출과 동시에 멤버 변수들을 초기화해주게 된다.
	멤버 초기화 리스트이 일반적인 꼴
	(생성자 이름) : var1(arg1), var2(arg2) {} *
	var 들은 클래스의 멤버 변수들 지칭
	arg는 그 멤버 변수들을 무엇으로 초기화 할 지 지칭하는 역할
	var1 이름 == arg1 이름
	ex) coord_x(coord_x)라고 입력 시, 바깥쪽 -> 무조건 멤버 변수 지칭
	괄호 안의 값 인자로 인식.

	생성자와 초기화 리스트 동일한 일을하는데, 왜 초기화 리스트를 사용해야할 까?
	차이점 : 초기화 리스트를 사용할 경우 생성과 초기화를 동시에 한다.
	초기화 리스트를 사용하지 않는다면 생성을 먼저 하고 그 다음에 대입을 수행
	ex) int a = 10; -> 초기화 리스트 사용
		int a;
		a = 10; -> 예전 버전의 생성자 사용.

	초기화 리스트를 사용하는 것이 더 효율적인 작업(하는 일이 줄어듬 -> 초기화와 생성을 같이 하기 때문)
	다른 이유, '생성과 동시에 초기화 되어야 하는 것들이 존재함.
	1. 레퍼런스
	2. 상수
	클래스 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 초기화 리스트를 사용해서 초기화 시켜줘야 한다.
*/

// #include <iostream>

// class Marine
// {
// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	int damage;			  // 공격력
// 	bool is_dead;

// public:
// 	Marine();			  // 기본 생성자
// 	Marine(int x, int y); // x, y 좌표에 마린 생성

// 	int attack();					   // 데미지를 리턴한다.
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// };

// Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {} // 초기화 리스트 <- 생성과 초기화를 동시

// Marine::Marine(int x, int y)
// 	: coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return damage; }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 0)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }

// int main()
// {
// 	Marine marine1(2, 3);
// 	Marine marine2(3, 5);

// 	marine1.show_status();
// 	marine2.show_status();
// }

// #include <iostream>

// class Marine
// {
// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// public:
// 	Marine();			  // 기본 생성자
// 	Marine(int x, int y); // x, y 좌표에 마린 생성

// 	int attack();					   // 데미지를 리턴한다.
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// };
// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

// Marine::Marine(int x, int y)
// 	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 0)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
// 			  << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }

// int main()
// {
// 	Marine marine1(2, 3);
// 	Marine marine2(3, 5);

// 	marine1.show_status();
// 	marine2.show_status();

// 	std::cout << std::endl
// 			  << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

// #include <iostream>

// class Marine
// {
// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// public:
// 	Marine();			  // 기본 생성자
// 	Marine(int x, int y); // x, y 좌표에 마린 생성
// 	Marine(int x, int y, int default_damage);

// 	int attack();					   // 데미지를 리턴한다.
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// };
// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

// Marine::Marine(int x, int y)
// 	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

// Marine::Marine(int x, int y, int default_damage)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),
// 	  default_damage(default_damage),
// 	  is_dead(false) {}

// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 0)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
// 			  << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// }

// int main()
// {
// 	Marine marine1(2, 3, 10);
// 	Marine marine2(3, 5, 10);

// 	marine1.show_status();
// 	marine2.show_status();

// 	std::cout << std::endl
// 			  << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

/* static 멤버 변수의 사용
	전역 변수의 경우 프로젝트의 크기가 커질 수 록 프로그래머의 실수로 인해 서로 겹쳐서 오류가 날 가능성이
	다분허가 때문제 반드시 필요한 경우가 아니면 사용을 하지 않는다.
	전역 변수 같지만 클래스 하나에만 종속되는 변수 -> static 멤버 변수

	C 언어에서 어떠한 함수의 static 변수가 지역 변수들 처럼 함수가 종료될 때 소멸되는 것이 아니라 프로그램이
	종료될 때 소멸되는 것 처럼, 어떤 클래스의 static 멤버 변수의 경우, 멤버 변수들 처럼, 객체가 소멸될 때
	소멸되는 것이 아닌, 프로그램이 종료될 때 소멸되는 것.

	또한, 이 static 멤버 변수의 경우, 클래스의 모든 객체들이 '공유'하는 변수로써 각 객체 별로 따로
	존재하는 멤버 변수들과는 달리 모든 객체들이 '하나의' staitc 멤버 변수를 사용하게 된다.

	static 변수들은 정의와 동시에 값이 자동으로 0으로 초기화.
	클래스 static 변수들의 경우 아래와 같은 방법으로 초기화
	int Marine::total_marine_num = 0;
	static 변수 역시 클래스 내부에서 초기화 하는 것은 불가능.
	static int total_marine = 0; 이 방식처럼 하려면
	const static int x = 0;과 같은 const static 변수일 때만 가능.
*/

// #include <iostream>

// class Marine
// {
// 	static int total_marine_num;

// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// public:
// 	Marine();			  // 기본 생성자
// 	Marine(int x, int y); // x, y 좌표에 마린 생성
// 	Marine(int x, int y, int default_damage);

// 	int attack();					   // 데미지를 리턴한다.
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.

// 	~Marine() { total_marine_num--; }
// };
// int Marine::total_marine_num = 0;

// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
// {
// 	total_marine_num++;
// }

// Marine::Marine(int x, int y)
// 	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false)
// {
// 	total_marine_num++;
// }

// Marine::Marine(int x, int y, int default_damage)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),
// 	  default_damage(default_damage),
// 	  is_dead(false)
// {
// 	total_marine_num++;
// }

// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 0)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
// 			  << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// 	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
// }

// void create_marine()
// {
// 	Marine marine3(10, 10, 4);
// 	marine3.show_status();
// }
// int main()
// {
// 	Marine marine1(2, 3, 5);
// 	marine1.show_status();

// 	Marine marine2(3, 5, 10);
// 	marine2.show_status();

// 	create_marine();

// 	std::cout << std::endl
// 			  << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

/*
	static 함수
	특정 객체에 종속되는 것이 아니라 클래스 전체에 딱 1개 존재
	static 이 아닌 멤버 함수들의 경우 객체를 만들어야하지만 각 멤버 함수들을 호출할 수 있음.
	static 함수의 경우, 객체가 없어도 그냥 클래스 자체에서 호출할 수 있게 된다.
	일반 함수 호출 방법
	(객체).(멤버함수)
	ex) marine1.show_status();
	static 함수 호출 방법
	Marine::show_total_marine();
	(클래스)::(static 함수) -> 어떠한 객체도 이 함수를 소유하고 있지 않기 때문.
	static 함수 내에서는 클래스의 static 변수만을 이용할 수 밖에 없다.
	static 함수내에서 그냥 클래스의 멤버 변수들을 이용한다면.
	ex)
	void Marine::show_total_marine() {
		std::cout << default_damage << std::endl; // default_damage 는 멤버 변수
		std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
	}
	default_damage가 누구의 default_damage 인지 아무도 모르는 상황이 발생
	그 이유는 어떤 객체에도 속해있지 않기 때문에 누구의 것인지 알 수 없다.
*/

// #include <iostream>

// class Marine
// {
// 	static int total_marine_num;
// 	const static int i = 0;

// 	int hp;				  // 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// public:
// 	Marine();			  // 기본 생성자
// 	Marine(int x, int y); // x, y 좌표에 마린 생성
// 	Marine(int x, int y, int default_damage);

// 	int attack();					   // 데미지를 리턴한다.
// 	void be_attacked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);		   // 새로운 위치

// 	void show_status(); // 상태를 보여준다.
// 	static void show_total_marine();
// 	~Marine() { total_marine_num--; }
// };
// int Marine::total_marine_num = 0;
// void Marine::show_total_marine()
// {
// 	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
// }
// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false)
// {
// 	total_marine_num++;
// }

// Marine::Marine(int x, int y)
// 	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false)
// {
// 	total_marine_num++;
// }

// Marine::Marine(int x, int y, int default_damage)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),
// 	  default_damage(default_damage),
// 	  is_dead(false)
// {
// 	total_marine_num++;
// }

// void Marine::move(int x, int y)
// {
// 	coord_x = x;
// 	coord_y = y;
// }
// int Marine::attack() { return default_damage; }
// void Marine::be_attacked(int damage_earn)
// {
// 	hp -= damage_earn;
// 	if (hp <= 0)
// 		is_dead = true;
// }
// void Marine::show_status()
// {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
// 			  << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// 	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
// }

// void create_marine()
// {
// 	Marine marine3(10, 10, 4);
// 	Marine::show_total_marine();
// }
// int main()
// {
// 	Marine marine1(2, 3, 5);
// 	Marine::show_total_marine();

// 	Marine marine2(3, 5, 10);
// 	Marine::show_total_marine();

// 	create_marine();

// 	std::cout << std::endl
// 			  << "마린 1 이 마린 2 를 공격! " << std::endl;
// 	marine2.be_attacked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

/*
	this
	자기 자신을 가리키는 포인터 this
	객체 자신을 가르키는 포인터의 역할. 즉, 이 멤버 함수를 호출하는 객체 자신을 가리킨다는 것

	Marine& Marine::be_attacked(int damage_earn) {
		hp -= damage_earn;
		if (hp <= 0) is_dead = true;

		return *this;
	}

	Marine& Marine::be_attacked(int damage_earn) {
		this->hp -= damage_earn;
		if (this->hp <= 0) this->is_dead = true;

		return *this;
	}
*/
// #include <iostream>

// class Marine {
// 	static int total_marine_num;
// 	const static int i = 0;

// 	int hp;	// 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// 	public:
// 		Marine(); // 기본 생성자
// 		Marine(int x, int y); // x, y 좌표에 마린 생성
// 		Marine(int x, int y, int default_damage);

// 	int attack(); // 데미지를 리턴한다.
// 	Marine& be_attcked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);

// 	void show_status(); // 상태를 보여준다.
// 	static void show_total_marine();
// 	~Marine() { total_marine_num--; }
// };

// int Marine::total_marine_num = 0;
// void Marine::show_total_marine() {
// 	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
// }

// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
// 		total_marine_num++;
// 	}

// Marine::Marine(int x, int y)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),

// 	  default_damage(5),
// 	  is_dead(false) {
// 		total_marine_num++;
// 	}

// Marine::Marine(int x, int y, int default_damage)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),
// 	  default_damage(default_damage),
// 	  is_dead(false) {
// 		total_marine_num++;
// 	}

// void Marine::move(int x, int y) {
// 	coord_x = x;
// 	coord_y = y;
// }

// int Marine::attack() { return default_damage; }
// Marine& Marine::be_attcked(int damafe_earn) {
// 	hp -= damafe_earn;
// 	if (hp <= 0) is_dead = true;

// 	return *this;
// }

// void Marine::show_status() {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// 	std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
// }

// int main() {
// 	Marine marine1(2, 3 ,5);
// 	marine1.show_status();

// 	Marine marine2(3, 5, 10);
// 	marine2.show_status();

// 	std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
// 	marine2.be_attcked(marine1.attack()).be_attcked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

/*
	레퍼런스를 리턴하는 함수
	레퍼런스가 아닌 타입을 리턴하는 경우는 '값'의 복사가 이루어지기 때문에 임시 객체가 생성되는데,
	임시객체의 레퍼런스를 가질 수 없기 때문이다.(임시객체는 문장이 끝나게 되면 소멸)
	a.access_x() = 3;
	위 문장이 잘 작동한다는 점.
	'레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다.'
	a.x=3;과 같은 뜻
	a.get_x() = 3;
	오류 발생 -> a.get_x() 는 get_x() 가 리턴하면서 생기는 임시 객체로 치환되며 임시 객체에 대입을 하게
	되는 모순적인 상황이 발생
	간단하게 말하면, 지역변수가 리턴하는데 그 함수 끝나면 없어지니까 레퍼런스 줄 수 없다~ 라는 뜻 그래서
	리턴형이 레퍼런스가 아닌 것을 쓰면 임시 객체가 발생하니까. 복사를 해야하는데 없어지는 것을 복사하니까 오류가 생긴다.
	임시객체에 값을 대입하는 것도 문제. 없어지는 값에 값을 넣는게 말이 되냐라는 뜻.
*/

// #include <iostream>

// class A {
// 	int x;

// 	public:
// 	A(int c) : x(c) {}

// 	int& access_x() { return x;}
// 	int get_x() { return x; }
// 	void show_x() { std::cout << x << std::endl; }
// };

// int main() {
// 	A a(5);
// 	a.show_x();

// 	int &c = a.access_x();
// 	c = 4;
// 	a.show_x();

// 	int d = a.access_x();
// 	d = 3;
// 	a.show_x();

// 	// 아래는 오류
// 	// int& e = a.get_x();
// 	// e = 2;
// 	// a.show_x();

// 	int f = a.get_x();
// 	f = 1;
// 	a.show_x();
// }

/*
	const 함수
	C++에서는 변수들의 값을 바꾸지 않고 읽기 만 하는, 마치 상수 같은 멤버 함수를 상수 함수로써 선언할 수 있다.

	상수 함수는 위와 같은 형태로 선언
	(기존의 함수의 정의) const;
	함수의 정의 역시 const 키워드를 꼭 넣어주어야 한다.
	int Marine::attack() const { return default_damage; }
	위 함수는 '상수 멤버 함수'로 정의.
	이 함수는 다른 변수의 값을 바꾸지 않는 함수라고 다른 프로그래머에게 명시 시킬 수 있다.
	상수 함수 내에서는 객체들의 '읽기'만이 수행, 상수 함수 내에서 호출 할 수 있는 함수로는 다른 상수 함수 밖에없다.

	많은 경우 클래스를 설계할 때, 멤버 변수들은 모두 private에 넣고, 이 변수들의 값에 접근하는 방법으로
	get_x 함수 처럼 함수를 public에 넣어 이 함수를 이용해 값을 리턴받는 형식을 많이 사용
	-> 위 같은 방법으로 멤버 변수들은 private 에 넣음으로써 함부로 변수에 접근하는 것을 막고, 또 그 값은 자유롭게
	구할 수 있게 된다.

*/

// 상수 멤버 함수
// #include <iostream>

// class Marine {
// 	static int total_marine_num;
// 	const static int i = 0;

// 	int hp;	// 마린 체력
// 	int coord_x, coord_y; // 마린 위치
// 	bool is_dead;

// 	const int default_damage; // 기본 공격력

// 	public:
// 		Marine(); // 기본 생성자
// 		Marine(int x, int y); // x, y 좌표에 마린 생성
// 		Marine(int x, int y, int default_damage);

// 	int attack() const; // 데미지를 리턴한다.
// 	Marine& be_attcked(int damage_earn); // 입는 데미지
// 	void move(int x, int y);

// 	void show_status(); // 상태를 보여준다.
// 	static void show_total_marine();
// 	~Marine() { total_marine_num--; }
// };

// int Marine::total_marine_num = 0;
// void Marine::show_total_marine() {
// 	std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
// }

// Marine::Marine()
// 	: hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
// 		total_marine_num++;
// 	}

// Marine::Marine(int x, int y)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),

// 	  default_damage(5),
// 	  is_dead(false) {
// 		total_marine_num++;
// 	}

// Marine::Marine(int x, int y, int default_damage)
// 	: coord_x(x),
// 	  coord_y(y),
// 	  hp(50),
// 	  default_damage(default_damage),
// 	  is_dead(false) {
// 		total_marine_num++;
// 	}

// void Marine::move(int x, int y) {
// 	coord_x = x;
// 	coord_y = y;
// }

// int Marine::attack() const { return default_damage; }
// Marine& Marine::be_attcked(int damafe_earn) {
// 	hp -= damafe_earn;
// 	if (hp <= 0) is_dead = true;

// 	return *this;
// }

// void Marine::show_status() {
// 	std::cout << " *** Marine *** " << std::endl;
// 	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
// 	std::cout << " HP : " << hp << std::endl;
// 	std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
// }

// int main() {
// 	Marine marine1(2, 3, 5);
// 	marine1.show_status();

// 	Marine marine2(3, 5, 10);
// 	marine2.show_status();

// 	std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
// 	marine2.be_attcked(marine1.attack()).be_attcked(marine1.attack());

// 	marine1.show_status();
// 	marine2.show_status();
// }

// 4 - 5 내가 만드는 String 클래스
// 문자열들을 효율적으로 관리하고 보관할 수 있는 문자열 클래스 만들 것.

/*
	나만의 문자열 클래스 만들기
	조건
	1. 문자(char)로 부터의 문자열 생성, C 문자열 (char *)로 부터의 생성
	2. 문자열 길이를 구하는 함수
	3. 문자열 뒤에 다른 문자열 붙이기
	4. 문자열 내에 포함되어 있는 문자열 구하기
	5. 문자열이 같은지 비교
	6. 문자열 크기 비교 (사전순)

	페이스북이나 구글 같은 큰 회사에서는 C++에서 기본적으로 지원하는 표준 문자열 대신에 자체적으로 최적화 된 버전을 만들어서 사용.
*/

/*
	기존 C 언어에서는 문자열을 나타내기 위해 널 종료 문자열(Null-terstd::minating string) 이라는 개념을 도입, 문자열 끝에 NULL 문자를 붙여 문자열을 나타냄
	C 언어 문자열을 사용하는데에는 번거로움이 많았는데, 예를 들어 만들어진 문자열의 크기를 바꾼다던지, 문자열 뒤에 다른 문자열을 붙인다던지 등의 작업들을 상당히 프로그래머
	입장에서는 귀찮을 수 밖에 없었다.

	C++에서는 표준 라이브러리로 string 클래스를 지원. (실제로 <string> 헤더파일을 include 하면 사용할 수 있다.)
*/

/*
	MyString 클래스에 멤버 변수로 무엇이 필요할지 생각해보자
	대표적으로 아래 두 개의 데이터들이 필요

	1. 문자열 데이터가 저장된 공간을 가리키는 포인터
	2. 문자열 데이터의 길이

	왜 문자열 데이터를 직접 관리하는 것이 아닌, 저장된 공간을 가리키는 포인터를 보관?
	-> 나중에 문자열 데이터의 크기가 바뀔 때, 저장된 공간을 가리키는 방식으로 하면 그 메모리를 해제한 뒤, 다시 할당 가능
	직접 보관 시, 불가능함.

	문자열 데이터의 길이를 보관하는 이유 -> 문자열 길이를 사용할 일이 굉장히 많은데, 그 때 마다 계속 길이를 구하는 것은 상당히 불필요한 일이기 때문.
	따라서 길이를 한 번 구해놓고 길이가 바뀔 때 까지 변경하지 않는 방법이 유용
*/

// #include <iostream>

// // string.h는 strlen 때문에 포함, 사실 strlen과 같은 함수를 만들어서 사용해도 된다.
// #include <string.h>
// class MyString
// {
// 	char *string_content; // 문자열 데이터를 가리키는 포인터
// 	int string_length;	  // 문자열 길이
// 	int memory_capacity;  // 현재 할당된 용량

// public:
// 	// 문자 하나로 생성
// 	MyString(char c);
// 	// 문자열로 부터 생성
// 	MyString(const char *str);
// 	// 복사 생성자
// 	MyString(const MyString &str);

// 	~MyString();

// 	int length() const;
// 	int capacity() const;
// 	void reserve(int size);

// 	void print() const;
// 	void println() const;

// 	MyString& assign(const MyString& str);
// 	MyString& assign(const char* str);
// };

// MyString::MyString(char c)
// {
// 	string_content = new char[1];
// 	string_content[0] = c;
// 	string_length = 1;
// }

// MyString::MyString(const char *str)
// {
// 	string_length = strlen(str);
// 	string_content = new char[string_length];

// 	for (int i = 0; i != string_length; i++)
// 		string_content[i] = str[i];
// }

// MyString::MyString(const MyString &str)
// {
// 	string_length = str.string_length;
// 	for (int i = 0; i != string_length; i++)
// 		string_content[i] = str.string_content[i];
// }
// MyString::~MyString() { delete[] string_content; }

// /* 내부 멤버 변수의 값을 바꾸지 않는다면 함수를 꼭 상수로 정의하기. */
// // length 함수 역시 string_length 의 값을 읽기만 하므로 상수 함수처럼 정의.
// int MyString::length() const { return string_length; }

// void MyString::print() const
// {
// 	for (int i = 0; i != string_length; i++)
// 		std::cout << string_content[i];
// }

// void MyString::println() const
// {
// 	for (int i = 0; i != string_length; i++)
// 		std::cout << string_content[i];

// 	std::cout << std::endl;
// }

// // int main()
// // {
// // 	MyString str1("hello world!");
// // 	MyString str2(str1);

// // 	str1.println();
// // 	str2.println();
// // }

// /*
// 	assign 함수
// 	assign 함수는 '지정하다'라는 뜻을 가진 함수, 우리가 흔히 생각하는 '='과 동일한 역할
// 	str.assign("abc");
// 	str = "abc"; 와 같은 의미
// */

// // MyString& MyString::assign(const MyString& str);
// // {
// // 	if (str.str_lenght > string_length) {
// // 		// 그러면 다시 할당 해줘야 한다.
// // 		delete[] string_content;

// // 		string_content = new char[str.string_length];
// // 	}
// // 	for (int i = 0; i != str.str_length; i++)
// // 		string_content[i]  = str.string_content[i];

// // 		// 그리고 굳이 str.string_length + 1 ~ string_length 부븐은 초기화
// // 		// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어 들이지 않기 때문.

// // 		string_length = str.string_length;

// // 		return *this;
// // }

// // MyString& MyString::assign(const char* str) {
// // 	int str_length = strlen(str);
// // 	if (str_length > string_legnth) {
// // 		// 다시 할당
// // 		delete[] string_content;

// // 		string_content = new char[str_length];
// // 	}
// // 	for (int i = 0; i != str_length; i++)
// // 		string_content[i] = str[i];

// // 	string_length = str_length;

// // 	return *this;
// // }

// MyString& MyString::assign(const MyString& str)
// {
// 	if (str.string_length > memory_capacity)
// 	{
// 		// 그러면 다시 할당 해줘야 한다.
// 		delete[] string_content;

// 		string_content = new char[str.string_length];
// 		memory_capacity = str.string_length;
// 	}
// 	for (int i = 0; i != str.string_length; i++)
// 		string_content[i] = str.string_content[i];

// 	// 그리고 굳이 str.string_length + 1 ~ string_length 부븐은 초기화
// 	// 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어 들이지 않기 때문.

// 	string_length = str.string_length;

// 	return *this;
// }

// MyString& MyString::assign(const char *str)
// {
// 	int str_length = strlen(str);
// 	if (str_length > memory_capacity)
// 	{
// 		// 다시 할당
// 		delete[] string_content;

// 		string_content = new char[str_length];
// 		memory_capacity = str_length;
// 	}
// 	for (int i = 0; i != str_length; i++)
// 		string_content[i] = str[i];

// 	string_length = str_length;

// 	return *this;
// }

// int MyString::capacity() const { return memory_capacity; }
// void MyString::reserve(int size) {
// 	if (size > memory_capacity) {
// 		char *prev_string_content = string_content;

// 		string_content = new char[size];
// 		memory_capacity = size;

// 		for (int i = 0; i != string_length; i++)
// 			string_content[i] = prev_string_content[i];

// 		delete[] prev_string_content;
// 	}

// 	// 만일 예약하려는 size 가 현재 capacity 보다 작다면 아무것도 안해도 된다.
// }

// int main() {
// 	MyString str1("very very very long string");
// 	str1.reserve(30);

// 	std::cout << "Capacity : " << str1.capacity() << std::endl;
// 	std::cout << "String length : " << str1.length() << std::endl;
// 	str1.println();
// }

// #include <iostream>

// // string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// // 과 같은 함수를 만들어서 써도 됩니다.
// #include <string.h>

// class MyString {
//   char* string_content;  // 문자열 데이터를 가리키는 포인터
//   int string_length;     // 문자열 길이
//   int memory_capacity;   // 현재 할당된 용량

//  public:
//   // 문자 하나로 생성
//   MyString(char c);

//   // 문자열로 부터 생성
//   MyString(const char* str);

//   // 복사 생성자
//   MyString(const MyString& str);

//   ~MyString();

//   int length() const;
//   int capacity() const;
//   void reserve(int size);

//   void print() const;
//   void println() const;

//   MyString& assign(const MyString& str);
//   MyString& assign(const char* str);
// };

// MyString::MyString(char c) {
//   string_content = new char[1];
//   string_content[0] = c;
//   memory_capacity = 1;
//   string_length = 1;
// }
// MyString::MyString(const char* str) {
//   string_length = strlen(str);
//   memory_capacity = string_length;
//   string_content = new char[string_length];

//   for (int i = 0; i != string_length; i++) {
//     string_content[i] = str[i];
//   }
// }

// MyString::MyString(const MyString& str) {
//   string_length = str.string_length;
//   memory_capacity = str.string_length;
//   string_content = new char[string_length];

//   for (int i = 0; i != string_length; i++) {
//     string_content[i] = str.string_content[i];
//   }
// }

// MyString::~MyString() { delete[] string_content; }
// int MyString::length() const { return string_length; }

// void MyString::print() const {
//   for (int i = 0; i != string_length; i++) {
//     std::cout << string_content[i];
//   }
// }
// void MyString::println() const {
//   for (int i = 0; i != string_length; i++) {
//     std::cout << string_content[i];
//   }

//   std::cout << std::endl;
// }

// MyString& MyString::assign(const MyString& str) {
//   if (str.string_length > memory_capacity) {
//     // 그러면 다시 할당을 해줘야만 한다.
//     delete[] string_content;

//     string_content = new char[str.string_length];
//     memory_capacity = str.string_length;
//   }
//   for (int i = 0; i != str.string_length; i++) {
//     string_content[i] = str.string_content[i];
//   }

//   // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
//   // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

//   string_length = str.string_length;

//   return *this;
// }
// MyString& MyString::assign(const char* str) {
//   int str_length = strlen(str);
//   if (str_length > memory_capacity) {
//     // 그러면 다시 할당을 해줘야만 한다.
//     delete[] string_content;

//     string_content = new char[str_length];
//     memory_capacity = str_length;
//   }
//   for (int i = 0; i != str_length; i++) {
//     string_content[i] = str[i];
//   }

//   string_length = str_length;

//   return *this;
// }
// int MyString::capacity() const { return memory_capacity; }
// void MyString::reserve(int size) {
//   if (size > memory_capacity) {
//     char* prev_string_content = string_content;

//     string_content = new char[size];
//     memory_capacity = size;

//     for (int i = 0; i != string_length; i++)
//       string_content[i] = prev_string_content[i];

//     delete[] prev_string_content;
//   }

//   // 만일 예약하려는 size 가 현재 capacity 보다 작다면
//   // 아무것도 안해도 된다.
// }
// int main() {
//   MyString str1("very very very long string");
//   str1.reserve(30);

//   std::cout << "Capacity : " << str1.capacity() << std::endl;
//   std::cout << "String length : " << str1.length() << std::endl;
//   str1.println();
// }

/*
	마지막으로 추가할 함수는 임의의 위치의 문자를 리턴하는 함수.
	이전 C언어에서 []로 구현되었던 것
	C 문자열의 경우 구조상 배열의 범위를 벗어나는 위치에 대한 문자를 요구하여도 이를 처리할 수  밖에 없었는데
	C++의 경우 특정 위치의 문자를 얻는 것을 함수로 만들어서 올바르지 않는 위치에 대한 문제를 처리할 수 있게 됐다.

	char MyString::at(int i) const {
		if (i >= string_lenghth || i < 0)
			return NULL;
		else
			return string_content[i];
	}

	i가 허용되는 범위를 초과한다면 NULL 을 리턴
*/

/*
	문자열 삽입하기(insert)
	문자열 처리에서 가장 빈번하게 사용되는 작업으로, 문자열 중간에 다른 문자열을 삽입하는 작업을 들 수 있다.
	사실 여태까지 만들어 놓은 함수들만 갖고 insert 작업을 쉽게 구현할 수 있겠지만, 빈번하게 사용되는 작업이다 보니,
	미리 만들어 놓아서 인터페이스로 제공하는 것도 나쁘지 않을 것 같다.
*/

/*
	MyString& MyString::insert(int loc, const MyString& str);
	MyString& MyString::insert(int loc, const char* str);
	MyString& MyString::insert(int loc, char c);
	
	insert 작업이 워낙 다양한 용도로 빈번하게 사용되기 때문에 3개 함수 구현
	loc 어떻게 생각할 지 미리 기준.
	일반적으로 insert 함수에서 입력 위치를 받는 경우, 그 입력 위치 '앞'에 문자를 insert
	모든 위치는 배열의 인덱스로 생각

*/

// MyString& MyString::insert(int loc, const MyString&* str) {

// 	// 범위를 벗어나는 입력해 대해서는 삽입을 수행하지 않는다.
// 	if (loc < 0 || loc > string_length) return *this;

// 	if (string_length + str.string_length > memory_capacity) {
// 		// 이제 새롭게 동적으로 할당해야한다.
// 		memory_capacity = string_length + str.string_length;

// 		char* prev_string_content = string_content;
// 		string_content = new char[memory_capacity];

// 		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
// 		int i;
// 		for (i = 0; i < loc; i+++) {
// 			string_content[i] = prev_string_content[i];
// 		}
		
// 		// 그리고 새롭게 insert 되는 문자열을 넣는다.
// 		for (int j = 0; j != str.string_length; j++)
// 			string_content[i + j] = str.string_content[j];

// 		// 이제 다시 원 문자열의 나머지 뒷 부분을 복사한다.
// 		for(; i < string_length; i++)
// 			string_content[str.string_length + i] = prev_string_content[i];
		
// 		delete[] prev_string_content;

// 		string_length = string_length + str.string_length;
// 		return *this;
// 	}

// 	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
// 	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

// 	for (int i = string_length - 1; i >= loc; i--) {
// 		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
// 		string_content[i + str.string_length] = string_content[i];
// 	}
// 	// 그리고 insert 되는 문자 다시 집어 넣기
// 	for (int i = 0; i < str.string_length; i++)
// 		string_content[i + loc] = str.string_content[i];
	
// 	string_length = string_length + str.string_length;
// 	return *this;
// }

#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

class MyString {
  char* string_content;  // 문자열 데이터를 가리키는 포인터
  int string_length;     // 문자열 길이
  int memory_capacity;   // 현재 할당된 용량

 public:
  // 문자 하나로 생성
  MyString(char c);

  // 문자열로 부터 생성
  MyString(const char* str);

  // 복사 생성자
  MyString(const MyString& str);

  ~MyString();

  int length() const;
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  char at(int i) const;

  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);
};

MyString::MyString(char c) {
  string_content = new char[1];
  string_content[0] = c;
  memory_capacity = 1;
  string_length = 1;
}
MyString::MyString(const char* str) {
  string_length = strlen(str);
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str[i];
  }
}

MyString::MyString(const MyString& str) {
  string_length = str.string_length;
  memory_capacity = str.string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++) {
    string_content[i] = str.string_content[i];
  }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}
void MyString::println() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }

  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
  if (str.string_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str.string_length];
    memory_capacity = str.string_length;
  }
  for (int i = 0; i != str.string_length; i++) {
    string_content[i] = str.string_content[i];
  }

  // 그리고 굳이 str.string_length + 1 ~ string_length 부분은 초기화
  // 시킬 필요는 없다. 왜냐하면 거기 까지는 읽어들이지 않기 때문이다.

  string_length = str.string_length;

  return *this;
}
MyString& MyString::assign(const char* str) {
  int str_length = strlen(str);
  if (str_length > memory_capacity) {
    // 그러면 다시 할당을 해줘야만 한다.
    delete[] string_content;

    string_content = new char[str_length];
    memory_capacity = str_length;
  }
  for (int i = 0; i != str_length; i++) {
    string_content[i] = str[i];
  }

  string_length = str_length;

  return *this;
}
int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
  if (size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;

    for (int i = 0; i != string_length; i++)
      string_content[i] = prev_string_content[i];

    delete[] prev_string_content;
  }

  // 만일 예약하려는 size 가 현재 capacity 보다 작다면
  // 아무것도 안해도 된다.
}
char MyString::at(int i) const {
  if (i >= string_length || i < 0) {
    return 0;
  } else {
    return string_content[i];
  }
}
MyString& MyString::insert(int loc, const MyString& str) {
  // 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
  // abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

  // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
  if (loc < 0 || loc > string_length) {
    return *this;
  }

  if (string_length + str.string_length > memory_capacity) {
    // 이제 새롭게 동적으로 할당을 해야 한다.
    memory_capacity = string_length + str.string_length;

    char* prev_string_content = string_content;
    string_content = new char[memory_capacity];

    // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
    int i;
    for (i = 0; i < loc; i++) {
      string_content[i] = prev_string_content[i];
    }

    // 그리고 새롭에 insert 되는 문자열을 넣는다.
    for (int j = 0; j != str.string_length; j++) {
      string_content[i + j] = str.string_content[j];
    }

    // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
    for (; i < string_length; i++) {
      string_content[str.string_length + i] = prev_string_content[i];
    }

    delete[] prev_string_content;

    string_length = string_length + str.string_length;
    return *this;
  }

  // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
  // 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

  for (int i = string_length - 1; i >= loc; i--) {
    // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
    string_content[i + str.string_length] = string_content[i];
  }
  // 그리고 insert 되는 문자 다시 집어넣기
  for (int i = 0; i < str.string_length; i++)
    string_content[i + loc] = str.string_content[i];

  string_length = string_length + str.string_length;
  return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}
int main() {
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();
}