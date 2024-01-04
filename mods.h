#pragma once
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141593
#include <stdio.h>
#include <locale.h> 
#include <iostream>
#include <conio.h> 
#include <math.h> 
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>
#include <iomanip>

#include "attestat.h"
#include "student.h"
#include "clas.h"
#include "school.h"




void cl() { // �-� �������, ������ ����� �������
    printf("\n\n������� ����� �������, ����� ����������...");
    _getch();
    system("cls");
}

void cl_ogl() { //�-� ������ ����������
    string ogl[] = {
        "�����",
        "���������� ��������",
        "������� ���� ����������"
    };
    cout.setf(ios::left);
    cout.width(25);
    cout << ogl[0];
    for (int i = 1; i < 3; i++) {
        cout.setf(ios::left);
        cout.width(25);
        cout << ogl[i];
    }
    cout << endl;
}

void st_ogl() { //�-� ������ ����������
    string ogl[] = {
        "���",
        "����������",
        "�������",
        "������� ����",
        "������� ���� ����������"
    };
    printf("\n");
    for (int i = 0; i < 5; i++) {
        cout.setf(ios::left);
        cout.width(25);
        cout << ogl[i];
    }
    cout << endl;
}

void menu() {
    string razdel[] = {
        "�����",
        "����������",
        "��������",
        "��������������",
        "���������� ������",
        "������ ��� - �� �������",
        "����� �� ���������"
    };
    for (int i = 0; i < 7; i++) {
        cout << i+1<< ")" << razdel[i]<<endl;
    }
    cout << endl;
}
void red_avg(School* scl, int n, int i) {
    float s = 0;
    (*scl).cls[n].stt[i].att.setAvg();
    for (int j = 0; j < (*scl).cls[n].getCount(); j++) {
        s += float((*scl).cls[n].stt[j].att.getAvg());
    }
    (*scl).cls[n].setAvg(s / float((*scl).cls[n].getCount()));
}

