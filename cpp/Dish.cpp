#include "../h/Dish.h"

// Constructor for the Dish class, initializing all member variables
// @param name: The name of the dish
// @param price: The price of the dish
// @param weight: The weight of the dish
// @param ingredients: A vector of Ingredient objects that the dish consists of

int Dish::instanceCount=0;
Dish::Dish(std::string name, float price, float weight, const std::vector<Ingredient>& ingredients)
    : name(std::move(name)), price(price), weight(weight), ingredients(ingredients) {
  instanceCount++;
    }

// Returns the name of the dish
// @return The name of the dish
const std::string& Dish::getName() const {
    return name;
}

// Returns the price of the dish
// @return The price of the dish
float Dish::getPrice() const {
    return price;
}

// Checks if the dish is vegetarian by inspecting its ingredients
// @return true if the dish contains no meat, otherwise false
bool Dish::isVegetarian() const {
    // Iterates over each ingredient to check if any is of type MEAT
    for (const auto& ingredient : ingredients) {
        if (ingredient.getType() == FoodType::MEAT) {
            return false;  // Dish is not vegetarian if it contains meat
        }
    }
    return true;  // Dish is vegetarian if no meat ingredient is found
}
int Dish::getInstanceCount() {return instanceCount;}


// Overloads the stream insertion operator to print a detailed representation of the dish
// @param os: The output stream
// @param dish: The dish to be printed
// @return The output stream with the dish's details inserted
std::ostream& operator<<(std::ostream& os, const Dish& dish) {
    os << "Dish: " << dish.name << " - Price: " << dish.price << " RON\n";  // Print dish name and price
    os << "Ingredients: \n";
    for (const auto& ingredient : dish.ingredients) {
        os << "  - " << ingredient << "\n";  // Print each ingredient in the dish
    }
    return os;
}

// Prints a simplified representation of the dish with just its name and price
void Dish::print() const {
    std::cout << name << ": " << price << " RON";
}
