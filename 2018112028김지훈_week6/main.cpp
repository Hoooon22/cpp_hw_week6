// 2018112028 김지훈
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Cal
{
private:
	string stringNum; // 숫자 입력
	string operate_c; // 연산자 입력
	int op[4];
	int* num; // 입력한 숫자 배열
	int size; // size
	int plus, minus, div, mul; // +-/* 개수
	int min, max; // result

public:
	Cal(string getnum)
	{
		this->stringNum = getnum;
	}

	void set();
	void setNum(); // num배열에 숫자 넣어주기
	void setOp(); // 연산자 문자열을 세어 변수에 저장
	void getMin_Max(int start, int end, int num); // 재귀함수 작성
	void result();

	// 이번에 추가한 메소드
	int getSize(); // size 가져오기
	void setStringNum(string tmp); // tmp으로 바꾼다.
	int* getNum(); // num 가져오기
	void changeNum(); // num 바꾸기

};

void Cal::set()
{
	this->setNum();
	this->setOp();
	this->getMin_Max(0, size - 1, this->num[0]);
}

void Cal::setNum()
{
	char *str_buff = new char[1000];
	strcpy(str_buff, this->stringNum.c_str());
	this->size = 1;

	for (int i = 0; str_buff[i] != NULL; i++) // size 계산
	{
		if (str_buff[i] == ' ')
		{
			this->size++;
		}
	}

	// tok으로 짤라 num에 넣기
	int str_cnt = 0;
	this->num = new int[this->size];

	char *tok = strtok(str_buff, " ");
	while (tok != nullptr)
	{
		num[str_cnt++] = atoi(tok);
		tok = strtok(nullptr, " ");
	}
}

void Cal::setOp() // 연산자 문자열을 세어 변수에 저장
{
	this->plus, this->minus, this->mul, this->div = 0;
	char *str_arr[1000];
	int str_cnt = 0;

	cout << this->size - 1 << "개의 연산자를 입력하시오:" << endl;
	getline(cin, this->operate_c);
	char *str_buff = new char[1000];
	strcpy(str_buff, operate_c.c_str());


	for (int i = 0; str_buff[i] != NULL; i++) // 연산자 변수 ++
	{
		if (str_buff[i] == '+')
		{
			this->plus++;
		}
		else if (str_buff[i] == '-')
		{
			this->minus++;
		}
		else if (str_buff[i] == '*')
		{
			this->mul++;
		}
		else if (str_buff[i] == '/')
		{
			this->div++;
		}
	}

	this->op[0] = this->plus;
	this->op[1] = this->minus;
	this->op[2] = this->mul;
	this->op[3] = this->div;
}

void Cal::getMin_Max(int start, int end, int num)
{
	if (start == end)
	{
		if (num > this->max) this->max = num;
		if (num < this->min) this->min = num;
		return;
	}
	if (this->op[0] > 0) // plus
	{
		this->op[0]--;
		getMin_Max(start + 1, end, num + this->num[start + 1]);
		this->op[0]++;
	}
	if (this->op[1] > 0) // minus
	{
		this->op[1]--;
		getMin_Max(start + 1, end, num - this->num[start + 1]);
		this->op[1]++;
	}
	if (this->op[2] > 0) // mul
	{
		this->op[2]--;
		getMin_Max(start + 1, end, num * this->num[start + 1]);
		this->op[2]++;
	}
	if (this->op[3] > 0) // div
	{
		this->op[3]--;
		getMin_Max(start + 1, end, num / this->num[start + 1]);
		this->op[3]++;
	}
}

void Cal::result()
{
	cout << "max : " << this->max << ", min : " << this->min << endl;
}

int Cal::getSize()
{
	return this->size;
}
void Cal::setStringNum(string tmp)
{
	this->stringNum = tmp;
}
int* Cal::getNum()
{
	return this->num;
}
void Cal::changeNum()
{
	/////////////////
}

void change(Cal A, Cal B)
{
	if (A.getSize() == B.getSize())
	{
		A.setStringNum(B.getNum());
	}
}

int main()
{
	string getnum;
	cout << "숫자를 입력하시오: ";
	getline(cin, getnum);
	Cal a(getnum);
	a.set();
	a.result();
}