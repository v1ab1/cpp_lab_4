#include <iostream>
#include "n1.h"
#include "n2.h"

int main() {
    Goods item("Toyota Corolla", 300000, "Toyota");
    std::cout << "Изначальная цена: " << item.toString() << std::endl;

    item.increasePriceIfToyota();
    std::cout << "После повышения: " << item.toString() << std::endl;

    std::cout << "Цена в долларах: " << item.calculatePriceUSD(40) << " USD" << std::endl;

    DiscountGoods luxuryItem("Lexus RX", 1000000, "Toyota", 2018, 15.0);
    std::cout << "До скидки: " << luxuryItem.toString() << std::endl;

    luxuryItem.applyDiscount();
    std::cout << "После скидки: " << luxuryItem.toString() << std::endl;
    
    Goods* goodsPtr = &luxuryItem;
    std::cout << "Описание класса: " << goodsPtr->toString() << std::endl;



    return 0;
}
