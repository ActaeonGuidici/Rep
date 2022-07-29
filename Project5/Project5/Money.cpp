#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include "Money.h"
#include "Date.h"
#include "RASHODY.h"

using namespace std;

void Money::LOAD() {
    string filename;
    cout << "Введите имя файла" << endl;
    cin >> filename;

    string line;
    R.clear();

    ifstream in(filename); // окрываем файл для чтения
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
    in.close();     // закрываем файл
}

void Money::Add(int d = 0, int w = 0, int m = 0, string t = "", string c = "", double s = 0) {

    //добавления в массив
    RASHODY T(d, w, m, t, c, s);
    R.push_back(T);
    cout << "Успешно добавлено" << endl;
}

void Money::SaveOtchet() {
    string filename;
    cout << "Введите имя файла" << endl;
    cin >> filename;
    ofstream out;			// поток для записи
    out.open(filename); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < R.size(); ++i)
            out << R[i].getDay() << " " << R[i].week << " " << R[i].month << " " << R[i].type << " " << R[i].category << " " << R[i].spend << endl;
    }
}

void Money::SaveRaiting() {

    string filename;
    cout << "Введите имя файла" << endl;
    cin >> filename;
    ofstream out;			// поток для записи
    out.open(filename); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < Rait.size(); ++i)
            out << Rait[i].day << " " << Rait[i].week << " " << Rait[i].month << " " << Rait[i].type << " " << Rait[i].category << " " << Rait[i].spend << endl;
    }
}

void Money::RaitingTraty() {
    Rait.clear();
    Rait = R;
    //Сортировка по убыванию расходов
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
    //Вывод на консоль
    for (int i = 0; i < min; ++i)
        cout << "День: " << Rait[i].day << "\tНеделя: " << Rait[i].week << "\tМесяц: " << Rait[i].month << "\tТип: " << Rait[i].type << "\tКатегория: " << Rait[i].category << "\tПотрачено: " << Rait[i].spend << endl;
}

void Money::RaitingTratyCategory(string cat) {
    Rait.clear();
    for (int i = 0; i < R.size(); ++i)
        if (R[i].category == cat)
            Rait.push_back(R[i]);
    //Сортировка по убыванию расходов
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
    //Вывод на консоль
    for (int i = 0; i < min; ++i)
        cout << "День: " << Rait[i].day << "\tНеделя: " << Rait[i].week << "\tМесяц: " << Rait[i].month << "\tТип: " << Rait[i].type << "\tКатегория: " << Rait[i].category << "\tПотрачено: " << Rait[i].spend << endl;
}