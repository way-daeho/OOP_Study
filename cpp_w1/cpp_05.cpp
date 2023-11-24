/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp_05.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:21:16 by daehlee           #+#    #+#             */
/*   Updated: 2023/11/24 21:40:03 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	오버로딩(Overloading) 같은 이름의 함수를 인자만 다르게 사용하는 것을 '함수를 오버로딩 했다' 라고 부른다.

	MyString 의 `==` 연산자 오버로딩
	(리턴 타입) operator(연산자) (연산자가 받는 인자)
	(* 참고적으로 위 방법 외에는 함수 이름으로 연산자를 절대 넣을 수 없다.)
	bool operator==(MyString& str);
	이제, 우리가 str1 == str2 라는 명령을 한다면 이는 str1.operator==(str2) 로 내부적으로 변환되어 처리.

	bool MyString::operator == (MyString& str) {
		return !compare(str); // str 과 같으면 compare 에서 0을 리턴한다.
	}
*/

// #include <string.h>
// #include <iostream>

// class MyString {
//   char* string_content;  // 문자열 데이터를 가리키는 포인터
//   int string_length;     // 문자열 길이

//   int memory_capacity;  // 현재 할당된 용량

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

//   char at(int i) const;

//   int compare(MyString& str);
//   bool operator==(MyString& str);
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

//   for (int i = 0; i != string_length; i++) string_content[i] = str[i];
// }
// MyString::MyString(const MyString& str) {
//   string_length = str.string_length;
//   string_content = new char[string_length];

//   for (int i = 0; i != string_length; i++)
//     string_content[i] = str.string_content[i];
// }
// MyString::~MyString() { delete[] string_content; }
// int MyString::length() const { return string_length; }
// void MyString::print() const {
//   for (int i = 0; i != string_length; i++) std::cout << string_content[i];
// }
// void MyString::println() const {
//   for (int i = 0; i != string_length; i++) std::cout << string_content[i];

//   std::cout << std::endl;
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
// char MyString::at(int i) const {
//   if (i >= string_length || i < 0)
//     return 0;
//   else
//     return string_content[i];
// }
// int MyString::compare(MyString& str) {
//   // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
//   // 1 은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0 은 두 문자열
//   // 이 같다는 의미, -1 은 (*this) 사 사전식으러 더 앞에 온다는 의미이다.

//   for (int i = 0; i < std::min(string_length, str.string_length); i++) {
//     if (string_content[i] > str.string_content[i])
//       return 1;

//     else if (string_content[i] < str.string_content[i])
//       return -1;
//   }

//   // 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이 된다.
//   // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

//   if (string_length == str.string_length) return 0;

//   // 참고로 abc 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
//   else if (string_length > str.string_length)
//     return 1;

//   return -1;
// }
// bool MyString::operator==(MyString& str) {
//   return !compare(str);  // str 과 같으면 compare 에서 0 을 리턴한다.
// }
// int main() {
//   MyString str1("a word");
//   MyString str2("sentence");
//   MyString str3("sentence");

//   if (str1 == str2)
//     std::cout << "str1 와 str2 같다." << std::endl;
//   else
//     std::cout << "st1 와 str2 는 다르다." << std::endl;

//   if (str2 == str3)
//     std::cout << "str2 와 str3 는 같다." << std::endl;
//   else
//     std::cout << "st2 와 str3 는 다르다" << std::endl;
// }
/*
	복소수 (Complex number)	클래스 만들기

	복소수는 허수와 실수를 모두 포함하는 수 체계로, 허수와 실수의 합으로 표현. 다시 말해서, 임의의 복소수 z는 다음과 같은 꼴
	z = a + bi (a, b는 모두 실수)

	int 형이라면 a + b / c + d; 와 같은 형식으로 작성 가능하나, 복소수 계산 시, 허수부와 실수부로 나눠 계산 해야하기 때문에,
	연산식이 복잡해진다. 다만 오버로딩을 통하면 기존 int 형 처럼 구현이 가능하다.
*/
// #include <iostream>

// class Complex {
// 	private:
// 		double real, img;

// 	public:
// 		Complex(double real, double img) : real(real), img(img) {}
// 		Complex(const Complex&c) { real = c.real, img = c.img; }

// 		Complex operator+(const Complex& c) const;
// 		Complex operator-(const Complex& c) const;
// 		Complex operator*(const Complex& c) const;
// 		Complex operator/(const Complex& c) const;

// 		void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
// };

// Complex Complex::operator+(const Complex& c) const {
// 	Complex temp(real + c.real, img + c.img);
// 	return temp;
// }

// Complex Complex::operator-(const Complex& c) const {
// 	Complex temp(real - c.real, img - c.img);
// 	return temp;
// }

// Complex Complex::operator*(const Complex& c) const {
// 	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
// 	return temp;
// }

// Complex Complex::operator/(const Complex& c) const {
// 	Complex temp(
// 		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
// 		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
// 	return temp;
// }

// int main() {
// 	Complex a(1.0, 2.0);
// 	Complex b(3.0, -2.0);
	
// 	Complex c = a * b;

// 	c.println();
// }

