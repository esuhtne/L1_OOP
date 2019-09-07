#ifndef CREDITMAP_H
#define CREDITMAP_H
#include <string>
#include <iostream>

#pragma pack(1)

class CreditMap
{
    int days_no_penalty, cardNum, end_mon, end_year, with_day, with_mon,with_year;
    double penalty_proc, money_limit;
    std::string familia;

    // �������� ���������� ����� �� ��, ����� ��� ���� ������������� (����� �����, ��� ��� ������)

    bool negative_number (const int &cardNums){
        if (cardNums < 0) return false;
        return true;
    }

    // �������� ������� �� ���������� � ��� ����

    bool number_string (const std::string &famil){
        int size_str = famil.length();
        for (int i = 0; i<size_str; i++){
            if (famil[i] >= 60 && famil[i] <= 71) return false;
        }
        return true;
    }

    public:

        void Init (const int &fcardNum, const std::string &ffamilia, const int &fend_mon, const int &fend_year, const int &fwith_day, const int &fwith_mon, const int &fwith_year, const int &fdays_no_penalty, const double &fpenalty_proc, const double &fmoney_limit){
            if (!negative_number(fcardNum))
            throw "\n������. ����� ����� �� ����� ���� �������������!\n";
            if (!number_string(ffamilia))
            throw "\n������. ������� �� ����� ��������� �����!\n";
            if (!(fend_mon > 0 && fend_mon < 13) && !(fend_year > 2019 && fend_year < 2030 ))
            throw "\n������. ���� �������� �� : ����� � ���������� �� 1 �� 12, ��� �� 2019 �� 2030!\n";
            if (!(fwith_day > 0 && fwith_day < 32) && !(fwith_mon > 0 && fwith_mon < 13) && !(fwith_year > 2009 && fwith_year < 2020))
                throw "\n������. ��������� ������ : ���� �� 1 �� 31, ����� �� 1 �� 12, ���! \n";
            if (!(fdays_no_penalty > 0 && fdays_no_penalty < 201))
                throw "\n������. ��� ��� ������ �� 1 �� 200! \n";
            if (!(fpenalty_proc > 0 && fpenalty_proc < 51))
                throw "\n������. ������� ������ �� 1 �� 50!\n";
            if (!(fmoney_limit > 99999 && fmoney_limit < 300001 ))
                throw "\n������. �������� ����� �� 100000 �� 300000\n";
            cardNum = fcardNum;
            familia = ffamilia;
            end_mon = fend_mon;
            end_year = fend_year;
            with_day = fwith_day;
            with_mon = fwith_mon;
            with_year = fwith_year;
            days_no_penalty = fdays_no_penalty;
            penalty_proc = fpenalty_proc;
            money_limit = fmoney_limit;
        }

        void Read();
        void Display();
        void end_date_change();
        void days_no_penalty_change();
        void money_withdraw();
        void money_deposit();
        void do_penalty();
        void cards_equal();
};

#endif // CREDITMAP_H
