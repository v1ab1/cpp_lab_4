#ifndef LUXURY_GOODS_H
#define LUXURY_GOODS_H

#include "n1.h"
#include <ctime>

class DiscountGoods : public Goods {
private:
    int yearOfManufacture;
    double discountPercent;
public:
    DiscountGoods();
    DiscountGoods(const std::string& name, double price_ua, const std::string& manufacturer,
                int yearOfManufacture, double discountPercent);
    DiscountGoods(const DiscountGoods& other);

    virtual ~DiscountGoods();

    void applyDiscount();
    std::string toString() const;
};

#endif
