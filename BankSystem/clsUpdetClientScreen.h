#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidation.h";

class clsUpdetClientScreen : protected clsScreen
{
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
	static void _ReadNewClientInfoLineByLine(clsBankClient& Client)
	{
		cout << "\nEnter Friste Name ";
		Client.FristeName = clsInputValidation::ReadString();

		bool UpdateThis = true;

		cout << "\nDo you want to update Laste Name ? 1 Yeas 0 NO : ";
		cin >> UpdateThis;
		if (UpdateThis)
		{
			cout << "\nEnter Laste Name ";
			Client.LasteName = clsInputValidation::ReadString();
		}

		cout << "\nDo you want to update Emil ? 1 Yeas 0 NO : ";
		cin >> UpdateThis;
		if (UpdateThis)
		{
			cout << "\nEnter Emil ";
			Client.Emil = clsInputValidation::ReadString();
		}

		cout << "\nDo you want to update Phone ? 1 Yeas 0 NO : ";
		cin >> UpdateThis;
		if (UpdateThis)
		{
			cout << "\nEnter Phone ";
			Client.Phone = clsInputValidation::ReadString();
		}

		cout << "\nDo you want to update Pine Code ? 1 Yeas 0 NO : ";
		cin >> UpdateThis;
		if (UpdateThis)
		{
			cout << "\nEnter PineCode ";
			Client.PineCode = clsInputValidation::ReadString();
		}

		cout << "\nDo you want To Update Account Balance ? 1 Yeas 0 NO : ";
		cin >> UpdateThis;
		if (UpdateThis)
		{
			cout << "\nEnter Account Balance ";
			Client.AccountBalance = clsInputValidation::ReadDoubleNumber();
		}
	}
	static void _ReadClientDate(clsBankClient& Client)
	{
		char UpdateClientInformation = 'A';
		cout << "Do you want to Update the Client information completely ? Enter  Y If yes Enter N If  No ";
		cin >> UpdateClientInformation;

		if (UpdateClientInformation == 'n' || UpdateClientInformation == 'N')
		{
			_ReadNewClientInfoLineByLine(Client);
		}

		else
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
			Client.AccountBalance = clsInputValidation::ReadFloatNumber();

		}

	}

public:

	static void UpdetClientDate()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;// this will exit the function and it will not continue
		}
		_DrawScreenHeader("\tUpdet Client Screen");

		string AccountNumber = "";
		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Wrong Account Number, Please Try Again \n";
			AccountNumber = clsInputValidation::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "Update Client Date \n";
		cout << "________________________\n";
		_ReadClientDate(Client1);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = Client1.Saev();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			system("cls");
			cout << "Done  Update Successfully -_- \n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "Error Account Was Not Saved Because Its Empty \n";
		}

		}
	}
};

