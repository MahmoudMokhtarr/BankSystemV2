#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsDate.h";
#include "clsUtility.h";
using namespace std;

class clsInputValidation
{
public:
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualeDate2(Date, From)) &&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualeDate2(Date, To)))
		{
			return true;
		}

		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualeDate2(Date, To)) &&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualeDate2(Date, From)))
		{
			return true;
		}
		return false;
	}
	static int ReadintNumber()
	{
		int Number = 0;
		cout << "Please Enter Number : ? ";
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	static double ReadDoubleNumber()
	{
		double Number = 0;
		cout << "Please Enter Number : ? ";
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}
	static int ReadintNumberBetween(int From, int To,string Massege)
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout  << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Massege << endl;
			cin >> Number;
		}

		return Number;

	}
	static double ReadDoubleNumberBetween(double From, double To, string Massege)
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Massege << endl;
			cin >> Number;
		}

		return Number;

	}
	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::isValidateDate(Date);
	}
	static string ReadString()
	{
		string  S1 = "";

		getline(cin >> ws, S1);
		return S1;
	}
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

};

