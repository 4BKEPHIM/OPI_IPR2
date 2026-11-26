// DateLogic.cpp - функции для работы с датами
#include "DateLogic.h"

bool IsLeapYear(int year)
{
    // високосный, если делится на 4 и не делится на 100, или делится на 400
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

int DaysInMonth(int month, int year)
{
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && IsLeapYear(year))
        return 29;

    return days[month - 1];
}

int GetDayOfWeek(int day, int month, int year)
{
    // в формуле Зеллера январь и февраль - это 13 и 14 месяц прошлого года
    if (month < 3)
    {
        month = month + 12;
        year = year - 1;
    }

    int k = year % 100; // год в веке
    int j = year / 100; // век

    int h = day + 13 * (month + 1) / 5;
    h = h + k + k / 4;
    h = (h + j / 4 + 5 * j) % 7;

    // h: 0 - суббота, 1 - воскресенье, 2 - понедельник ...
    // переделываем, чтобы было 1 - понедельник ... 7 - воскресенье
    int w = (h + 5) % 7 + 1;
    return w;
}

int DayOfYear(int day, int month, int year)
{
    int n = day;
    for (int i = 1; i < month; i++)
        n = n + DaysInMonth(i, year);
    return n;
}
