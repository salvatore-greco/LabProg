

#ifndef LABPROG_ACTIVITY_H
#define LABPROG_ACTIVITY_H

#include <string>
#include "Date.h"

using namespace std;

enum class Priority{
    low,
    medium,
    high
};

class Activity {
public:
    Activity(string n, string descr, Date date, Priority p, bool c = false): name(n), description(descr), priority(p), isCompleted(c), dueDate(date){};

    void setName(const string &name);

    void setDescription(const string &description);

    void setPriority(Priority priority);

    void setIsCompleted(bool isCompleted);

    void setDueDate(const Date &dueDate);

private:
    //int id; think if it's useful or not
    string name; //main title of the activity
    string description; //extended description of it
    Date dueDate;
    Priority priority;
    bool isCompleted;
};


#endif //LABPROG_ACTIVITY_H
