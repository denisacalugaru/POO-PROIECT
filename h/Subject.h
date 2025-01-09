#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <algorithm>

/**
 * @brief Abstract base class for subjects that notify observers about changes.
 */
class Subject {
private:
    std::vector<Observer*> observers; ///< List of registered observers.

public:
    virtual ~Subject() = default;

    /**
     * @brief Add an observer to the list of observers.
     * @param observer The observer to add.
     */
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Notify all registered observers about a change.
     * @param message The notification message.
     */
    void notify(const std::string& message) {
        for (auto* observer : observers) {
            observer->update(message);
        }
    }
};

#endif // SUBJECT_H
