#pragma once
#include "clsScreen.h";
#include "clsLoginRegister.h";
class clsLoginRegisterScreen : protected clsScreen
{
    static void _PrintLoginRegisterRecordLine(clsLoginRegister::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;

    }

public:

    static  void ShowLoginRecordScren()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsLoginRegister::stLoginRegisterRecord> vLoginRegisterRecord = clsLoginRegister::GetLoginRegisterList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "System Time Date";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsLoginRegister::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};



