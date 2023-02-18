#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include<ctime>
using namespace std;

class clsDate
{
private:
	short _Day, _Month, _Year;
public:

	// Constructors Initialization
	clsDate ()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon +1;
		_Year = now->tm_year + 1900;
	}
	clsDate(string DateString)
	{
		vector <string> VDate;
		VDate = SplitString(DateString, "/");
		_Day = stoi(VDate[0]);
		_Month = stoi(VDate[1]);
		_Year = stoi(VDate[2]);
	}
	clsDate(short Day,short Month,short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short DaysOrderInYear, short Year)
	{
		short ReminingDays = DaysOrderInYear;
		short MonthDays = 0;

		_Year = Year;
		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(_Year, _Month);
			if (ReminingDays > MonthDays)
			{
				ReminingDays -= MonthDays;
				_Month++;
			}
			else
			{
				_Day = ReminingDays;
				break;
			}

		}
	}
	               
	// Get And Set Properties

	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

    // Methods required to run Constructors
	vector <string>  SplitString(string Line, string Delim)
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

	// required to run Print Method
	void Print()
	{
		cout << DateToString() << endl;
		
	}


	static bool CheckYearisLeap(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0) ? true : false;
	}
	bool CheckYearisLeap()
	{
		return CheckYearisLeap(_Year);
	}

	static short NumberOfDayInYear(short Year)
	{
		return CheckYearisLeap(Year) ? 366 : 365;
	}
	short NumberOfDayInYear()
	{
		return NumberOfDayInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumberOfDayInYear(Year) * 24;
	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDayInMonth(short Year, short Month)
	{
		if (Month == 2)
		{
			return CheckYearisLeap(Year) ? 29 : 28;
		}
		else
			return	(Month != 4 && Month != 6 && Month != 9 && Month != 11) ? 31 : 30;
	}
	short NumberOfDayInMonth()
	{
		return NumberOfDayInMonth(_Year, _Month);
	}

	static short NumberOfHoursInMonth(short Year, short Month)
	{
		return NumberOfDayInMonth(Year, Month) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month);
	}

	static int NumberOfMinutesInMonth(short Year, short Month)
	{
		return NumberOfHoursInMonth(Year, Month) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecondsInMonth(short Year, short Month)
	{
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Year, _Month);
	}

	static short IndexDayInWeek(short Year, short Month, short Day)
	{
		short A = 0, Y = 0, M = 0, D = 0;

		A = (14 - Month) / 12;
		Y = (Year - A);
		M = (Month + 12 * A - 2);

		D = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + (31 * M / 12)) % 7;
		return D;
	}
	short IndexDayInWeek()
	{
		return IndexDayInWeek(_Year, _Month, _Day);
	}

	static string PrintDayName(short IndexDayInWeek)
	{
		string ArrDayName[] = { "Sunday","Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return ArrDayName[IndexDayInWeek];
	}
	string PrintDayName()
	{
		return PrintDayName(IndexDayInWeek());
	}

	static string MonthName(short IndexMonthNInYear)
	{
		string ArrMonthName[] = { "", "January","February","March","April","May","June","July","August","September","October","November","December" };
		return ArrMonthName[IndexMonthNInYear];
	}
	string MonthName()
	{
		return MonthName(_Month);
	}

	static void PrintMonthCalnder(short Year, short Month)
	{
		cout << "---------------------------" << MonthName(Month) << "---------------------------\n\n";
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int Currnt = IndexDayInWeek(Year, Month, 1);
		short Number_Day_Month = NumberOfDayInMonth(Year, Month);
		short A;
		for (A = 0; A < Currnt; A++)
			printf("     ");
		for (short i = 1; i <= Number_Day_Month; i++)
		{
			printf("%5d", i);

			if (++A == 7)
			{
				A = 0;
				printf("\n");
			}
		}
		cout << "\n---------------------------------------------------------------\n";
	}
	void PrintMonthCalnder()
	{
		PrintMonthCalnder(_Year, _Month);
	}

	static void PrintYearCalnder(short Year)
	{
		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalnder(Year, i);
			cout << "\n";
		}
	}
	void PrintYearCalnder()
	{
		PrintYearCalnder(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
	{
		short DaysFromTheBeginningOfMonth = 0;
		for (short i = 1; i < Month; i++)
		{
			DaysFromTheBeginningOfMonth += NumberOfDayInMonth(Year, i);
		}
		return DaysFromTheBeginningOfMonth += Day;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		short DaysFromTheBeginningOfMonth = 0;
		for (short i = 1; i < _Month; i++)
		{
			DaysFromTheBeginningOfMonth += NumberOfDayInMonth(_Year, i);
		}
		return DaysFromTheBeginningOfMonth += _Day;

	}

	void DateAddDayse(short AddingDay, clsDate Date)
	{
		short ReminingDays = AddingDay + NumberOfDaysFromTheBeginingOfTheYear();
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(_Year, _Month);
			if (ReminingDays > MonthDays)
			{
				ReminingDays -= MonthDays;
				Date.Month++;

				if (_Month > 12)
				{
					_Year++;
					_Month = 1;
				}
			}
			else
			{
				_Day = ReminingDays;
				break;
			}
		}
	}

	static clsDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
	{
		short ReminingDays = DaysOrderInYear;
		short MonthDays = 0;

		clsDate Date;
		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDayInMonth(Year, Date._Month);
			if (ReminingDays > MonthDays)
			{
				ReminingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = ReminingDays;
				break;
			}
		}
		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day) ? true : false;
	}
	bool IsDate1EqualeDate2(clsDate Date2)
	{
		return IsDate1EqualeDate2(*this,Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualeDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLasteDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDayInMonth(Date.Year, Date.Month));
	}
	bool IsLasteDayInMonth()
	{
		return IsLasteDayInMonth(*this);
	}

	static bool IsLasteMonthInYear(clsDate Date)
	{
		return (Date.Month == 12);
	}
	bool IsLasteMonthInYear()
	{
		return IsLasteMonthInYear(*this);
	}

	static clsDate AddOneDay(clsDate & Date)
	{
		if (IsLasteDayInMonth(Date))
		{
			if (IsLasteMonthInYear(Date))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
				return Date;
			}
			Date.Day = 1;
			Date.Month++;
			return Date;
		}
		Date.Day++;
		return Date;
	}
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		short Days = 0;

		if (IsDate1BeforeDate2(Date1, Date2))
		{
			while (IsDate1BeforeDate2(Date1, Date2))
			{
				Days++;
				Date1 = AddOneDay(Date1);
			}
			return IncludeEndDay ? ++Days : Days;
		}
		return (-1) * GetDifferenceInDays(Date2, Date1);
	}
	int GetDifferenceInDays(clsDate Date2)
	{
		return GetDifferenceInDays(*this, Date2);
	}

	static clsDate IncreaseDataByOneWeek(clsDate & Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncreaseDataByOneWeek()
	{
		IncreaseDataByOneWeek(*this);
	}

	static clsDate IncreaseDataByXWeek(short Weeks, clsDate &Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDataByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDataByXWeek(short Weeks)
	{
		IncreaseDataByXWeek(Weeks, *this);
	}

	static clsDate IncreaseDataByOneMonth(clsDate & Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}
		short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void IncreaseDataByOneMonth()
	{
		IncreaseDataByOneMonth(*this);
	}

	static clsDate IncreaseDataByXMonth(short Month, clsDate &Date)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = IncreaseDataByOneMonth(Date);
		}

		return Date;
	}
	void IncreaseDataByXMonth(short Month)
	{
		IncreaseDataByXMonth(Month, *this);
	}

	static clsDate IncreaseDataByOneYear(clsDate &Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDataByOneYear()
	{
		IncreaseDataByOneYear(*this);
	}

	static clsDate IncreaseDataByXYear(short Years, clsDate& Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDataByOneYear(Date);
		}
		return Date;
	}
	void IncreaseDataByXYear(short Years)
	{
		IncreaseDataByXYear(Years, *this);
	}

	static clsDate IncreaseDataByXYearFaster(short Years, clsDate& Date)
	{
		Date.Year += Years;

		return Date;
	}
	void IncreaseDataByXYearFaster(short Years)
	{
		IncreaseDataByXYearFaster(Years, *this);
	}

	static clsDate IncreaseDataByOneDecade(clsDate &Date)
	{
		Date.Year += 10;
		return Date;
	}
	void IncreaseDataByOneDecade()
	{
		IncreaseDataByOneDecade(*this);
	}

	static clsDate IncreaseDataByXDecade(short Decade, clsDate& Date)
	{
		for (short i = 1; i <= Decade; i++)
		{
			Date = IncreaseDataByOneDecade(Date);
		}
		return Date;
	}
	void IncreaseDataByXDecade(short Decade)
	{
		IncreaseDataByXDecade(Decade, *this);
	}

	static clsDate IncreaseDataByXDecadeFaster(short Decade, clsDate& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}
	void IncreaseDataByXDecadeFaster(short Decade)
	{
		IncreaseDataByXDecadeFaster(Decade, *this);
	}

	static clsDate IncreaseDataByOneCentury(clsDate &Date)
	{
		Date.Year += 100;
		return Date;
	}
	void IncreaseDataByOneCentury()
	{
		IncreaseDataByOneCentury(*this);
	}

	static clsDate IncreaseDataByOneMillennium(clsDate & Date)
	{
		Date.Year += 1000;
		return Date;
	}
	void IncreaseDataByOneMillennium()
	{
		IncreaseDataByOneMillennium(*this);
	}

    // Decrease Date Func 

	static clsDate DecreaseDateByOneDay(clsDate &Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
				return Date;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDayInMonth(Date.Year, Date.Month);
				return Date;
			}
		}
		Date.Day--;
		return Date;
	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, short Days)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(*this, Days);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXeWeek(clsDate& Date, short Week)
	{
		for (short i = 1; i <= Week; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXeWeek(short Week)
	{
		DecreaseDateByXeWeek(*this, Week);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
			return Date;
		}
		else
		{
			Date.Month--;
			return Date;
		}
		short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(Date.Year, Date.Month);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonth(clsDate &Date, short Month)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonth(short Month)
	{
		DecreaseDateByXMonth(*this, Month);
	}

	static clsDate DecreaseDataByOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreaseDataByOneYear()
	{
		DecreaseDataByOneYear(*this);
	}

	static clsDate DecreaseDataByXYear(clsDate& Date, short Year)
	{
		for (short i = 1; i <= Year; i++)
		{
			Date = DecreaseDataByOneYear(Date);
		}
		return Date;
	}
	void DecreaseDataByXYear(short Year)
	{
		DecreaseDataByXYear(*this, Year);
	}

	static clsDate DecreaseDataByXYearFaster(clsDate& Date, short Year)
	{
		Date.Year -= Year;
		return Date;
	}
	void DecreaseDataByXYearFaster(short Year)
	{
		DecreaseDataByXYearFaster(*this, Year);
	}

	static clsDate DecreaseDataByOneDecade(clsDate& Date)
	{
		Date.Year -= 10;
		return Date;
	}
	void DecreaseDataByOneDecade()
	{
		DecreaseDataByOneDecade(*this);
	}

	static clsDate DecreaseDataByXDecade(clsDate& Date, short Decade)
	{
		for (short i = 1; i <= Decade; i++)
		{
			Date = DecreaseDataByOneDecade(Date);
		}
		return Date;
	}
	void DecreaseDataByXDecade(short Decade)
	{
		DecreaseDataByXDecade(*this,Decade);
	}

	static clsDate DecreaseDataByXDecadeFaster(clsDate& Date, short Decade)
	{
		Date.Year -= Decade * 10;
		return Date;
	}
	void DecreaseDataByXDecadeFaster(short Decade)
	{
		DecreaseDataByXDecadeFaster(*this, Decade);
	}

	static clsDate DecreaseDataByOneCentury(clsDate& Date)
	{
		Date.Year -= 100;
		return Date;
	}
	void DecreaseDataByOneCentury()
	{
		DecreaseDataByOneCentury(*this);
	}

	static clsDate DecreaseDataByOneMillennium(clsDate& Date)
	{
		Date.Year -= 1000;
		return Date;
	}
	void DecreaseDataByOneMillennium()
	{
		DecreaseDataByOneMillennium(*this);
	}


	static short IsEndOfWeek(clsDate& Date)
	{
		return IndexDayInWeek(Date.Year, Date.Month, Date.Day) == 6;
	}
	bool IsEndOfWeek()
	{
		IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate& Date)
	{
		short IndexDayWeek = IndexDayInWeek(Date.Year, Date.Month, Date.Day);

		return(IndexDayWeek == 5 || IndexDayWeek == 6);
	}
	bool IsWeekEnd()
	{
		IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate& Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate& Date)
	{
		return 6 - IndexDayInWeek(Date.Year, Date.Month, Date.Day);
	}
	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate& Date)
	{
		clsDate EndManth;
		EndManth.Day = NumberOfDayInMonth(Date.Year, Date.Month);
		EndManth.Month = Date.Month;
		EndManth.Year = Date.Year;
		return GetDifferenceInDays(Date, EndManth, true);
	}
	short DaysUntilEndOfMonth()
	{
		return  DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate& Date)
	{
		clsDate EndYear;
		EndYear.Day = 31;
		EndYear.Month = 12;
		EndYear.Year = Date.Year;
		return 	 GetDifferenceInDays(Date, EndYear, true);
	}
	short DaysUntilEndOfYear()
	{
		return  DaysUntilEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;
			DateFrom = AddOneDay(DateFrom);
		}
		return Days;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDays(DateFrom, DateTo);
	}

	enum enCompareCase { After = 1, Before = -1, Equale = 0 };

	static enCompareCase CompareDate(clsDate Date1, clsDate Date2)
	{
		return (IsDate1AfterDate2(Date1, Date2)) ? enCompareCase::After : ((IsDate1BeforeDate2(Date1, Date2)) ? enCompareCase::Before : enCompareCase::Equale);
	}

	 enCompareCase CompareDates(clsDate Date2)
	{
		return CompareDate(*this, Date2);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + ":" + to_string(Date._Month) + ":" + to_string(Date._Year);
	}
	 string DateToString()
	{
		return DateToString(*this);
	}

	 static bool isValidateDate(clsDate Date)
	 {
		 short NumberDaysMonth = NumberOfDayInMonth(Date.Year, Date.Month);
		 return ((Date.Day >= 1 && Date.Day <= NumberDaysMonth) && (Date.Month >= 1 && Date.Month <= 12) && (Date.Year >= 1) ? true : false);
	 }


	 static string GetSystemTimeDateString()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);
		 string Tiem;

		 short Hours, Minute, Second;
		 Hours = now->tm_hour ;
		 Minute = now->tm_min;
		 Second = now->tm_sec;

		 Tiem += DateToString(clsDate());
		 Tiem += " - ";
		 Tiem += DateToString(clsDate(Hours, Minute, Second));

		 return Tiem;

	 }



	 __declspec(property(get = TimeInDetail)) string SystemTimeDateString;

};