#include <iostream>
#include <fstream>
#include <string>

class TOY {
public:
    TOY(std::string _name) : name(_name) {}
    virtual void displayInfo(std::ostream& output) {
        output << "Тип іграшки: головна іграшка" << std::endl;
        output << "Ім'я: " << name << std::endl;
    }
    virtual ~TOY() {}

protected:
    std::string name;
};

class CAR : public TOY {
public:
    CAR(std::string _name, std::string _model) : TOY(_name), model(_model) {}
    void displayInfo(std::ostream& output) override {
        output << "Тип Іграшки: " << std::endl;
        output << "Ім'я: " << name << std::endl;
        output << "Модель: " << model << std::endl;
    }
    ~CAR() {}

private:
    std::string model;
};

class SOFTTOY : public TOY {
public:
    SOFTTOY(std::string _name, std::string _material) : TOY(_name), material(_material) {}
    void displayInfo(std::ostream& output) override {
        output << "Тип іграшки: М'яка іграшка" << std::endl;
        output << "Ім'я: " << name << std::endl;
        output << "Матеріал: " << material << std::endl;
    }
    ~SOFTTOY() {}

private:
    std::string material;
};

int main() {
    TOY* toy1 = new CAR("BMW ", "X5");
    TOY* toy2 = new SOFTTOY("Teddy Bear", "М'який");

    std::ofstream file("toy_information.txt");

    toy1->displayInfo(file);
    file << "-----------------------------" << std::endl;
    toy2->displayInfo(file);

    file.close();

    delete toy1;
    delete toy2;

    return 0;
}
