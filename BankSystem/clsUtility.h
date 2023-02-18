#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsUtility
{
private:
	// Enums
	enum EnPassFail { Pass = 1, Fail = 2 };
	enum EnOddOrEven { Odd = 1, Even = 2 };
	enum EnPrimeNotPrime { Prime = 1, NotePrime = 2 };
	enum EnCategory { SmallLetter = 1, CapitalLetter = 2, Specialcharacters = 3, Digit = 4 };
public:
	// Methods
	static EnPassFail ChackAvrage(float Avrage)
	{
		if (Avrage >= 50)
			return EnPassFail::Pass;
		else
			return EnPassFail::Fail;
	}
	static void Swap(int Number1, int Number2)
	{
		cout << "Number1 = " << Number2 << endl;
		cout << "Number2 = " << Number1 << endl;
	}
	static EnOddOrEven CheckOddOrEven(int Number)
	{
		if (Number % 2 != 0)
			return EnOddOrEven::Odd;

		else
			return
			EnOddOrEven::Even;
	}
	static float ReadPositivNumber(string Massage)
	{
		float Number = 0;
		do
		{
			cout << Massage << endl;
			cin >> Number;
		} while (Number <= 0);
		return Number;
	}
	static float TotalBillAfterserviceAndTax(float TotalBill)
	{
		TotalBill = TotalBill * 1.1;
		TotalBill = TotalBill * 1.16;
		return TotalBill;

	}
	static EnPrimeNotPrime CheckPeime(int Number)

	{
		int M = round(Number / 2);

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return EnPrimeNotPrime::NotePrime;
		}

		return EnPrimeNotPrime::Prime;
	}
	static bool IsPerfctNumber(int Number)
	{
		int Sum = 0;
		int M = round(Number / 2);

		for (int i = 1; i <= M; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}
		return Number == Sum;
	}
	static void PrintreverseNumber(int Number)
	{
		int Num = 0;
		int Reminder = 0;
		while (Number > 0)
		{
			Reminder = Number % 10;
			Number = Number / 10;
			cout << Reminder << endl;
		}
	}
	static string ReadText()
	{
		string Text;
		cout << "Please Enter Text" << endl;
		cin >> Text;
		return Text;
	}
	static string EncryptText(string Text, short Key = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + Key);
		}
		return Text;
	}
	static string DercryptText(string Text, short Key = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - Key);
		}
		return Text;
	}
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{
		int RanndNumber = rand() % (To - From + 1) + From;
		return RanndNumber;
	}
	static char PrintRandomChar(EnCategory Category)
	{
		switch (Category)
		{
		case EnCategory::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case EnCategory::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case EnCategory::Specialcharacters:
			return char(RandomNumber(33, 47));
			break;
		case EnCategory::Digit:
			return char(RandomNumber(48, 57));
			break;
		}
	}
	static string generateWord(EnCategory Category, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + PrintRandomChar(Category);
		}
		return  Word;
	}
	static string generatKey()
	{
		string Key;
		Key = generateWord(EnCategory::CapitalLetter, 4) + "-";
		Key = Key + generateWord(EnCategory::CapitalLetter, 4) + "-";
		Key = Key + generateWord(EnCategory::CapitalLetter, 4) + "-";
		Key = Key + generateWord(EnCategory::CapitalLetter, 4);

		return Key;
	}
	static void GeneratKeys(short NumberKey)
	{
		for (int i = 1; i <= NumberKey; i++)
		{
			cout << "Key Number {" << i << "} : ";
			cout << generatKey() << endl;
		}
	}
	static void FillArray(int NumberElements[100], int& ArrLength)
	{

		for (int i = 0; i < ArrLength; i++)
		{
			NumberElements[i] = i + 1;
		}
	}
	static void PrintprintElementsArryAfterShuffle(int NumberElements[100], int& ArrLength)
	{
		for (int i = 0; i <= ArrLength - 1; i++)
		{
			NumberElements[i] = RandomNumber(1, ArrLength);
			cout << RandomNumber(1, ArrLength) << " ";
		}
		cout << "\n";
	}
	static void FibonacciNumberUsingLoop(int Number)
	{
		int FebNumber = 0;
		short Num1 = 1, Num2 = 0;
		cout << "1   ";

		for (short i = 1; i < 10; i++)
		{
			FebNumber = Num1 + Num2;
			cout << FebNumber << "   ";
			Num2 = Num1;
			Num1 = FebNumber;
		}
	}
	static void PrintFirestLetters(string Message)
	{
		bool FirestLetar = true;
		cout << "First letters of this string: \n";
		for (int i = 0; i < Message.length(); i++)
		{
			if (Message[i] != ' ' && FirestLetar)
			{
				cout << Message[i] << endl;
			}

			FirestLetar = (Message[i] == ' ' ? true : false);
		}
	}
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
	static string UperAllstring(string Line)
	{
		for (short i = 0; i < Line.length(); i++)
		{
			Line[i] = toupper(Line[i]);

		}
		return Line;
	}
	static string LowerAllstring(string Line)
	{
		for (short i = 0; i < Line.length(); i++)
		{
			Line[i] = tolower(Line[i]);

		}
		return Line;
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
	static int CountSmallLetters(string Line)
	{
		int Counter = 0;
		for (short i = 0; i < Line.length(); i++)
		{
			if (islower(Line[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	static short CountLetter(string Line, char char1, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < Line.length(); i++)
		{
			if (MatchCase)
			{
				if (Line[i] == char1)
					Counter++;
			}
			else
			{
				if (toupper(Line[i]) == toupper(char1))
				Counter++;
			}
		}
		return Counter;
	}
	static bool IsVowelChar(char Char1)
	{
		char Arrchar[5] = { 'A','E','I','O','U' };

		for (short i = 0; i < 5; i++)
		{
			if (toupper(Arrchar[i]) == toupper(Char1))
			{

				return 1;
			}
		}
		return 0;
	}
	static short CountVowel(string Message)
	{
		short Counter = 0;

		for (short i = 0; i < Message.length(); i++)
		{
			if (IsVowelChar(Message[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	static void PrintEachWordInString(string Line)
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
	}
	static int ConterEachWordInString(string Line)
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
	static vector <string>  SplitString(string Line, string Delim)
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
	static string JoinString(vector <string> Vstring, string Delim)
	{
		string S1;

		for (string& S : Vstring)
		{
			S1 = S1 + S + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	static string ReversWord(string Line)
	{
		string  S1;
		vector <string> Vstring;
		Vstring = SplitString(Line, " ");

		vector <string> ::iterator Iter = Vstring.end();

		while (Iter != Vstring.begin())
		{
			Iter--;

			S1 += *Iter + " ";
		}
		return S1.substr(0, S1.length() - 1);

	}
	static string ReplacementWordInString(string Message, string SearchTerm, string Replacement)
	{
		short  PosStr = Message.find(SearchTerm);

		while (PosStr != std::string::npos)
		{
			Message = Message.replace(PosStr, SearchTerm.length(), Replacement);

			PosStr = Message.find(SearchTerm);
		}

		return Message;
	}


	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}

	}
};



