// 2018112028 김지훈
#include <iostream>
#include <string>

using namespace std;

class Buffer
{
private:
	string str;

public:
	Buffer(string sStr);
	void addStr(string aStr); // 문자열 +
	void print(); // 객체의 str을 출력
};

Buffer::Buffer(string sStr)
{
	this->str = sStr;
}

void Buffer::addStr(string aStr)
{
	this->str += aStr;
}

void Buffer::print()
{
	cout << this->str << endl;
}

Buffer& append(Buffer& buf, string aStr)
{
	buf.addStr(aStr);
	return buf;
}	

int main()
{
	Buffer buf("Hello");
	Buffer &temp = append(buf, "Guys");

	temp.print(); // 출력
	buf.print(); // 출력
}