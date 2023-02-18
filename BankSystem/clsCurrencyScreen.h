#pragma once
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidation.h";
#include "clsCurrencyListScreen.h";
#include "clsFindCurrency.h";
#include "clsUpdateCurrencyRate.h";
#include "clsCurrencyExchangeScreen.h";

class clsCurrencyScreen : protected clsScreen
{
private:

    enum enCurrencyMenuOptions {
        eListCurrencys = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidation::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 8? ");
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowCurrencyMenu();
        
    }

    static void _ShowListCurrencysScreen()
    {
        clsCurrencyListScreen::ShowCurrencyList();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();


    }
    static void _ShowUpdateRatecreen()
    {
        
        clsUpdateCurrencyRate::ShowUpdateCurrencyRate();

    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();

    }

    static void _PerfromMainMenueOption(enCurrencyMenuOptions CurrencyMenuOptions)
    {

        switch (CurrencyMenuOptions)
        {
        case enCurrencyMenuOptions::eListCurrencys:
        {
            system("cls");
            _ShowListCurrencysScreen();
            _GoBackToMainMenue();
            break;
        }

        case enCurrencyMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToMainMenue();
            break;
        }

        case enCurrencyMenuOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRatecreen();
            _GoBackToMainMenue();
            break;
        }
        case enCurrencyMenuOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToMainMenue();
            break;
        }

        case enCurrencyMenuOptions::eMainMenue:
        {  

        }

        }
    }

public:

    static void ShowCurrencyMenu()
    {
        system("cls");

        if (!CheckAccessRights(clsUser::enPermissions::pCurrency))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t\Currency Menu ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\Currency Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencys \n";
        cout << setw(37) << left << "" << "\t[2] Find Currency \n";
        cout << setw(37) << left << "" << "\t[3] Update Rate \n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator \n";
        cout << setw(37) << left << "" << "\t[5] Main Menu \n";

        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption(enCurrencyMenuOptions(_ReadCurrencyMenueOption()));

    }


};

