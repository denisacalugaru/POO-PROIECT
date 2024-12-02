#include "Ingredient.h"

Ingredient::Ingredient(std::string name, FoodType type)
    : name(std::move(name)), type(type) {}  // Initialize name and type using an initializer list

// Getter for the name of the ingredient
// @return: A constant reference to the ingredient's name
const std::string& Ingredient::getName() const {
    return name;  // Return the name of the ingredient
}

// Getter for the type of the ingredient
// @return: The FoodType of the ingredient (e.g., Meat, Vegetable, etc.)
FoodType Ingredient::getType() const {
    return type;  // Return the type of the ingredient
}

// Output stream operator overload for Ingredient
// @param os: The output stream to print to
// @param ingredient: The Ingredient object to print
// @return: The output stream after printing the ingredient's name
std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
    os << ingredient.name;  // Print the name of the ingredient
    return os;  // Return the stream so it can be chained
}
