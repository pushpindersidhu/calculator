#include <iostream>
#include "menu/Menu.h"

using namespace std;

int main() {
    Menu::Menu menu(Menu::Type::SCIENTIFIC);
    menu.mainloop();
    return 0;
}
