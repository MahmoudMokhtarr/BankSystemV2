#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private :
	string _Value;
	struct SClient
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		double AccountBalance;

	};

public:
	// initialization Value In Library
	clsString()
	{
		_Value = " ";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	};

	static string UpperFirestLetters(string Message)
	{
		bool FirestLetar = true;
		for (int i = 0; i < Message.length(); i++)
		{
			if (Message[i] != ' ' && FirestLetar)
			{
				Message[i] = toupper(Message[i]);
			}

			FirestLetar = (Message[i] == ' ' ? true : false);
		}
		return Message;
	}
	void UpperFirestLetters()
	{
		_Value= UpperFirestLetters(_Value);
	}

	static string LowerFirestLetters(string Message)
	{
		bool FirestLetar = true;
		for (int i = 0; i < Message.length(); i++)
		{
			if (Message[i] != ' ' && FirestLetar)
			{
				Message[i] = tolower(Message[i]);
			}

			FirestLetar = (Message[i] == ' ' ? true : false);
		}
		return Message;
	}
	void LowerFirestLetters()
	{
		 _Value = LowerFirestLetters(_Value);
	}

	static char  InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string InvertAllStringLettersCase(string Line)
	{
		for (int i = 0; i < Line.length(); i++)
		{
			if (isupper(Line[i]) == 1)
			{
				Line[i] = tolower(Line[i]);
			}
			else
				Line[i] = toupper(Line[i]);
		}
		return Line;
	}
	void InvertAllStringLettersCase()
	{
		 _Value = InvertAllStringLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	static short CountCapitalLetter(string Line)
	{
		int Counter = 0;
		for (short i = 0; i < Line.length(); i++)
		{
			if (isupper(Line[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static 	short CountSmallLetters(string Line)
	{
		short Counter = 0;
		for (short i = 0; i < Line.length(); i++)
		{
			if (islower(Line[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static string  UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void  UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string  LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void  LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	string PrintEachWordInString(string Line)
	{
		string Delim = " ";
		short Pos = 0;
		string TempString;

		cout << "Your string wrords are: \n";

		while ((Pos = Line.find(Delim)) != string::npos)
		{
			TempString = Line.substr(0, Pos);

			if (TempString != "")
			{
				cout << TempString << endl;
			}

			Line.erase(0, Pos + Delim.length());


		}
		if (Line != "")
		{
			cout << Line << endl;
		}
		return " ";
	}
	void PrintEachWordInString()
	{
		 PrintEachWordInString(_Value);
	}

	static short ConterEachWordInString(string Line)
	{
		string Delim = " ";
		short Pos = 0;
		string TempString;
		short Conter = 0;
		while ((Pos = Line.find(Delim)) != string::npos)
		{
			TempString = Line.substr(0, Pos);

			if (TempString != "")
			{
				Conter++;
			}
			Line.erase(0, Pos + Delim.length());
		}
		if (Line != "")
		{
			Conter++;
		}
		return Conter;
	}
	short ConterEachWordInString()
	{
		return ConterEachWordInString(_Value);
	}

	static vector <string>  Split(string Line, string Delim = "#//#")
	{
		vector <string> Vstring;
		short Pos = 0;
		string TempString;

		while ((Pos = Line.find(Delim)) != string::npos)
		{
			TempString = Line.substr(0, Pos);

			if (TempString != "")
			{
				Vstring.push_back(TempString);
			}
			Line.erase(0, Pos + Delim.length());
		}
		if (Line != "")
		{
			Vstring.push_back(Line);
		}
		return Vstring;
	}
	vector <string>  SplitString(string Delim)
	{
		return  Split(_Value, Delim);
	}

	static string TrimeLeft(string Line)
	{
		short Counter = 0;
		for (short i = 0; i < Line.length(); i++)
		{
			if (Line[i] != ' ')
				return Line.substr(i, Line.length() - i);
		}
		return "";
	}
	void TrimeLeft()
	{
		_Value = TrimeLeft(_Value);
	}

	static string TrimeRight(string Line)
	{
		short Counter = 0;
		short i = 0;
		for ( i = Line.size(); i >= 0; i--)
		{
			if (Line[i] != ' ')
			return Line.substr(0, i + 1);
		}
		return "";
	}
	void TrimeRight()
	{
		_Value= TrimeRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimeLeft(TrimeRight(S1)));

	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector <string> Vstring, string Delim ="#//#")
	{
		string S1;

		for (string& S : Vstring)
		{
			S1 = S1 + S + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReversWord(string Line)
	{
		string  S1;
		vector <string> Vstring;
		Vstring = Split(Line, " ");

		vector <string> ::iterator Iter = Vstring.end();

		while (Iter != Vstring.begin())
		{
			Iter--;

			S1 += *Iter + " ";
		}
		return S1.substr(0, S1.length() - 1);

	}
	string ReversWord()
	{
		return _Value = ReversWord(_Value);
	}

	static string PunctuationsInEnglish(string Message)
	{
		string NotPunctuations;
		for (short i = 0; i < Message.length(); i++)
		{
			if (!ispunct(Message[i]))
			{
				NotPunctuations += Message[i];
			}
		}
		return NotPunctuations;
	}
	string PunctuationsInEnglish()
	{
		return _Value = PunctuationsInEnglish(_Value);
	}

	static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}

		}

		return Counter;
	}
	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}
	static short  CountVowels(string S1)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (IsVowel(S1[i]))
				Counter++;

		}

		return Counter;
	}
	short  CountVowels()
	{
		return CountVowels(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{

			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}

			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}

			}

		}

		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}
};

