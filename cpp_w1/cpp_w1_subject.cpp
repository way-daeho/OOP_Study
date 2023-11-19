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

/* #include <iostream>
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
	date.AddDay(5050);
	date.showDate();
	return 0;
} */

// 예외처리를 하긴 했지만, 윤년을 구하는 함수를 만들어서 사용하는 것이 더 좋을 것 같다. 주어진 조건만 사용하긴 했는데.


/* 생각해보기
	아래와 같은 문자열 클래스를 완성해보세요. */
// #include <string.h>
// #include <iostream>

// class string
// {
// 	char *str;
// 	int len;

// public:
// 	string(char c, int n); // 문자 c가 n개 있는 문자열로 정의
// 	string(const char *s);
// 	string(const string &s);
// 	~string();

// 	void add_string(const string &s);  // str 뒤에 s 를 붙인다.
// 	void copy_string(const string &s); // str 에 s 를 복사한다.
// 	int strlen();					   // 문자열 길이 리턴
// };

// string::string(char c, int n) {
// 	int i = 0;
// 	str = new char[n + 1];
// 	for (i = 0; i < n; i++)
// 		str[i] = c;
// 	len = n;
// }

// string::string(const char *s)
// {
// 	size_t slen = 0;
// 	while (s[slen])
// 		slen++;
// 	len = slen;
// 	str = new char[len + 1];
// 	strcpy(str, s);
// }

// string::string(const string &s)
// {
// 	str = new char[strlen(s) + 1];
// 	strcpy(str, s);
// 	len = s.len;
// }

// string::~string()
// {
// 	if (str)
// 		delete[](str);
// 	std::cout << "소멸자 호출 " << std::endl;
// }

// void string::add_string(const string &s) // str 뒤에 s를 붙인다.
// {
// 	if (!s)
// 		exit(1);
// 	char	*temp;
// 	len = len + s.len;
// 	temp = new char[len + 1];
// 	strcat(temp, str);
// 	strcat(temp, (const char*)s);
// 	if (str)
// 		delete[] str;
// 	str = new char[strlen(temp) + 1];
// 	strcpy(str,temp);
// 	delete [] temp;
// }

// void string::copy_string(const string &s) // str에 s를 복사한다.
// {
// 	if (str)
// 		delete[] str;
// 	str = new char[s.len + 1];
// 	strcpy(str, s);
// 	len = string::strlen(str);
// }

// int string::strlen()
// {
// 	return (len);
// }

/* Point로 점에 관한 정보들 담고, 하나는 Geometry로 점들을 가지고 연산을 하는 클래스 */
#include <iostream>
#include <math.h>
class Point {
	int x,y;

	public:
		Point(int pos_x, int pos_y)
		{
			x = pos_x;
			y = pos_y;
		}
};

class Geometry {
	private:
	// 점 100 개를 보관하는 배열.
	Point* point_array[100];
	int num_points;

	public:
		Geometry() {
			num_points = 0;
		}

		void AddPoint(const Point &point); {
			point_array[num_points++] = new Point(point.x, point.y);
		}

		// 모든 점들 간의 거리를 출력하는 함수
		void PrintDistance ()
		{
			
		}

		// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수.
		/* 참고로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
			이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2,y2) 가 f(x,y) = 0을 기준으로
			서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 된다.*/
		void PrintNumMeets();


};