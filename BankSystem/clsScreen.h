#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include "clsDate.h";

class clsScreen
{

protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        _DateToday();
        _LoginUserBy();
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

    static void _DateToday()
    {
        cout << "\t\t\t\t\t" << "Date : " << clsDate::DateToString(clsDate());
    }

    static void _LoginUserBy()
    {
        cout << "\n\t\t\t\t\t" << "Login User By : " << CurrentUser.GetUserName() << endl;
    }
};

