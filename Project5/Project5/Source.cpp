#include <iostream>
#include "Money.h"
#include "CreditCard.h"
#include "Wallet.h"
#include "Date.h"
#include "RASHODY.h"


using namespace std;

int main()
{
    //установка русского языка в консоли
    setlocale(LC_ALL, "ru");

    Money CASH[10];
    CreditCard Cards[10];
    Wallet Wallets[10];
    int k = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    int day = CASH[num1].GetDay();

    do {
        system("cls");
        cout << "Главное меню (текущий день " << day << ")" << endl;
        cout << "1 : Управление кошельками/картами" << endl;
        cout << "2 : Внести затраты" << endl;
        cout << "3 : Следующий день" << endl;
        cout << "4 : Сформировать отчеты" << endl;
        cout << "5 : Сохранить отчеты в файл" << endl;
        cout << "6 : Сформировать рейтинг ТОП затрат и категорий" << endl;
        cout << "7 : Сохранить рейтинг ТОП затрат и категорий в файл" << endl;
        cout << "0 : Выход" << endl;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            int l = 0;
            system("cls");
            cout << "Выберите подпункт меню" << endl;
            cout << "1 : Задать номер для работы" << endl;
            cout << "2 : Загрузить данные(кошелек/карта)" << endl;
            cout << "3 : Удалить данные(кошелек/карта)" << endl;
            cout << "4 : Пополнить баланс" << endl;
            cin >> l;
            switch (l)
            {
            case 1:
            {
                system("cls");
                int g = 0;
                cout << "Выберите подпункт меню" << endl;
                cout << "1 : Работа с наличными" << endl;
                cout << "2 : Работа с картами" << endl;
                cout << "3 : Работа с кошельками" << endl;
                cin >> g;
                if (g == 1) {
                    cout << "Задайте номер наличных(0-9)" << endl;
                    cin >> num1;
                }
                if (g == 2) {
                    cout << "Задайте номер карты(0-9)" << endl;
                    cin >> num2;
                }
                if (g == 3) {
                    cout << "Задайте номер кошелька(0-9)" << endl;
                    cin >> num3;
                }
                break;
            }
            case 2:
            {
                system("cls");
                CASH[num1].LOAD();
                Cards[num2].LOAD();
                Wallets[num3].LOAD();
                break;
            }
            case 3:
            {
                system("cls");
                int g = 0;
                cout << "Выберите подпункт меню" << endl;
                cout << "1 : Работа с наличными" << endl;
                cout << "2 : Работа с картами" << endl;
                cout << "3 : Работа с кошельками" << endl;
                cin >> g;
                int num = 0;
                cout << "Задайте номер для удаления" << endl;
                cin >> num;
                if (g == 1)
                    CASH[num].Clear();
                if (g == 2)
                    Cards[num].Clear();
                if (g == 3)
                    Wallets[num].Clear();
                break;
            }
            case 4:
            {
                system("cls");
                int g = 0;
                cout << "Выберите подпункт меню" << endl;
                cout << "1 : Работа с наличными" << endl;
                cout << "2 : Работа с картами" << endl;
                cout << "3 : Работа с кошельками" << endl;
                cin >> g;
                double sum = 0;
                cout << "На какую сумму пополнить счет" << endl;
                cin >> sum;
                if (g == 1)
                    CASH[num1].setBalance(sum);
                if (g == 2)
                    Cards[num2].setBalance(sum);
                if (g == 3)
                    Wallets[num3].setBalance(sum);
            }
            default:
                break;
            }


            break;
        }
        case 2:
        {
            system("cls");
            int d, w, m;
            string t, c;
            double s;
            cout << "Введите день: ";
            cin >> d;
            cout << "Введите неделю: ";
            cin >> w;
            cout << "Введите месяц: ";
            cin >> m;
            cout << "Введите тип (кошелек/карта): ";
            cin >> t;
            cout << "Введите категорию: ";
            cin >> c;
            cout << "Введите потраченую суму: ";
            cin >> s;

            CASH[num1].Add(d, w, m, t, c, s);
            if (c == "карта")
                Cards[num2].Add(d, w, m, t, c, s);
            else
                Wallets[num3].Add(d, w, m, t, c, s);
            break;
        }
        case 3:
        {
            system("cls");
            day++;
            break;
        }
        case 4:
        {
            system("cls");
            CASH[num1].Otchet();
            break;
        }
        case 5:
        {
            system("cls");
            CASH[num1].SaveOtchet();
            break;
        }
        case 6:
        {
            system("cls");
            string cat;
            cout << "Введите название категории" << endl;
            cin >> cat;
            cout << "ТОП-3 затрат:" << endl;
            CASH[num1].RaitingTraty();
            cout << "ТОП-3 затрат категории:" << endl;
            CASH[num1].RaitingTratyCategory(cat);
            break;
        }
        case 7:
        {
            system("cls");
            CASH[num1].SaveRaiting();
            break;
        }
        default:
            break;
        }

    } while (k != 0);

    return 0;
}