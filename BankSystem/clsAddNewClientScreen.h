#pragma once
#include <string>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidation.h";
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Info : ";
		cout << "\n-----------------------------";
		cout << "\nFriste Name : " << Client. FristeName << endl;
		cout << "Laste Name : " << Client. LasteName << endl;
		cout << "Full Name : " << Client.FullName() << endl;
		cout << "Emil : " << Client. Emil << endl;
		cout << "Phone : " << Client. Phone << endl;
		cout << "Account Number : " << Client. AccountNumber << endl;
		cout << "Password : " << Client. PineCode << endl;
		cout << "Account Balance : " << Client. AccountBalance << endl;
		cout << "-----------------------------\n";
	}
	static void _ReadNewClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter Friste Name ";
		Client.FristeName = clsInputValidation::ReadString();

		cout << "\nEnter Laste Name ";
		Client.LasteName = clsInputValidation::ReadString();

		cout << "\nEnter Emil ";
		Client.Emil = clsInputValidation::ReadString();

		cout << "\nEnter Phone ";
		Client.Phone = clsInputValidation::ReadString();

		cout << "\nEnter PineCode ";
		Client.PineCode = clsInputValidation::ReadString();

		cout << "\nEnter Account Balance ";
		Client.AccountBalance = clsInputValidation::ReadDoubleNumber();

	}

public:
	static void AddNewClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;// this will exit the function and it will not continue
		}

		_DrawScreenHeader("\tAdd New Client Screen ");

		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidation::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThe account number is already Enter again \n";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadNewClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = NewClient.Saev();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			system("cls");
			cout << "Done  Update Successfully -_- \n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "Error Account Was Not Saved Because Its Empty \n";
		}

		case clsBankClient::enSaveResults::svFieldAccountNumber:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}

		}
	}
};