void vivod_scl(School* scl, int n_class) {
    cl_ogl();
    for (int i = 0; i < n_class; i++) {
        cout.setf(ios::right);
        cout.width(4);
        cout << (*scl).cls[i].getNum();
        cout.width(1);
        cout << (*scl).cls[i].getB();
        printf("%24d %24.2f", (*scl).cls[i].getCount(), (*scl).cls[i].getAvg());
        cout << endl;
    }
}
void vivod_cls(School* scl, int i) {
    st_ogl();

    for (int j = 0; j < (*scl).cls[i].getCount(); j++) {
        cout.setf(ios::right);
        printf("%d)", j + 1);
        cout.width(24);
        cout << *(*scl).cls[i].stt[j].getFio();
        printf("%24d %24d %24d %22.2f", (*scl).cls[i].stt[j].att.getMath(), (*scl).cls[i].stt[j].att.getHistory(), (*scl).cls[i].stt[j].att.getRussian(), (*scl).cls[i].stt[j].att.getAvg());
        cout << endl;
    }

}
void vivod(School* scl) {
    if ((*scl).getN_cl() > 0) {
        int v, c;
        do {
            printf("1)����� ���� �������\n2)����� ������� ���������� ������\n");
            printf("������� ����� ����: ");
            v = scanf("%d", &c);
            while (getchar() != '\n');
            system("cls");
        } while (c > 2 || c < 1 || v < 1);
        switch (c)
        {
        case 2: {
            int num, p = 0;
            string b;
            do {
                printf("������� ����� ������ (1-11): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
                system("cls");
            } while (num > 11 || num < 1 || v < 1);

            printf("������� ����� ������: ");
            cin >> setw(1) >> b;
            for (int i = 0; i < (*scl).getN_cl(); i++) {
                if ((*scl).cls[i].getB() == b && num == (*scl).cls[i].getNum()) {
                    vivod_cls(scl, i);
                    p = 1;
                    break;
                }
            }
            if (p == 0) {
                printf("������ ������ ���");

            }
            break;
        }
        case 1: {
            vivod_scl(scl, (*scl).getN_cl());
            break;
        }

        default:
            break;
        }
    }
    else
        printf("���� ������� �����.\n");
    cl();

}


int create_class(School* scl) {
    int st, s = 0, n = (*scl).getN_cl(), c, num, v;
    string b,f;
    do {
        printf("1)�������� �����\n2)�������� ������� � �����\n");
        printf("������� ����� ����: ");
        v = scanf("%d", &c);
        while (getchar() != '\n');
        system("cls");
    } while (c > 2 || c < 1 || v < 1);

    switch (c) {
    case 1: {
        if (n == 5) {
            printf("����� ��� ������ ������ ���");
            cl();
            return 0;
        }

        do {
            printf("������� ����� ������ (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("������� ����� ������: ");
        cin >> setw(1) >> b;

        do {
            printf("�������, ������� �������� ������ ��������: ");
            v = scanf("%d", &st);
            while (getchar() != '\n');
        } while (st < 1 || v < 1 || st > 30);
        (*scl).cls[n].setB(b);
        (*scl).cls[n].setNum(num);
        (*scl).cls[n].setCount(st);
        (*scl).setN_cl((*scl).getN_cl() + 1);
        for (int i = 0; i < st; i++) {
            printf("������ %d:\n", i + 1);
            printf("������� ���: ");
            cin >> setw(25) >> f;
            (*scl).cls[n].stt[i].setFio(f);

            do {
                printf("������� ���������� �� ���������� (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setMath(num);
            s += num;

            do {
                printf("������� ���������� �� ������� (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setHistory(num);
            s += num;
            do {
                printf("������� ���������� �� ������� (2-5): ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
            } while (num > 5 || num < 2 || v < 1);
            (*scl).cls[n].stt[i].att.setRussian(num);
            s += num;
            (*scl).cls[n].stt[i].att.setAvg();
        }
        (*scl).cls[n].setAvg(float(s) / (float((*scl).cls[n].getCount()) * 3.f));
        cl();
        break;
    }
    case 2: {
        c = 0;
        if (n < 1) {
            printf("���� ������� �����.\n");
            cl();
            return 0;
        }
        do {
            printf("������� ����� ������ (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("������� ����� ������: ");
        cin >> setw(1) >> b;
        for (int i = 0; i < n; i++) {
            if ((*scl).cls[i].getB() == b && num == (*scl).cls[i].getNum()) {
                if ((*scl).cls[i].getCount() == 30) {
                    printf("����� ��� �������� ������ ���");
                    cl();
                    return 0;
                }
                printf("������� ���: ");
                cin >> setw(25) >> f;
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].setFio(f);

                do {
                    printf("������� ���������� �� ���������� (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setMath(num);


                do {
                    printf("������� ���������� �� ������� (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setHistory(num);

                do {
                    printf("������� ���������� �� ������� (2-5): ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                } while (num > 5 || num < 2 || v < 1);
                (*scl).cls[i].stt[(*scl).cls[i].getCount()].att.setRussian(num);

                (*scl).cls[i].setCount((*scl).cls[i].getCount() + 1);
                red_avg(scl, i, (*scl).cls[i].getCount() - 1);

                c = 1;
            }
        }
        if (c == 0)
            printf("������ ������ ���");
        cl();
        break;

    }
    default:
        break;
    }
}


void red_class(School* scl) {
    string b,f;
    int v, num, n = (*scl).getN_cl(), p = 0, att;

    do {
        printf("������� ����� ������ (1-11): ");
        v = scanf("%d", &num);
        while (getchar() != '\n');
        system("cls");
    } while (num > 11 || num < 1 || v < 1);

    printf("������� ����� ������: ");
    cin >> setw(1) >> b;

    for (int i = 0; i < n; i++) {
        if ((*scl).cls[i].getB() == b && num == (*scl).cls[i].getNum()) {

            do {
                vivod_cls(scl, i);
                printf("������� ����� �������, ���������� �������� ������ ���������������: ");
                v = scanf("%d", &num);
                while (getchar() != '\n');
                system("cls");
            } while (num - 1 > (*scl).cls[i].getCount() || num < 1 || v < 1);

            do {
                vivod_cls(scl, i);
                printf("������� ����� ������, ������� ������ ���������������: ");
                v = scanf("%d", &p);
                while (getchar() != '\n');
                system("cls");
            } while (p > 4 || p < 1 || v < 1);

            switch (p) {
            case 1: {
                printf("������� ����� ���: ");
                cin >> setw(25) >> f;
                (*scl).cls[i].stt[num - 1].setFio(f);
                break;
            }
            case 2: {
                do {
                    printf("������� ����� ���������� �� ���������� (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setMath(att);
                red_avg(scl, i, num - 1);
                break;
            }
            case 3: {
                do {
                    printf("������� ����� ���������� �� ������� (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setHistory(att);
                red_avg(scl, i, num - 1);
                break;
            }
            case 4: {
                do {
                    printf("������� ����� ���������� �� ������� (2-5): ");
                    v = scanf("%d", &att);
                    while (getchar() != '\n');
                } while (att > 5 || att < 2 || v < 1);
                (*scl).cls[i].stt[num - 1].att.setRussian(att);
                red_avg(scl, i, num - 1);
                break;
            }
            default:
                break;
            }
            p = 1;
            break;
        }

    }
    if (p == 0) {
        printf("������ ������ ���");
        cl();
    }

}
void del(School* scl) {
    string b,f;
    int v, num, n = (*scl).getN_cl(), p = 0, att;
    do {

        printf("1)������� �����\n2)������� �������\n������� ����� ������, �� �������� ����� ����������� ��������: ");
        v = scanf("%d", &p);
        while (getchar() != '\n');
        system("cls");
    } while (p > 2 || p < 1 || v < 1);

    switch (p) {

    case 1: {
        p = 0;
        do {
            printf("������� ����� ������ (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("������� ����� ������: ");
        cin >> setw(1) >> b;

        for (int i = 0; i < n; i++) { 
            if ((*scl).cls[i].getB() == b && num == (*scl).cls[i].getNum()) {
                for (int j = i; j < n; j++) {
                    (*scl).cls[j] = (*scl).cls[j + 1];
                }
                (*scl).setN_cl((*scl).getN_cl() - 1);
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("������ ������ ���");
            cl();
        }
        break;
    }
    case 2: {
        p = 0;
        do {
            printf("������� ����� ������ (1-11): ");
            v = scanf("%d", &num);
            while (getchar() != '\n');
        } while (num > 11 || num < 1 || v < 1);

        printf("������� ����� ������: ");
        cin >> setw(1) >> b;

        for (int i = 0; i < n; i++) {
            if ((*scl).cls[i].getB() == b && num == (*scl).cls[i].getNum()) {
                do {
                    vivod_cls(scl, i);
                    printf("������� ����� �������, ���������� �������� ������ �������: ");
                    v = scanf("%d", &num);
                    while (getchar() != '\n');
                    system("cls");
                } while (num - 1 > (*scl).cls[i].getCount() || num < 1 || v < 1);
                for (int j = num - 1; j < (*scl).cls[i].getCount(); j++) {
                    (*scl).cls[i].stt[j] = (*scl).cls[i].stt[j + 1];
                }
                (*scl).cls[i].setCount((*scl).cls[i].getCount() - 1);
                if ((*scl).cls[i].getCount() == 0) {
                    for (int j = i; j < n; j++) {
                        (*scl).cls[j] = (*scl).cls[j + 1];
                    }
                    (*scl).setN_cl((*scl).getN_cl() - 1);
                }
                p = 1;
                break;
            }

        }
        if (p == 0) {
            printf("������ ������ ���");
            cl();
        }
        break;
    }
    default:
        break;
    }
}
int merge(School *scl) {
    if ((*scl).getN_cl() > 1) {
        string b1, b2;
        int p = 0, num1, num2, v, n = (*scl).getN_cl();
        do {
            printf("������� ����� ������ ������� �������� (1-11): ");
            v = scanf("%d", &num1);
            while (getchar() != '\n');
        } while (num1 > 11 || num1 < 1 || v < 1);

        printf("������� ����� ����� ������: ");
        cin >> setw(1) >> b1;
        
        for (int i = 0; i < n; i++) {
            if ((*scl).cls[i].getB() == b1 && num1 == (*scl).cls[i].getNum()) {
                do {
                    printf("������� ����� ������ ������� ����� (1-11): ");
                    v = scanf("%d", &num2);
                    while (getchar() != '\n');
                } while (num2 > 11 || num2 < 1 || v < 1);

                printf("������� ����� ����� ������: ");
                cin >> setw(1) >> b2;
                for (int j = 0; j < n; j++) {
                    if ((*scl).cls[j].getB() == b2 && num2 == (*scl).cls[j].getNum()) {
                        if ((*scl).cls[j].getCount() + (*scl).cls[i].getCount() <= 30) {
                            (*scl).cls[i] + (*scl).cls[j];
                            red_avg(scl, i, (*scl).cls[i].getCount());
                            for (int k = j; k < n; k++) {
                                (*scl).cls[k] = (*scl).cls[k + 1];
                            }
                            (*scl).setN_cl((*scl).getN_cl() - 1);
                            p = 1;
                        }
                        else {
                            printf("���� � ������ ������������ ��� �����������");
                            cl();
                            return 0;
                        }
                    }
                }
                
                if (p == 0) {
                    printf("������ ������ ���");
                    cl();
                }
                return 0;
            }

        }
        if (p == 0) {
            printf("������ ������ ���");
            cl();
        }
    }
    else {
        printf("��� ������� ��� �����������");
        cl();
        return 0;
    }
}
