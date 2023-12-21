//
// Created by Pushpinder Sidhu on 2023-12-21.
//

#include "Option.h"
#include "Menu.h"


Option::Option(
        int id,
        std::string name,
        std::string description,
        Menu::Type type) :
        id(id),
        name(std::move(name)),
        description(std::move(description)),
        type(type) {}