/*
	return 타입이 &복사 연산자가 아닌, 레퍼런스를 리턴한다.
	복사 생성자를 사용할 경우,
	Complex a = b + c + b;
	문자을 작성한 사람 입장에선 결과적으로 a = 2 * b + c; 를 의도하였겠지만,
	실제로 하다보면 (b + c)가 들어가 있기 때문에 원하는 대로 연산이 이뤄지지 않는다.

	인자의 값이 함수 내부에서 바뀌지 않는 다고 확신할 떄에는 const 키워드를 붙여줘야 한다.
	나중에 발생할 수 있는 실수들을 줄여주기 때문.

	상수 함수로 선언 할 수 있는 경우 상수 함수로 선언하는 것이 바람직하다.
*/

/*
	대입 연산자 함수
	대입 연산자 함수는, 기존의 사칙연산 연산자 함수, 자기 자신을 가리키는 레퍼런스 (Compelx&)을 리턴한다.
	왜 굳이 대입 연산자가 자기 자신을 리턴해야 되냐면,
	a = b = c;
	위와 같은 코드에서 b = c;가 b를 리턴해야 a = b;가 성공적으로 수행될 수 있기 때문이다.
	Complex 타입을 리턴하지 않고 굳이 Complex& 타입을 리턴하냐면, 대입 연산 이후에 불필요한 복사를 방지하기 위해서다.

	Complex& Complex::operator=(const Complex& c)
	{
		real = c.real;
		img = c.img;
		return *this;
	}
*/

// #include <iostream>

// class Complex {
//  private:
//   double real, img;

//  public:
//   Complex(double real, double img) : real(real), img(img) {}
//   Complex(const Complex& c) { real = c.real, img = c.img; }

//   Complex operator+(const Complex& c) const;
//   Complex operator-(const Complex& c) const;
//   Complex operator*(const Complex& c) const;
//   Complex operator/(const Complex& c) const;

//   Complex& operator=(const Complex& c);
//   void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
// };

// Complex Complex::operator+(const Complex& c) const {
//   Complex temp(real + c.real, img + c.img);
//   return temp;
// }
// Complex Complex::operator-(const Complex& c) const {
//   Complex temp(real - c.real, img - c.img);
//   return temp;
// }
// Complex Complex::operator*(const Complex& c) const {
//   Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//   return temp;
// }
// Complex Complex::operator/(const Complex& c) const {
//   Complex temp(
//     (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//     (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
//   return temp;
// }
// Complex& Complex::operator=(const Complex& c) {
//   real = c.real;
//   img = c.img;
//   return *this;
// }

// int main() {
//   Complex a(1.0, 2.0);
//   Complex b(3.0, -2.0);
//   Complex c(0.0, 0.0);
//   c = a * b + a / b + a + b;
//   c.println();
// }

/*
	operator = 를 만들지 않아도 잘 작동한다.
	이는 컴파일러 차원에서 디폴트 대입 연산자를 지원하기 때문인데, 이전에 복사 생성자를 다룰 때
	디폴트 복사 생성자가 있었던 것과 일맥 상통한다. -> 이거 질문해야지

	두 문장의 차이를 알고 있는가?
	Some_Class a = b; // 1 <- 복사 생성자 호출
	Some_Class a; // 2 <- a 의 그냥 기본 생정자가 호출 된 다음, 다음 문징에서 대입 연산자 함수가 실행.
	a = b;
*/

// #include <iostream>

// class Complex {
//  private:
//   double real, img;

//  public:
//   Complex(double real, double img) : real(real), img(img) {}
//   Complex(const Complex& c) { real = c.real, img = c.img; }

//   Complex operator+(const Complex& c) const;
//   Complex operator-(const Complex& c) const;
//   Complex operator*(const Complex& c) const;
//   Complex operator/(const Complex& c) const;

//   Complex& operator+=(const Complex& c);
//   Complex& operator-=(const Complex& c);
//   Complex& operator*=(const Complex& c);
//   Complex& operator/=(const Complex& c);

//   void println() {
//     std::cout << "( " << real << " , " << img << " ) " << std::endl;
//   }
// };

// Complex Complex::operator+(const Complex& c) const {
//   Complex temp(real + c.real, img + c.img);
//   return temp;
// }
// Complex Complex::operator-(const Complex& c) const {
//   Complex temp(real - c.real, img - c.img);
//   return temp;
// }
// Complex Complex::operator*(const Complex& c) const {
//   Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//   return temp;
// }
// Complex Complex::operator/(const Complex& c) const {
//   Complex temp(
//       (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//       (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
//   return temp;
// }

// Complex& Complex::operator+=(const Complex& c) {
// 	(*this) = (*this) + c;
// 	return *this;
// }

// Complex& Complex::operator-=(const Complex& c) {
// 	(*this) = (*this) - c;
// 	return *this;
// }

// Complex& Complex::operator*=(const Complex& c) {
// 	(*this) = (*this) * c;
// 	return *this;
// }

// Complex& Complex::operator/=(const Complex& c) {
// 	(*this) = (*this) / c;
// 	return *this;
// }

// int main() {
//   Complex a(1.0, 2.0);
//   Complex b(3.0, -2.0);
//   a += b;
//   a.println();
//   b.println();
// }

/*
	연산자 오버로딩을 하게 된다면 내가 생각하는 모든 연산자들에 대해 개별적인 정의가 필요하다.
*/

