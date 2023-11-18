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

/* 생각 해볼 문제
	Date 클래스를 디자인
	SetDate -> Date 함수 내부 초기화
	AddDay, AddMonth, Addyear -> 일, 월, 년 원하는 만큼 더함.
*/

/* Edge Point
	1. Luna year 윤년 year % 4 == 0 일 때 2월은 29일까지
		역은 2월 28일까지 존재.
	2. 12월 이후로 달을 더하게 된다면,
		1. year가 1 증가해야함.
		2. 달 별로 max_day가 다르기 때문에 이 부분도 생각해야함
			1,3,5,7,8,10,12 -> 31
			4, 6 ,9, 11 -> 30
			2월 year % 4 == 0 -> 29
			else 28
		3. 2012 2월 28 + 3 일 -> 2012년 3월 2일, 2013 2월 28일 + 3일 -> 2013 3월 3일
			해결방안 생각하기 if else 문으로 해결하는 것 밖에 생각이 안들음
*/

/*
#include <iostream>
class Date {
	int year_;
	int month_; // 1 부터 12 까지.
	int day_; // 1 부터 31 까지.

	public:
		void SetDate(int year, int month, int date)
		{
			// year_ 초기화 부분
			if (year < 0)
			{
				std::cout << "Error : year는 양수이여야 합니다." << std::endl;
				exit(1);
			}
			else
				year_ = year;

			// month와 date 초기화 부분 -> date는 month의 값의 종속이 된다.
			if (month <= 0 || 12 < month || date < 1 || 31 < date)
			{
				std::cout << "Error : 유효하지 않은 값을 입력하셨습니다." << std::endl;
				std::cout << "입력한 month 값 : " << month << " 입력한 date 값 : " << date << std::endl;
				exit(1);
			}
			else
			{
				month_ = month;
				day_ = date;
			}

			// 윤년 구별
			if ((year % 4 == 0 && year % 100 != 0 && month == 2) || (year % 400 == 0 && month == 2))
			{
				if (date < 1 || 29 < date)
				{
					std::cout << "입력한 " << year << "는 윤년입니다. 최소 입력 date 는 \"1\"이고 최대 입력 date는 \"29\"입니다. 유효한 date값을 입력해주세요." << std::endl;
					exit(1);
				}
			}
			else
			{
				if (date < 1 || 28 < date)
				{
					std::cout << "입력한 " << year << "는 윤년이 아닙니다. 최소 입력 date 는 \"1\"이고 최대 입력 date는 \"28\"입니다. 유효한 date값을 입력해주세요." << std::endl;
					exit(1);
				}
			}

			if (month == 4 || month == 6 || month == 9 || month == 11)
				if (30 < date)
				{
					std::cout << month <<"월의 최대 date는 30입니다."<<std::endl;
					std::cout << "입력한 date 값 : " << date << std::endl;
					exit(1);
				}
			day_ = date;
		};

		void AddDay(int inc)
		{
			if (inc < 0)
			{
				std::cout << "해당 프로그램은 양수의 값만 더합니다." << std::endl;
				exit(1);
			}

			int MAX_DAY[12] = {31, 28 , 31, 30 ,31, 30 ,31, 31, 30, 31, 30 ,31};
			int MD = MAX_DAY[month_ - 1];
			if ((year_ % 4 == 0 && year_ % 100 != 0 && month_ ==2) || (year_ % 400 == 0 && month_ == 2))
				MD = 29;
			if (day_ + inc <= MD)
			{
				day_ += inc; // 해당 달에 포함되는 경우
				return ;
			}
			else if (MAX_DAY[month_ - 1] < day_ + inc)
			{
				int tmpMonth = month_;
				int tmpYear = year_;
				int overMonthDaysSum = 0;
				int addMonth = -1;
				if (day_ + inc <= MAX_DAY[month_ - 1])
					day_ = (day_ + inc);
				else
				{
					while (overMonthDaysSum < day_ + inc)
					{
						addMonth++;
						if (12 < tmpMonth)
						{
							tmpMonth = 1;
							tmpYear++;
						}
						if ((tmpYear % 4 == 0 && tmpYear % 100 != 0 && tmpMonth == 2) || tmpYear % 400 == 0 && tmpMonth == 2)
							overMonthDaysSum += 29;
						else
							overMonthDaysSum += MAX_DAY[tmpMonth - 1];
						tmpMonth++;
					}
					AddMonth(addMonth);
					day_ = (day_ + inc) - (overMonthDaysSum - MAX_DAY[tmpMonth - 2]) - 1;
				}
			}
		};

		void AddMonth(int inc)
		{
			if (inc <= 0)
			{
				std::cout << "Error : 유효하지 않은 값을 입력하셨습니다." << std::endl;
				std::cout << "입력한 값 : " << inc << std::endl;
				exit(1);
			}
			AddYear((inc + month_ - 1) / 12);
			month_ = month_ + (inc % 12);
			if (12 < month_)
				month_ %= 12;
		};

		void AddYear(int inc)
		{
			year_ += inc;
		};

	void showDate()
	{
		std::cout << year_ << " 년 " << month_ << " 월 " << day_ << " 일 " << std::endl;
	};
};

int main()
{
	Date date;
	date.SetDate(2012, 2, 28);
	date.showDate();
	date.AddDay(5000);
	date.showDate();
	return 0;
}

예외처리를 하긴 했지만, 윤년을 구하는 함수를 만들어서 사용하는 것이 더 좋을 것 같다. 주어진 조건만 사용하긴 했는데.
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
#include <iostream>
class Date {
int year_;
int month_; // 1 부터 12 까지.
int day_; // 1 부터 31 까지.
public:
void ShowDate();
Date() {
year_ = 2012;
month_ = 7;
day_ = 12;
}
};
void Date::ShowDate() {
std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
<< " 일 입니다 " << std::endl;
}
int main() {
Date day = Date();
Date day2;
day.ShowDate();
day2.ShowDate();
return 0;
}
