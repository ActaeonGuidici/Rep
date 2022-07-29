#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include "Date.h"
#include "RASHODY.h"
class Money
{
private:
    //������ ��� �������� ������
    vector<RASHODY> R;
    //������ ��� ��������
    vector<RASHODY> Rait;
    //������
    double balance = 0;
public:
    //�����������
    Money() {};

    void LOAD() {
        string filename;
        cout << "������� ��� �����" << endl;
        cin >> filename;

        string line;
        R.clear();

        ifstream in(filename); // �������� ���� ��� ������
        if (in.is_open())
        {
            while (getline(in, line))
            {
                RASHODY tmp(0, 0, 0, "", "", 0);
                string word = "";
                int count = 0;
                for (int i = 0; i < line.size(); ++i)
                {
                    if (line[i] != ' ')
                        word += line[i];
                    else
                    {
                        if (count == 0)
                            tmp.setDay(stoi(word));
                        if (count == 1)
                            tmp.setWeek(stoi(word));
                        if (count == 2)
                            tmp.setMonth(stoi(word));
                        if (count == 3)
                            tmp.setType(word);
                        if (count == 4)
                            tmp.setCategory(word);
                    }
                }
                if (word != "")
                    tmp.setSpend(stod(word));
                R.push_back(tmp);
            }
        }
        in.close();     // ��������� ����
    }

    //������ ���-�� ����
    int GetDay() {
        return R.size();
    }
    //������� ����������
    void Add(int d = 0, int w = 0, int m = 0, string t = "", string c = "", double s = 0) {

        //���������� � ������
        RASHODY T(d, w, m, t, c, s);
        R.push_back(T);
        cout << "������� ���������" << endl;
    }
    //����� �������� ������� ������ �� �����
    virtual void Otchet() {
        for (int i = 0; i < R.size(); ++i)
            cout << "����: " << R[i].getDay() << "\t������: " << R[i].getWeek() << "\t�����: " << R[i].getMonth() << "\t���: " << R[i].getType() << "\t���������: " << R[i].getCategory() << "\t���������: " << R[i].getSpend() << endl;
    }
    //���������� ������
    void SaveOtchet() {
        string filename;
        cout << "������� ��� �����" << endl;
        cin >> filename;
        ofstream out;			// ����� ��� ������
        out.open(filename); // �������� ���� ��� ������
        if (out.is_open())
        {
            for (int i = 0; i < R.size(); ++i)
                out << R[i].getDay() << " " << R[i].week << " " << R[i].month << " " << R[i].type << " " << R[i].category << " " << R[i].spend << endl;
        }
    }
    //���������� ��������
    void SaveRaiting() {

        string filename;
        cout << "������� ��� �����" << endl;
        cin >> filename;
        ofstream out;			// ����� ��� ������
        out.open(filename); // �������� ���� ��� ������
        if (out.is_open())
        {
            for (int i = 0; i < Rait.size(); ++i)
                out << Rait[i].day << " " << Rait[i].week << " " << Rait[i].month << " " << Rait[i].type << " " << Rait[i].category << " " << Rait[i].spend << endl;
        }
    }

    //���������� ��� ��������
    void RaitingTraty() {
        Rait.clear();
        Rait = R;
        //���������� �� �������� ��������
        for (int i = 0; i < Rait.size() - 1; ++i)
            for (int j = i + 1; j < Rait.size(); ++j)
                if (Rait[i].spend < Rait[j].spend)
                {
                    RASHODY tmp = Rait[i];
                    Rait[i] = Rait[j];
                    Rait[j] = tmp;
                }
        int min = Rait.size();
        if (min > 3)
            min = 3;
        //����� �� �������
        for (int i = 0; i < min; ++i)
            cout << "����: " << Rait[i].day << "\t������: " << Rait[i].week << "\t�����: " << Rait[i].month << "\t���: " << Rait[i].type << "\t���������: " << Rait[i].category << "\t���������: " << Rait[i].spend << endl;
    }
    //���������� ��� �������� �� �����������
    void RaitingTratyCategory(string cat) {
        Rait.clear();
        for (int i = 0; i < R.size(); ++i)
            if (R[i].category == cat)
                Rait.push_back(R[i]);
        //���������� �� �������� ��������
        for (int i = 0; i < Rait.size() - 1; ++i)
            for (int j = i + 1; j < Rait.size(); ++j)
                if (Rait[i].spend < Rait[j].spend)
                {
                    RASHODY tmp = Rait[i];
                    Rait[i] = Rait[j];
                    Rait[j] = tmp;
                }
        int min = Rait.size();
        if (min > 3)
            min = 3;
        //����� �� �������
        for (int i = 0; i < min; ++i)
            cout << "����: " << Rait[i].day << "\t������: " << Rait[i].week << "\t�����: " << Rait[i].month << "\t���: " << Rait[i].type << "\t���������: " << Rait[i].category << "\t���������: " << Rait[i].spend << endl;
    }
    //��������� �������
    void setBalance(double b) {
        balance += b;
    }
    //������ �������
    double getBalance() {
        return balance;
    }
    void Clear() {
        R.clear();
        balance = 0;
    }
    //����������
    ~Money() {};
};