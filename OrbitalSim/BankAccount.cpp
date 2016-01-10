#include "BankAccount.h"

BankAccount::BankAccount()
{

}

BankAccount::BankAccount(const int balance) : balance(balance)
{

}

void BankAccount::deposit(int amount)
{
	balance += amount;
}

bool BankAccount::withdraw(int amount)
{
	if (amount <= balance + 500)
	{
		balance -= amount;
		return true;
	}

	return false;
}