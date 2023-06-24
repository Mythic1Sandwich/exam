#include "singleton.h"
#include <iostream>

MetricRegister* MetricRegister::instance = nullptr;

MetricRegister::MetricRegister()
{
    // ����������� ������� ������
}

MetricRegister::~MetricRegister()
{
    // ���������� ������� ������
}

MetricRegister* MetricRegister::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MetricRegister();
    }
    return instance;
}

bool MetricRegister::add_metr(int resp_t, int wait_t)
{
    // ���������� ������� � ������������� ������
    int currentTime = static_cast<int>(time(0));
    std::pair<int, int> value(resp_t, wait_t);
    metrics[currentTime] = value;

    return true;
}

bool MetricRegister::show_mert()
{
    // ����� �� ����� ���� ������, ������������� �� �����
    for (const auto& m : metrics)
    {
        std::cout << "Time: " << m.first << "; Response Time: " << m.second.first << "; Wait Time: " << m.second.second << std::endl;
    }

    return true;
}

int MetricRegister::count_cometr(int key)
{
    // ���������� ��������������� �������
    int cometr = 0;
    if (metrics.find(key) != metrics.end())
    {
        cometr = metrics[key].first + metrics[key].second;
    }
    return cometr;
}