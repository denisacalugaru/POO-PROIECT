#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Menu.h"

/**
 * @class MenuManager
 * @brief This class manages a Menu object, allowing operations like displaying and sorting the menu.
 *
 * The MenuManager class is designed to handle a pointer to a Menu object, which could be of any derived class.
 * It supports copy and move semantics, as well as functionality for interacting with the Menu object, such as displaying the menu and sorting its categories.
 */
class MenuManager {
private:
    Menu* menu;  ///< Pointer to the base class Menu

public:
    /**
     * @brief Constructor that initializes the MenuManager with a given Menu pointer.
     *
     * This constructor accepts a pointer to a derived Menu object and stores it in the `menu` member variable.
     *
     * @param m A pointer to a Menu object (or derived class). Defaults to nullptr.
     */
    explicit MenuManager(Menu* m = nullptr);

    /**
     * @brief Copy constructor.
     *
     * This constructor creates a new MenuManager instance by copying the data from another MenuManager object.
     *
     * @param other The MenuManager object to copy from.
     */
    MenuManager(const MenuManager& other);

    /**
     * @brief Move constructor for MenuManager.
     *
     * This constructor transfers ownership of the `menu` pointer from another MenuManager instance to the new one.
     * The original instance is left with a null pointer.
     *
     * @param other The MenuManager object to move from.
     */
    MenuManager(MenuManager&& other) noexcept;

    /**
     * @brief Copy assignment operator using the copy-and-swap idiom.
     *
     * This operator performs a safe copy assignment by swapping the current object with a temporary copy of the other object.
     *
     * @param other The MenuManager object to copy from.
     * @return A reference to the current MenuManager object.
     */
    MenuManager& operator=(MenuManager other);

    /**
     * @brief Move assignment operator for MenuManager.
     *
     * This operator moves the `menu` resource from another MenuManager instance to the current one, transferring ownership
     * and nullifying the source.
     *
     * @param other The MenuManager object to move from.
     * @return A reference to the current MenuManager object.
     */
    MenuManager& operator=(MenuManager&& other) noexcept;

    /**
     * @brief Calls the `print()` method of the Menu object.
     *
     * This method invokes the `print()` method of the `menu` object, which is a virtual method defined in the Menu base class
     * or its derived classes.
     */
     void displayMenu() const;

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
     * If no menu was assigned, no deletion occurs.
     */
    ~MenuManager();
};

#endif // MENUMANAGER_H
