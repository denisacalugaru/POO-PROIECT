#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

/**
 * @enum FoodType
 * @brief Enum class to represent different types of food categories.
 */
enum class FoodType {
    VEGETABLE, /**< Represents vegetable food type */
    DAIRY,     /**< Represents dairy food type */
    MEAT,      /**< Represents meat food type */
    SPICE,     /**< Represents spice food type */
    SAUCE,     /**< Represents sauce food type */
    DESSERT,   /**< Represents dessert food type */
    CEREAL     /**< Represents cereal food type */
};

/**
 * @class Ingredient
 * @brief Represents an ingredient used in a dish.
 */
class Ingredient {
private:
    std::string name; /**< The name of the ingredient */
    FoodType type;    /**< The type of the ingredient (e.g., meat, vegetable, etc.) */

public:
    /**
     * @brief Constructor to create an ingredient with a name and type.
     * @param name The name of the ingredient.
     * @param type The type of the ingredient (FoodType).
     */
    Ingredient(std::string name, FoodType type) : name(std::move(name)), type(type) {}

    /**
     * @brief Get the name of the ingredient.
     * @return A constant reference to the ingredient's name.
     */
    [[nodiscard]] const std::string& getName() const { return name; }

    /**
     * @brief Get the type of the ingredient.
     * @return The type of the ingredient (FoodType).
     */
    [[nodiscard]] FoodType getType() const { return type; }

    /**
     * @brief Overload the stream insertion operator for Ingredient.
     * @param os The output stream.
     * @param ingredient The ingredient to insert into the stream.
     * @return The output stream with the ingredient inserted.
     */
    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
        os << ingredient.name;
        return os;
    }

    ~Ingredient() = default;
};

/**
 * @class Preparat
 * @brief Represents a dish (or preparation) in the menu.
 */
class Preparat {
private:
    std::string name; /**< The name of the dish */
    float price;      /**< The price of the dish */
    float weight;     /**< The weight of the dish */
    std::vector<Ingredient> ingredients; /**< The list of ingredients used in the dish */

public:
    /**
     * @brief Constructor to create a dish with a name, price, weight, and ingredients.
     * @param name The name of the dish.
     * @param price The price of the dish.
     * @param weight The weight of the dish.
     * @param ingredients A list of ingredients used in the dish.
     */
    Preparat(std::string name, float price, float weight, const std::vector<Ingredient>& ingredients)
        : name(std::move(name)), price(price), weight(weight), ingredients(ingredients) {}

    /**
     * @brief Get the name of the dish.
     * @return A constant reference to the name of the dish.
     */
    [[nodiscard]] const std::string& getName() const { return name; }

    /**
     * @brief Get the price of the dish.
     * @return The price of the dish.
     */
    [[nodiscard]] float getPrice() const { return price; }

    /**
     * @brief Check if the dish is vegetarian.
     * @return True if the dish is vegetarian, false otherwise.
     */
    bool isVegetarian() const {
        for (const auto& ingredient : ingredients) {
            if (ingredient.getType() == FoodType::MEAT) {
                return false; // Dish contains meat, not vegetarian
            }
        }
        return true; // Dish is vegetarian
    }

    /**
     * @brief Overload the stream insertion operator for Preparat.
     * @param os The output stream.
     * @param dish The dish to insert into the stream.
     * @return The output stream with the dish inserted.
     */
    friend std::ostream& operator<<(std::ostream& os, const Preparat& dish) {
        os << "Dish: " << dish.name << " - Price: " << dish.price << " RON\n";
        os << "Ingredients: \n";
        for (const auto& ingredient : dish.ingredients) {
            os << "  - " << ingredient << "\n";
        }
        return os;
    }

    ~Preparat() = default;
};

/**
 * @class Categorie
 * @brief Represents a category of dishes in the menu (e.g., Pizza, Salads, Desserts).
 */
class Categorie {
private:
    std::string name; /**< The name of the category */
    std::vector<Preparat> dishes; /**< The list of dishes in this category */

public:
    /**
     * @brief Constructor to create a category with a name and a list of dishes.
     * @param name The name of the category.
     * @param dishes A list of dishes in the category.
     */
    Categorie(const std::string& name, const std::vector<Preparat>& dishes)
        : name(name), dishes(dishes) {}

