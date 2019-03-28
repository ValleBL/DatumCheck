#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Deklaration der Funktionen
bool checkDay(int day); //Legale Tagesangabe (1/31)
bool checkMonth(int month); //Legale Monatsangabe (1/12)
bool checkYear(int year); //Legale Jahresangabe (>= 1582)
bool checkDate(int day, int month, int year);
bool schaltjahr(int year); //Prüfe ob InputJahr Schaltjahr ist
int splitJahrhundert(int year); 
int splitJahrzehnt(int year);
string convertWeekday(int weekday);
//void errorOutput(string ErrorText); //ErrorCode Ausgabe - Wird nicht verwendet

int main() {
    int day, month, year, weekday, month_new, year_new;

    //system("cls");
    cout << "<-- Datumscheck [dd.mm.yyyy]-->" << endl;
    cout << "Gruppe 2: Christoph, Florian, Marco, Stefan, Valentin" << endl << endl;
    
    do
    {
        do
        {
            cout << "Bitte geben Sie einen Tag im Format 'dd' an: ",
            cin >> day;
            if (checkDay(day) == false)
            {
                //errorOutput("Wert nicht zugelassen. (01-31)");
                cout << "> Fehler! Wert nicht zugelassen. (01-31)" << endl;
            }
        }
        while (checkDay(day) == false);

        do
        {
            cout << "Bitte geben Sie einen Monat im Format 'mm' an: ";
            cin >> month;
            if (checkMonth(month) == false)
            {
                //errorOutput("Wert nicht zugelassen. (01-12)");
                cout << "> Fehler! Wert nicht zugelassen. (01-12)" << endl;
            }
        }
        while (checkMonth(month) == false);

        do
        {
            cout << "Bitte geben Sie eine Jahreszahl im Format 'yyyy' an: ";
            cin >> year;
            if (checkYear(year) == false)
            {
                //errorOutput("Wert nicht zugelassen. (Ab 1582)");
                cout << "> Fehler! Wert nicht zugelassen. (Ab 1582)" << endl;
            }
        }
        while (checkYear(year) == false);
        cout << endl;

    if (checkDate(day, month, year) == false)
    {
        system("cls");
        cout << "<-- Datumscheck [dd.mm.yyyy]-->" << endl;
        cout << "Gruppe 2: Stefan, Christoph, Florian, Marco, Valentin" << endl << endl;
        //errorOutput("Ungueltiger Tag im Monat oder gewaehltes Datum vor 15.10.1582");
        cout << "> Fehler! Ungueltiger Tag im Monat oder gewaehltes Datum vor 15.10.1582" << endl;
    }
    } while (checkDate(day, month, year) == false);

    if (month == 1 || month == 2)
    {
        month_new = month + 12;
        year_new = year - 1;
    }
    else
    {
        month_new = month;
        year_new = year;
    }
    weekday = (day + (26 * (month_new + 1)) / 10 + splitJahrzehnt(year_new) + splitJahrzehnt(year_new) / 4 + splitJahrhundert(year_new) / 4 - 2 * splitJahrhundert(year_new)) % 7;
    if (weekday < 0)
    {
        weekday = weekday + 7;
    }

    cout << "> Wochentag von " << day << "." << month << "." << year << " (Schaltjahr: " << schaltjahr(year) << ") ist: " << convertWeekday(weekday);

    return 0;
}
// ENDE Main Funktion
bool checkDate(int day, int month, int year)
{
    int max_day;

    if (month == 2 && schaltjahr(year) == true)
    {
        max_day = 29;
    }
    else if (month == 2 && schaltjahr(year) == false)
    {
        max_day = 28;
    }
    else if (month % 2 == 0)
    {
        max_day = 30;
    }
    else if (month % 2 != 0)
    {
        max_day = 31;
    }
    
    if(day >= 1 && day <= max_day && month >= 1 && month <= 12)
    {
        return true;
    }
    else if (day <= 15 && month <= 10 && year <= 1582)
    {
        return false;
    }
    else
    {
        return false;
    }
}

bool checkDay(int day)
{
    if(day >= 1 && day <= 31)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkMonth(int month)
{
    if(month >= 1 && month <= 12)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkYear(int year)
{
    if(year >= 1582)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool schaltjahr(int year)
{
    if (year % 4 != 0)
	{
		return false;
	}
	else if ((year % 4 == 0) && (year % 100 != 0))
	{
		return true;
	}
	else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
	{
		return true;
	}
    return false;
}

int splitJahrzehnt(int year)
{
    int jahrzehnt;
    jahrzehnt = year % 100;
    return jahrzehnt;
}

int splitJahrhundert(int year)
{
    int jahrhundert;
    jahrhundert = (year / 100) % 100;
    return jahrhundert;
}

string convertWeekday(int weekday)
{
    string weekdayText;
    if (weekday == 0)
    {
        weekdayText = "Samstag";
    }
    else if (weekday == 1)
    {
        weekdayText = "Sonntag";
    }
    else if (weekday == 2)
    {
        weekdayText = "Montag";
    }
    else if (weekday == 3)
    {
        weekdayText = "Dienstag";
    }
    else if (weekday == 4)
    {
        weekdayText = "Mittwoch";
    }
    else if (weekday == 5)
    {
        weekdayText = "Donnerstag";
    }
    else if (weekday == 6)
    {
        weekdayText = "Freitag";
    }
    return weekdayText;
}

void errorOutput(string errorText) //Wird nicht verwendet
{
    cout << "> Fehler: " << errorText << endl;
}