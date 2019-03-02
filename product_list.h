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
    int size() const {return _ps.size();}
    Product at(int i) const {return _ps.at(i);}
    void add_a(Product p);
    bool operator==(const Product_list b);
    bool operator!=(const Product_list b);
  private:
    std::vector<Product> _ps;
};