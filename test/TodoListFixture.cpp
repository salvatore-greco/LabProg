#include "gtest/gtest.h"
#include "../TodoList.h"

class TodoListFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        todos.addActivity("prima", "descrizione", Date(1,2,2024), Priority::low);
        todos.addActivity("seconda", "descrizione", Date(2,2,2024), Priority::medium);
        todos.addActivity("terza", "descrizione", Date(3,2,2024), Priority::high);
    }
    TodoList todos = TodoList("test");
};


TEST_F(TodoListFixture, addActivity) {
    int size = todos.getSize();
    EXPECT_NO_THROW(todos.addActivity("quarta", "descrizione", Date(3,2,2024), Priority::high));
    EXPECT_EQ(todos.getSize(), size+1);
}

TEST_F(TodoListFixture, fileHandling){
    ASSERT_NO_THROW(todos.saveToFile());
    todos.addActivity("quinta", "descrizione", Date(1,2,2013), Priority::low);
    ASSERT_NO_THROW(todos.saveToFile());

}
