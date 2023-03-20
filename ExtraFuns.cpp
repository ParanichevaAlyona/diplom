#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <vector>
#include "ExtraFuns.h"

using namespace std;

int sizevec(int n) {
    int size = 0;
    for (int i = 1; i <= n; i++)
        size += i;
    return size;
}

std::vector<int> genMas(int n) {
    std::mt19937 gen;
    int size = sizevec(n);
    gen.seed(static_cast<unsigned int>(time(0)));
    std::vector<int> array(size);
    int flag = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == flag) {
            array[i] = 0;
            flag += n - count;
            count++;
        }
        else if (gen() % 100 < 20)
            array[i] = 1;
        else array[i] = 0;
    }
    return array;
}

std::vector<int> mixMas(int n) {
    // Устанавливаем seed для rand, чтобы при каждом
    // запуске программы массив перемешивался по-разному
    srand(time(NULL));

    vector<int> a(n);

    // Заполняем наш массив числами от 1 до N
    for (size_t i = 0; i < n; i++)
        a[i] = i;

    // Перемешивание массива
    for (int i = n; i > 1; i--) {
        int rand_index = rand() % i;

        // Обмен элементов a[i-1] и a[rand_index]
        int tmp = a[i - 1];
        a[i - 1] = a[rand_index];
        a[rand_index] = tmp;
    }

    return a;
}
