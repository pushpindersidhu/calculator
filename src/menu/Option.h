//
// Created by Pushpinder Sidhu on 2023-12-21.
//

#ifndef CALCULATOR_OPTION_H
#define CALCULATOR_OPTION_H

#include <string>
#include "Menu.h"

class Option {
public:
    Option(int id, std::string name, std::string description, Menu::Type type);

    int id;
    std::string name;
    std::string description;
    Menu::Type type;
};


#endif //CALCULATOR_OPTION_H
