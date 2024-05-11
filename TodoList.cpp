#include "TodoList.h"

void TodoList::addActivity(string name, string descr, Date date, Priority p) {
    try {
        Activity act(name, descr, date, p);
        todos.push_back(act); //todo: controlla come usare emplace, forse può fare al caso nostro
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << " aborting" << std::endl;
    }
}

bool TodoList::removeActivity(int pos) {
    if (todos.empty() || pos > todos.size() || pos < todos.size())
        return false;
    auto it = todos.begin();
    for(int i = 0; i<pos; i++)
        it++;
    todos.erase(it);
    return true;
}

bool TodoList::completeActivity(int pos) {
    if (todos.empty() || pos > todos.size() || pos < todos.size())
        return false;
    auto it = todos.begin();
    for(int i = 0; i<pos; i++)
        it++;
    it->setIsCompleted(true);
    return true;
}

void TodoList::showAllActivity() {
    int i = 1;
    Priority p;
    string priority;
    cout << "indice - nome - descrizione - data di scadenza - priorità" << endl;
    for (const auto &todo: todos) {
        p = todo.getPriority();
        if(p == Priority::low)
            priority = "low";
        else if (p == Priority::medium)
            priority = "medium";
        else
            priority = "high"; //fa schifo si può fare meglio

        cout << i << " " << todo.getName() << " " << todo.getDescription() << " " << todo.getDueDate().getDd() << "/"
             << todo.getDueDate().getMm() << "/" << todo.getDueDate().getYyyy() << " "<<priority<<endl;
    }
}

const string &TodoList::getName() const {
    return name;
}

/*void TodoList::showExpiringActivity(int day) {
    cout<<"attività in scadenza fra "<<day<<"giorni: "<<endl;
    for (const auto& todo: todos){
        if(todo.getDueDate()
    }
}*/

