#ifndef MENUDISPLAYSTRATEGY_H
#define MENUDISPLAYSTRATEGY_H



#include <string>

/**
 * @brief Interface for menu display strategy.
 * Each menu type will implement this interface to display dishes in a specific way.
 */
class MenuDisplayStrategy {
public:
    virtual ~MenuDisplayStrategy() = default;

    /**
     * @brief Method to display the menu.
     *
     * @param menuName The name of the menu (e.g., "Breakfast", "Lunch", "Dinner").
     */
    virtual void display(const std::string& menuName) const = 0;
};

#endif

