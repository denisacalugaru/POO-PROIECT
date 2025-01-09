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
 * @brief Static method to get the Singleton instance of MenuManager.
 *
 * Ensures that only one instance of MenuManager exists. If the instance does not exist,
 * it creates a new one. Subsequent calls will return the same instance.
 *
 * @param m Pointer to a Menu object. Defaults to nullptr
 * @return MenuManager& Reference to the Singleton instance.
 */
MenuManager& MenuManager::getInstance(Menu* m) {
    if (instance == nullptr) {
        instance = new MenuManager(m);
    }
    return *instance;
}

/**
 * @brief Sets a new Menu object to be managed by MenuManager.
 *
 * Deletes the existing `menu` object (if any) and assigns the new Menu pointer.
 *
 * @param m Pointer to the new Menu object.
 */
void MenuManager::setMenu(Menu* m) {
    if (menu) {
        delete menu;  // Clean up existing menu
    }
    menu = m;
}

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
