#include "Breakfast.h"

/**
 * @brief Constructor for the Breakfast menu.
 *
 * This constructor initializes the Breakfast menu with the given categories.
 * It calls the base class Menu constructor to set the categories.
 *
 * @param categories The list of categories for the breakfast menu.
 */
Breakfast::Breakfast(const std::vector<Category>& categories) : Menu(categories) {}

/**
 * @brief Checks if the breakfast menu is available at the given time.
 *
 * This function checks if the current time is within the valid range for breakfast (08:00 - 10:00).
 *
 * @param time The time to check in "HH:MM" format.
 * @return True if the menu is available, false otherwise.
 */
bool Breakfast::isAvailableAt(const std::string& time) const {
    // Implementation for the breakfast menu time range
    return time >= "08:00" && time <= "10:00";
}

/**
 * @brief Returns the description of the breakfast menu.
 *
 * @return A string describing the menu as "Breakfast Menu".
 */
 [[maybe_unused]]std::string Breakfast::getDescription() const {
    return "Breakfast Menu";
}

/**
 * @brief Prints the categories of the breakfast menu.
 *
 * This function prints the "Breakfast Menu" title followed by the details of each category
 * in the breakfast menu by calling the print function from the Category class.
 */
void Breakfast::print() const {
    std::cout << "Breakfast Menu:\n";
    for (const auto& category : categories) {
        category.print();  // Calling the print method from the `Category` class
    }
}
