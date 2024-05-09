

#ifndef LABPROG_ACTIVITY_H
#define LABPROG_ACTIVITY_H

#include <string>
#include "Date.h"

using namespace std;

enum class priority{
    low,
    medium,
    high
};

class Activity {
public:
    //think about which constructor use
private:
    int id;
    string name; //main title of the activity
    string description; //extended description of it
    Date dueDate;
    priority priority;
    bool completed;
};


#endif //LABPROG_ACTIVITY_H
