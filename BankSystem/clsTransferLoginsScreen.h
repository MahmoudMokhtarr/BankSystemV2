#pragma once
#include "clsTransferLogins.h";

class clsTransferLoginsScreen : protected clsScreen
{
private:
    static void _PrintTrensFerRegisterRecordLine(clsTransferLogins::stTransferRegisterRecord LoginTransferRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << LoginTransferRecord.DateTime;
        cout << "| " << setw(8) << left << LoginTransferRecord.FromAccountNumbrt;
        cout << "| " << setw(8) << left << LoginTransferRecord.ToAccountNumber;
        cout << "| " << setw(8) << left << LoginTransferRecord.TransferAmount;
        cout << "| " << setw(10) << left << LoginTransferRecord.BalanceSendAccountAfterTransfer;
        cout << "| " << setw(10) << left << LoginTransferRecord.BalanceReceptionAccountAfterTransfer;
        cout << "| " << setw(8) << left << LoginTransferRecord.UserName;
    }

public:

    static void ShowTransferLoginsScreen()
    {
        vector <clsTransferLogins::stTransferRegisterRecord> vTransferRegisterRecord = clsTransferLogins::GetTransferRegisterList();
        string Title = "\t  Transfer Logins Screen";
        string SubTitle = "\t    (" + to_string(vTransferRegisterRecord.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date / Time";
        cout << "| " << left << setw(8) << "S.Acct";
        cout << "| " << left << setw(8) << "D.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Trensfer Available In the System ! ";
        else

            for (clsTransferLogins::stTransferRegisterRecord Record : vTransferRegisterRecord)
            {
                _PrintTrensFerRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

