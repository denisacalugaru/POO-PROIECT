#include "MenuManager.h"
#include <iostream>
#include <algorithm>  // std::swap

/**
 * @brief Constructor that initializes the MenuManager with a given Menu pointer.
 *
 * This constructor accepts a pointer to a derived Menu object and stores it in
 * the `menu` member variable. The pointer is managed by the MenuManager instance.
 *
 * @param m A pointer to a Menu object (or derived class).
 */
MenuManager::MenuManager(Menu* m) : menu(m) {}

/**
 * @brief Move constructor for MenuManager.
 *
 * This constructor transfers ownership of the `menu` pointer from another
 * MenuManager instance to the new one. The original instance is left with a
 * null pointer.
 *
 * @param other The MenuManager object to move from.
 */
MenuManager::MenuManager(MenuManager&& other) noexcept : menu(other.menu) {
    other.menu = nullptr;  // Transfer the resource and nullify the source object
}

/**
 * @brief Copy-and-swap assignment operator.
 *
 * This operator performs a copy-and-swap assignment. The current object
 * swaps its `menu` resource with the temporary `other` object, effectively
 * performing a deep copy of the `menu` pointer.
 *
 * @param other The MenuManager object to copy from.
 * @return A reference to the current MenuManager object.
 */
MenuManager& MenuManager::operator=(MenuManager other) {
    std::swap(menu, other.menu);  // Swap between current object and temporary
    return *this;  // Return reference to the current object
}

/**
 * @brief Move assignment operator for MenuManager.
 *
 * This operator moves the `menu` resource from another MenuManager instance
 * to the current one, transferring ownership and nullifying the source.
 *
 * @param other The MenuManager object to move from.
 * @return A reference to the current MenuManager object.
 */
MenuManager& MenuManager::operator=(MenuManager&& other) noexcept {
    if (this != &other) {  // Avoid self-assignment
        delete menu;  // Free the current resource
        menu = other.menu;  // Transfer ownership
        other.menu = nullptr;  // Nullify the source pointer
    }
    return *this;
}

/**
 * @brief Calls the `print()` method of the Menu object.
 *
 * This method invokes the `print()` method of the `menu` object, which is
 * a virtual method defined in the Menu base class or its derived classes.
 */
[[maybe_unused]]void MenuManager::displayMenu() const {
    menu->print();  // Call the print function from the derived class
}

/**
 * @brief Calls the `sortCategories()` method of the Menu object.
 *
 * This method invokes the `sortCategories()` method of the `menu` object,
 * which sorts the categories of the menu.
 */
void MenuManager::sortCategories() const {
    menu->sortCategories();  // Call the sortCategories function from the base class
}

/**
 * @brief Destructor for MenuManager.
 *
 * The destructor cleans up the resources by deleting the managed `menu` object.
 * If no menu was assigned, no deletion occurs.
 */
MenuManager::~MenuManager() {
    delete menu;  // Clean up the allocated resource
}
