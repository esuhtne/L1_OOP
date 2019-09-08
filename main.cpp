#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"������������ 1, ������� 14. �������� �.�. ����� - 21"<<std::endl;
    std::cout <<"�������: ������� ����� CreditMap (��������� �����).";
    std::cout << "\n� ������ ������ ���� ��������� ����: ";
    std::cout << " \n����� �����, ������� ���������, ���� ��������� ��������, ���� ���������� ������, ���������� ���� ����� ������ ��� ������,";
    std::cout << "������� ������, ����� ��������� �����.\n";
    std::cout << " ���������� ��������� ��������� ��������: ";
    std::cout << "�������� ���� ��������� ��������, �������� ���������� ���� ��� ������, ����� ��������� ����� ����� � ���-��, \n";
    std::cout << "�������� ������ �� �����, ��������� �����. ����������� ����� ��������� �� ����� �� �����. \n";

    std::cout <<"������ ������ ��� ������������� pragma pack (1): "<<sizeof(CreditMap)<<std::endl;
    std::cout <<"������ ������ � �������������� pragma pack (1): "<<sizeof(CreditMap)<<std::endl;

    std::cout <<"\n�������� � ���������� ������� ������ \n"<<std::endl;
    CreditMap firstCard;
    if (firstCard.Read()){
    CreditMap secondCard(firstCard);
    std::cout <<"\n����� �������� ����� "<<std::endl;
    secondCard.Display();
    std::cout << std::endl;
    std::cout <<"\n�������. ��������� ���� ��������� �������� ����� "<<std::endl;
    CreditMap thirdCard = secondCard;
    thirdCard.end_date_change();
    std::cout <<"\n�������. ��������� ���������� ���� ��� ������ "<<std::endl;
    thirdCard.days_no_penalty_change();
    std::cout <<"\n�������. ������ ����� � �����  "<<std::endl;
    thirdCard.money_withdraw();
    std::cout <<"\n�������. �������� ����� �� ����� "<<std::endl;
    thirdCard.money_deposit();
    std::cout <<"\n�������. ���������� ������  "<<std::endl;
    thirdCard.do_penalty();
    std::cout <<"\n�������. ��� ������ ��������� �� ����� �������� ��� 1 �����  "<<std::endl;
    CreditMap fourthCard;
    if (fourthCard.Read()){
    std::cout << std::endl;
    std::cout <<"\n�������. ��������� ����� ���� ����  "<<std::endl;
    thirdCard.cards_equal(fourthCard);}}

    // ������ ������� �� 5 ���������

    CreditMap Newest[5];
    CreditMap *NewestN = new CreditMap[5] ;

    return 0;
}