/*
	문자열로 `Complex` 수와 덧셈하기
	목표 : operator+ 를 개량해서, 꼭 Complex 수를 더하는 것이 아니라, 문자열로도 덧셈을 할 수 있도록 operator+
	함수를 만들 것.
	y = z + "3+i2"; 이런 문장을 사용했을 경우 성공적으로 처리해야한다.
	참고로, 문자열로 복소수를 어떻게 표현해야 할 지 대해서는 모종의 약속이 필요, 우리 Complex 클래스의 경우 다음과 같은 꼴로 표현
	(부호) (실수부) (부호)  i (허수부)

	만일 실수부나 허수부의 값이 0 이라면 굳이 안써줘도 된다.
	참고로 우리의 실수부와 허수부는 double 변수이기 때문에 문자열로 입력 받을 때 단순히 정수 부분만 받는 것이 아니라
	소수점 아래부분도 처리해줘야 한다.
*/

// #include <iostream>
// #include <cstring>

// class Complex {
// 	private:
// 		double real, img;

// 		double get_number(const char* std, int from, int to) const;

// 	public:
// 		Complex(double real, double img) : real(real), img(img) {}
// 		Complex(const Complex& c) { real = c.real, img = c.img; }

// 		Complex operator+(const Complex& c) const;
// 		Complex operator+(const char* str) const;

// 		Complex operator-(const Complex& c) const;
// 		Complex operator*(const Complex& c) const;
// 		Complex operator/(const Complex& c) const;

// 		Complex& operator+=(const Complex& c);
// 		Complex& operator-=(const Complex& c);
// 		Complex& operator*=(const Complex& c);
// 		Complex& operator/=(const Complex& c);

// 		Complex& operator=(const Complex& c);

// 		void println() { std::cout << "( " << real << ", " << img << " ) " << std::endl; } 
// };

// Complex Complex::operator+(const Complex& c) const {
// 	Complex temp(real + c.real, img + c.img);
// 	return temp;
// }
// double Complex::get_number(const char* str, int from, int to) const {
// 	bool minus = false;
// 	if (from > to) return 0;

// 	if (str[from] == '-') minus = true;
// 	if (str[from] == '-' || str[from] == '+') from++;

// 	double num = 0.0;
// 	double decimal = 1.0;

// 	bool integer_part = true;
// 	for (int i = from; i <= to; i++) {
// 		if (isdigit(str[i]) && integer_part) {
// 			num *= 10.0;
// 			num += (str[i] - '0');
// 		} else if (str[i] == '.')
// 			integer_part = false;
// 		else if (isdigit(str[i]) && !integer_part){
// 			decimal /= 10.0;
// 			num += ((str[i] - '0') * decimal);
// 		} else
// 			break; // 그 이외의 이상한 문자들이 올 경우
// 	}

// 	if (minus) num *= -1.0;

// 	return num;
// }

// Complex Complex::operator+(const char* str) const {
// 	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 	// 문자열의 꼴은 다음과 같다. "[부호](실수부)(부호)i(허수부)"
// 	// 이 때 맨 앞의 부호는 생략 가능. (생략 시 + 라 가정)

// 	int begin = 0, end = strlen(str);
// 	double str_img = 0.0, str_real = 0.0;

// 	// 먼저 가장 기준이 되는 'i'의 위치를 찾는다.
// 	int pos_i = -1;
// 	for (int i = 0; i != end; i++) {
// 		if (str[i] == 'i'){
// 			pos_i = i;
// 			break;
// 		}
// 	}

// 	// 만일 'i'가 없다면 이 수는 실수 뿐이다.
// 	if (pos_i == -1){
// 		str_real = get_number(str, begin, end - 1);

// 		Complex temp(str_real, str_img);
// 		return (*this) + temp;
// 	}

// 	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
// 	if (pos_i == -1) {
// 		str_real = get_number(str, begin, end - 1);

// 		Complex temp(str_real, str_img);
// 		return (*this) + temp;
// 	}

// 	// 만일 'i'가 있다면, 실수부와 허수부를 나누어서 처리하면 된다.
// 	str_real = get_number(str, begin, pos_i - 1);
// 	str_img = get_number(str, pos_i + 1, end - 1);

// 	if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

// 	Complex temp(str_real, str_img);
// 	return (*this) + temp;
// }

// Complex Complex::operator-(const Complex& c) const {
//   Complex temp(real - c.real, img - c.img);
//   return temp;
// }
// Complex Complex::operator*(const Complex& c) const {
//   Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//   return temp;
// }
// Complex Complex::operator/(const Complex& c) const {
//   Complex temp(
//     (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//     (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
//   return temp;
// }
// Complex& Complex::operator+=(const Complex& c) {
//   (*this) = (*this) + c;
//   return *this;
// }
// Complex& Complex::operator-=(const Complex& c) {
//   (*this) = (*this) - c;
//   return *this;
// }
// Complex& Complex::operator*=(const Complex& c) {
//   (*this) = (*this) * c;
//   return *this;
// }
// Complex& Complex::operator/=(const Complex& c) {
//   (*this) = (*this) / c;
//   return *this;
// }
// Complex& Complex::operator=(const Complex& c) {
//   real = c.real;
//   img = c.img;
//   return *this;
// }

// int main() {
//   Complex a(0, 0);
//   a = a + "-1.1 + i3.923";
//   a.println();
// }

