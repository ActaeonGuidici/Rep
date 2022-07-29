#pragma once

class Date
{
public:
    int day;
    int week;
    int month;

    //конструктор
    Date(int d = 0, int w = 0, int m = 0) {
        day = d;
        week = w;
        month = m;
    };
    //Конструктор копирования
    Date(const Date& other) {
        this->day = other.day;
        this->month = other.month;
        this->week = other.week;
    }
    //Установка дня
    void setDay(int d) {
        day = d;
    }
    //Установка недели
    void setWeek(int w) {
        week = w;
    }
    //Установка месяца
    void setMonth(int m) {
        month = m;
    }
    //Взятие дня
    int getDay() {
        return day;
    }
    //Взятие недели
    int getWeek() {
        return week;
    }
    //взятие месяца
    int getMonth() {
        return month;
    }
    //Деструктор
    ~Date() {};
};
