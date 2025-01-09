#ifndef MENUINVENTORY_H
#define MENUINVENTORY_H

#include <vector>
#include <iostream>

/**
 * @brief Template class for managing a menu inventory.
 *
 * Allows storing and displaying menus derived from the `Menu` class.
 *
 * @tparam T The type of the menu objects (e.g., Breakfast, Lunch, Dinner).
 */
template <typename T>
class MenuInventory {
private:
    std::vector<T> menus; ///< Vector for storing menu objects.

public:
    /**
     * @brief Adds a menu to the inventory.
     * @param menu The menu object to add.
     */
    void addMenu(const T& menu) {
        menus.push_back(menu);
    }

    /**
     * @brief Displays all menus in the inventory.
     */
    void displayMenus() const {
        std::cout << "Menus in inventory:\n";
        for (const auto& menu : menus) {
            menu.display();
            std::cout << "\n";
        }
    }


};

#endif // MENUINVENTORY_H
