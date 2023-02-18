#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
private:
	string _FristeName, _LasteName, _Emil,_Phone;

public:

	clsPerson(string FristeName, string LasteName, string Emil, string Phone)
	{
		_FristeName = FristeName;
		_LasteName = LasteName;
		_Emil = Emil;
		_Phone = Phone;
	}

	void SetFristeName(string FristeName)
	{
		_FristeName = FristeName;
	}
	string GetFristeName()
	{
		return _FristeName;
	}
	__declspec(property (put = SetFristeName, get = GetFristeName)) string FristeName;


	void SetLasteName(string LasteName)
	{
		_LasteName = LasteName;
	}
	string GetLasteName()
	{
		return _LasteName;
	}
	__declspec(property (put = SetLasteName, get = GetLasteName)) string LasteName;

	void SetEmil(string Emil)
	{
		_Emil = Emil;
	}
	string GetEmil()
	{
		return _Emil;
	}
	__declspec(property (put = SetEmil, get = GetEmil)) string Emil;

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property (put = SetPhone, get = GetPhone)) string Phone;
};

