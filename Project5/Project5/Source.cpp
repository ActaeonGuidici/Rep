#include <iostream>
#include "Money.h"
#include "CreditCard.h"
#include "Wallet.h"
#include "Date.h"
#include "RASHODY.h"


using namespace std;

int main()
{
    //��������� �������� ����� � �������
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
        cout << "������� ���� (������� ���� " << day << ")" << endl;
        cout << "1 : ���������� ����������/�������" << endl;
        cout << "2 : ������ �������" << endl;
        cout << "3 : ��������� ����" << endl;
        cout << "4 : ������������ ������" << endl;
        cout << "5 : ��������� ������ � ����" << endl;
        cout << "6 : ������������ ������� ��� ������ � ���������" << endl;
        cout << "7 : ��������� ������� ��� ������ � ��������� � ����" << endl;
        cout << "0 : �����" << endl;
        cin >> k;
        switch (k)
        {
        case 1:
        {
            int l = 0;
            system("cls");
            cout << "�������� �������� ����" << endl;
            cout << "1 : ������ ����� ��� ������" << endl;
            cout << "2 : ��������� ������(�������/�����)" << endl;
            cout << "3 : ������� ������(�������/�����)" << endl;
            cout << "4 : ��������� ������" << endl;
            cin >> l;
            switch (l)
            {
            case 1:
            {
                system("cls");
                int g = 0;
                cout << "�������� �������� ����" << endl;
                cout << "1 : ������ � ���������" << endl;
                cout << "2 : ������ � �������" << endl;
                cout << "3 : ������ � ����������" << endl;
                cin >> g;
                if (g == 1) {
                    cout << "������� ����� ��������(0-9)" << endl;
                    cin >> num1;
                }
                if (g == 2) {
                    cout << "������� ����� �����(0-9)" << endl;
                    cin >> num2;
                }
                if (g == 3) {
                    cout << "������� ����� ��������(0-9)" << endl;
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
                cout << "�������� �������� ����" << endl;
                cout << "1 : ������ � ���������" << endl;
                cout << "2 : ������ � �������" << endl;
                cout << "3 : ������ � ����������" << endl;
                cin >> g;
                int num = 0;
                cout << "������� ����� ��� ��������" << endl;
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
                cout << "�������� �������� ����" << endl;
                cout << "1 : ������ � ���������" << endl;
                cout << "2 : ������ � �������" << endl;
                cout << "3 : ������ � ����������" << endl;
                cin >> g;
                double sum = 0;
                cout << "�� ����� ����� ��������� ����" << endl;
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
            cout << "������� ����: ";
            cin >> d;
            cout << "������� ������: ";
            cin >> w;
            cout << "������� �����: ";
            cin >> m;
            cout << "������� ��� (�������/�����): ";
            cin >> t;
            cout << "������� ���������: ";
            cin >> c;
            cout << "������� ���������� ����: ";
            cin >> s;

            CASH[num1].Add(d, w, m, t, c, s);
            if (c == "�����")
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
            cout << "������� �������� ���������" << endl;
            cin >> cat;
            cout << "���-3 ������:" << endl;
            CASH[num1].RaitingTraty();
            cout << "���-3 ������ ���������:" << endl;
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