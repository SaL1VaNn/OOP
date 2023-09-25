#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:
    // Оголошення публічних змінних класу
    float x, y, z;
    int factorial;
    double b;

    Calculator(float x, float y, float z, int factorial) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->factorial = factorial;
        this->b = calculateB();  // Обчислюємо значення b при створенні об'єкта
    }

    double calculateA() {
        // Обчислення факторіала
        double result = tgamma(factorial + 1);

        // Обчислення a 
        double a = log(10) * pow(((fabs(pow(b, 2)) - cbrt(fabs(pow(y, 2) - x) / (x + 2.1)) + (x - pow(y, 2)) / (b + 2 * pow(z, 2)))), 2.0 / 3.0);
        return a;
    }

    double calculateB() {
        double result = tgamma(factorial + 1);
        double b = log(10) * pow(fabs(z), 1.0 / 3.0) + (pow(y, 2) + pow(cos(x), 2) * pow(fabs(x), 0.3)) / (3 + y + pow(x, 2) / result + pow(z, 3));
        return b;
    }
};

int main() {
    float x_start = -1;
    float x_end = 1;
    float x_step = 0.2;
    float y = 0.47 * 14;
    float z = -1.32 * 14;
    int factorial = 2;

    cout << "Results:" << endl;

    for (float x = x_start; x <= x_end; x += x_step) {
        Calculator calc(x, y, z, factorial);
        double a = calc.calculateA();
        double b = calc.b;  // Використовуємо попередньо обчислене значення b

        cout << "x = " << x << ", a: " << a << ", b: " << b << endl;
    }

    return 0;
}
