#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

#include <map>
#include <ctime>

class MetricRegister
{
public:
    static MetricRegister* getInstance();

    bool add_metr(int resp_t, int wait_t);
    bool show_mert();
    int count_cometr(int key);

private:
    MetricRegister();  // ��������� �����������, ����� �������� �������� �����������
    ~MetricRegister();

    static MetricRegister* instance;  // ��������� �� ������������ ���������

    std::map<int, std::pair<int, int>> metrics;  // ������������� ������ ��� �������� ������
};

#endif // SINGLETON_H
