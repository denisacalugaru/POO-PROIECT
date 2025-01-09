#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

/**
 * @brief Interface for observer objects that react to changes in the subject.
 */
class Observer {
public:
    virtual ~Observer() = default;

    /**
     * @brief React to a notification from the subject.
     * @param message The notification message describing the change.
     */
    virtual void update(const std::string& message) = 0;
};

#endif // OBSERVER_H