    /**
     * @brief Sort the dishes in the category alphabetically by their name.
     */
    void sortDishesAlphabetically() {
        std::ranges::sort(dishes, [](const Preparat& a, const Preparat& b) {
            return a.getName() < b.getName();
        });
    }

    /**
     * @brief Overload the stream insertion operator for Categorie.
     * @param os The output stream.
     * @param category The category to insert into the stream.
     * @return The output stream with the category inserted.
     */
    friend std::ostream& operator<<(std::ostream& os, const Categorie& category) {
        os << "Category: " << category.name << "\n";
        for (const auto& dish : category.dishes) {
            os << dish << "\n";
        }
        return os;
    }

    ~Categorie() = default;
};

/**
 * @class Meniu
 * @brief Represents the entire menu, consisting of multiple categories.
 */
class Meniu {
private:
    std::vector<Categorie> categories; /**< The list of categories in the menu */

public:
    /**
     * @brief Constructor to create a menu with a list of categories.
     * @param categories A list of categories in the menu.
     */
    Meniu(const std::vector<Categorie>& categories) : categories(categories) {}

    /**
     * @brief Sort all categories and their dishes alphabetically.
     */
    void sortCategories() {
        for (auto& category : categories) {
            category.sortDishesAlphabetically();
        }
    }

    /**
     * @brief Calculate the total price of the ordered dishes.
     * @param orderedDishes A list of dishes that have been ordered.
     * @return The total price of the ordered dishes.
     */
    static float calculateTotalPrice(const std::vector<Preparat>& orderedDishes) {
        float total = 0.0;
        for (const auto& dish : orderedDishes) {
            total += dish.getPrice();
        }
        return total;
    }

    /**
     * @brief Overload the stream insertion operator for Meniu.
     * @param os The output stream.
     * @param menu The menu to insert into the stream.
     * @return The output stream with the menu inserted.
     */
    friend std::ostream& operator<<(std::ostream& os, const Meniu& menu) {
        os << "Menu:\n";
        for (const auto& category : menu.categories) {
            os << category << "\n";
        }
        return os;
    }

    ~Meniu() = default;
};

/**
 * @brief The main function where the program begins execution.
 * Creates ingredients, dishes, categories, and a menu. Then it sorts, checks for vegetarian status,
 * calculates the total price, and prints the results.
 */
int main() {
    // Initialize ingredients
    Ingredient ingr1("Tomatoes", FoodType::VEGETABLE);
    Ingredient ingr2("Mozzarella", FoodType::DAIRY);
    Ingredient ingr3("Basil", FoodType::SPICE);
    Ingredient ingr4("Chicken", FoodType::MEAT);
    Ingredient ingr5("Tomato sauce", FoodType::SAUCE);
    Ingredient ingr6("Chocolate", FoodType::DESSERT);
    Ingredient ingr7("Flour", FoodType::CEREAL);

    // Create dishes (Preparat)
    Preparat dish1("Margherita Pizza", 20.0, 250, { ingr1, ingr2, ingr3, ingr5 });
    Preparat dish2("Chicken Caesar Salad", 18.0, 200, { ingr4, ingr1, ingr5 });
    Preparat dish3("Chocolate Cake", 15.0, 150, { ingr6, ingr7 });

    // Create categories (Categorie)
    Categorie category1("Pizza", { dish1 });
    Categorie category2("Salads", { dish2 });
    Categorie category3("Desserts", { dish3 });

    // Create the menu (Meniu)
    Meniu menu({ category1, category2, category3 });

    // Print original menu
    std::cout << "Original Menu:\n";
    std::cout << menu << std::endl;

    // Sort categories and dishes
    menu.sortCategories();
    std::cout << "\nSorted Menu:\n";
    std::cout << menu << std::endl;

    // Check if a dish is vegetarian
    std::cout << "\nIs " << dish1.getName() << " vegetarian? " << (dish1.isVegetarian() ? "Yes" : "No") << std::endl;
    std::cout << "Is " << dish2.getName() << " vegetarian? " << (dish2.isVegetarian() ? "Yes" : "No") << std::endl;

    // Calculate the total price of the ordered dishes
    std::vector<Preparat> orderedDishes = { dish1, dish3 };
    float totalPrice = Meniu::calculateTotalPrice(orderedDishes);
    std::cout << "\nTotal Price for ordered dishes: " << totalPrice << " RON" << std::endl;

    return 0;
}
