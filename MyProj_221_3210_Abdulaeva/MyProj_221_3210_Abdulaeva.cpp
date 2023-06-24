#include "singleton.h"
#include <iostream>

int main()
{
    MetricRegister* mr = MetricRegister::getInstance();


    // Добавление нескольких метрик
    mr->add_metr(10, 5);
    mr->add_metr(20, 5);

    mr->add_metr(30, 5);

    // Вывод всех метрик на экран
    std::cout << "All Metrics:" << std::endl;
    mr->show_mert();

    // Вычисление вспомогательной метрики для текущего времени
    int cometr = mr->count_cometr(static_cast<int>(time(0)));
    std::cout << "Cometr: " << cometr << std::endl;


    return 0;
}