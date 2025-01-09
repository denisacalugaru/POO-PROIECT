#include "../h/Category.h"

// Constructor that initializes the category with a name and a list of dishes
// @param name The name of the category (e.g., "Breakfast", "Lunch")
// @param dishes A vector of Dish objects that belong to this category
Category::Category(const std::string& name, const std::vector<Dish>& dishes)
    : name(name), dishes(dishes) {}

// Sorts the dishes in the category alphabetically by their name
void Category::sortDishesAlphabetically() {
    std::ranges::sort(dishes, [](const Dish& a, const Dish& b) {
        // Comparison of dish names (alphabetical order)
        return a.getName() < b.getName();
    });
}

// Checks if the category is available at a given time of the day
// This could be overridden by derived classes to provide more specific logic
// @param timeOfDay The time in "HH:MM" format to check for availability
// @return Always returns true in the current implementation
bool Category::isAvailableAt([[maybe_unused]]const std::string& timeOfDay) const {
    // Currently, it is a placeholder that always returns true.
    // In a more complex system, this function would check if the category is available at the given time.
    return true;
}

// Prints the name of the category and details of each dish (name and price)
void Category::print() const {
    std::cout << "Category: " << name << "\n";  // Print category name
    for (const auto& dish : dishes) {
        // Print each dish's name and price
        std::cout << dish.getName() << ": " << dish.getPrice() << " RON\n";
    }
}


// Returns the list of dishes in the category
// @return A vector containing all the dishes in the category
const std::vector<Dish>& Category::getDishes() const {
    return dishes;  // Return the list of dishes
}

// Overloading the output stream operator to print a Category object
// This allows Category objects to be printed directly using std::cout or similar
// @param os The output stream to write to
// @param category The Category object to print
// @return The modified output stream
std::ostream& operator<<(std::ostream& os, const Category& category) {
    os << "Category: " << category.name << "\n";  // Print category name
    for (const auto& dish : category.dishes) {
        // Print each dish in the category by calling its overloaded operator<<
        os << dish << "\n";
    }
    return os;  // Return the output stream after writing
}
