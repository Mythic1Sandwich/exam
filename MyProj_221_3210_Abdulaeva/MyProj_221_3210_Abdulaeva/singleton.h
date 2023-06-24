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
    MetricRegister();  // приватный конструктор, чтобы избежать создани€ экземпл€ров
    ~MetricRegister();

    static MetricRegister* instance;  // указатель на единственный экземпл€р

    std::map<int, std::pair<int, int>> metrics;  // ассоциативный массив дл€ хранени€ метрик
};

#endif // SINGLETON_H
