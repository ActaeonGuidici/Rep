#pragma once
#include <iostream>
#include <vector>
#include "Money.h"
#include "RASHODY.h"

using namespace std;

class Wallet : public Money
{
private:
    //баланс
    double balance = 0;
    //массив для хранения данных
    vector<RASHODY> R;

public:
    //конструктор
    Wallet(int _balance = 0) {
        balance = _balance;
    };
    //конструктор копирование
    Wallet(const Wallet& other) {
        this->R = other.R;
        this->balance = other.balance;

    }
    //вывод значений массива данных на екран
    void Otchet() override {
        for (int i = 0; i < R.size(); ++i)
            cout << "День: " << R[i].getDay() << "\tНеделя: " << R[i].getWeek() << "\tМесяц: " << R[i].getMonth() << "\tТип: Кошелек\tКатегория: " << R[i].getCategory() << "\tПотрачено: " << R[i].getSpend() << endl;
    }
    //установка баланса
    void setBalance(double b) {
        balance += b;
    }
    //взятие баланса
    double getBalance() {
        return balance;
    }
    //дестуктор
    ~Wallet() {};


};