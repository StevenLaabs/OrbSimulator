#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

class BankAccount
{

public:
	BankAccount();

	BankAccount(const int balance);

	void deposit(int amount);
	bool withdraw(int amount);

	int balance = 0;

};

#endif // !_BANKACCOUNT_H
