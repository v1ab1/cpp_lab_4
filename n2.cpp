#include "n2.h"
#include <iostream>

DiscountGoods::DiscountGoods(): Goods(), yearOfManufacture(0), discountPercent(0.0) {}

DiscountGoods::DiscountGoods(const std::string& name, double price_ua, const std::string& manufacturer,
                         int yearOfManufacture, double discountPercent)
    : Goods(name, price_ua, manufacturer), yearOfManufacture(yearOfManufacture), discountPercent(discountPercent) {}

DiscountGoods::DiscountGoods(const DiscountGoods& other)
    : Goods(other), yearOfManufacture(other.yearOfManufacture), discountPercent(other.discountPercent) {}

DiscountGoods::~DiscountGoods() {
    std::cout << "Уничтожение объекта: " << this->getName() << std::endl;
}

void DiscountGoods::applyDiscount() {
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int currentYear = aTime->tm_year + 1900;

    if (currentYear - this->yearOfManufacture > 2) {
        double newPrice = getPriceUA() * (1 - discountPercent / 100);
        setPriceUA(newPrice);
    }
}

std::string DiscountGoods::toString() const {
    return Goods::toString() + ", Год производства: " + std::to_string(yearOfManufacture) +
           ", Процент скидки: " + std::to_string(discountPercent) + "%";
}
