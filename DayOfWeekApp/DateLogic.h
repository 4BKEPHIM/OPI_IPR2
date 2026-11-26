// DateLogic.h - функции для работы с датами
#pragma once

// високосный ли год
bool IsLeapYear(int year);

// сколько дней в месяце
int DaysInMonth(int month, int year);

// день недели по формуле Зеллера (1 - понедельник ... 7 - воскресенье)
int GetDayOfWeek(int day, int month, int year);

// номер дня в году
int DayOfYear(int day, int month, int year);
