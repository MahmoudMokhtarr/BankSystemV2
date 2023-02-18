#pragma once
#include <string>
#include <iomanip>
#include "clsScreen.h";
#include "clsCurrency.h";

class clsCurrencyListScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }


public:

    static void ShowCurrencyList()
    {

        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country ";
        cout << "| " << left << setw(8) << "Code ";
        cout << "| " << left << setw(45) << "Name ";
        cout << "| " << left << setw(10) << "Rate ";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintClientRecordLine(Currency);

                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


    }


};

