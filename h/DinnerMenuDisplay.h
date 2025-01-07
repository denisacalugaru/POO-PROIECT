#ifndef DINNERMENUDISPLAY_H
#define DINNERMENUDISPLAY_H


#include "MenuDisplayStrategy.h"
#include <iostream>

/**
 * @brief Strategy for displaying the dinner menu.
 */
class DinnerMenuDisplay : public MenuDisplayStrategy {
public:
    void display(const std::string& menuName) const override {
        std::cout << "Displaying " << menuName << " menu with dinner items!" << std::endl;
    }
};

#endif

