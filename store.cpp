#include "store.h"
#include <fstream>

Store::Store(std::string name) : _name{name} { }
std::string Store::name() const {return _name;}

// Product Management
void Store::add_product(Product product) {_products.add_a(product);}
int Store::num_products() const {return _products.size();}
Product Store::product(int index) const {
    if (0 > index || index > (_products.size()-1)) 
        throw std::out_of_range{"Store " + _name + ": Product index " + std::to_string(index) 
            + " with only " + std::to_string(_products.size()-1) + " products"};
    return _products.at(index);
}

// Order Management
void Store::save(std::string path){

    std::ofstream ost;
    ost.open(path+"/store.db",std::ofstream::out);
    ost << _name << '\n';
    ost.close();

    ost.open(path+"/products.db",std::ofstream::out);
    _products.save(ost);
    ost.close();

    ost.open(path+"/orders.db",std::ofstream::out);
    _orders.save(ost);
    ost.close();
}

void Store::load(std::string path){

    std::ifstream ist;
    ist.open(path+"/store.db",std::ifstream::in);
    ist >> _name;
    ist.close();

    ist.open(path+"/products.db",std::ifstream::in);
    _products.load(ist);
    ist.close();

    ist.open(path+"/orders.db",std::ifstream::in);
    _orders.load(ist);
    ist.close();
}

int Store::create_order(std::string email) {
    _orders.add_a(Order{email});
    return _orders.size()-1;
}
void Store::add_to_order(int order_num, Product_order po) {
    if (0 > order_num || order_num > (_orders.size()-1)) 
        throw std::out_of_range{"Store " + _name + ": Tried to add to Order " + std::to_string(order_num) 
            + " with only " + std::to_string(_orders.size()-1) + " orders"};
    _orders.at(order_num).add_product_order(po);
}
int Store::num_orders() const {return _orders.size();}
Order Store::order(int order_num) const {
    if (0 > order_num || order_num > (_orders.size()-1)) 
        throw std::out_of_range{"Store " + _name + ": Tried to access Order " + std::to_string(order_num) 
            + " with only " + std::to_string(_orders.size()-1) + " orders"};
    return _orders.at(order_num);
}
std::ostream& operator<<(std::ostream& ost, const Store& store) {
    for (int i=0; i<store.num_products(); ++i) ost << i << ") " << store.product(i) << std::endl;
    return ost;
}
