#ifndef LABORATORIOPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIOPROGRAMMAZIONE_TODOLIST_H

#include <unordered_map>
#include <algorithm>
#include <fstream>
#include "Activity.h"
#include "ctime"
#include <iostream>


class TodoList {
public:
    TodoList(string n):name(){};

    void addActivity(string name, string descr, Date date, Priority p);
    bool removeActivity(const string &key);
    bool completeActivity(const string &key);
    void showAllActivity();
    void showExpiringActivity(int day = 2);
    void showNotCompletedActivity();
    void showPrioritySort();
    void saveToFile();
    void restoreFromFile();
    const string &getName() const;
    inline const int getSize() const{ //mi serve per gli unit test
        return (int)todos.size();
    }
private:
    std::unordered_map<string, Activity> todos;
    string name;
};


#endif //LABORATORIOPROGRAMMAZIONE_TODOLIST_H
