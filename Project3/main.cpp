// 2018112028 김지훈
#include <iostream>

using namespace std;

class Bank
{
private:
	int balance; // 잔고
public:
	Bank(int money); // 생성자
	void setBalance(int money); // 잔고 설정
	void getInfo(); // 현재 정보 가져오기
};

class Customer
{
private:
	int cash; // 보유 현금
public:
	Customer(int money); // 생성자
	void getInfo(); // 현재 정보 가져오기
	void withDraw(Bank& bank, int money); // 출금
	void deposit(Bank& bank, int money); // 입금
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
	cout << "은행잔고: " << this->balance << endl;
}

void Customer::getInfo()
{
	cout << "보유현금: " << this->cash << endl << endl;
}

void Customer::withDraw(Bank& bank, int money)
{
	this->cash += money;
	bank.setBalance(-money); // 해당 매개변수를 +해주기 때문에 -를 붙여준다.
	cout << "출금->" << money << endl;
}

void Customer::deposit(Bank& bank, int money)
{
	this->cash -= money;
	bank.setBalance(money);
	cout << "입금->" << money << endl;
}

int main()
{
	Bank bank(2000); // 잔고 2000원
	Customer customer(1000); // 보유현금 1000원
	customer.getInfo();
	customer.withDraw(bank, 500);
	bank.getInfo();
	customer.getInfo();
	customer.deposit(bank, 1000);
	bank.getInfo();
	customer.getInfo();
}