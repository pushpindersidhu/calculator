//
// Created by Pushpinder Sidhu on 2023-12-21.
//

#ifndef CALCULATOR_MENU_H
#define CALCULATOR_MENU_H

namespace Menu {

    enum class Type {
        BASIC,
        SCIENTIFIC
    };

    class Menu {
    private:
        Type _type;
        std::string results;

        void displayMenu();
        void displayMenuHeader() const;

        static void clearScreen();
        static void prompt();
        static int getOption();
    public:
        explicit Menu(Type type);

        [[nodiscard]] Type getType() const;
        void setType(Type type);

        void mainloop();
    };
} // Menu

#endif //CALCULATOR_MENU_H
