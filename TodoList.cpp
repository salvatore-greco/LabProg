//
// Created by salvatore on 09/05/24.
//

#include "TodoList.h"


void TodoList::addActivity(string name, string descr, Date date, Priority p) {
    try{
        Activity act (name, descr, date, p);
        todo.push_back(act);
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << " aborting" << std::endl;
    }
}
