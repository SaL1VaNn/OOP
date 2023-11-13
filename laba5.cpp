#include <iostream>
#include <climits>
#include <Windows.h>

// Абстрактний клас
class ArrayCharacteristics {
public:
    virtual void calculateCharacteristics(int arr[], int size) = 0;
    virtual ~ArrayCharacteristics() {}
};

// Клас для обчислення суми та добутку елементів масиву
class SumProductCalculator : public ArrayCharacteristics {
public:
    void calculateCharacteristics(int arr[], int size) override {
        int sum = 0;
        long long product = 1;

        for (int i = 0; i < size; ++i) {
            sum += arr[i];
            product *= arr[i];
        }

        std::cout << "Сума: " << sum << std::endl;
        std::cout << "Добуток: " << product << std::endl;
    }
};

// Клас для знаходження мінімального та максимального елементів
class MinMaxFinder : public ArrayCharacteristics {
public:
    void calculateCharacteristics(int arr[], int size) override {
        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        for (int i = 0; i < size; ++i) {
            if (arr[i] < minElement) {
                minElement = arr[i];
            }

            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }

        std::cout << "Мінімальний елемент: " << minElement << std::endl;
        std::cout << "Максимальний елемент: " << maxElement << std::endl;
    }
};

// Клас для знаходження кількості додатних, від'ємних та нульових елементів
class CountElements : public ArrayCharacteristics {
public:
    void calculateCharacteristics(int arr[], int size) override {
        int positiveCount = 0;
        int negativeCount = 0;
        int zeroCount = 0;

        for (int i = 0; i < size; ++i) {
            if (arr[i] > 0) {
                positiveCount++;
            }
            else if (arr[i] < 0) {
                negativeCount++;
            }
            else {
                zeroCount++;
            }
        }

        std::cout << "Додатні елементи: " << positiveCount << std::endl;
        std::cout << "Від'ємні елементи: " << negativeCount << std::endl;
        std::cout << "Нульові елементи: " << zeroCount << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5; 
    int arr[size];

    std::cout << "Введіть " << size << " елементів масиву:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    ArrayCharacteristics* calculator = new SumProductCalculator();
    calculator->calculateCharacteristics(arr, size);
    delete calculator;

    calculator = new MinMaxFinder();
    calculator->calculateCharacteristics(arr, size);
    delete calculator;

    calculator = new CountElements();
    calculator->calculateCharacteristics(arr, size);
    delete calculator;

    return 0;
}
