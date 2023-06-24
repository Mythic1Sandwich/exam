#include <iostream>
#include "singleton.h"

using namespace std;

int main() {
    MetricRegister* metricReg = MetricRegister::getInstance();  // Создаем единственный экземпляр класса MetricRegister

    // Генерируем 10 различных метрик
    int testCases[10][2] = { {1, 2}, {5, 3}, {7, 7}, {-1, 0}, {10, -5}, {0, -2}, {2, 19}, {100, 50}, {8, 4}, {17, 23} };

    for (int i = 0; i < 10; i++) {  // Проходим по всем тестовым случаям
        bool result = metricReg->add_metr(testCases[i][0], testCases[i][1]);  // Вызываем метод add_metr() для текущей метрики

        if (result) {  // Если метрика была успешно добавлена, выводим сообщение об успехе
            cout << "Test case " << i + 1 << ": passed" << endl;
        }
        else {  // Иначе - сообщение об ошибке и значения, которые были переданы в функцию
            cout << "Test case " << i + 1 << ": failed. Metric with Response Time = " << testCases[i][0] << " and Wait Time = " << testCases[i][1] << " was not added." << endl;
        }
    }
    return 0;
}