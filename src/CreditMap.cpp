#include "CreditMap.h"
#include <string>
#include <iostream>
#include <conio.h>

// ���������� ������ � �����
bool CreditMap::Read(){
    int fdays_no_penalty,fcardNum, fend_mon, fend_year, fwith_day, fwith_mon,fwith_year;
    double fpenalty_proc,fmoney_limit;
    std::string ffamilia;

    std::cout << "������� ����� �����: ";
    std::cin >> fcardNum;
    std::cin.ignore();
    std::cout << "������� ������� ���������: ";
    std::getline(std::cin,ffamilia);
    std::cout << "������� ����� ��������� �������� ����� ( 1 - 12 ) ";
    std::cin >> fend_mon;
    std::cin.ignore();
    std::cout << "������� ��� ��������� �������� ����� ( 2019 - 2030 ): ";
    std::cin >> fend_year;
    std::cin.ignore();
    std::cout << "������� ���� ����������� ������ � �����: ";
    std::cin >> fwith_day;
    std::cin.ignore();
    std::cout << "������� ����� ����������� ������ � �����: ";
    std::cin >> fwith_mon;
    std::cin.ignore();
    std::cout << "������� ��� ����������� ������ � �����: ";
    std::cin >> fwith_year;
    std::cin.ignore();
    std::cout << "������� ���������� ���� ����� ������ ��� ������: ";
    std::cin>>fdays_no_penalty;
    std::cin.ignore();
    std::cout << "������� ������� ������: ";
    std::cin>>fpenalty_proc;
    std::cin.ignore();
    std::cout << "������� ����� ��������� ����� (���-�� ����� �� �����): ";
    std::cin >> fmoney_limit;
    try {this->Init(fcardNum,ffamilia,fend_mon,fend_year,fwith_day,fwith_mon,fwith_year,fdays_no_penalty,fpenalty_proc,fmoney_limit); return true;}
    catch (const char* exc) {std::cout << exc; return false;}
}

// ����� ������ � �����
void CreditMap::Display(){
    std::cout << "����� �����: "<<this->cardNum<<std::endl;
    std::cout << "������� ���������: "<<this->familia<<std::endl;
    std::cout << "���� ��������� �������� (�� ��): "<<this->end_mon<<" "<<this->end_year<<std::endl;
    std::cout << "���� ���������� ������ (�� �� ��): "<<this->with_day<<" "<<this->with_mon<<" "<<this->with_year<<std::endl;
    std::cout << "���������� ���� ����� ������ ��� ������: "<<this->days_no_penalty<<std::endl;
    std::cout << "������� ������: "<<this->penalty_proc<<"%"<<std::endl;
    std::cout << "����� ��������� �����: "<<this->money_limit<<" ������"<<std::endl;
}

// ��������� ���� �������� �����
void CreditMap::end_date_change(){
    std::cout << "�� ������ ������ ����� ������������� ��: "<<this->end_mon<<" "<<this->end_year<<std::endl;
    std::cout << "������� ����� ���� �������� ����� (�� ��): ";
    int fend_mon,fend_year;
    std::cout << "\n������� ����� ��������� �������� ����� ( 1 - 12 ) ";
    std::cin >> fend_mon;
    std::cin.ignore();
    std::cout << "������� ��� ��������� �������� ����� ( 2019 - 2030 ): ";
    std::cin >> fend_year;
    std::cin.ignore();
    // �������� �� ��������� ���� ��� ���� � 5 ��������
    try { this->Init(this->cardNum,this->familia,fend_mon,fend_year,this->with_day,this->with_mon,this->with_year,this->days_no_penalty,this->penalty_proc,this->money_limit);
        std::cout << "�� ������ ������ ����� ������������� ��: "<<this->end_mon<<" "<<this->end_year<<std::endl;}
    catch (const char* exc) {std::cout << exc;}
    }


void CreditMap::days_no_penalty_change(){
    std::cout << "�� ������ ���������� ���� ��� ������: "<<this->days_no_penalty<<std::endl;
    std::cout << "������� ����� ���������� ���� ��� ������: ";
    int days;
    std::cin >> days;
    std::cin.ignore();
    try { this->Init(this->cardNum,this->familia,this->end_mon,this->end_year,this->with_day,this->with_mon,this->with_year,days,this->penalty_proc,this->money_limit);
    std::cout << "�� ������ ���������� ���� ��� ������: "<<this->days_no_penalty<<std::endl; }
    catch (std::string exc) {std::cout << exc;}
}
void CreditMap::money_withdraw(){
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
    std::cout << "������� ���������� ����� ��� ������: ";
    double money;
    std::cin>>money;
    std::cin.ignore();
    if (money < 0 || money > this->money_limit) std::cout <<"������ ������ ����� ����������!"<<std::endl;
    else this->money_limit -= money;
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}
void CreditMap::money_deposit(){
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
    std::cout << "������� ���������� ����� ��� �������� (�� 300000): ";
    double money;
    std::cin>>money;
    std::cin.ignore();
    if (money < 0 && money > 300001) std::cout<<"�������� �������� �� �������!"<<std::endl;
    else this->money_limit += money;
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}
void CreditMap::do_penalty(){
    std::cout << "�� ������ ������ % ������ = "<<this->penalty_proc<<std::endl;
    double summa;
    std::cout << "������� ����� ��� ���������� ������ = ";
    std::cin>>summa;
    if (summa < 0.000001) std::cout <<"����� ��� ������ �� ���������!"<<std::endl;
    else {
        this->money_limit-=summa*(this->penalty_proc/100);
    }
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}

void CreditMap::cards_equal(CreditMap &newCard){

    if (this->money_limit>newCard.money_limit) std::cout <<"�� ����� � �������: "<<this->cardNum<<" ����� ������!"<<std::endl;
    else if (this->money_limit<newCard.money_limit) std::cout <<"�� ����� � �������: "<<newCard.cardNum<<" ����� ������!"<<std::endl;
    else if (this->money_limit - newCard.money_limit < 0.000001) std::cout <<"���������� ����� �� ������ ���������!"<<std::endl;
}
