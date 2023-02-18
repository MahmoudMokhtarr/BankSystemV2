#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsManageUsersScreen.h";
#include "clsScreen.h";
#include "clsInputValidation.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdetClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsLoginRegisterScreen.h";
#include "clsCurrencyScreen.h";

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrency = 9, eExit = 10
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidation::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 8? ");
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    // Show All Screans 
    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient();

    }
    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();

    }
    static void _ShowUpdateClientScreen()
    {
        clsUpdetClientScreen::UpdetClientDate();

    }
    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
        
    }
    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();

    }
    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }
    static void _ShowLoginRecordScren()
    {
        clsLoginRegisterScreen::ShowLoginRecordScren();
    }
    static void _ShowCurrencyScren()
    {
        clsCurrencyScreen::ShowCurrencyMenu();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        }
        case enMainMenueOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();

            break;
        }

        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRecordScren();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eCurrency:
        {
            system("cls");
            _ShowCurrencyScren();
            _GoBackToMainMenue();
            break;
        }

        case enMainMenueOptions::eExit:
        {
            system("cls");
            _Logout();
            break;
        }
        }
    }

public:

	static void ShowMainMenue()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List \n";
        cout << setw(37) << left << "" << "\t[2] Add New Client \n";
        cout << setw(37) << left << "" << "\t[3] Delete Client \n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info \n";
        cout << setw(37) << left << "" << "\t[5] Find Client \n";
        cout << setw(37) << left << "" << "\t[6] Transactions \n";
        cout << setw(37) << left << "" << "\t[7] Manage Users \n";
        cout << setw(37) << left << "" << "\t[8] Login Record \n";
        cout << setw(37) << left << "" << "\t[9] Currency \n";
        cout << setw(37) << left << "" << "\t[10] Logout \n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

	}

};

