/**
 * @file main.cpp
 * @brief This file contains the main function that demonstrates how the restaurant menu system works.
 * It includes functionality for displaying menus, calculating the total price of orders, checking vegetarian status,
 * verifying menu availability at a specific time, and handling exceptions.
 */

#include <iostream>
#include <vector>
#include "Ingredient.h"
#include "Dish.h"
#include "Category.h"
#include "Breakfast.h"
#include "Lunch.h"
#include "Dinner.h"
#include "InvalidTimeException.h"
#include "EmptyMenuException.h"
#include "InvalidDishException.h"

int main() {
    // Initialize ingredients
    Ingredient ingr1("Tomatoes", FoodType::VEGETABLE);  ///< Ingredient: Tomatoes, type: Vegetable
    Ingredient ingr2("Mozzarella", FoodType::DAIRY);     ///< Ingredient: Mozzarella, type: Dairy
    Ingredient ingr3("Basil", FoodType::SPICE);          ///< Ingredient: Basil, type: Spice
    Ingredient ingr4("Chicken", FoodType::MEAT);         ///< Ingredient: Chicken, type: Meat
    Ingredient ingr5("Tomato sauce", FoodType::SAUCE);   ///< Ingredient: Tomato sauce, type: Sauce
    Ingredient ingr6("Chocolate", FoodType::DESSERT);    ///< Ingredient: Chocolate, type: Dessert
    Ingredient ingr7("Flour", FoodType::CEREAL);         ///< Ingredient: Flour, type: Cereal

    // Create dishes with ingredients
    Dish dish1("Margherita Pizza", 20.0, 250, {ingr1, ingr2, ingr3, ingr5});  ///< Dish: Margherita Pizza
    Dish dish2("Chicken Caesar Salad", 18.0, 200, {ingr4, ingr1, ingr5});     ///< Dish: Chicken Caesar Salad
    Dish dish3("Chocolate Cake", 15.0, 150, {ingr6, ingr7});                 ///< Dish: Chocolate Cake
    Dish dish4("Pancakes", 12.0, 100, {ingr7, ingr6});                       ///< Dish: Pancakes
    Dish dish5("Scrambled Eggs", 10.0, 150, {ingr2});                        ///< Dish: Scrambled Eggs
    Dish dish6("Grilled Salmon", 30.0, 300, {ingr4});                        ///< Dish: Grilled Salmon

    // Create categories for the dishes
    Category breakfastCategory("Breakfast", {dish4, dish5});  ///< Category: Breakfast, dishes: Pancakes, Scrambled Eggs
    Category lunchCategory("Lunch", {dish1, dish2});           ///< Category: Lunch, dishes: Margherita Pizza, Chicken Caesar Salad
    Category dinnerCategory("Dinner", {dish6});                ///< Category: Dinner, dish: Grilled Salmon
    Category dessertCategory("Desserts", {dish3});             ///< Category: Desserts, dish: Chocolate Cake

    // Create menu objects (Breakfast, Lunch, Dinner)
    Breakfast breakfast({breakfastCategory});              ///< Breakfast menu created
    Lunch lunch({lunchCategory, dessertCategory});          ///< Lunch menu created with a dessert category
    Dinner dinner({dinnerCategory});                        ///< Dinner menu created

    // Store menus in a vector of base class pointers (polymorphism in action)
    std::vector<Menu*> menus;
    menus.push_back(&breakfast);    ///< Add breakfast menu
    menus.push_back(&lunch);        ///< Add lunch menu
    menus.push_back(&dinner);       ///< Add dinner menu

    // Display all menus
    std::cout << "---------- Menus ----------\n";
    for (const auto& menu : menus) {
        menu->print();  ///< Call the virtual print() method to display the menu
        std::cout << "\n";
    }

    // Example of calculating the total price for ordered dishes
    std::vector<Dish> orderedDishes = {dish1, dish3};  ///< Example of ordered dishes: Margherita Pizza, Chocolate Cake
    float totalPrice = Menu::calculateTotalPrice(orderedDishes);  ///< Calculate the total price
    std::cout << "Total price for ordered dishes: " << totalPrice << " RON\n";

    // Check if each menu is vegetarian
    std::cout << "---------- Vegetarian Check ----------\n";
    bool allVegetarian = true;
    for (const auto& dish : breakfastCategory.getDishes()) {
        if (!dish.isVegetarian()) {
            allVegetarian = false;
            break;
        }
    }
    std::cout << "Is the breakfast menu vegetarian? " << (allVegetarian ? "Yes" : "No") << "\n";

    allVegetarian = true;
    for (const auto& dish : lunchCategory.getDishes()) {
        if (!dish.isVegetarian()) {
            allVegetarian = false;
            break;
        }
    }
    std::cout << "Is the lunch menu vegetarian? " << (allVegetarian ? "Yes" : "No") << "\n\n";

    // Check menu availability at a specific time (e.g., 14:00 for lunch)
    std::string time = "14:00";  ///< Example time: 14:00 (lunch time)
    std::cout << "---------- Availability Check at " << time << " ----------\n";

    if (breakfast.isAvailableAt(time)) {
        std::cout << "Breakfast menu is available at " << time << ".\n";
    } else {
        std::cout << "Breakfast menu is not available at " << time << ".\n";
    }

    if (lunch.isAvailableAt(time)) {
        std::cout << "Lunch menu is available at " << time << ".\n";
    } else {
        std::cout << "Lunch menu is not available at " << time << ".\n";
    }

    if (dinner.isAvailableAt(time)) {
        std::cout << "Dinner menu is available at " << time << ".\n";
    } else {
        std::cout << "Dinner menu is not available at " << time << ".\n";
    }

    // ----------------------------------------
    // Display availability using dynamic_cast
    // ----------------------------------------
    std::cout << "\n---------- Availability Check using dynamic_cast at 14:00 ----------\n";

    // Iterate through the menus and use dynamic_cast to determine the specific menu type
    for (const auto& menu : menus) {
        if (auto breakfastMenu = dynamic_cast<Breakfast*>(menu)) {
            std::cout << "Breakfast Menu is available at 14:00: ";
            std::cout << (breakfastMenu->isAvailableAt("14:00") ? "Yes" : "No") << std::endl;
        } else if (auto lunchMenu = dynamic_cast<Lunch*>(menu)) {
            std::cout << "Lunch Menu is available at 14:00: ";
            std::cout << (lunchMenu->isAvailableAt("14:00") ? "Yes" : "No") << std::endl;
        } else if (auto dinnerMenu = dynamic_cast<Dinner*>(menu)) {
            std::cout << "Dinner Menu is available at 14:00: ";
            std::cout << (dinnerMenu->isAvailableAt("14:00") ? "Yes" : "No") << std::endl;
        }
    }

    // ----------------------------------------
    // Handle exceptions with try-catch blocks
    // ----------------------------------------
    try {
        // Simulate an invalid time exception
        throw InvalidTimeException("The specified time for the menu is invalid.");
    } catch (const MenuException& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;  ///< Print the error message
    }

    try {
        // Simulate an empty menu exception
        throw EmptyMenuException("The menu is empty.");
    } catch (const MenuException& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;  ///< Print the error message
    }

    try {
        // Simulate an invalid dish exception
        throw InvalidDishException("The specified dish does not exist.");
    } catch (const MenuException& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;  ///< Print the error message
    }

    return 0;  ///< End of the main function
}
