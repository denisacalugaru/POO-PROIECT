
#ifndef MENUCONTEXT_H
#define MENUCONTEXT_H


#include "MenuDisplayStrategy.h"

/**
 * @brief The menu context that uses a display strategy.
 */
class MenuContext {
private:
    MenuDisplayStrategy* strategy;  ///< The current display strategy

public:
    MenuContext(MenuDisplayStrategy* initialStrategy)
        : strategy(initialStrategy) {}

    // Change the display strategy
    void setStrategy(MenuDisplayStrategy* newStrategy) {
        strategy = newStrategy;
    }

    // Display the menu using the current strategy
    void displayMenu(const std::string& menuName) const {
        strategy->display(menuName);  ///< Call the display() method from the current strategy
    }
};

#endif
