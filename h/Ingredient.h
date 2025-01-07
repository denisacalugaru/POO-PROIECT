#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <iostream>

// Enum class for FoodType, representing different categories of food
enum class FoodType {
    VEGETABLE,
    DAIRY,
    MEAT,
    SPICE,
    SAUCE,
    DESSERT,
    CEREAL
};

class Ingredient {
private:
    std::string name;  // Name of the ingredient (e.g., "Tomato", "Cheese")
    FoodType type;    // The type of the ingredient (using FoodType enum)

public:
    // Constructor to initialize the ingredient with a name and type
    // @param name: Name of the ingredient
    // @param type: Type of the ingredient (from FoodType enum)
    Ingredient(std::string name, FoodType type);

    // Getter for the name of the ingredient
    // @return: A constant reference to the name of the ingredient
    [[nodiscard]] const std::string& getName() const;

    // Getter for the type of the ingredient
    // @return: The type of the ingredient (FoodType)
    [[nodiscard]] FoodType getType() const;

    // Friend function to overload the << operator for easy printing
    // @param os: Output stream to which the ingredient will be written
    // @param ingredient: The ingredient object to be printed
    // @return: The output stream after printing the ingredient's name
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient);

    // Destructor (default implementation)
    ~Ingredient() = default;
};

#endif // INGREDIENT_H
