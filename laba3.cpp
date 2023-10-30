#include <iostream>
#include <cmath>
#include <stdexcept>
#include <Windows.h>

class Square {
public:
    Square() : side(0) {}

    Square(double side) {
        set_side(side);
    }

    void set_side(double new_side) {
        if (new_side <= 0) {
            throw std::invalid_argument("Сторона повинна бути додатнім числом.");
        }
        side = new_side;
    }

    double get_side() const {
        return side;
    }

    double calculate_diagonal() const {
        return side * std::sqrt(2);
    }

    double calculate_perimeter() const {
        return 4 * side;
    }

    
    double calculate_area() const {
        return side * side;
    }

   
    double calculate_area(double length, double width) const {
        return length * width;
    }

    friend std::ostream& operator<<(std::ostream& output, const Square& square) {
        output << "Квадрат:" << std::endl;
        output << "Сторона: " << square.get_side() << std::endl;
        output << "Периметр: " << square.calculate_perimeter() << std::endl;
        output << "Площа: " << square.calculate_area() << std::endl; 
        return output;
    }

private:
    double side;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        double side;
        std::cout << "Введіть сторону квадрата: ";
        std::cin >> side;

        Square square(side);

        int choice;
        std::cout << "Виберіть, що ви хочете обчислити:" << std::endl;
        std::cout << "1. Діагональ" << std::endl;
        std::cout << "2. Периметр" << std::endl;
        std::cout << "3. Площу" << std::endl;
        std::cout << "4. Вивести інформацію про фігуру" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Діагональ: " << square.calculate_diagonal() << std::endl;
        }
        else if (choice == 2) {
            std::cout << "Периметр: " << square.calculate_perimeter() << std::endl;
        }
        else if (choice == 3) {
            std::cout << "Площа: " << square.calculate_area() << std::endl;
        }
        else if (choice == 4) {
            std::cout << square;
        }
        else {
            std::cout << "Невірний вибір операції." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
