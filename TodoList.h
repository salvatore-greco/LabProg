#ifndef LABORATORIOPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIOPROGRAMMAZIONE_TODOLIST_H

#include <list>
#include <fstream>
#include "Activity.h"
#include <iostream>


class TodoList {
public:
    TodoList(string n) : name(n) {};

    void addActivity(string name, string descr, Date date, Priority p);
    bool removeActivity(int pos);
    bool completeActivity(int pos); //vediamo se serve o no
    void showAllActivity();
    void showExpiringActivity(int day = 2);
    void showNotCompletedActivity();
    void showPrioritySort();
    void saveToFile();
    void restoreFromFile();
    const string &getName() const;
private:
    std::list<Activity> todos;
    string name;
    fstream file;
};


#endif //LABORATORIOPROGRAMMAZIONE_TODOLIST_H
