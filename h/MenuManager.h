#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Menu.h"

/**
 * @class MenuManager
 * @brief Singleton class to manage a Menu object, ensuring only one instance exists.
 *
 * The MenuManager class is responsible for managing a pointer to a Menu object, allowing operations like displaying
 * and sorting the menu. It follows the Singleton design pattern to ensure a single instance exists throughout the program.
 */
class MenuManager {
private:
    Menu* menu;  ///< Pointer to the base class Menu
    static MenuManager* instance;  ///< Static instance for the Singleton

    /**
     * @brief Private constructor for Singleton pattern.
     *
     * This ensures the class cannot be instantiated directly.
     *
     * @param m Optional pointer to a Menu object.
     */
    explicit MenuManager(Menu* m = nullptr);

public:
    /**
     * @brief Static method to access the unique instance of MenuManager.
     *
     * This ensures that only one instance of MenuManager exists. If the instance does not exist, it is created.
     *
     * @param m Optional pointer to initialize the menu (only applies on the first call).
     * @return MenuManager& The single instance of MenuManager.
     */
    static MenuManager& getInstance(Menu* m = nullptr);

    /**
     * @brief Sets a new Menu object to be managed.
     *
     * @param m Pointer to the new Menu object.
     */
    void setMenu(Menu* m);

    /**
     * @brief Calls the `print()` method of the Menu object.
     *
     * This method invokes the `print()` method of the `menu` object, which is a virtual method defined in the Menu base class
     * or its derived classes.
     */
    [[maybe_unused]] void displayMenu() const;

    /**
     * @brief Calls the `sortCategories()` method of the Menu object.
     *
     * This method invokes the `sortCategories()` method of the `menu` object, which sorts the categories of the menu.
     */
    void sortCategories() const;

    /**
     * @brief Destructor for MenuManager.
     *
     * The destructor cleans up the resources by deleting the managed `menu` object.
     */
    ~MenuManager();

    // Deleted copy constructor and assignment operator to enforce Singleton
    MenuManager(const MenuManager&) = delete;
    MenuManager& operator=(const MenuManager&) = delete;
};

#endif // MENUMANAGER_H
