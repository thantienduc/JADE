#ifndef __VIEW_H
#define __VIEW_H
#include "store.h"

class View{
    private:
        Store& _store;
    public:
        View(Store& store);
        std::string main_menu();
        std::string help();

};
#endif