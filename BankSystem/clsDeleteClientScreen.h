#pragma once
#include "clsScreen.h";
#include "clsInputValidation.h";

class clsDeleteClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "Client Info : ";
		cout << "\n-----------------------------";
		cout << "\nFriste Name : " << Client.FristeName << endl;
		cout << "Laste Name : " << Client.LasteName << endl;
		cout << "Full Name : " << Client.FullName() << endl;
		cout << "Emil : " << Client.Emil << endl;
		cout << "Phone : " << Client.Phone << endl;
		cout << "Account Number : " << Client.AccountNumber << endl;
		cout << "Password : " << Client.PineCode << endl;
		cout << "Account Balance : " << Client.AccountBalance << endl;
		cout << "-----------------------------\n";
	}

public:

	static void DeleteClient()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "The account number was not found, Please Try Again \n";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		char Answr = 'a';
		cout << "Are You sour you want Delete This Client ?  ";
		cin >> Answr;

		if (Answr == 'y' || Answr == 'Y')
		{

			if (Client1.Delete())
			{
				cout << "Delete Account Done _-_ \n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "Error The client was not deleted -_- \n";
			}
		}
	}

};

