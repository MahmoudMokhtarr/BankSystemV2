#pragma once
#include "clsCurrency.h";
#include "clsScreen.h";
#include "clsInputValidation.h";

class clsCurrencyExchangeScreen  : protected clsScreen
{

private:

	static clsCurrency _ReadCurrencyCode(string Message)
	{
		cout << Message;

		string CurrencyCode = clsInputValidation::ReadString();

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "\n Currency Code " << CurrencyCode <<  " is not found, choose another one : ";

			 CurrencyCode = clsInputValidation::ReadString();
		}

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		clsCurrency Currency = Currency.FindByCode(CurrencyCode);

		return Currency;
	}

	 

public:

	static void ShowCurrencyExchangeScreen()
	{

		double AmounForUsd = 0;
		double AmountNumber = 0;

		_DrawScreenHeader("\t Currency Exchange Screen ");

		char Answer = 'y';

		do
		{
			system("cls");

			_DrawScreenHeader("\t Currency Exchange Screen ");

		clsCurrency CurrencyFrom = _ReadCurrencyCode("\nEnter Currency 1 Code : ");

		clsCurrency CurrencyTo = _ReadCurrencyCode("\nEnter Currency 2 Code : ");

		cout << "\nEnter Amount Currency Exchange : ";

		float CurrencyExchange = clsInputValidation::ReadFloatNumber();
		
		if (CurrencyFrom.CurrencyCode() != "USD")
		{
			if (CurrencyFrom.Rate() > 1)
			{
				AmounForUsd = CurrencyExchange * CurrencyFrom.Rate();
			}

			else
			{
				AmounForUsd = CurrencyExchange / CurrencyFrom.Rate();
			}

			AmountNumber = AmounForUsd * CurrencyTo.Rate();

			cout << "\n" << CurrencyExchange << " " << CurrencyFrom.CurrencyCode() << " = " << AmountNumber << " " << CurrencyTo.CurrencyCode() << endl;

		}

		else
		{

			if (CurrencyTo.Rate() > 1)
			{
				AmountNumber = CurrencyExchange * CurrencyTo.Rate();
			}

			else
			{
				AmountNumber = CurrencyExchange / CurrencyTo.Rate();
			}

			cout << "\n" << CurrencyExchange << " " << CurrencyFrom.CurrencyCode() << " = " << AmountNumber << " " << CurrencyTo.CurrencyCode() << endl;


		}

		cout << "\nAre You  Want To Agine Currency Exchange  y/n? ";
		cin >> Answer;


		} while (Answer == 'y' || Answer == 'Y');


	}


};

