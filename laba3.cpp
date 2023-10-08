#include <iostream>
#include <cmath>
#include <stdexcept>
#include <windows.h>

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
        update();
    }

    double get_side() const {
        return side;
    }

    double get_diagonal() const {
        return diagonal;
    }

    double get_perimetr() const {
        return perimetr;
    }

    double get_area() const {
        return area;
    }

    void enter_data() {
        double new_side;
        std::cout << "Введіть довжину сторони квадрата: ";
        std::cin >> new_side;
        set_side(new_side);
    }

    void output_data() const {
        std::cout << "Сторона: " << side << std::endl;
        std::cout << "Діагональ: " << diagonal << std::endl;
        std::cout << "Периметр: " << perimetr << std::endl;
        std::cout << "Площа: " << area << std::endl;
    }

private:
    double side;
    double diagonal;
    double perimetr;
    double area;

    void update() {
        diagonal = side * std::sqrt(2);
        perimetr = 4 * side;
        area = side * side;
    }
};

int main() {
    SetConsoleOutputCP(1251); 

    try {
        Square square;
        square.enter_data();
        std::cout << "Дані про квадрат:" << std::endl;
        square.output_data();
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
