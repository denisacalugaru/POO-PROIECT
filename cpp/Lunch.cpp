#include "../h/Lunch.h"

Lunch::Lunch(const std::vector<Category>& categories) : Menu(categories) {}

bool Lunch::isAvailableAt(const std::string& time) const {
    // This function checks if the lunch menu is available at the specified time
    // The lunch menu is available between 12:00 and 16:00
    return time >= "12:00" && time <= "16:00";
}

std::string Lunch::getDescription() const {
    // This function returns a description for the lunch menu
    return "Lunch Menu";
}

void Lunch::print() const {
    // This function prints out the details of the lunch menu
    std::cout << "Lunch Menu:\n";
    // Iterates through each category and calls the `print` method to display it
    for (const auto& category : categories) {
        category.print();
    }
}
