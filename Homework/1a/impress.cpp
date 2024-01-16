#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
class TodoList
{
private:
    std::vector<T> tasks;

public:
    void addTask(const T &task)
    {
        tasks.push_back(task);
    }

    void displayTasks()
    {
        std::for_each(tasks.begin(), tasks.end(), [](const T &task)
                      { std::cout << task << std::endl; });
    }
};

int main()
{
    TodoList<std::string> myTodoList;

    myTodoList.addTask("Finish C++ project");
    myTodoList.addTask("Read about lambda expressions");
    myTodoList.addTask("Practice STL");

    std::cout << "My Todo List:\n";
    myTodoList.displayTasks();

    return 0;
}
