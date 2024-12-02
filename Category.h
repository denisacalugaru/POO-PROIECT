#ifndef CATEGORY_H
#define CATEGORY_H

#include "Dish.h"  // Include the Dish class to use it within Category
#include <string>   // Include string for handling text data
#include <vector>   // Include vector for storing a collection of Dish objects
#include <iostream> // Include iostream for output streaming (printing to console)
#include <algorithm> // Include algorithm for sorting functions
#include <ranges>    // Include ranges for modern sorting capabilities

// Class representing a category of dishes (e.g., "Breakfast", "Lunch")
class Category {
private:
    std::string name;           // Name of the category (e.g., "Breakfast")
    std::vector<Dish> dishes;   // A list of Dish objects that belong to this category

public:
    // Constructor that initializes the category with a name and a list of dishes
    // @param name: The name of the category (e.g., "Breakfast", "Lunch")
    // @param dishes: A list of Dish objects belonging to this category
    Category(const std::string& name, const std::vector<Dish>& dishes);

    // Sorts the dishes in the category alphabetically by their name
    void sortDishesAlphabetically();

    // Overload the << operator to allow printing Category objects directly
    // @param os: The output stream to write to
    // @param category: The Category object to be printed
    // @return The modified output stream (os)
    friend std::ostream& operator<<(std::ostream& os, const Category& category);

    // Returns the list of dishes in the category
    // @return A vector containing all dishes in the category
    const std::vector<Dish>& getDishes() const;

    // Virtual destructor ensures proper cleanup in derived classes
    virtual ~Category() = default;

    // Prints the category name and details of each dish
    void print() const;

    // Checks if the category is available at a given time of the day
    // This is a virtual function that can be overridden by derived classes
    // @param timeOfDay: The time to check availability for (e.g., "10:00")
    // @return True if the category is available, false otherwise
    bool isAvailableAt(const std::string& timeOfDay) const;
};

#endif // CATEGORY_H
