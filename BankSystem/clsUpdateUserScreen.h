#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsInputValidation.h";

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FristeName = clsInputValidation::ReadString();

        cout << "\nEnter LastName: ";
        User.LasteName = clsInputValidation::ReadString();

        cout << "\nEnter Email: ";
        User.Emil = clsInputValidation::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidation::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidation::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FristeName;
        cout << "\nLastName    : " << User.LasteName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Emil;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

    public:

        static void ShowUpdateUserScreen()
        {

            _DrawScreenHeader("\tUpdate User Screen");

            string UserName = "";

            cout << "\nPlease Enter User UserName: ";
            UserName = clsInputValidation::ReadString();

            while (!clsUser::IsUserExist(UserName))
            {
                cout << "\nAccount number is not found, choose another one: ";
                UserName = clsInputValidation::ReadString();
            }

            clsUser User1 = clsUser::Find(UserName);

            _PrintUser(User1);

            cout << "\nAre you sure you want to update this User y/n? ";

            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                cout << "\n\nUpdate User Info:";
                cout << "\n____________________\n";


                _ReadUserInfo(User1);

                clsUser::enSaveResults SaveResult;

                SaveResult = User1.Save();

                switch (SaveResult)
                {
                case  clsUser::enSaveResults::svSucceeded:
                {
                    cout << "\nUser Updated Successfully :-)\n";

                    _PrintUser(User1);
                    break;
                }
                case clsUser::enSaveResults::svFaildEmptyObject:
                {
                    cout << "\nError User was not saved because it's Empty";
                    break;

                }

                }
            }
        }

};

