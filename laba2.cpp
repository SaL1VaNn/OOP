#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

class Product {
public:
    Product(std::string name, std::string quality_certificate, double price)
        : name(name), quality_certificate(quality_certificate), price(price) {}

    void set(std::string name, std::string quality_certificate, double price) {
        this->name = name;
        this->quality_certificate = quality_certificate;
        this->price = price;
    }

    void show() const {
        SetConsoleOutputCP(1251);
        std::cout << "Назва товару: " << name << std::endl;
        std::cout << "Свідоцтво якості: " << quality_certificate << std::endl;
        std::cout << "Вартість: " << price << std::endl;
    }

    const std::string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    bool operator==(const Product& other) const {
        return this->name == other.name;
    }

private:
    std::string name;
    std::string quality_certificate;
    double price;
};

class Customer {
public:
    void addProductToShoppingList(const Product& product) {
        shopping_list.push_back(product);
    }

    double calculateTotalCost() const {
        double total_cost = 0;
        for (const Product& product : shopping_list) {
            total_cost += product.getPrice();
        }
        return total_cost;
    }

    void showShoppingList() const {
        SetConsoleOutputCP(1251); 
        std::cout << "Перелік товарів у кошику:" << std::endl;
        for (const Product& product : shopping_list) {
            product.show();
            std::cout << "----------" << std::endl;
        }
    }

private:
    std::vector<Product> shopping_list;
};

class Store {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(const Product& product) {
        products.erase(std::remove(products.begin(), products.end(), product), products.end());
    }

    Product* findProductByName(const std::string& name) {
        auto it = std::find_if(products.begin(), products.end(), [name](const Product& product) {
            return product.getName() == name;
            });
        if (it != products.end()) {
            return &(*it);
        }
        return nullptr;

    }

    void showAvailableProducts() const {
        SetConsoleOutputCP(1251); 
        std::cout << "Наявні товари у магазині:" << std::endl;
        for (const Product& product : products) {
            product.show();
            std::cout << "----------" << std::endl;
        }
    }

private:
    std::vector<Product> products;
};

int main() {
    SetConsoleOutputCP(1251);

    Store store;

    Product product1("Молоко", "Сертифікат 123", 20);
    Product product2("Хліб", "Сертифікат 456", 10);
    Product product3("Яйця", "Сертифікат 789", 5);

    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);

    Customer customer;
    customer.addProductToShoppingList(product1);
    customer.addProductToShoppingList(product2);

    std::cout << "Перелік товарів у магазині:" << std::endl;
    store.showAvailableProducts();

    std::cout << "Перелік товарів у кошику покупця:" << std::endl;
    customer.showShoppingList();

    double total_cost = customer.calculateTotalCost();
    std::cout << "Загальна вартість товарів у кошику: " << total_cost << std::endl;

    return 0;
}
