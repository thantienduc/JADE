#include "order.h"

Order::Order(std::string email) : _email{email} { }
Order::Order(std::istream& ist) {
    ist >> _email; ist.ignore();
    int numoforder;
    ist >> numoforder;
    while (--numoforder) _product_orders.add_a(Product_order(ist)); 
}
std::string Order::email() {return _email;}
double Order::cost() {
    double sum;
    for (auto& po : _product_orders.list()) sum += po.cost();
    return sum;
}
void Order::add_product_order(Product_order po) {
    _product_orders.add_a(po);
}
int Order::num_product_orders() {return _product_orders.size();}
Product_order Order::product_order(int index) {
    if (0 > index || index > (_product_orders.size()-1)) 
        throw std::out_of_range{"Order: Product index " + std::to_string(index) 
            + " with only " + std::to_string(_product_orders.size()-1) + " products"};
    return _product_orders.at(index);
}
std::ostream& operator<<(std::ostream& ost, const Order& order) {
    for (auto& po : order._product_orders.list()) ost << "  " << po << '\n';
    return ost;
}

void Order::save(std::ostream& ost){
    ost << _email <<'\n';
    ost << _product_orders.size() << '\n';
    int s = _product_orders.size();
    while (--s) {
       _product_orders.at(s).save(ost);
    }
}
