#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h";
#include "clsString.h";
#include "Global.h";

using namespace std;

class clsBankClient : public  clsPerson
{
private:

	enum EnMode { EmptyMode = 1, UpdetMode = 2, AddNewMode = 3 };

	EnMode _Mode;
	string _AccountNumber, _PineCode;
	double _AccountBalance;
	bool _MarkedForDeleted = false;


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(EnMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;

		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(EnMode::UpdetMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FristeName + Seperator;
		stClientRecord += Client.LasteName + Seperator;
		stClientRecord += Client.Emil + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.PineCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	 void _AddNew()
	{
		 _AddDataLineToFile(_ConverClientObjectToLine(*this));
	}
	void _Updet()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClient);
	}
	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient & C : vClients)
			{
				if (C._MarkedForDeleted == false)
				{
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;

				}

			}

			MyFile.close();

		}

	}


	void _AddDataToFiTransferLogins(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("TransferLogins.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}
	string _ConverDateTransferToRecord(float Amount,clsBankClient DestinationClient,string Seperator = "#//#")
	{
		string DateRecord = "";
		DateRecord += clsDate::GetSystemTimeDateString() + Seperator;
		DateRecord += _AccountNumber + Seperator;
		DateRecord += DestinationClient.AccountNumber + Seperator;
		DateRecord += to_string(Amount) + Seperator;
		DateRecord += to_string(_AccountBalance) + Seperator;
		DateRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		DateRecord += CurrentUser.UserName;
		return DateRecord;
	}


public:

	clsBankClient(EnMode Mode, string FristeName, string LasteName, string Emil, string Phone, string AccountNumber, string PineCode, double AccountBalance)
	: clsPerson(FristeName, LasteName, Emil, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PineCode = PineCode;
		_AccountBalance = AccountBalance;
	}

	bool isEmpty()
	{
		return (_Mode == EnMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property (get = GetAccountNumber)) string AccountNumber;


	void SetPineCode(string PineCode)
	{
		_PineCode = PineCode;
	}
	string GetPineCode()
	{
		return _PineCode;
	}
	__declspec(property (put = SetPineCode, get = GetPineCode)) string PineCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property (put = SetAccountBalance, get = GetAccountBalance)) double AccountBalance;

	string FullName()
	{
		return FristeName + " " + LasteName;
	}

	void Print()
	{
		cout << "Client Info : ";
		cout << "\n-----------------------------";
		cout << "\nFriste Name : " << FristeName << endl;
		cout << "Laste Name : " << GetLasteName() << endl;
		cout << "Emil : " << GetEmil() << endl;
		cout << "Phone : " << GetPhone() << endl;
		cout << "Account Number : " << _AccountNumber << endl;
		cout << "Password : " << _PineCode << endl;
		cout << "Account Balance : " << _AccountBalance << endl;
		cout << "-----------------------------\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PineCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.GetPineCode() == PineCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.isEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 1, svSucceeded = 2, svFieldAccountNumber = 3 };

	enSaveResults Saev()
	{
		switch (_Mode)
		{
		case EnMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case EnMode::UpdetMode:
		{
			_Updet();
			return enSaveResults::svSucceeded;
		}
		case EnMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildEmptyObject;
			}
			else
			{
				_AddNew();
				_Mode = EnMode::UpdetMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(EnMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	 bool Delete()
	{
		vector <clsBankClient> _vClient;
		_vClient = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClient)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkedForDeleted = true;
				break;
			}

		}

		_SaveCleintsDataToFile(_vClient);
		*this = _GetEmptyClientObject();
		return true;

	}

	 static vector <clsBankClient> GetClientsList()
	 {
		 return _LoadClientsDataFromFile();
	 }

	 static double GetTotalBalances()
	 {
		 vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		 double TotalBalances = 0;

		 for (clsBankClient Client : vClients)
		 {

			 TotalBalances += Client.AccountBalance;
		 }

		 return TotalBalances;

	 }

	 void Deposit(double Amount)
	 {
		 _AccountBalance += Amount;
		 Saev();
	 }

	 bool Withdraw(double Amount)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 else
		 {
			 _AccountBalance -= Amount;
			 Saev();
		 }
	 }

	 bool Transfer(float Amount, clsBankClient & ClientRecipient)
	 {
		 if (Amount > _AccountBalance)
		 {
			 return false;
		 }
		 Withdraw(Amount);
		 ClientRecipient.Deposit(Amount);
		 RegisterTransferInFile(Amount, ClientRecipient);
		 return true;
	 }

	 void RegisterTransferInFile(float Amount,clsBankClient DestinationClient)
	 {
		 _AddDataToFiTransferLogins(_ConverDateTransferToRecord(Amount,DestinationClient));
	 }
};

