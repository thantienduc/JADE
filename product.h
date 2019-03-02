#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <fstream>
#include <iostream>
class Product {
  public:
    Product(std::string name, double price);
    Product(std::istream& ist);
    std::string name() const;
    double price() const;
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Product& product);
  private:
    std::string _name;
    double _price;
};
#endif
