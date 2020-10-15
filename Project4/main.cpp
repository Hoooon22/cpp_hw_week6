// 2018112028 김지훈
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

	cout << "변경전 : " << x << ", " << y << ", " << z << endl << endl; // 변경 전 출력
	
	cout << "주소의 의한 인수 전달" << endl;
	swapByAdress(&x, &y, &z); // 주소 값을 인자로 넣어줌
	cout << "변경후 : " << x << ", " << y << ", " << z << endl; // 출력

	// 다시 원래 값으로 초기화
	x = 1;
	y = 10;
	z = 100;

	cout << "참조에 의한 인수 전달" << endl;
	swapByReference(x, y, z);
	cout << "변경후 : " << x << ", " << y << ", " << z << endl; // 출력
	
	return 0;
}