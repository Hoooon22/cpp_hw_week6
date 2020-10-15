// 2018112028 ������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Cal
{
private:
	string stringNum; // ���� �Է�
	string operate_c; // ������ �Է�
	int op[4];
	int* num; // �Է��� ���� �迭
	int size; // size
	int plus, minus, div, mul; // +-/* ����
	int min, max; // result

public:
	Cal(string getnum)
	{
		this->stringNum = getnum;
	}

	void set();
	void setNum(); // num�迭�� ���� �־��ֱ�
	void setOp(); // ������ ���ڿ��� ���� ������ ����
	void getMin_Max(int start, int end, int num); // ����Լ� �ۼ�
	void result();

	// �̹��� �߰��� �޼ҵ�
	int getSize(); // size ��������
	void setStringNum(string tmp); // tmp���� �ٲ۴�.
	int* getNum(); // num ��������
	void changeNum(); // num �ٲٱ�

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

	for (int i = 0; str_buff[i] != NULL; i++) // size ���
	{
		if (str_buff[i] == ' ')
		{
			this->size++;
		}
	}

	// tok���� ©�� num�� �ֱ�
	int str_cnt = 0;
	this->num = new int[this->size];

	char *tok = strtok(str_buff, " ");
	while (tok != nullptr)
	{
		num[str_cnt++] = atoi(tok);
		tok = strtok(nullptr, " ");
	}
}

void Cal::setOp() // ������ ���ڿ��� ���� ������ ����
{
	this->plus, this->minus, this->mul, this->div = 0;
	char *str_arr[1000];
	int str_cnt = 0;

	cout << this->size - 1 << "���� �����ڸ� �Է��Ͻÿ�:" << endl;
	getline(cin, this->operate_c);
	char *str_buff = new char[1000];
	strcpy(str_buff, operate_c.c_str());


	for (int i = 0; str_buff[i] != NULL; i++) // ������ ���� ++
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
	cout << "���ڸ� �Է��Ͻÿ�: ";
	getline(cin, getnum);
	Cal a(getnum);
	a.set();
	a.result();
}