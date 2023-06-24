#include "singleton.h"

#include <iostream>
MetricRegister* MetricRegister::instance = nullptr;

MetricRegister::MetricRegister()
{
    // конструктор реестра метрик
}

MetricRegister::~MetricRegister()
{
    // деструктор реестра метрик
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
    // добавление метрики в ассоциативный массив
    int currentTime = static_cast<int>(time(0));
    std::pair<int, int> value(resp_t, wait_t);
    metrics[currentTime] = value;

    return true;
}

bool MetricRegister::show_mert()
{
    // вывод на экран всех метрик, упорядоченных по ключу
    for (const auto& m : metrics)
    {
        std::cout<< "Key: " << m.first << "; Value: (" << m.second.first << ", " << m.second.second << ")" ;
    }

    return true;
}

int MetricRegister::count_cometr(int key)
{
    // вычисление вспомогательной метрики
    int cometr = 0;
    if (metrics.find(key) != metrics.end())
    {
        cometr = metrics[key].first + metrics[key].second;
    }
    return cometr;
}


