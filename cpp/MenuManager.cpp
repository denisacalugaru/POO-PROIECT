#include "../h/MenuManager.h"

// Initialize the static instance to nullptr
/**
 * @brief Static instance of MenuManager, initialized to nullptr.
 *
 * Used to ensure only one instance of MenuManager exists (Singleton pattern).
 */
MenuManager* MenuManager::instance = nullptr;

/**
 * @brief Constructor for MenuManager.
 *
 * Initializes the `menu` pointer to the provided Menu object.
 *
 * @param m Pointer to a Menu object. Defaults to nullptr.
 */
MenuManager::MenuManager(Menu* m) : menu(m) {}


/**
 * @brief Displays the menu using the `print()` method of the Menu object.
 *
 * This method calls the `print()` method of the `menu` object, which is defined
 * in the Menu base class or its derived classes. If no menu is set, nothing happens.
 */
void MenuManager::displayMenu() const {
    if (menu) {
        menu->print();
    }
}

/**
 * @brief Sorts the menu categories using the `sortCategories()` method.
 *
 * This method calls the `sortCategories()` method of the `menu` object, which sorts
 * the categories of the menu. If no menu is set, nothing happens.
 */
void MenuManager::sortCategories() const {
    if (menu) {
        menu->sortCategories();
    }
}

/**
 * @brief Destructor for MenuManager.
 *
 * Deletes the managed `menu` object to free resources. If no menu is set, no action is taken.
 */
MenuManager::~MenuManager() {
    delete menu;
}
