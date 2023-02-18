#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidation.h";

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string Massage)
    {
        string AccountNumber = "";
        cout << "\n" << Massage;
        cin >> AccountNumber;
        return AccountNumber;
    }
public:

    static  void ShowTransferScreen()
    {

        _DrawScreenHeader("\t Transfer Screen ");

        string AccountNumberSender = _ReadAccountNumber("Enter The Sender's Account Number ");
        while (!clsBankClient::IsClientExist(AccountNumberSender))
        {
            cout << "\nClient with [" << AccountNumberSender << "] does not exist.\n";
            AccountNumberSender = _ReadAccountNumber("Enter The Sender's Account Number");
        }

        clsBankClient ClientSender = clsBankClient::Find(AccountNumberSender);
        _PrintClient(ClientSender);

        string AccountNumberRecipient = _ReadAccountNumber("Enter The Recipient Account Number ");
        while (!clsBankClient::IsClientExist(AccountNumberRecipient))
        {
            cout << "\nClient with [" << AccountNumberRecipient << "] does not exist.\n";
            AccountNumberRecipient = _ReadAccountNumber("Enter The Recipient Account Number");
        }

        clsBankClient ClientRecipient = clsBankClient::Find(AccountNumberRecipient);
        _PrintClient(ClientRecipient);

        double Amount = 0;
        cout << "\nPlease enter transfer amount ? ";
        Amount = clsInputValidation::ReadDoubleNumber();

        cout << "\nAre you sure you want to perform this transaction ? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (ClientSender.Transfer(Amount,ClientRecipient))
            {
                cout << "Transfer Done ! \n";
                _PrintClient(ClientSender);
                _PrintClient(ClientRecipient);
            }
            else
            {
                cout << "\nTransfer Faild\n";
                cout << "\nAmout to withdraw is: " << Amount;
                cout << "\nYour Balance is: " << ClientSender.AccountBalance;

            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};

