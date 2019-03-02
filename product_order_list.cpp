#include "./product_order_list.h"

Product_order_list::Product_order_list() {};
void Product_order_list::save(std::ostream& ost) {
        ost << _ps.size() << '\n';
        for(Product_order& a : _ps) a.save(ost);
    }

void Product_order_list::load(std::istream& ist) {
       int num_elements; 
       ist >> num_elements; ist.ignore();
       while(num_elements--) _ps.push_back(Product_order{ist});
}

void Product_order_list::add_a(Product_order p) {
        _ps.push_back(p);
    }

    // The == and != operators are just needed for testing in main. They aren't needed
    // for loading or saving class data at all. Note that our implementation here is 
    // relying on A's overloading of != above.
    
    /*bool Produc_order_list:: operator==(const Produc_order_list b) {
        if(_ps.size() != b._ps.size()) return false; // vector length differs
        for(int i=0; i<_ps.size(); ++i) if (_ps[i] != b._ps[i]) return false; // data differs
        return true;  // same vector length and elements, so they are equal!
    }
    bool Produc_order_list:: operator!=(const Produc_order_list b) {
        return !(*this == b);
    }*/