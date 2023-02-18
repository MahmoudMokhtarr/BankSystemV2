#pragma once
#include "clsScreen.h";
#include <iomanip>
#include "Global.h";
#include "clsDate.h";

class clsTransferLogins
{
public:
    struct stTransferRegisterRecord
    {
        string DateTime;
        string FromAccountNumbrt;
        string ToAccountNumber;
        float TransferAmount;
        float BalanceSendAccountAfterTransfer;
        float BalanceReceptionAccountAfterTransfer;
        string UserName;
    };

    static stTransferRegisterRecord _ConvertLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransferRegisterRecord TransferRegisterRecord;

        vector <string> TransferRegisterDataLine = clsString::Split(Line, Seperator);

        TransferRegisterRecord.DateTime = TransferRegisterDataLine[0];
        TransferRegisterRecord.FromAccountNumbrt = TransferRegisterDataLine[1];
        TransferRegisterRecord.ToAccountNumber = TransferRegisterDataLine[2];

        TransferRegisterRecord.TransferAmount = stod(TransferRegisterDataLine[3]);
        TransferRegisterRecord.BalanceSendAccountAfterTransfer = stod(TransferRegisterDataLine[4]);
        TransferRegisterRecord.BalanceReceptionAccountAfterTransfer = stod(TransferRegisterDataLine[5]);
        TransferRegisterRecord.UserName = TransferRegisterDataLine[6];


        return TransferRegisterRecord;
    }

    static  vector <stTransferRegisterRecord> GetTransferRegisterList()
    {
        vector <stTransferRegisterRecord> vTransferRegisterRecord;

        fstream MyFile;
        MyFile.open("TransferLogins.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTransferRegisterRecord TransferRegisterRecord;

            while (getline(MyFile, Line))
            {

                TransferRegisterRecord = _ConvertLineToRecord(Line);

                vTransferRegisterRecord.push_back(TransferRegisterRecord);
            }
            MyFile.close();
        }
        return vTransferRegisterRecord;
    }

};

