// 2018112028 ������
#include <iostream>

using namespace std;

class Bank
{
private:
	int balance; // �ܰ�
public:
	Bank(int money); // ������
	void setBalance(int money); // �ܰ� ����
	void getInfo(); // ���� ���� ��������
};

class Customer
{
private:
	int cash; // ���� ����
public:
	Customer(int money); // ������
	void getInfo(); // ���� ���� ��������
	void withDraw(Bank& bank, int money); // ���
	void deposit(Bank& bank, int money); // �Ա�
};

Bank::Bank(int money)
{
	this->balance = money;
}

Customer::Customer(int money)
{
	this->cash = money;
}

void Bank::setBalance(int money)
{
	this->balance += money;
}

void Bank::getInfo()
{
	cout << "�����ܰ�: " << this->balance << endl;
}

void Customer::getInfo()
{
	cout << "��������: " << this->cash << endl << endl;
}

void Customer::withDraw(Bank& bank, int money)
{
	this->cash += money;
	bank.setBalance(-money); // �ش� �Ű������� +���ֱ� ������ -�� �ٿ��ش�.
	cout << "���->" << money << endl;
}

void Customer::deposit(Bank& bank, int money)
{
	this->cash -= money;
	bank.setBalance(money);
	cout << "�Ա�->" << money << endl;
}

int main()
{
	Bank bank(2000); // �ܰ� 2000��
	Customer customer(1000); // �������� 1000��
	customer.getInfo();
	customer.withDraw(bank, 500);
	bank.getInfo();
	customer.getInfo();
	customer.deposit(bank, 1000);
	bank.getInfo();
	customer.getInfo();
}