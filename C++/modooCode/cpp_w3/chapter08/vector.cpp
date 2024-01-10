/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:23:38 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/01 23:44:17 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	벡터 클래스 (Vector)
	문자열 보관하기 위한 벡터
*/
#include <iostream>

class Vector
{
private:
	/* data */
	string *data;
	int capacity; //  현재 할당되어 있는 크기
	int length;	  //	실제로 사용하는 양

public:
	// 생성자
	Vector(int n = 1); // n = 1의 경우 사용자가 지정하지 않을 경우, 자동으로 n = 1로 지정

	// 맨 뒤에 새로운 원소를 추가한다.
	void push_back(string s);

	// 임의의 위치의 원소에 접근한다.
	string operator[](int i);

	// x 번째 위치한 원소를 제거한다.
	void remove(int x);

	// 현재 벡터의 크기를 구한다.
	int size();

	~Vector();
};

/*
	클래스 내부 함수 선언에서 디폴트 인자를 명시했다면, 함수 본체에서 명시하면 안된다.
	함수 본체에서 명시했다면, 클래스 내부 함수 선언에 명시하면 안된다. 둘 중 한 곳에서만 표시.
	즉, 둘 중 한 곳에서만 표시해야한다.
*/

Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void Veector::push_bakc(string s)
{
	if (capacity <= length)
	{
		string *temp = new string[capacity * 2];
		for (int i = 0; i < length; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		capacity *= 2;
	}

	data[length] = s;
	length++;
}

string Vector::operator[](int i) { return data[i]; }

void Vector::remove(int x)
{
	for (int i = x + 1; i < length; i++)
		data[i - 1] = data[i];
	length--;
}

int Vector::size() { return length; }

Vector::~Vector()
{
	if (data)
	{
		delete[] data;
	}
}

void Vector::push_back(string s)
{
	if (capacity <= length)
	{
		string *temp = new string[capcity * 2];
		for (int i = 0; i < length; i++)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		capacity *= 2;
	}

	data[length] = s;
	length++;
}