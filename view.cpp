#include "view.h"
#include <iostream>
#include <fstream>
#include <streambuf>

View::View(Store& store): _store{store}{};

std::string View::main_menu(){

    std::ifstream ifs("./main_menu.txt");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    return content;
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