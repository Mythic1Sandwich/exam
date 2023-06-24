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
    MetricRegister();  // приватный конструктор, чтобы избежать создания экземпляров
    ~MetricRegister();

    static MetricRegister* instance;  // указатель на единственный экземпляр

    std::map<int, std::pair<int, int>> metrics;  // ассоциативный массив для хранения метрик
};

#endif // SINGLETON_H
