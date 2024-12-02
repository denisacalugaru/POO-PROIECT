#ifndef LUNCH_H
#define LUNCH_H

#include "Menu.h"

class Lunch : public Menu {
public:
    // Constructor that initializes the lunch menu with categories.
    explicit Lunch(const std::vector<Category>& categories);

    // Method to check if the menu is available at a specific time.
    bool isAvailableAt(const std::string& time) const override;

    // Method to print out the lunch menu.
    void print() const override;

protected:
    // Method to return the description of the lunch menu.
    std::string getDescription() const override;
};

#endif // LUNCH_H
