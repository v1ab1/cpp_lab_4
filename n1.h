#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>

class Goods {
private:
    std::string name;
    double price_ua;
    std::string manufacturer;

protected:
    double getPriceUA() const { return price_ua; }
    void setPriceUA(double price) { price_ua = price; }

public:
    Goods();
    Goods(const std::string& name, double price_ua, const std::string& manufacturer);
    Goods(const Goods& other);
    virtual ~Goods();

    double calculatePriceUSD(double exchangeRate) const;
    void increasePriceIfToyota();
    std::string toString() const;

    Goods& operator=(const Goods& other);
    bool operator==(const Goods& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Goods& goods);
    friend std::istream& operator>>(std::istream& is, Goods& goods);

    std::string getName() const { return name; }
};

#endif
