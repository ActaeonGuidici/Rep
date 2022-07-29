#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class RASHODY : public Date
{
public:
    string category; //��������� ����
    double spend; //���������� �����
    string type; //��� (�������� ��� �������)

    RASHODY(int d = 0, int w = 0, int m = 0, string t = "", string c = "", double s = 0) {
        day = d;
        week = w;
        month = m;
        category = c;
        spend = s;
        type = t;
    };
    //��������� ���������
    void setCategory(string c) {
        category = c;
    }
    //��������� ���������� �����
    void setSpend(double s)
    {
        spend = s;
    }
    //��������� ����
    void setType(string t)
    {
        type = t;
    }
    //������ ���������
    string getCategory() {
        return category;
    }
    //������ �����
    double getSpend() {
        return spend;
    }
    //������ ����
    string getType() {
        return type;
    }
    //���������
    ~RASHODY() {};
};
