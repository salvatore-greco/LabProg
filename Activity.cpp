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
    Activity::isCompleted = isCompleted;
}

void Activity::setDueDate(const Date &dueDate) {
    Activity::dueDate = dueDate;
}


