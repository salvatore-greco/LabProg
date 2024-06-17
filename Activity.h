#ifndef LABPROG_ACTIVITY_H
#define LABPROG_ACTIVITY_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;
//todo: refactor, trova una posizione migliore per questa enum; potrei fare una wrapper class che ha i metodi toString e toPriority

enum class Priority{
    low,
    medium,
    high
};

static string priorityToString(const Priority& p){ //todo: rimuovere static
    if(p == Priority::low)
        return "low";
    else if (p == Priority::medium)
        return "medium";
    else
        return "high";
};

static Priority stringToPriority(const string& s){
    if(s=="low")
        return Priority::low;
    else if(s=="medium")
        return Priority::medium;
    else return Priority::high;
}


class Activity {
public:
    Activity(string n, string descr, Date date, Priority p, bool c = false);
    //todo: controllo nullità n e descr
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
