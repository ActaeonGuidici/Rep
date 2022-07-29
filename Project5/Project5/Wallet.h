#pragma once
#include <iostream>
#include <vector>
#include "Money.h"
#include "RASHODY.h"

using namespace std;

class Wallet : public Money
{
private:
    //������
    double balance = 0;
    //������ ��� �������� ������
    vector<RASHODY> R;

public:
    //�����������
    Wallet(int _balance = 0) {
        balance = _balance;
    };
    //����������� �����������
    Wallet(const Wallet& other) {
        this->R = other.R;
        this->balance = other.balance;

    }
    //����� �������� ������� ������ �� �����
    void Otchet() override {
        for (int i = 0; i < R.size(); ++i)
            cout << "����: " << R[i].getDay() << "\t������: " << R[i].getWeek() << "\t�����: " << R[i].getMonth() << "\t���: �������\t���������: " << R[i].getCategory() << "\t���������: " << R[i].getSpend() << endl;
    }
    //��������� �������
    void setBalance(double b) {
        balance += b;
    }
    //������ �������
    double getBalance() {
        return balance;
    }
    //���������
    ~Wallet() {};


};