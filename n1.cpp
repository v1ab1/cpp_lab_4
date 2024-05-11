#include "n1.h"

Goods::Goods(): name("Undefined"), price_ua(0.0), manufacturer("Undefined") {}

Goods::Goods(const std::string& name, double price_ua, const std::string& manufacturer)
    : name(name), price_ua(price_ua), manufacturer(manufacturer) {}

Goods::Goods(const Goods& other)
    : name(other.name), price_ua(other.price_ua), manufacturer(other.manufacturer) {}

Goods::~Goods() {
    std::cout << "Уничтожение объекта: " << this->name << std::endl;
}

double Goods::calculatePriceUSD(double exchangeRate) const {
    return price_ua / exchangeRate;
}

void Goods::increasePriceIfToyota() {
    if (name.find("Toyota") != std::string::npos) {
        price_ua *= 1.10;
    }
}

std::string Goods::toString() const {
    return "Название: " + name + ", Цена: " + std::to_string(price_ua) + " UAH, Производитель: " + manufacturer;
}

Goods& Goods::operator=(const Goods& other) {
    if (this != &other) {
        name = other.name;
        price_ua = other.price_ua;
        manufacturer = other.manufacturer;
    }
    return *this;
}

bool Goods::operator==(const Goods& other) const {
    return name == other.name && price_ua == other.price_ua && manufacturer == other.manufacturer;
}

std::ostream& operator<<(std::ostream& os, const Goods& goods) {
    os << goods.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Goods& goods) {
    std::getline(is, goods.name);
    is >> goods.price_ua;
    is.ignore();
    std::getline(is, goods.manufacturer);
    return is;
}
