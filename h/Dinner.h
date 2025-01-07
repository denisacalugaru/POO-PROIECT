#ifndef DINNER_H
#define DINNER_H

#include "Menu.h"  // Include the base class Menu

// The Dinner class inherits from the Menu class, representing the dinner menu
class Dinner : public Menu {
public:
    // Constructor for the Dinner class, initializes the base Menu class with categories
    // @param categories: A vector of Category objects that represent the available categories in the dinner menu
    explicit Dinner(const std::vector<Category>& categories);

    // Function to check if the dinner menu is available at the specified time
    // @param time: A string representing the time (e.g., "18:00", "20:00")
    // @return true if the time is between 18:00 and 22:00, indicating availability for dinner
    bool isAvailableAt(const std::string& time) const override;

protected:
    // Function to return the description of the dinner menu
    // @return A string representing the description of the dinner menu
    std::string getDescription() const override;

    // Function to print the dinner menu along with its categories and dishes
    void print() const override;
};

#endif // DINNER_H
