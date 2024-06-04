#include <iostream>
#include "TodoList.h"

using namespace std;


void avalaibleTodoLists(const unordered_map<string, TodoList> &t) {
    cout << "TodoList disponibili: \n";
    for (const auto &todo: t) {
        cout << todo.first << endl;
    }
}

TodoList findTodoList(const unordered_map<string, TodoList> &t, const string &n) {
    auto it = t.find(n);
    if (it == t.end())
        throw runtime_error("TodoList non trovata");
    return it->second;
}

int main() {
    int scelta = -1;
    string buffer;
    unordered_map<string, TodoList> todoLists; //insieme di tutte le todolist
    cout << "Benvenuto nella mia todolist, scegli un opzione: " << endl;
    do {
        switch (scelta) {
            case 1: {
                cout << "Inserisci il nome della todoList: ";
                cin >> buffer;
                TodoList t(buffer);
                todoLists.insert(make_pair(t.getName(), t));
                scelta = -1; //mi faccio ristampare tutto l'elenco delle funzionalità
                break;
            }
            case 2: {
                while (true) {
                    try {
                        cout << "Scegli una todolist fra quelle elencate: \n";
                        avalaibleTodoLists(todoLists);
                        cin >> buffer;
                        TodoList t = findTodoList(todoLists, buffer);
                        break;
                    } catch (runtime_error &e) {
                        cerr << e.what();
                    }
                }
                string name, desc, date, priority;
                cout << "Inserisci il nome dell'attività: ";
                cin >> name;
                cout << "\nInserisci la descrizione: ";
                cin >> desc;
                //todo: vedi come gestire l'inserimento della data da tastiera
                //stoi lancia un eccezione invalid_argument se non riesce a convertire ad int
                //inserisco giorno mese e anno separatamente oppure faccio inserire una stringa sola e vedo di trovare i delimitatori?
                //t.addActivity();
                scelta = -1;
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                break;
            }
            case 6: {
                break;
            }
            case 7: {
                break;
            }
            case 8: {
                break;
            }
            case 9: {
                break;
            }
            case 0: {
                for (auto &todoList: todoLists) {
                    todoList.second.saveToFile();
                }
                return 0;
            }
            case -1: {
                cout << "1: Crea una Todolist" << endl
                     << "2: Aggiungi un' attività" << endl
                     << "3: Completa un' attività" << endl
                     << "4: Modifica un' attività" << endl
                     << "5: Mostra tutte le attività" << endl
                     << "6: Mostra tutte le attività non completate" << endl
                     << "7: Mostra le attività in ordine di priorità" << endl
                     << "8: Salva tutte le attività su un file"
                     << endl //il file si chiamerà come la todolist, bisogna far scegliere all'utente su quale todolist operare
                     << "9: Ripristina tutte le attività da un file" << endl
                     << "0: esci dal programma" << endl;
                cin >> scelta;
                break;
            }
        }
    } while (scelta != 0);

    return 0;
}
