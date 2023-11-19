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

/* 복사 생성자 */
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

/* 생성자의 초기화 리스트 */
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

// static 함수
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