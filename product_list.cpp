#include "./product_list.h"

Product_list::Product_list() {};
void Product_list::save(std::ostream& ost) {
        ost << _ps.size() << '\n';
        for(Product& a : _ps) a.save(ost);
    }

void Product_list::load(std::istream& ist) {
       int num_elements; 
       ist >> num_elements; ist.ignore();
       while(num_elements--) _ps.push_back(Product{ist});
}

void Product_list::add_a(Product p) {
        _ps.push_back(p);
    }

    // The == and != operators are just needed for testing in main. They aren't needed
    // for loading or saving class data at all. Note that our implementation here is 
    // relying on A's overloading of != above.
    
    /*bool Product_list:: operator==(const Product_list b) {
        if(_ps.size() != b._ps.size()) return false; // vector length differs
        for(int i=0; i<_ps.size(); ++i) if (_ps[i] != b._ps[i]) return false; // data differs
        return true;  // same vector length and elements, so they are equal!
    }
    bool Product_list:: operator!=(const Product_list b) {
        return !(*this == b);
    }*/