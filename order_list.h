#include "./order.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class Order_list{
  public:   
    Order_list() {};
    void save(std::ostream& ost);
    void load(std::istream& ist);
    Order_list(std::istream& ist);
    void add_a(std::string name, double price);
    bool operator==(const Order_list o);
    bool operator!=(const Order_list o);
  private:
    std::vector<Order> _ps;
};