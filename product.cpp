#include "product.h"
#include <iomanip>

Product::Product(std::string name, double price) : _name{name}, _price{price} {}
Product::Product(std::istream& ist){
    ist>> _name >> _price;
}
std::string Product::name() const {return _name;}
double Product::price() const {return _price;}
std::ostream& operator<<(std::ostream& ost, const Product& product) {
    ost << product._name << " ($" << std::fixed << std::setprecision(2) << product._price << ')';
    return ost;
}

void Product::save(std::ostream& ost) {
        ost << _name  << " " << _price << '\n';
    }
