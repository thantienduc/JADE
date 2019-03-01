#include "view.h"
#include <iostream>
#include <fstream>
#include <streambuf>

View::View(Store& store): _store{store}{};

std::string View::main_menu(){
    std::ifstream menu("./main_menu.txt");
    std::string str;
    menu.seekg(0, std::ios::end);   
    str.reserve(menu.tellg());
    menu.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(menu)),
            std::istreambuf_iterator<char>());
            return str;
}

std::string View::help(){
    std::ifstream help("./help.txt");
    std::string str;
    help.seekg(0, std::ios::end);   
    str.reserve(help.tellg());
    help.seekg(0, std::ios::beg);
    str.assign((std::istreambuf_iterator<char>(help)),
            std::istreambuf_iterator<char>());
    return str;
}