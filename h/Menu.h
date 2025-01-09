#ifndef MENU_H
#define MENU_H

#include "Category.h"
#include "Subject.h" // Include Subject pentru integrarea Observer Pattern
#include <vector>
#include <iostream>

/**
 * @brief Abstract base class representing a Menu.
 *
 * The Menu class is an abstract base class that holds a collection of categories
 * and provides functionality to sort categories, calculate total price, and
 * check availability. It also extends Subject to support notifications for
 * changes, such as adding or removing categories.
 */

class Menu : public Subject {
protected:
    std::vector<Category> categories; /**< A vector of Category objects representing the menu's sections. */

   public:
    /**
     * @brief Constructor that initializes a Menu with a list of categories.
     *
     * @param categories A vector of Category objects that represent different sections of the menu.
     */
    explicit Menu(const std::vector<Category>& categories);

    /**
     * @brief Pure virtual function to check if the menu is available at a specific time.
     *
     * @param time The time of day to check availability.
     * @return True if the menu is available at the specified time, false otherwise.
     */
    virtual bool isAvailableAt(const std::string& time) const = 0;

    /**
     * @brief Pure virtual function for printing the details of the menu.
     *
     * This method should be implemented by derived classes to print the menu's specific content.
     */
    virtual void print() const = 0;

    /**
     * @brief Sorts the categories of the menu and their respective dishes alphabetically.
     */
    void sortCategories();

    /**
     * @brief Adds a new category to the menu and notifies observers.
     * @param category The category to add.
     */
    void addCategory(const Category& category);

    /**
     * @brief Removes a category from the menu by name and notifies observers.
     * @param categoryName The name of the category to remove.
     */
    void removeCategory(const std::string& categoryName);

    /**
     * @brief Returns the categories of the menu.
     *
     * @return A vector of Category objects representing the menu's sections.
     */
    std::vector<Category> getCategory() const;

    /**
     * @brief Static function to calculate the total price of a list of ordered dishes.
     *
     * @param orderedDishes A vector of Dish objects representing the dishes ordered by the customer.
     * @return The total price of the ordered dishes.
     */
    static float calculateTotalPrice(const std::vector<Dish>& orderedDishes);

    /**
     * @brief Overloaded stream insertion operator to print the Menu details.
     *
     * This operator prints the Menu object in a readable format, listing all categories and their dishes.
     *
     * @param os The output stream to which the Menu will be printed.
     * @param menu The Menu object to be printed.
     * @return The output stream with the menu printed.
     */
    friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

    virtual ~Menu() = default; /**< Virtual destructor. */

    /**
     * @brief Check the availability of the menu based on the time.
     * @param time The time to check (e.g., "12:00").
     */
    void checkAvailability(const std::string& time);

    /**
     * @brief Check if the menu is empty and notify observers if necessary.
     * @param menuItems A list of menu item names.
     */
    void checkMenuEmpty(const std::vector<std::string>& menuItems);

    /**
     * @brief Check the validity of a dish name.
     * @param dish The name of the dish to validate.
     */
    void checkDishValidity(const std::string& dish);

    void display() const {
    print();
 }

protected:
    /**
     * @brief Pure virtual function for returning a description of the menu.
     *
     * This method should be implemented by derived classes to return a description
     * specific to the type of menu (e.g., "Breakfast Menu", "Lunch Menu").
     *
     * @return A string representing the description of the menu.
     */
    virtual std::string getDescription() const = 0;
 ~Menu() override = default;

};

#endif // MENU_H
