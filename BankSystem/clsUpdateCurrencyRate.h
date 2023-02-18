#pragma once
#include "clsScreen.h"
#include "clsCurrency.h";
#include "clsInputValidation.h"
#include <iomanip>

class clsUpdateCurrencyRate : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "__________________________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n__________________________________________\n";

    }



public:

    static void ShowUpdateCurrencyRate()
    {

        _DrawScreenHeader("\t  Update Currency Rate Screen");

        string CurrencyCode;

        cout << "Enter Currency Code : ";

        CurrencyCode = clsInputValidation::ReadString();

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        if (Currency.IsEmpty())
        {
            cout << "Currency Code Not Found -_- \n";
            return;
        }

        else

            _PrintCurrency(Currency);
    

        char Answr = 'a';
        cout << "\nAre You sour you want Update Currency Rate ?  ";
        cin >> Answr;

        if (Answr == 'y' || Answr == 'Y')
        {

            float NewRate = 0;

            cout << "\nEnter New Rate : ";

            NewRate= clsInputValidation::ReadFloatNumber();

            Currency.UpdateRate(NewRate);

            cout << "\nDone Update Rate successfully \n";

            _PrintCurrency(Currency);
        }

        else
            ;

    }

};

