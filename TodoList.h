#ifndef LABORATORIOPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIOPROGRAMMAZIONE_TODOLIST_H
#include <list>
#include <fstream>
#include "Activity.h"
#include <iostream>

class TodoList {
public:
    TodoList(string n): name(n){};
    void addActivity(string name, string descr, Date date, Priority p);
    void removeActivity(Activity act);
    void completeActivity(Activity act); //vediamo se serve o no
    void showAllActivity();
    void showExpiringActivity(int day = 2);
    void showNotCompletedActivity();
    void showPrioritySort();
    void saveToFile(/*file pointer, it's late i don't remember how to do it*/);
    void restoreFromFile(/*same thing as written above*/);

private:
    std::list<Activity> todo;
    string name;
};


#endif //LABORATORIOPROGRAMMAZIONE_TODOLIST_H
