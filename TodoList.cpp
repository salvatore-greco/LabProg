#include "TodoList.h"

const string &TodoList::getName() const {
    return name;
}

void TodoList::addActivity(string name, string descr, Date date, Priority p, bool c) {
    try {
        Activity act(name, descr, date, p, c);
        todos.insert(make_pair(act.getName(), act));
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << " aborting" << std::endl;
    }
}

bool TodoList::removeActivity(const string &key) {
    if (todos.empty() || todos.erase(key) == 0)
        return false;
    return true;
}

bool TodoList::completeActivity(const string &key) {
    auto it = todos.find(key);
    if (it != todos.end()) { //copre anche il caso nel quale la lista sia vuota
        it->second.setIsCompleted(true);
        return true;
    }
    return false;
}

void TodoList::showAllActivity() const{
    int i = 0;
    cout << "indice - nome - descrizione - data di scadenza - priorità" << endl;
    for (const auto &todo: todos) {
        cout << ++i << " ";
        cout<<todo.second.toString();
    }
}

void TodoList::showNotCompletedActivity() const {
    cout << "indice - nome - descrizione - data di scadenza - priorità" << endl;
    for (const auto &todo: todos) {
        if (todo.second.isCompleted()){
            cout<<todo.second.toString();
        }
    }
}

void TodoList::showExpiringActivity(int day) const{
    time_t now = time(0);
    tm *tmTime = localtime(&now);
    Date today(tmTime->tm_mday, tmTime->tm_mon + 1, tmTime->tm_year);
    cout << "attività in scadenza fra " << day << " giorni: " << endl;
    for (const auto &todo: todos) {
        if (Date::distanceBetween(todo.second.getDueDate(), today) <= day)
            cout<<todo.second.toString();
    }
}

void TodoList::showPrioritySort() const{
    //TODO: implementazione bruttissima ma sono le 3, non ho trovato altro modo al momento
    cout << "--- ALTA PRIORITÀ ---" << endl;
    for (const auto &todo: todos) {
        if (todo.second.getPriority() == Priority::high)
            cout<<todo.second.toString();
    }
    cout << "--- MEDIA PRIORITÀ ---" << endl;
    for (const auto &todo: todos) {
        if (todo.second.getPriority() == Priority::medium)
            cout<<todo.second.toString();
    }
    cout << "--- BASSA PRIORITÀ ---" << endl;
    for (const auto &todo: todos) {
        if (todo.second.getPriority() == Priority::low)
            cout<<todo.second.toString();
    }
}

void TodoList::saveToFile() {
    string comp;
    ofstream file("../" + name + ".csv"); //creo il file e lo apro
    if (!file.is_open())
        throw std::runtime_error("Error while opening file!");
    for (const auto &todo: todos) {
        todo.second.isCompleted() ? comp="true" : comp="false"; //bool to string
        file << todo.second.getName() << "," << todo.second.getDescription() << "," << todo.second.getDueDate().getDd()
             << "," << todo.second.getDueDate().getMm() << "," << todo.second.getDueDate().getYyyy() << ","
             << priorityToString(todo.second.getPriority()) << "," << comp << "\n";
        if (file.bad()) {
            file.close(); //in teoria non servirebbe per via dei RAII, ma male non fa e lo lascio lo stesso
            throw std::runtime_error("Error while writing in file");
        }
    }
    file.close();
}

void TodoList::restoreFromFile() {
    ifstream file("../" + name + ".csv");
    if (!file.is_open())
        throw std::runtime_error("Error while opening file!");
    string line, name, description, day, month, year, priority, completed;
    bool isCompleted;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, description, ',');
        getline(ss, day, ',');
        getline(ss, month, ',');
        getline(ss, year, ',');
        getline(ss, priority, ',');
        getline(ss, completed, ',');

        completed == "true" ? isCompleted = true : isCompleted = false;

        addActivity(name, description, Date(stoi(day), stoi(month), stoi(year)), stringToPriority(priority),
                    isCompleted);
    }
    file.close();
}

int TodoList::completedActivity() const{
    int counter = 0;
    for(const auto& todo : todos){
        if(todo.second.isCompleted())
            counter++;
    }
    return counter;
}







