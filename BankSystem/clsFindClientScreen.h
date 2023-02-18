#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsPerson.h";
#include "clsBankClient.h";
#include "clsInputValidation.h";

using namespace std;
class clsFindClientScreen : protected clsScreen
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

public :

    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tFind Client Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidation::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.isEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};

