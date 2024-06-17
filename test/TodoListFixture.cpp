#include "gtest/gtest.h"
#include "../TodoList.h"

class TodoListFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        todoList.addActivity("prima", "descrizione", Date(1, 2, 2024), Priority::low);
        todoList.addActivity("seconda", "descrizione", Date(2, 2, 2024), Priority::medium);
        todoList.addActivity("terza", "descrizione", Date(3, 2, 2024), Priority::high);
        todoList.addActivity("expiringActivity", "descrizione molto accurata di un attività che sta per scadere", Date(15,5,2024), Priority::high);
    }
    TodoList todoList = TodoList("test");
};

TEST_F(TodoListFixture, addActivity) {
    int size = todoList.getSize();
    EXPECT_NO_THROW(todoList.addActivity("quarta", "descrizione", Date(3, 2, 2024), Priority::high, false));
    EXPECT_NO_THROW(todoList.addActivity("", "", Date(3, 2, 2024), Priority::high, false)); //no throw perchè l'eccezione viene gestita nel metodo
    EXPECT_EQ(todoList.getSize(), size + 1);
}

TEST_F(TodoListFixture, savingToFile){
    ASSERT_NO_THROW(todoList.saveToFile());
    todoList.addActivity("quinta", "descrizione", Date(1, 2, 2013), Priority::low, false);
    ASSERT_NO_THROW(todoList.saveToFile());
    //qui poi c'è da guardare effettivamente se il file viene scritto correttamente (spoiler: sì);
}

TEST_F(TodoListFixture, restoringFromFile){
    TodoList copied(todoList); //copy constructor
    ASSERT_NO_THROW(todoList.saveToFile()); //popoliamo effettivamente il file
    todoList.removeAllActivity();
    ASSERT_NO_THROW(todoList.restoreFromFile());
    ASSERT_EQ(todoList.getSize(), copied.getSize());
    //non avendo accesso alla struttura dati sottostante stampo tutte le attività dopo che ho fatto save e restore
    cout<<"originale\n";
    todoList.showAllActivity();
    cout<<"copia\n";
    copied.showAllActivity();
}

TEST_F(TodoListFixture, removingActivity){
    int startingSize = todoList.getSize();
    EXPECT_TRUE(todoList.removeActivity("prima"));
    ASSERT_TRUE(startingSize > todoList.getSize());
    EXPECT_FALSE(todoList.removeActivity("attivitanonpresente"));
    EXPECT_FALSE(todoList.removeActivity("unaltraattivitanonpresente"));
    todoList.removeAllActivity();
    EXPECT_TRUE(todoList.getSize() == 0);
    EXPECT_FALSE(todoList.removeActivity("seconda"));
}

TEST_F(TodoListFixture, completingActivity){
    ASSERT_TRUE(todoList.completeActivity("prima"));
    ASSERT_FALSE(todoList.completeActivity("attivitànonesistente"));
    ASSERT_EQ(todoList.completedActivity(), 1);
    todoList.removeAllActivity();
    ASSERT_FALSE(todoList.completeActivity("prima"));

}

TEST_F(TodoListFixture, printingStuff){ //questi intaseranno un po' la console, li faccio una volta e poi non li eseguo più ogni volta, solo all'occorrenza
    cout<<"------------\n";
    todoList.showExpiringActivity();
    cout<<"------------ attività non completate\n";
    todoList.completeActivity("prima");
    todoList.showNotCompletedActivity();
    cout<<"------------\n";
    todoList.showPrioritySort();

}