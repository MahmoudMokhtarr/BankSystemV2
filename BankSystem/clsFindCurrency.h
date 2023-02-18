#pragma once
#include "clsScreen.h"
#include "clsCurrency.h";
#include "clsInputValidation.h"
#include <iomanip>

class clsFindCurrency : protected clsScreen

{

private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _FindByCurrencyCode()
    {
        string CurrencyCode;

        cout << "Enter Currency Code : ";

        CurrencyCode = clsInputValidation::ReadString();

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        if (Currency.IsEmpty())
        {
            cout << "Currency Code Not Found -_- \n";
        }
        else

            _PrintCurrency(Currency);
    }

    static void _FindByCountery()
    {
        string CounteryName;

        cout << "Enter Countery Name : ";

        CounteryName = clsInputValidation::ReadString();

        CounteryName = clsString::UpperFirestLetters(CounteryName);

        clsCurrency Currency = clsCurrency::FindByCountry(CounteryName);

        if (Currency.IsEmpty())
        {
            cout << "Currency Code Not Found -_- \n";
        }
        else

            _PrintCurrency(Currency);

    }

   

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");


        short FindByCodeOrCountery = 0;

        cout << "\nFind By Code [1] Or Countery [2] ";

        FindByCodeOrCountery = clsInputValidation::ReadShortNumberBetween(1, 2);

        switch (FindByCodeOrCountery)

        {

        case 1:
        {
            _FindByCurrencyCode();
            break;
        }

        case 2:
            _FindByCountery();
            break;
        }

    }


};