/*
	각각의 코드를 반복적으로 쓰는 것은 매우 귀찮은 일.
	완전 불편한 작업을 막기 위해 아예 const char * 로 오버로딩되는 Complex 생성자를 추가하는 것도 나쁘지 않다.

	그렇게 되면 길고 복잡했던 operator+ (const char *) 부분을 다음과 같이 간단히 줄일 수 있다.
	Complex Complex::operator+(const char * str) const {
		Complex temp(str);
		return (*this) + temp;
	}

	간단히 Complex(const char *str) 을 만들어보면 다음과 같다.

	Complex::Complex(const char* str) {
		int begin = 0, end = strlen(str);
		img = 0.0;
		real = 0.0;

		int pos_i = -1;
		for (int i = 0; i != end; i++){
			if (str[i] == 'i'){
				pos_i = i;
				break;
			}
		}

		// 만일 'i'가 없다면 이 수는 실수 뿐이다.
		if (pos_i == -1) {
			real = get_number(str, begin, end -1);
			return;
		}

		// 만일 'i' 가 있다면, 실수부와 허수부를 나눠 처리하면 된다.
		real = get_number(str, begin, pos_i - 1);
		img = get_number(str, pos+i + 1, end - 1);

		if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
	}

	다음과 같이 Complex(const char* str) 을 만들면 아래와 같이 사용할 수 있다.
*/

// #include <cstring>
// #include <iostream>

// class Complex {
//  private:
//   double real, img;

//   double get_number(const char* str, int from, int to) const;

//  public:
//   Complex(double real, double img) : real(real), img(img) {}
//   Complex(const Complex& c) { real = c.real, img = c.img; }
//   Complex(const char* str);

//   Complex operator+(const Complex& c) const;
//   Complex operator-(const Complex& c) const;
//   Complex operator*(const Complex& c) const;
//   Complex operator/(const Complex& c) const;

//   Complex operator+(const char* str) const;
//   Complex operator-(const char* str) const;
//   Complex operator*(const char* str) const;
//   Complex operator/(const char* str) const;

//   Complex& operator+=(const Complex& c);
//   Complex& operator-=(const Complex& c);
//   Complex& operator*=(const Complex& c);
//   Complex& operator/=(const Complex& c);

//   Complex& operator=(const Complex& c);

//   void println() {
//     std::cout << "( " << real << " , " << img << " ) " << std::endl;
//   }
// };
// Complex::Complex(const char* str) {
//   // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
//   // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
//   // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

//   int begin = 0, end = strlen(str);
//   img = 0.0;
//   real = 0.0;

//   // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
//   int pos_i = -1;
//   for (int i = 0; i != end; i++) {
//     if (str[i] == 'i') {
//       pos_i = i;
//       break;
//     }
//   }

//   // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
//   if (pos_i == -1) {
//     real = get_number(str, begin, end - 1);
//     return;
//   }

//   // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
//   real = get_number(str, begin, pos_i - 1);
//   img = get_number(str, pos_i + 1, end - 1);

//   if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
// }
// double Complex::get_number(const char* str, int from, int to) const {
//   bool minus = false;
//   if (from > to) return 0;

//   if (str[from] == '-') minus = true;
//   if (str[from] == '-' || str[from] == '+') from++;

//   double num = 0.0;
//   double decimal = 1.0;

//   bool integer_part = true;
//   for (int i = from; i <= to; i++) {
//     if (isdigit(str[i]) && integer_part) {
//       num *= 10.0;
//       num += (str[i] - '0');
//     } else if (str[i] == '.')
//       integer_part = false;
//     else if (isdigit(str[i]) && !integer_part) {
//       decimal /= 10.0;
//       num += ((str[i] - '0') * decimal);
//     } else
//       break;  // 그 이외의 이상한 문자들이 올 경우
//   }

//   if (minus) num *= -1.0;

//   return num;
// }
// Complex Complex::operator+(const Complex& c) const {
//   Complex temp(real + c.real, img + c.img);
//   return temp;
// }
// Complex Complex::operator-(const Complex& c) const {
//   Complex temp(real - c.real, img - c.img);
//   return temp;
// }
// Complex Complex::operator*(const Complex& c) const {
//   Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//   return temp;
// }
// Complex Complex::operator/(const Complex& c) const {
//   Complex temp(
//       (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//       (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
//   return temp;
// }
// Complex Complex::operator+(const char* str) const {
//   Complex temp(str);
//   return (*this) + temp;
// }
// Complex Complex::operator-(const char* str) const {
//   Complex temp(str);
//   return (*this) - temp;
// }
// Complex Complex::operator*(const char* str) const {
//   Complex temp(str);
//   return (*this) * temp;
// }
// Complex Complex::operator/(const char* str) const {
//   Complex temp(str);
//   return (*this) / temp;
// }
// Complex& Complex::operator+=(const Complex& c) {
//   (*this) = (*this) + c;
//   return *this;
// }
// Complex& Complex::operator-=(const Complex& c) {
//   (*this) = (*this) - c;
//   return *this;
// }
// Complex& Complex::operator*=(const Complex& c) {
//   (*this) = (*this) * c;
//   return *this;
// }
// Complex& Complex::operator/=(const Complex& c) {
//   (*this) = (*this) / c;
//   return *this;
// }
// Complex& Complex::operator=(const Complex& c) {
//   real = c.real;
//   img = c.img;
//   return *this;
// }

