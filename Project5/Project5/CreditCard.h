#pragma once
#include <iostream>
#include <vector>
#include "Money.h"
#include "RASHODY.h"

using namespace std;

class CreditCard : public Money
{
private:
    //баланс
    double balance = 0;
    //массив для хранения данных
    vector<RASHODY> R;

public:
    //Конструктор
    CreditCard(int b = 0) {
        balance = b;
    };
    //Конструктор корпирования
    CreditCard(const CreditCard& other) {
        this->R = other.R;
        this->balance = other.balance;
    }
    //вывод значений массива данных на екран
    void Otchet() override {
        for (int i = 0; i < R.size(); ++i)
            cout << "День: " << R[i].getDay() << "\tНеделя: " << R[i].getWeek() << "\tМесяц: " << R[i].getMonth() << "\tТип: Карта\tКатегория: " << R[i].getCategory() << "\tПотрачено: " << R[i].getSpend() << endl;
    }
    //установка баланса
    void setBalance(double b) {
        balance += b;
    }
    //взятие баланса
    double getBalance() {
        return balance;
    }
    //Деструктор
    ~CreditCard() {};
};