#include "TodoList.h"

void TodoList::addActivity(string name, string descr, Date date, Priority p) {
    try {
        Activity act(name, descr, date, p);
        todos.insert(make_pair(act.getName(), act));
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << " aborting" << std::endl;
    }
}

bool TodoList::removeActivity(const string& key) {
    if (todos.empty())
        return false;
    todos.erase(key);
    return true;
}

bool TodoList::completeActivity(const string &key) {
    if (todos.empty())
        return false;
    auto it = todos.find(key);
    it->second.setIsCompleted(true);
    return true;
}

void TodoList::showAllActivity() {
    int i = 0;
    cout << "indice - nome - descrizione - data di scadenza - priorità" << endl;
    for (const auto &todo: todos) {
        cout << ++i<< " ";
        todo.second.printActivity();
    }
}

const string &TodoList::getName() const {
    return name;
}

void TodoList::showNotCompletedActivity() {
    cout << "indice - nome - descrizione - data di scadenza - priorità" << endl;
    for(const auto &todo: todos)
        if(todo.second.isCompleted())
            todo.second.printActivity();

}

void TodoList::showExpiringActivity(int day) {
    time_t now = time(0);
    tm* tmTime = localtime(&now);
    Date today(tmTime->tm_mday, tmTime->tm_mon+1, tmTime->tm_year);
    cout<<"attività in scadenza fra "<<day<<" giorni: "<<endl;
    for(const auto &todo:todos){
        if(Date::distanceBetween(todo.second.getDueDate(), today)<=day)
            todo.second.printActivity();
    }
}

