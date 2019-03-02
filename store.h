#ifndef __STORE_H
#define __STORE_H

#include "order.h"
#include <vector>
#include <iostream>
#include "product_list.h"
#include "order_list.h"

class Store {
  public:
    Store(std::string name);
    Store(std::istream& ist);
    std::string name() const;

    // Product Management
    void add_product(Product product);
    int num_products() const;
    Product product(int index) const;
    void save(std::string path);
    void load (std::string path);
    // Order Management
    int create_order(std::string email);
    void add_to_order(int order_num, Product_order po);
    int num_orders() const;
    Order order(int order_num) const;
  
    friend std::ostream& operator<<(std::ostream& ost, const Store& store);
  private:
    std::string _name;
    Product_list _products;
    Order_list _orders;
};

#endif
