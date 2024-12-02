#include "Menu.h"

Menu::Menu(const std::vector<Category>& categories) : categories(categories) {}

void Menu::sortCategories() {
    // Iterate through each category and sort its dishes alphabetically
    for (auto& category : categories) {
        category.sortDishesAlphabetically();
    }
}

float Menu::calculateTotalPrice(const std::vector<Dish>& orderedDishes) {
    float total = 0.0;

    // Sum up the prices of the ordered dishes
    for (const auto& dish : orderedDishes) {
        total += dish.getPrice();
    }
    return total;
}

std::ostream& operator<<(std::ostream& os, const Menu& menu) {
    os << "Menu:\n";

    // Iterate through the categories and print each one using the overloaded operator
    for (const auto& category : menu.categories) {
        os << category << "\n";
    }

    return os;
}

void Menu::print() const {
    // Print all categories of the menu
    for (const auto& category : categories) {
        category.print();
    }
}
