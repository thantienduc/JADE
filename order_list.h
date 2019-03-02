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
    int size() const {return _ps.size();}
    Order at(int i) const {return _ps.at(i);}
    void add_a(Order ps);
    bool operator==(const Order_list o);
    bool operator!=(const Order_list o);
  private:
    std::vector<Order> _ps;
};