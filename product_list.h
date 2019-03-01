#include "./product.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class Product_list{
  public:   
    Product_list() {};
    void save(std::ostream& ost);
    void load(std::istream& ist);
    Product_list(std::istream& ist);
    void add_a(std::string name, double price);
    bool operator==(const Product_list b);
    bool operator!=(const Product_list b);
  private:
    std::vector<Product> _ps;
};