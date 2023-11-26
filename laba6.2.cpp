#include <iostream>
#include<Windows.h>

template <typename T, int maxSize>
class Stack {
private:
    T elements[maxSize];
    int top;  // Індекс вершини стеку

public:
    Stack() : top(-1) {}

    // Функція для занесення елемента у стек
    void push(const T& element) {
        if (top < maxSize - 1) {
            elements[++top] = element;
            std::cout << "Елемент " << element << " додано до стеку.\n";
        }
        else {
            std::cout << "Стек переповнений. Неможливо додати елемент.\n";
        }
    }

    // Функція для вилучення значення із вершини стеку
    T pop() {
        if (top >= 0) {
            std::cout << "Елемент " << elements[top] << " вилучено зі стеку.\n";
            return elements[top--];
        }
        else {
            std::cout << "Стек порожній. Неможливо вилучити елемент.\n";
            return T();  // Повертається значення за замовчуванням для типу T
        }
    }

    // Функція для виведення усіх значень стеку на екран
    void display() {
        std::cout << "Значення стеку:";
        for (int i = 0; i <= top; ++i) {
            std::cout << " " << elements[i];
        }
        std::cout << "\n";
    }

    // Функція для повернення кількості елементів стеку
    int size() const {
        return top + 1;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Приклад використання шаблонного класу Stack
    Stack<int, 5> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    intStack.display();

    std::cout << "Кількість елементів у стеку: " << intStack.size() << "\n";

    intStack.pop();
    intStack.display();

    return 0;
}
