// 2018112028 ������
#include <iostream>

using namespace std;

void swapByAdress(int* a, int* b, int* c)
{
	int *tmp = a;
	a = b;
	b = c;
	c = tmp;
}

void swapByReference(int& a, int& b, int& c)
{
	int &tmp = a;
	a = b;
	b = c;
	c = tmp;
}

int main()
{
	int x = 1;
	int y = 10;
	int z = 100;

	cout << "������ : " << x << ", " << y << ", " << z << endl << endl; // ���� �� ���
	
	cout << "�ּ��� ���� �μ� ����" << endl;
	swapByAdress(&x, &y, &z); // �ּ� ���� ���ڷ� �־���
	cout << "������ : " << x << ", " << y << ", " << z << endl; // ���

	// �ٽ� ���� ������ �ʱ�ȭ
	x = 1;
	y = 10;
	z = 100;

	cout << "������ ���� �μ� ����" << endl;
	swapByReference(x, y, z);
	cout << "������ : " << x << ", " << y << ", " << z << endl; // ���
	
	return 0;
}