#include "CreditMap.h"
#include <string>
#include <iostream>

void cin_clear()
{
    while (std::cin.get() != '\n');
    std::cin.clear();
}

void CreditMap::Read(){
    int fdays_no_penalty;
    double fpenalty_proc,fmoney_limit;
    std::string ffamilia,fend_data,flast_data,fcardNum;
    std::cout << "������� ����� ����� (����.: 1234 5678 9123 4564): ";
    while (!std::getline(std::cin,fcardNum)) std::cout <<"����� ����� ������ �������!\n"<<"������� ����� ����� (����.: 1234 5678 9123 4564): ";
    std::cout << "\n������� ������� ���������: ";
    while (!std::getline(std::cin,ffamilia) || ffamilia.length() < 2) std::cout << "\n������� ������� ���������: ";;
    std::cout << "\n������� ���� ��������� �������� (����� ������� / �� ��): ";
    while (!std::getline(std::cin,fend_data) && fend_data.length() != 5)
        std::cout << "\n������� ���� ��������� �������� (����� ������� / �� ��): ";
    std::cout << "\n������� ���� ���������� ������ (����� ������� / �� �� ��): ";
    while (!std::getline(std::cin,flast_data) && flast_data.length() != 8)
        std::cout << "\n������� ���� ���������� ������ (����� ������� / �� �� ��): ";
        std::cout << "\n������� ���������� ���� ����� ������ ��� ������: ";
    while (!std::cin>>fdays_no_penalty)
        std::cout << "\n������� ���������� ���� ����� ������ ��� ������: ";
        cin_clear();
    std::cout << "\n������� ������� ������: ";
    std::cin>>fpenalty_proc;
    std::cout << "\n������� ����� ��������� ����� (���-�� ����� �� �����): ";
    std::cin>>fmoney_limit;
    CreditMap::Init(fcardNum,ffamilia,fend_data,flast_data,fdays_no_penalty,fpenalty_proc,fmoney_limit);
}

void CreditMap::Display(){
    std::cout << "����� �����: "<<this->cardNum<<std::endl;
    std::cout << "������� ���������: "<<this->familia<<std::endl;
    std::cout << "���� ��������� �������� (�� ��): "<<this->end_data<<std::endl;
    std::cout << "���� ���������� ������ (�� �� ��): "<<this->last_data<<std::endl;
    std::cout << "���������� ���� ����� ������ ��� ������: "<<this->days_no_penalty<<std::endl;
    std::cout << "������� ������: "<<this->penalty_proc<<"%"<<std::endl;
    std::cout << "����� ��������� �����: "<<this->money_limit<<" ������"<<std::endl;
}

void CreditMap::end_date_change(){
    std::cout << "�� ������ ������ ����� ������������� ��: "<<this->end_data<<std::endl;
    std::cout << "������� ����� ���� �������� ����� (�� ��): ";
    std::string new_data;
    getline(std::cin, new_data);
    // �������� �� ��������� ���� ��� ���� � 5 ��������
    this->end_data = new_data;
    }
void CreditMap::days_no_penalty_change(){
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
    std::cout << "�� ������ ���������� ���� ��� ������: "<<this->days_no_penalty<<std::endl;
    std::cout << "������� ����� ���������� ���� ��� ������: ";
    int days;
    std::cin >> days;
    this->days_no_penalty = days;
    std::cout << "�� ������ ���������� ���� ��� ������: "<<this->days_no_penalty<<std::endl;
}
void CreditMap::money_withdraw(){
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
    std::cout << "������� ���������� ����� ��� ������: ";
    double money;
    std::cin>>money;
    if (money < 0 || money-this->money_limit<0.000001) std::cout <<"������ ������ ����� ����������!"<<std::endl;
    else this->money_limit -= money;
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}
void CreditMap::money_deposit(){
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
    std::cout << "������� ���������� ����� ��� �������� (�� 1 ���): ";
    double money;
    std::cin>>money;
    if (money < 0 && money > 1000000) std::cout<<"�������� �������� �� �������!"<<std::endl;
    else this->money_limit+=money;
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}
void CreditMap::do_penalty(){
    std::cout << "�� ������ ������ % ������ = "<<this->penalty_proc<<std::endl;
    double summa;
    std::cout << "������� ����� ��� ���������� ��������: "<<std::endl;
    std::cin>>summa;
    if (summa < 0.000001) std::cout <<"����� ��� ������ �� ���������!"<<std::endl;
    else {
        this->money_limit-=summa*(this->penalty_proc/100);
    }
    std::cout << "�� ������ ���������� ����� �� �����: "<<this->money_limit<<std::endl;
}

void CreditMap::cards_equal(){
    CreditMap newCard;
    newCard.Read();
    if (this->money_limit>newCard.money_limit) std::cout <<"�� ����� � �������: "<<this->cardNum<<" ����� ������!"<<std::endl;
    else if (this->money_limit<newCard.money_limit) std::cout <<"�� ����� � �������: "<<newCard.cardNum<<" ����� ������!"<<std::endl;
    else if (this->money_limit - newCard.money_limit < 0.000001) std::cout <<"���������� ����� �� ������ ���������!"<<std::endl;
}
