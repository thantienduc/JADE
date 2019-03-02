#include "./product_order.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class Product_order_list{
  public:   
    Product_order_list() {};
    void save(std::ostream& ost);
    void load(std::istream& ist);
    Product_order_list(std::istream& ist);
    int size() const {return _ps.size();}
    Product_order at(int i) const {return _ps.at(i);}
    std::vector<Product_order> list() const {return _ps;}
    void add_a(Product_order p);
    bool operator==(const Product_order_list b);
    bool operator!=(const Product_order_list b);
  private:
    std::vector<Product_order> _ps;
};