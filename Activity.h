

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

static string priorityToString(Priority p){
    if(p == Priority::low)
        return "low";
    else if (p == Priority::medium)
        return "medium";
    else
        return "high";
}

class Activity {
public:
    Activity(string n, string descr, Date date, Priority p, bool c = false): name(n), description(descr), priority(p), completed(c), dueDate(date){};

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

    void printActivity() const;

private:
    //int id;
    string name; //main title of the activity
    string description; //extended description of it
    Date dueDate;
    Priority priority;
    bool completed;
};


#endif //LABPROG_ACTIVITY_H
