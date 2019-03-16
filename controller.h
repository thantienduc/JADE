#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "view.h"
#include "dialogs.h"

    class Controller{
        public:
            Controller();
            Controller(Store store);
            void cli();
            void execute_cmd(int cmd);
            void add_product();
            std::string list_all_product(bool state);
            void add_order();
            void list_all_order();
            void easter_egg();
            void help();
            void save ();
            void load ();
        private:
            Store _store;
            View _view;
            double get_double(std::string prompt);
            int get_int(std::string prompt);
    };

#endif