// int main() {
//   Complex a(0, 0);
//   a = a + "-1.1 + i3.923";
//   a.println();
//   a = a - "1.2 -i1.823";
//   a.println();
//   a = a * "2.3+i22";
//   a.println();
//   a = a / "-12+i55";
//   a.println();
// }
/* Complex(const char *str) 생성자만 남기고, operator+(const char *str) 계열들을 모두 지워보고 컴파일 */

// #include <iostream>
// #include <cstring>

// class Complex {
//  private:
//   double real, img;

//   double get_number(const char* str, int from, int to) const;

//  public:
//   Complex(double real, double img) : real(real), img(img) {}
//   Complex(const Complex& c) { real = c.real, img = c.img; }
//   Complex(const char* str);

//   Complex operator+(const Complex& c) const;
//   Complex operator-(const Complex& c) const;
//   Complex operator*(const Complex& c) const;
//   Complex operator/(const Complex& c) const;

//   Complex& operator+=(const Complex& c);
//   Complex& operator-=(const Complex& c);
//   Complex& operator*=(const Complex& c);
//   Complex& operator/=(const Complex& c);

//   Complex& operator=(const Complex& c);

//   void println() {
//     std::cout << "( " << real << " , " << img << " ) " << std::endl;
//   }
// };
// Complex::Complex(const char* str) {
//   // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
//   // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
//   // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

//   int begin = 0, end = strlen(str);
//   img = 0.0;
//   real = 0.0;

//   // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
//   int pos_i = -1;
//   for (int i = 0; i != end; i++) {
//     if (str[i] == 'i') {
//       pos_i = i;
//       break;
//     }
//   }

//   // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
//   if (pos_i == -1) {
//     real = get_number(str, begin, end - 1);
//     return;
//   }

//   // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
//   real = get_number(str, begin, pos_i - 1);
//   img = get_number(str, pos_i + 1, end - 1);

//   if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
// }
// double Complex::get_number(const char* str, int from, int to) const {
//   bool minus = false;
//   if (from > to) return 0;

//   if (str[from] == '-') minus = true;
//   if (str[from] == '-' || str[from] == '+') from++;

//   double num = 0.0;
//   double decimal = 1.0;

//   bool integer_part = true;
//   for (int i = from; i <= to; i++) {
//     if (isdigit(str[i]) && integer_part) {
//       num *= 10.0;
//       num += (str[i] - '0');
//     } else if (str[i] == '.')
//       integer_part = false;
//     else if (isdigit(str[i]) && !integer_part) {
//       decimal /= 10.0;
//       num += ((str[i] - '0') * decimal);
//     } else
//       break;  // 그 이외의 이상한 문자들이 올 경우
//   }

//   if (minus) num *= -1.0;

//   return num;
// }
// Complex Complex::operator+(const Complex& c) const {
//   Complex temp(real + c.real, img + c.img);
//   return temp;
// }
// Complex Complex::operator-(const Complex& c) const {
//   Complex temp(real - c.real, img - c.img);
//   return temp;
// }
// Complex Complex::operator*(const Complex& c) const {
//   Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
//   return temp;
// }
// Complex Complex::operator/(const Complex& c) const {
//   Complex temp(
//       (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
//       (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
//   return temp;
// }

// Complex& Complex::operator+=(const Complex& c) {
//   (*this) = (*this) + c;
//   return *this;
// }
// Complex& Complex::operator-=(const Complex& c) {
//   (*this) = (*this) - c;
//   return *this;
// }
// Complex& Complex::operator*=(const Complex& c) {
//   (*this) = (*this) * c;
//   return *this;
// }
// Complex& Complex::operator/=(const Complex& c) {
//   (*this) = (*this) / c;
//   return *this;
// }
// Complex& Complex::operator=(const Complex& c) {
//   real = c.real;
//   img = c.img;
//   return *this;
// }

// int main() {
//   Complex a(0, 0);
//   a = a + "-1.1 + i3.923";
//   a.println();
//   a = a - "1.2 -i1.823";
//   a.println();
//   a = a * "2.3+i22";
//   a.println();
//   a = a / "-12+i55";
//   a.println();
// }

/* 
	컴파일러가 똑똑해서 가능하다..
	a = a = "-1.1 +i3.932";
	-> a = a.operator+("-1.1 + i3.923"); 으로 바꿔준다.
	operator+(const char *str) 이 없고, operator+(const Complex& c) 밖에 없기 때문에
	직접적으로 오버로딩 되지 않는다. 그러나, 컴파일러는 매우 똑똑하여
	그 다음 순위로 오버로딩 될 수 있는 함수들이 있는지 없는 지 확인한다.
	const char * -> Complex를 생성할 수 있는 생성자
	Complex(const char* str); 이 있기 때문에
	컴파일러는 문자열 리터러로 부터 const Complex 타입의 객체를 새롭게 생성할 수 있게 된다.

	=> a = a.operator+(Complex("-1.1 + i3.923"));
	Complex& c로 받도록했다면, 위와 같은 변환은 이뤄지지 않는다.
	왜냐면 -1.1 + i3.923 자체가 문자열 리터럴 이므로, 이를 바탕으로 생성된 객체 역시 상수 여야 한다.
	여러 모로 함수 인자의 값을 변형하지 않는다고 확신이 들면 무조건 const 인자로 받도록 하자.
*/

