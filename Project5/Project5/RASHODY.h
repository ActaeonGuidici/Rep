#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class RASHODY : public Date
{
public:
    string category; //категория трат
    double spend; //потраченая сумма
    string type; //тип (карточки или кошелек)

    RASHODY(int d = 0, int w = 0, int m = 0, string t = "", string c = "", double s = 0) {
        day = d;
        week = w;
        month = m;
        category = c;
        spend = s;
        type = t;
    };
    //установка категории
    void setCategory(string c) {
        category = c;
    }
    //установка потраченой суммы
    void setSpend(double s)
    {
        spend = s;
    }
    //установка типа
    void setType(string t)
    {
        type = t;
    }
    //взятие категории
    string getCategory() {
        return category;
    }
    //взятие суммы
    double getSpend() {
        return spend;
    }
    //взятие типа
    string getType() {
        return type;
    }
    //дестуктор
    ~RASHODY() {};
};
