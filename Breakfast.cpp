#include "Breakfast.h"

/**
 * @brief Constructor for the Breakfast menu.
 *
 * Initializes the breakfast menu with the given categories by calling the base class Menu constructor.
 *
 * @param categories The list of categories for the breakfast menu.
 */
Breakfast::Breakfast(const std::vector<Category>& categories) : Menu(categories) {}

/**
 * @brief Checks if the breakfast menu is available at the given time.
 *
 * Checks whether the time falls within the breakfast hours (08:00 to 10:00).
 *
 * @param time The time to check in "HH:MM" format.
 * @return True if the menu is available, false otherwise.
 */
bool Breakfast::isAvailableAt(const std::string& time) const {
    // The breakfast menu is available between 08:00 and 10:00
    return time >= "08:00" && time <= "10:00";
}

/**
 * @brief Returns the description of the breakfast menu.
 *
 * @return A string that represents the description of the menu.
 */
std::string Breakfast::getDescription() const {
    return "Breakfast Menu";
}

/**
 * @brief Prints the breakfast menu categories.
 *
 * Prints the menu's title followed by each category in the breakfast menu.
 */
void Breakfast::print() const {
    std::cout << "Breakfast Menu:\n";
    // Loop through each category and print it
    for (const auto& category : categories) {
        category.print();  // Calls the print method from the Category class to print the category's details
    }
}
