#pragma once

class Date
{
public:
    int day;
    int week;
    int month;

    //�����������
    Date(int d = 0, int w = 0, int m = 0) {
        day = d;
        week = w;
        month = m;
    };
    //����������� �����������
    Date(const Date& other) {
        this->day = other.day;
        this->month = other.month;
        this->week = other.week;
    }
    //��������� ���
    void setDay(int d) {
        day = d;
    }
    //��������� ������
    void setWeek(int w) {
        week = w;
    }
    //��������� ������
    void setMonth(int m) {
        month = m;
    }
    //������ ���
    int getDay() {
        return day;
    }
    //������ ������
    int getWeek() {
        return week;
    }
    //������ ������
    int getMonth() {
        return month;
    }
    //����������
    ~Date() {};
};
