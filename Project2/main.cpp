// 2018112028 ������
#include <iostream>
#include <string>

using namespace std;

class Buffer
{
private:
	string str;

public:
	Buffer(string sStr);
	void addStr(string aStr); // ���ڿ� +
	void print(); // ��ü�� str�� ���
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

	temp.print(); // ���
	buf.print(); // ���
}