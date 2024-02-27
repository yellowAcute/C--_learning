#if !defined(CALENDAR_h)
#define CALENDAR_h
#include <string>
#include <iostream>
#include <array>
using namespace std;

class Calendar
{
private:
    unsigned year, month, day;
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    array<std::string, 12> month_names{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                       "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    unsigned MonthFromName(const string &str);

    Calendar(const string &date)
    {
        if (date.empty())
        {
            return;
        }
        string delimiters{" ,/"};
        string::size_type month_day_delim_pos = date.find_first_of(delimiters);

        month = MonthFromName(date.substr(0, month_day_delim_pos));
        auto day_year_delim_pos = date.find_first_of(delimiters, month_day_delim_pos + 1);
        day = stoi(date.substr(month_day_delim_pos + 1, day_year_delim_pos));
        year = stoi(date.substr(day_year_delim_pos + 1));
    }

    void print() const;

    Calendar() : year(0), month(0), day(0){};
};



#endif // CALENDAR_h

void Calendar::print() const
{
    cout << month << "-" << day << "-" << year << endl;
}

unsigned Calendar::MonthFromName(const string &str)
{
    if (str.empty())
    {
        return 0;
    }
    if (isdigit(str[0]))
    {
        return stoi(str);
    }

    for (array<string, 12>::size_type i = 0; i != 12; i++)
    {
        if (str.find(month_names[i]) != string::npos)
        {
            return i + 1;
        }
    }
}