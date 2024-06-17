#ifndef LABPROG_ACTIVITY_H
#define LABPROG_ACTIVITY_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

enum class Priority{
    low,
    medium,
    high
};
Priority stringToPriority(const string& s);
string priorityToString(const Priority& p); //implementazione nel file .c


class Activity {
public:
    Activity(string n, string descr, Date date, Priority p, bool c = false);
    //controllo nullità n e descr
    void setName(const string &name);

    void setDescription(const string &description);

    void setPriority(Priority priority);

    void setIsCompleted(bool isCompleted);

    void setDueDate(const Date &dueDate);

    const string &getName() const;

    const string &getDescription() const;

    const Date &getDueDate() const;

    Priority getPriority() const;

    bool isCompleted() const;

    void toString() const; //todo: usa sstream

private:
    string name; //main title of the activity
    string description; //extended description of it
    Date dueDate;
    Priority priority;
    bool completed;
};


#endif //LABPROG_ACTIVITY_H
