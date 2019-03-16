#include "controller.h"
#include <fstream>
#include <iostream>

Controller::Controller(Store store): _store{store}, _view{store}{};

double Controller::get_double(std::string prompt) {
    while(true) {
        try {

            std::string s = Dialogs::input(prompt);

            if(s == "") break;
            std::istringstream iss{s};
            double d;
            iss >> d;
            return d;
        } catch(std::runtime_error e) {
            std::cerr << "Error: Invalid input: " << e.what() << std::endl;
        }
    }
    throw std::runtime_error{prompt + " was not detected"};
}
int Controller::get_int(std::string prompt) {
    while(true) {
        try {
            std::string s = Dialogs::input(prompt);
            if(s == "") break;
            std::istringstream iss{s};
            int d;
            iss >> d;
            return d;
        } catch(std::runtime_error e) {
            std::cerr << "Error: Invalid input: " << e.what() << std::endl;
        }
    }
    throw std::runtime_error{prompt + " was not detected"};
}

void Controller::cli(){
    int cmd=1;
    while(true){
        try {
            std::string Message = _view.main_menu();
            //Message += "\n\nCommand?";

            cmd = get_int(Message);

            if (cmd == 0) break;
            execute_cmd(cmd);
        } catch (std::runtime_error e) {
            std::cerr << "Error: Invalid input" << std::endl;
        }
    }
}

void Controller::execute_cmd(int cmd){
    switch (cmd)
    {
        case 1: add_product(); break;
        case 2: list_all_product(true); break;
        case 3: add_order(); break;
        case 4: list_all_order(); break;
        case 5: help(); break;
        case 6: save();break;
        case 7: load();break;
        case 0: break; 
        default: cmd =6;
            break;
    }
}

void Controller::add_product(){
    std::string name;
    double price;
    bool cont = true;
    while(cont){
    try {
        name = Dialogs::input("Product name?");
        if (name.empty()) throw std::runtime_error{"Unavailable product name"};
        price = get_double("Price?");
        _store.add_product(Product{name, price});
    } catch(std::runtime_error e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::vector<std::string> buttons ={"Yes","No"};
    int conti= Dialogs::question("Do you want continue?","Decide!",buttons);
    if (conti ==0) cont =true;
    else cont =false;
    }
}

std::string Controller::list_all_product(bool state){
    std::stringstream iss;
    iss << "\nAvailable Products\n";
    for(int i=0; i<_store.num_products(); ++i)
    {
      iss << i << ") " << _store.product(i) << std::endl;
    }
    std::string message = iss.str();
    if(state==true) {
    Dialogs::message(message,"All Products");
      }
    return message;
}

void Controller::add_order(){
    /*std::string email;
    std::cout << "Enter your email address: ";
    std::cin >> email;
    int orderid=_store.create_order(email);
    bool cont=true;
    std::string name;
    double price;
    int num;
    while(cont){
        std::cout << "Enter the name of product and price: ";
        std::cin >> name >> price;
        std::cout << "Enter the quantity: ";
        std::cin >> num;
        Product_order pro(name,price,num);
        _store.add_to_order(orderid, pro); 
        std::string answer;
        std::cout << "Do you want to continue or not (y or n): "<<std::endl;
        std::cin >> answer;
        if (answer =="y") cont =true;
        else cont =false;
    }*/
    try {
        std::string email=Dialogs::input("Customer email address? ");

        if (email.empty()) throw std::runtime_error{"Empty email address"};
        int order_num = _store.create_order(email);

        while(true) {
            std::stringstream iss;
            iss << "\n\nCurrent Products in Order " << order_num << "\n\n"
                      << _store.order(order_num) << "\n" << "\n";
            iss<<Controller::list_all_product(false);
            iss<<"\n\n"<<"Product number to add (-1 when done)";
            int product_num = get_int(iss.str());

            if (0 <= product_num && product_num < _store.num_products()) {
                int product_quantity = get_int("Quantity?");
                if (0 <= product_quantity)
                    _store.add_to_order(order_num, Product_order{_store.product(product_num), product_quantity});
                else
                    std::cerr << "Invalid quantity: " << product_quantity << std::endl;
            } else if (product_num == -1) {
                break;
            } else {
                std::cerr << "No such product number: " << product_num << std::endl;
            }
        }
    } catch (std::runtime_error e) {
        std::cerr << "Place Order aborted: " << e.what() << std::endl;
    }
}

void Controller::list_all_order(){
    std::stringstream iss;
    for(int i=0; i<_store.num_orders(); ++i)
    {
      iss << i << ") " << _store.order(i) << "\n";
    }
    std::string message = iss.str();
    Dialogs::message(message,"All Orders");
}

void Controller::help(){
    std::string Message=_view.help();
    Dialogs::message(Message,"Help");
}

void Controller::easter_egg(){
    _store.add_product(Product("soda",3.44));
}

void Controller::save(){
    std::string path = "./database";
    _store.save(path);
}

void Controller::load(){
    std::string path = "./database";
    _store.load(path);
}

