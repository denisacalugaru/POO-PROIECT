#ifndef BREAKFAST_H
#define BREAKFAST_H

#include "Menu.h"  // Include the Menu base class for inheritance

// The Breakfast class is a derived class of Menu
// It represents the breakfast menu and overrides methods from the Menu class.
class Breakfast : public Menu {

public:
    /**
     * @brief Constructor for the Breakfast class.
     *
     * Initializes the breakfast menu with a list of categories.
     * Calls the constructor of the base Menu class to initialize the menu categories.
     *
     * @param categories A vector of Category objects that represent the categories in the breakfast menu.
     */
    explicit Breakfast(const std::vector<Category>& categories);

    /**
     * @brief Checks if the breakfast menu is available at the given time.
     *
     * The breakfast menu is available only within specific hours (e.g., 08:00 - 10:00).
     *
     * @param time The time in "HH:MM" format to check for availability.
     * @return True if the menu is available at the given time, otherwise false.
     */
    bool isAvailableAt(const std::string& time) const override;

protected:
    /**
     * @brief Returns a description of the breakfast menu.
     *
     * The description will be "Breakfast Menu", which is specific to the Breakfast class.
     *
     * @return A string that represents the description of the menu.
     */
    std::string getDescription() const override;

    /**
     * @brief Prints the details of the breakfast menu, including the categories.
     *
     * The print function loops through the categories of the breakfast menu and prints them.
     */
    void print() const override;

};

#endif // BREAKFAST_H
