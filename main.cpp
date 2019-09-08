#include <iostream>
#include <windows.h>
#include "CreditMap.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout <<"������������ 1, ������� 14. �������� �.�. ����� - 21. ������ 2"<<std::endl;
    std::cout <<"�������: ������� ����� CreditMap (��������� �����).";
    std::cout << "\n� ������ ������ ���� ��������� ����: ";
    std::cout << " \n����� �����, ������� ���������, ���� ��������� ��������, ���� ���������� ������, ���������� ���� ����� ������ ��� ������,";
    std::cout << "������� ������, ����� ��������� �����.\n";
    std::cout << " ���������� ��������� ��������� ��������: ";
    std::cout << "�������� ���� ��������� ��������, �������� ���������� ���� ��� ������, ����� ��������� ����� ����� � ���-��, \n";
    std::cout << "�������� ������ �� �����, ��������� �����. ����������� ����� ��������� �� ����� �� �����. \n";

    std::cout <<"������ ������ ��� ������������� pragma pack (1): "<<sizeof(CreditMaps)<<std::endl;
    std::cout <<"������ ������ � �������������� pragma pack (1): "<<sizeof(CreditMap)<<std::endl;

    try {
    std::cout <<"\n�������� � ���������� ������� ������ �������: "<<std::endl;
    std::cout << "����� �����: 1234"<<std::endl;
    std::cout << "������� ���������: ��������"<<std::endl;
    std::cout << "���� ��������� �������� (�� ����): 3 2020"<<std::endl;
    std::cout << "���� ���������� ������ (�� �� ����): 10 4 2019"<<std::endl;
    std::cout << "���������� ���� ����� ������ ��� ������: 90"<<std::endl;
    std::cout << "������� ������: 15%"<<std::endl;
    std::cout << "����� ��������� �����: 250000 ������"<<std::endl;
    CreditMap firstCard(1234,"��������",3,2020,10,4,2019,90,15,250000);
    // �������� ����� ������ ������ ������
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
    fourthCard.Read();
    std::cout << std::endl;
    std::cout <<"\n�������. ��������� ����� ���� ����  "<<std::endl;
    thirdCard.cards_equal(fourthCard);}
    catch (const char* exc){
        std::cout << exc<<std::endl;
    }
    // ������ ������� �� 5 ���������

    CreditMap Newest[5];
    CreditMap *NewestN = new CreditMap[5];
    for (int i = 0; i < 5; i++) NewestN[i] = CreditMap(1234,"��������",3,2020,10,4,2019,90,15,250000);

    return 0;
}
