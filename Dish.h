#ifndef DISH_H
#define DISH_H

#include "Ingredient.h"
#include <string>
#include <vector>
#include <iostream>

// Represents a dish on the menu with its properties and ingredients
class Dish {
private:
    std::string name;            // Name of the dish
    float price;                 // Price of the dish
    [[maybe_unused]]float weight;                // Weight of the dish (could be useful in some menus)
    std::vector<Ingredient> ingredients;  // List of ingredients that make up the dish

public:
    // Constructor to initialize a dish object
    // @param name: Name of the dish
    // @param price: Price of the dish
    // @param weight: Weight of the dish
    // @param ingredients: A vector of Ingredient objects that are part of the dish
    Dish(std::string name, float price, float weight, const std::vector<Ingredient>& ingredients);

    // Returns the name of the dish
    // @return The name of the dish
    [[nodiscard]] const std::string& getName() const;

    // Returns the price of the dish
    // @return The price of the dish
    [[nodiscard]] float getPrice() const;

    // Checks whether the dish is vegetarian based on its ingredients
    // @return true if no meat is found in the ingredients, otherwise false
    bool isVegetarian() const;

    // Overloads the stream insertion operator to print the dish's details
    // @param os: Output stream where the dish details will be inserted
    // @param dish: The dish whose details are to be printed
    // @return The output stream with the inserted dish details
    friend std::ostream& operator<<(std::ostream& os, const Dish& dish);

    // Destructor (default implementation)
    ~Dish() = default;

    // Prints the name and price of the dish
    void print() const;
};

#endif // DISH_H