/*
	friend 키워드
	클래스 내부에서 다른 클래스나 함수들을 friend로 정의할 수 있는데, friend 로 정의된 클래스나 함수들은
	원래 클래스의 private 로 정의된 변수나 함수들에 접근할 수 있다.

	friend class B;

	friend void func();
	친구라고 선언하게 되면, B와 func안에서는 A의 모든 private 멤버 함수들과 멤버 변수들에 대한 접근 권한을 부여하게 된다.

	그러나 관계는 "짝사랑과 같다." 즉 위 경우  B 는 A 의 모든 private들을 볼 수 있지만, B 안에서 A를 friend로 
	지정하지 않는 이상, A는 B의 private	개체들에 접근할 수 없다.
	class A {
		private:
			int x;

			friend class B;
	};

	class B {
		private:
			int y;
	};

	B 에는 A가 friend 라고 지정하지 않았으므로, A는 B의 private	변수인 int y에 접근할 수 없게 된다.
*/

// class A {
// 	private:
// 		void private_func() {}
// 		int private_num;

// 		// B 는  A 의 친구!
// 		friend class B;

// 		// func 은 A의 친구!
// 		friend void func();
// };

// class B {
// 	public:
// 		void b() {
// 			A a;

// 			// 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
// 			a.private_func();
// 			a.private_num = 2;
// 		}
// };

// void func() {
// 	A a;

// 	// 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근 가능
// 	a.private_func();
// 	a.private_num = 2;
// }

/*
	이항 연산자
	1. a = a + "-1.1 + i3.932"; -> 컴파일 실행
	2. a = "-1.1 + i3.932" + a; -> 컴파일이 되지않는다.

	1의 경우, a.operator+("i3.923"); 으로 변환될 수 있지만
	2는 그러하지 못한다.
	원칙적으로 클래스를 사용하는 사용자의 입장에서 1이 된다면 당연히 2도 수행될 수 있어야 연산자 오버로딩을 하는 명분이 생긴다.

	컴파일러는 이항 연산자를 다음과 같은 두개의 방식으로 해석한다.
	어떤 임의의 연산자 @에 대해서, a@b 는
	*a.operator@(b);
	*operator@(a,b);
	컴파일러는 둘 중 가능한 녀석을 택해서 처리. a.operator@(b) 에서의 operator@ 는 a 의 클래스의 멤버 함수로써 사용,
	*operator@(a,b) 에서의 operator@ 는 클래스 외부에 정의되어 있는 일반적인 함수를 의미.

	참고로 이는 일부 연산자들에 대해서는 해당되지 않는데, [] 연산자 (첨자), -> 연산자(멤버 접근), 대입 연산자(=),
	() 함수 호출 연산자들의 경우 멤버 함수로만 존재할 수 있습니다. 즉, 따로 멤버 함수가 아닌 전역 함수로 뺼 수 없다는 의미.
	따라서 이들 함수를 오버로딩 할 때 주의

	Complex operator+(const Complex& a, const Complex& b) {
		// ...
	}

	우리의 또 다른 operator+ 는 두 개의 const Complex& 타입의 인자 a,b 를 받게 된다.
	앞에서도 말했지만 컴파일러는 정확히 일치 하지 않는 경우, 가장 가까운 가능한 오버로딩 되는 함수를 찾게 되는데,
	우리에게 Complex(const char *) 타입의 생성자가 있으므로,
	"-1.1 + i3.923" + a; => operator+(Complex("-1.1 + i3.923"), a);
	가 되어서 잘 실행되게 된다. 그런데 문제는
	Complex operator+(const Complex& a, const Complex& b)가 제대로 작동하기 위해선
	이 함수가 a와 b 의 real 과 img 에 접근해야 하는 데, 해당 멤버 변수들은 모두 private다.

	해결 방법 =>Complex operator+(const Complex& a, const Complex& b) 함수를 Complex의 friend로 지정하면 된다.
	
int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;

  a = a + a;
  a.println();
}

컴파일 오류

test.cc: In function ‘int main()’:
test.cc:106:11: warning: ISO C++ says that these are ambiguous, even though the worst conversion for the first is better than the worst conversion for the second:
  106 |   a = a + a;
      |           ^
test.cc:27:9: note: candidate 1: ‘Complex operator+(const Complex&, const Complex&)’
   27 | Complex operator+(const Complex& a, const Complex& b) {
      |         ^~~~~~~~
test.cc:91:9: note: candidate 2: ‘Complex Complex::operator+(const Complex&) const’
   91 | Complex Complex::operator+(const Complex& c) const {
      |     
흠, 앞서 컴파일러는 a + a를 해석할 때

a.operator+(a);
operator+(a, a);
위 두 가지 형태 중에서 하나를 고른다고 하였습니다. 그런데 위 경우 위 두 가지 형태가 모두 가능하기 때문에 어떤 녀석을 골라야 할지 모르겠어! 라면서 불평하는 내용입니다. 따라서 이를 해결 하기 위해서는 두 함수 중 하나를 없애야겠지요.

통상적으로 자기 자신을 리턴하지 않는 이항 연산자들, 예를 들어 위와 같은 +, -, *, / 들은 모두 외부 함수로 선언하는 것이 원칙 입니다. 반대로 자기 자신을 리턴하는 이항 연산자들, 예를 들어 +=, -= 같은 애들은 모두 멤버 함수로 선언하는 것이 원칙 입니다.

주의 사항
자기 자신을 리턴하는 이항 연산자는 멤버 함수로, 아닌 애들은 외부 함수로 정의한다!
*/

