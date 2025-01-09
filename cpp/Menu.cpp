#include "../h/Menu.h"
#include "../h/InvalidDishException.h"
#include "../h/InvalidTimeException.h"
#include "../h/EmptyMenuException.h"
#include"../h/Category.h"
#include"../h/Dish.h"
#include<stdexcept>


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
[[maybe_unused]] void Menu::checkAvailability(const std::string& time) {
    if (time != "08:00" && time != "12:00" && time != "18:00") {
        throw InvalidTimeException("Invalid time for menu availability.");
    }
}

[[maybe_unused]] void Menu::checkMenuEmpty(const std::vector<std::string>& menuItems) {
    if (menuItems.empty()) {
        throw EmptyMenuException("The menu is empty.");
    }
}

[[maybe_unused]] void Menu::checkDishValidity(const std::string& dish) {
    if (dish != "Pizza" && dish != "Pasta" && dish != "Burger") {
        throw InvalidDishException("The specified dish does not exist.");
    }
}

void Menu::addCategory(const Category& category) {
    categories.push_back(category);
    notify("Category added: " + category.getName()); // Notify observers
}

void Menu::removeCategory(const std::string& categoryName) {
    auto it = std::remove_if(categories.begin(), categories.end(), [&](const Category& category) {
        return category.getName() == categoryName;
    });
    if (it != categories.end()) {
        categories.erase(it, categories.end());
        notify("Category removed: " + categoryName); // Notify observers
    }

}
