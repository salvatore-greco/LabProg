#include "Activity.h"

Activity::Activity(string n, string descr, Date date, Priority p, bool c) : name(n), description(descr), dueDate(date), priority(p), completed(c){
    if (n.empty() || descr.empty())
        throw std::invalid_argument("name or description is empty");
}

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

void Activity::toString() const {
    string comp;
    isCompleted() ? comp = "true" : comp ="false";
    cout << name << " - " << description << " - " << dueDate.getDd() << "/"
         << dueDate.getMm() << "/" << dueDate.getYyyy() << " - "<<priorityToString(priority)<<" - "<<comp<<endl;

}





