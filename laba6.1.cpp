#include <iostream>
#include <Windows.h>

template <typename T>
void rotateArray(T array[], int size) {
    if (size <= 1) {
        return;
    }

   
    T lastElement = array[size - 1];

 
    for (int i = size - 1; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = lastElement;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5; 
    int intArray[size] = { 1, 2, 3, 4, 5 };

    std::cout << "Масив перед ротацією: ";
    for (int i = 0; i < size; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    rotateArray(intArray, size);

    std::cout << "Масив після ротації: ";
    for (int i = 0; i < size; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
