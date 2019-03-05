#include "./order_list.h"

void Order_list::save(std::ostream& ost) {
        ost << _ps.size() << '\n';
        for(Order& a : _ps) a.save(ost);
    }

void Order_list::load(std::istream& ist) {
       int num_elements; 
       ist >> num_elements; ist.ignore();
       while(num_elements--) _ps.push_back(Order{ist});
}
void Order_list::add_a(Order ps) {
    _ps.push_back(ps);
}

    // The == and != operators are just needed for testing in main. They aren't needed
    // for loading or saving class data at all. Note that our implementation here is 
    // relying on A's overloading of != above.
    
    /*bool Order_list:: operator==(const Order_list b) {
        if(_ps.size() != b._ps.size()) return false; // vector length differs
        for(int i=0; i<_ps.size(); ++i) if (_ps[i] != b._ps[i]) return false; // data differs
        return true;  // same vector length and elements, so they are equal!
    }
    bool Order_list:: operator!=(const Order_list b) {
        return !(*this == b);
    }*/

//// MODIFICATION FUNCTIONS

void Order_list::add_product_order(int orderid, Product_order po){
    _ps.at(orderid).add_product_order(po);
}