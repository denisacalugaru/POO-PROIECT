#include "../h/Dinner.h"

// Constructor for the Dinner class that initializes the base Menu class with categories
// @param categories: A vector of Category objects that define the available categories in the dinner menu
Dinner::Dinner(const std::vector<Category>& categories) : Menu(categories) {}

// Function to check if the dinner menu is available at the specified time
// @param time: A string representing the time (e.g., "18:00", "20:00")
// @return true if the time is between 18:00 and 22:00, indicating availability for dinner
bool Dinner::isAvailableAt(const std::string& time) const {
    // Dinner menu is available from 18:00 to 22:00
    return time >= "18:00" && time <= "22:00";
}

// Function to print the dinner menu and all its categories and dishes
void Dinner::print() const {
    std::cout << "Dinner Menu:\n"; // Print header for the dinner menu
    // Iterate through each category and print its details
    for (const auto& category : categories) {
        category.print();  // Print each category's details using its print method
    }
}

// Function to return the description of the dinner menu
// @return A string representing the description of the dinner menu
std::string Dinner::getDescription() const {
    return "Dinner Menu";  // Return a simple description string for the dinner menu
}
