

#ifndef LUNCHMENUDISPLAY_H
#define LUNCHMENUDISPLAY_H


#include "MenuDisplayStrategy.h"
#include <iostream>

/**
 * @brief Strategy for displaying the lunch menu.
 */
class LunchMenuDisplay : public MenuDisplayStrategy {
public:
    void display(const std::string& menuName) const override {
        std::cout << "Displaying " << menuName << " menu with lunch items!" << std::endl;
    }
};

#endif