// #include <cstring>
// #include <iostream>

// class Complex {
//  private:
//   double real, img;

//   double get_number(const char* str, int from, int to) const;

//  public:
//   Complex(double real, double img) : real(real), img(img) {}
//   Complex(const Complex& c) { real = c.real, img = c.img; }
//   Complex(const char* str);

//   Complex& operator=(const Complex& c);

//   // 나머지 연산자 함수들은 생략 :)

//   void println() {
//     std::cout << "( " << real << " , " << img << " ) " << std::endl;
//   }

//   friend Complex operator+(const Complex& a, const Complex& b);
// };

// Complex operator+(const Complex& a, const Complex& b) {
//   Complex temp(a.real + b.real, a.img + b.img);
//   return temp;
// }

// Complex::Complex(const char* str) {
//   // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
//   // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
//   // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

//   int begin = 0, end = strlen(str);
//   img = 0.0;
//   real = 0.0;

//   // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
//   int pos_i = -1;
//   for (int i = 0; i != end; i++) {
//     if (str[i] == 'i') {
//       pos_i = i;
//       break;
//     }
//   }

//   // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
//   if (pos_i == -1) {
//     real = get_number(str, begin, end - 1);
//     return;
//   }

//   // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
//   real = get_number(str, begin, pos_i - 1);
//   img = get_number(str, pos_i + 1, end - 1);

//   if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
// }
// double Complex::get_number(const char* str, int from, int to) const {
//   bool minus = false;
//   if (from > to) return 0;

//   if (str[from] == '-') minus = true;
//   if (str[from] == '-' || str[from] == '+') from++;

//   double num = 0.0;
//   double decimal = 1.0;

//   bool integer_part = true;
//   for (int i = from; i <= to; i++) {
//     if (isdigit(str[i]) && integer_part) {
//       num *= 10.0;
//       num += (str[i] - '0');
//     } else if (str[i] == '.')
//       integer_part = false;
//     else if (isdigit(str[i]) && !integer_part) {
//       decimal /= 10.0;
//       num += ((str[i] - '0') * decimal);
//     } else
//       break;  // 그 이외의 이상한 문자들이 올 경우
//   }

//   if (minus) num *= -1.0;

//   return num;
// }

// Complex& Complex::operator=(const Complex& c) {
//   real = c.real;
//   img = c.img;
//   return *this;
// }

// int main() {
//   Complex a(0, 0);
//   a = "-1.1 + i3.923" + a;
//   a = a + a;

//   Complex b(1, 2);
//   b = a + b;

//   b.println();
// }


/*
	입출력 연산자 오버로딩 하기
	std::cout << a; == std::cout.operator<<(a) 를 하는 것과 동일한 명령
	std::cout이라는 객체에 멤버 함수 operator << 가 정의되어 있어, a를 호출하게 되는 것
	std::cout 이 int 나 double 변수, 심지어 문자열까지 자유 자재로 operator<< 하나로 가능했던 이유?
	-> operator << 함수들이 오버로딩 되어 있다는 뜻.

	클래스의 연산자 함수를 추가하는 방법, 멤버 함수를 사용하는 것 말고도 한가지 더있음.
	ostream 클래스 객체와 Complex 객체 두 개를 인자로 받는 전역 operator << 함수를 정의

	std::ostream& operator<<(std::ostream& os, const Complex& c) {
		os << "( " << c.real << " , " << c.img << " ) ";
		return os;
	}

	참고로 operator << 에서 ostream& 타입을 리턴하는 이유는 다음과 같은 문장을 처리할 수 있기 위해서
	std::cout << "a 의 값은 : " << a << "이다. " << std::endl;

	friend 키워드를 남발하는 것은 썩 권장하지 않는다.
	그 이유는 해당 함수나 클래스에게 자기 자신의 모든 private 멤버 함수와 변수들을 공개하기 때문.
	따라서 구현 디테일은 최대한 숨기라! 는 원칙을 지키키 힘들어진다.
*/

/*
	int Wrapper 클래스 - 타입 변환 연산자
	Wrapper 기본 자료형들(int, float ···)을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것

	int 자료형을 감싸는 int Wrapper 클래스 Int 는 다음과 같이 구성
	class Int
	{
		int data;
		// some other data

		public:
			Int(int data) : data(data) {}
			Int(const Int& i) : data(i.data) {}
	};

	Int 클래스에 int 형 자료형을 보관하는 data 라는 변수를 정의
	int 형 데이터를 저장하는 객체로 Int 클래스르 사용할 수 있다.

	타입 변환 연산자는 다음과 같이 정의
	operator (변환 하고자 하는 타입) ()

	int Wrapper 클래스의 경우 다음과 같은 타입 변환 연산자 정의
	operator int()
	한 가지 주의할 점, 생성자 처럼 함수의 리턴 타입을 써주면 안된다.
	C++에서 변환 연산자를 정의하기 위한 언어 상의 규칙
	operator int () { return data; }
	단순히 data를 리턴해주면 된다.
	그렇게되면 Wrapper 클래스의 객체를 '읽는' 데에는 아무런 문제가 없게 된다.
	-> 컴파일러 입장에서 적절한 변환 연산자로 operator int 를 찾아 결국 int 로 변환해서 처리

	다만 문제는 '대입' 시에 발생, 다행이도 디폴트 대입 연산자가 이 역시 알아서 잘 처리
*/

