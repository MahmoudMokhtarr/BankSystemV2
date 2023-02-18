#pragma once
#include "clsScreen.h";
#include "clsUser.h";
#include "clsMainScreen.h";
#include "clsMainScreen.h";
#include "clsDate.h";

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFailde = false;

		string Username, Password;
		short Counter = 3;
		do
		{
			if (LoginFailde)
			{
				cout << "\nInvelid Username/Password ! \n";

				Counter--;
				cout << "You Have " << Counter << " Taril To Login ;\n";
			}

			cout << "\nEnter Username : ";
			cin >> Username;

			cout << "\nEnter Password : ";
			cin >> Password;
			

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailde = CurrentUser.IsEmpty();

			if (Counter <= 1)
			{
				cout << "\nYou Are Locked After 3 Field Trials ;\n";
				CurrentUser = clsUser::Find("");
				return false;
			}

		} while (LoginFailde);

		CurrentUser.RegisterLoginsInLogFile();
		clsMainScreen::ShowMainMenue();
		return true;
	}


public:

	static bool LoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen ");
		return _Login();
	}
};

