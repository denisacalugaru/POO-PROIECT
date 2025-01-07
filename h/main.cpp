#include <iostream>
#include <vector>
#include "../h/Ingredient.h"
#include "../h/Dish.h"
#include "../h/Category.h"
#include "../h/Breakfast.h"
#include "../h/Lunch.h"
#include "../h/Dinner.h"
#include "../h/InvalidTimeException.h"
#include "../h/EmptyMenuException.h"
#include "../h/InvalidDishException.h"
#include "MenuContext.h"
#include "BreakfastMenuDisplay.h"
#include "LunchMenuDisplay.h"
#include "DinnerMenuDisplay.h"
#include "MenuManager.h"

/**
 * @brief Template function to calculate the average of numeric values in a vector.
 *
 * This function is designed to calculate the average of numeric values in a vector.
 * It works with any numeric type (like int, float, or double) and returns the average
 * as the same type.
 *
 * @tparam T The type of the values in the vector (numeric types such as int, float, double).
 * @param values A vector containing the values for which the average is to be calculated.
 * @return The average value of the numbers in the vector.
 */
template <typename T>
T calculateAverage(const std::vector<T>& values) {
    T sum = 0;
    for (const T& value : values) {
        sum += value;
    }
    return sum / values.size();
}

/**
 * @brief Template specialization for `calculateAverage` when the type is `std::string`.
 *
 * This specialization is specifically for vectors of strings. Instead of calculating
 * the numeric average, it concatenates the strings and returns the concatenated result.
 *
 * @param values A vector of strings to be concatenated.
 * @return The concatenated string formed from all the strings in the vector.
 */
template <>
std::string calculateAverage(const std::vector<std::string>& values) {
    std::string result;
    for (const auto& value : values) {
        result += value + " ";  ///< Concatenate each string with a space.
    }
    return result;
}

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
    menus.push_back(&dinner);      ///< Add dinner menu

    // Display all menus
    std::cout << "---------- Menus ----------\n";
    for (const auto* menu : menus) {
        menu->print();  ///< Call the virtual print() method to display the menu
        std::cout << "\n";
    }
    std::cout << "Number of Dish instances: " << Dish::getInstanceCount() << "\n";

    // Calculate the average price of dishes (template instantiation)
    std::vector<float> prices = {dish1.getPrice(), dish2.getPrice(), dish3.getPrice(), dish4.getPrice(), dish5.getPrice(), dish6.getPrice()};
    float averagePrice = calculateAverage(prices);  ///< Template instantiation for float
    std::cout << "Average price of dishes: " << averagePrice << " RON\n";

    // Another example of template instantiation with an int vector
    std::vector<int> intPrices = {10, 20, 15, 12, 25};  ///< Example prices (in int)
    int averageIntPrice = calculateAverage(intPrices);  ///< Template instantiation for int
    std::cout << "Average integer price: " << averageIntPrice << "\n";

    // Example of using the string specialization for the template
    std::vector<std::string> dishNames = {"Margherita Pizza", "Chicken Caesar Salad", "Chocolate Cake"};
    std::string concatenatedDishNames = calculateAverage(dishNames);  ///< Template specialization for std::string
    std::cout << "Concatenated dish names: " << concatenatedDishNames << "\n";

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

    // ------------ Strategy Pattern Integration ------------

    // Create strategy instances for Breakfast, Lunch, and Dinner
    BreakfastMenuDisplay breakfastDisplay;
    LunchMenuDisplay lunchDisplay;
    DinnerMenuDisplay dinnerDisplay;

    // Create a MenuContext object and set the initial strategy (Breakfast)
    MenuContext menuContext(&breakfastDisplay);

    // Display the breakfast menu using the strategy
    std::cout << "\n---------- Strategy Pattern: Breakfast Menu ----------\n";
    menuContext.displayMenu("Breakfast");

    // Change strategy to Lunch and display the lunch menu
    menuContext.setStrategy(&lunchDisplay);
    std::cout << "\n---------- Strategy Pattern: Lunch Menu ----------\n";
    menuContext.displayMenu("Lunch");

    // Change strategy to Dinner and display the dinner menu
    menuContext.setStrategy(&dinnerDisplay);
    std::cout << "\n---------- Strategy Pattern: Dinner Menu ----------\n";
    menuContext.displayMenu("Dinner");

    // ------------ End of Strategy Pattern Integration ------------

    // Handle exceptions with try-catch blocks

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

    // ------------ Singleton Pattern Integration ------------

    // Get the singleton instance of MenuManager
    MenuManager& menuManager = MenuManager::getInstance();  // Singleton instance

    // Set and display Breakfast menu using Singleton
    menuManager.setMenu(&breakfast);
    std::cout << "\n---------- Singleton Pattern: Breakfast Menu ----------\n";
    menuManager.displayMenu();

    // Change to Lunch menu using Singleton
    menuManager.setMenu(&lunch);
    std::cout << "\n---------- Singleton Pattern: Lunch Menu ----------\n";
    menuManager.displayMenu();

    // Change to Dinner menu using Singleton
    menuManager.setMenu(&dinner);
    std::cout << "\n---------- Singleton Pattern: Dinner Menu ----------\n";
    menuManager.displayMenu();

    // ------------ End of Singleton Pattern Integration ------------

    return 0;
}
