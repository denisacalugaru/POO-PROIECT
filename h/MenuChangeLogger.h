#ifndef MENU_CHANGE_LOGGER_H
#define MENU_CHANGE_LOGGER_H

#include "Observer.h"
#include <iostream>

/**
 * @brief A concrete observer that logs menu changes.
 *
 * The MenuChangeLogger class implements the Observer interface and is notified
 * whenever the subject (e.g., Menu) undergoes a change. It logs these changes
 * to the console.
 */
class MenuChangeLogger : public Observer {
public:
    /**
     * @brief Reacts to notifications from the subject.
     *
     * This method is called whenever the subject notifies its observers.
     * It logs the message describing the change.
     *
     * @param message The notification message describing the change.
     */
    void update(const std::string& message) override {
        std::cout << "[MenuChangeLogger] " << message << std::endl;
    }
};

#endif // MENU_CHANGE_LOGGER_H
