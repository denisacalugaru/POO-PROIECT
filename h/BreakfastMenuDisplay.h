
#ifndef BREAKFASTMENUDISPLAY_H
#define BREAKFASTMENUDISPLAY_H


#include "MenuDisplayStrategy.h"
#include <iostream>

/**
 * @brief Strategy for displaying the breakfast menu.
 */
class BreakfastMenuDisplay : public MenuDisplayStrategy {
public:
    void display(const std::string& menuName) const override {
        std::cout << "Displaying " << menuName << " menu with breakfast items!" << std::endl;
    }
};

#endif