/*
	전위/후위 증감 연산자
	a++;
	++a;
	두 연산자 모두 operator++다.
	operator++();
	operator--();
	전위 증감 연산자(++x, --x)를 오버로딩
	operator++(int x), operator--(int x) == operator(int), operator++(int), operator--(int)

	전위 연산자의 경우 ++ 에 해당하는 연산을 수행한 후에 자기 자신을 반환
	A& operator++ () {
		// A++ 을 수행한다.
		return *this;
	}
	반면 후위 연산자의 경우 ++ 하기 전에 객체를 반환, temp 객체를 만들어서 이전 상태를 기록한 후, ++을 수행한 뒤에 temp
	객체를 반환
	A operator++(int) {
		A temp(A);
		// A++ 을 수행한다.
		return temp;
	}

	따라서 후위 증감 연산의 경우 추가적으로 복사 생성자를 호출하기 때문에 전위 증감 연산보다 더 느리다.
*/

// #include <iostream>


// class Test {
//   int x;

//  public:
//   Test(int x) : x(x) {}
//   Test(const Test& t) : x(t.x) {}

//   Test& operator++() {
//     x++;
//     std::cout << "전위 증감 연산자" << std::endl;
//     return *this;
//   }

//   // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
//   // 받지만 실제로는 아무것도 전달되지 않는다.
//   Test operator++(int) {
//     Test temp(*this);
//     x++;
//     std::cout << "후위 증감 연산자" << std::endl;
//     return temp;
//   }

//   int get_x() const {
//     return x;
//   }
// };

// void func(const Test& t) {
//   std::cout << "x : " << t.get_x() << std::endl;
// }

// int main() {
//   Test t(3);

//   func(++t); // 4
//   func(t++); // 4 가 출력됨
//   std::cout << "x : " << t.get_x() << std::endl;
// }

/*
	C++ 스타일의 캐스팅
	C 언어 캐스팅 크게 2가지 방법
	1. 컴파일러가 알아서 캐스팅 하는 암시적(implicit) 캐스팅
	2. 직접 캐스팅 지정하는 명시적(explicit) 캐스팅

	암시적 캐스팅의 경우 int 와 double 변수와의 덧셈을 수행할 때, int 형 변수가 자동으로
	double 변수로 캐스팅 되는 것과 같은 것.

	명시적 캐스팅의 경우 void * 타입의 주소를 특정 구조체 포인터 타입의 주소로 바꾼다넌지 등의 캐스팅

	명시적 캐스팅 예)
	ptr = (Something *)other_ptr;
	int_variable = (int)float_variable;

	괄호 안에 원하는 타입을 넣고 변환을 수행
	1. 타입 캐스팅의 경우 말도 안되는 캐스팅에 대해서 컴파일러가 오류 발생시키지 않는다. => 프로그래머의 실수에 취약
	2. 괄호 안에 타입을 넣는 방식으로 변환을 수행, 코드의 가독성이 떨어지게 된다.
	즉, function((int)variable);
	와 같이 함수 호출에도 괄호를 사용, 괄호가 많아지면 코드를 읽는 사람과 유지보수하는 사람 입장에서 여러모로 불편

	C++ 에서는 다음과 같은 4가지의 캐스팅을 제공
	1. static_cast : 우리가 흔히 생각하는, 언어적 차원에서 지원하는 일반적인 타입 변환
	2. const_cast : 객체의 상수성(const)를 없애는 타입 변환. 쉽게 말해 const int 가 int로 바뀐다.
	3. dynamin_cast : 파생 클래스 사이에서의 다운 캐스팅
	4. reinterpret_cast : 위험을 감수하고 하는 캐스팅으로 서로 관련이 없는 포인터들 사이의 캐스팅 등

	ex)
	static_cast 로 float 타입의 float_variable 이라는 변수를 int 타입의 변수로 타입 변환.
	static_cast<int>(float_variable); => C (int)(float_variable);
*/

/*
	N 차원 배열 만들기
	N 차원 배열을 구현하는 방법 크게 두 가지 방법
	1. 일차원 배열을 할당한 뒤에 접근할 때 정확한 위치를 찾아주는 방법
	이러한 방식으로 구현, 메모리도 정확히 필요한 만큼만 사용할 수 있기에 좋은 방법

	N 차원 배열을 구현하는 프로젝트에서 사용할 아이디어는, 이전에 2차원 배열의 동적할당을 수행하면서 얻은
	아이디어와 유사.

	2차원 배열로 하면 문어발형식, 단 포인터 자체가 잡아먹는 크기 떄문에 x1 * x2 + x1 + 1 만큼의 메모리를 잡아 먹게 된다.
	메모리가 허용하는 한 크기가 매우매우 큰 배열도 생성할 수 있다.
	일차원 배열의 경우 전체 배열 원소 수가 int 크기를 넘어가게 된다면, 따로 큰 수의 정수를 다룰 수 있는 라이브러리를 사용,
	메모리를 동적 할당해주어야한다.
*/