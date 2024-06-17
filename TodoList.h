#ifndef LABORATORIOPROGRAMMAZIONE_TODOLIST_H
#define LABORATORIOPROGRAMMAZIONE_TODOLIST_H

#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Activity.h"



class TodoList {
public:
    explicit TodoList(const string& n):name(n){}; // passare come riferimento costante



    void addActivity(string name, string descr, Date date, Priority p, bool c = false);
    bool removeActivity(const string &key);
    bool completeActivity(const string &key);
    void showAllActivity() const;
    void showExpiringActivity(int day = 2) const;
    void showNotCompletedActivity() const;
    void showPrioritySort() const;
    void saveToFile();
    void restoreFromFile();
    const string &getName() const;
    inline int getSize() const{ //mi serve per gli unit test
        return (int)todos.size();
    }
    inline void removeAllActivity(){
        todos.clear();
    }
    int completedActivity() const;
    inline int notCompletedActivity() const{
        return getSize() - completedActivity();
    }
private:
    std::unordered_map<string, Activity> todos;
    string name;
};


#endif //LABORATORIOPROGRAMMAZIONE_TODOLIST_H
