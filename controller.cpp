#include "controller.h"
#include <fstream>
#include <iostream>

Controller::Controller(Store store): _store{store}, _view{store}{};

void Controller::cli(){
    int cmd=1;
    while(cmd){
        std::cout << _view.main_menu();
        std::cout << _store.num_orders() << std::endl;
        std::cin >> cmd;
        execute_cmd(cmd);
    }
}

void Controller::execute_cmd(int cmd){
    switch (cmd)
    {
        case 1: add_product(); break;
        case 2: list_all_product(); break;
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
    std::cout << "Enter the name and price of product: ";
    std::cin >>name>>price;
    _store.add_product(Product(name,price));
    std::string answer;
    std::cout << "Do you want to continue or not (y or n): "<<std::endl;
    std::cin >> answer;
    if (answer =="y") cont =true;
    else cont =false;
    }
}

void Controller::list_all_product(){
    std::cout << _store <<std::endl;
}

void Controller::add_order(){
    std::string email;
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
    }
}

void Controller::list_all_order(){
    for(int i =0; i<_store.num_orders();i++) {
        std::cout << "Order ID: " << i+1 << std::endl;
        std::cout << _store.order(i) <<std::endl;
    }
}

void Controller::help(){
    _view.help();
}

void Controller::save(){
    std::string path = "./database";
    _store.save(path);
}

void Controller::load(){
    std::string path = "./database";
    _store.load(path);
}

