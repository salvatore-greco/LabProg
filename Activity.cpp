#include "Activity.h"


void Activity::setName(const string &name) {
    Activity::name = name;
}

void Activity::setDescription(const string &description) {
    Activity::description = description;
}

void Activity::setPriority(Priority priority) {
    Activity::priority = priority;
}

void Activity::setIsCompleted(bool isCompleted) {
    Activity::completed = isCompleted;
}

void Activity::setDueDate(const Date &dueDate) {
    Activity::dueDate = dueDate;
}

const string &Activity::getName() const {
    return name;
}

const string &Activity::getDescription() const {
    return description;
}

const Date &Activity::getDueDate() const {
    return dueDate;
}

Priority Activity::getPriority() const {
    return priority;
}

bool Activity::isCompleted() const {
    return completed;
}



