// To-Do List App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

void printTasks(const std::vector<std::string>& tasks);


int main()
{
    int ch{};
    std::vector<std::string> tasks{};
    std::string task{};
    int index{};
    do
    {
        std::cout << "Choose an option from the menu: \n 1.Add Task\n 2.View Tasks\n"
            << " 3.Mark Completed\n 4.Delete Task\n 5.Exit\n ";
        std::cin >> ch;
        std::cin.ignore(); // clear leftover newline

        switch (ch)
        {
        case 1:                 //Add Task
            std::cout << "Enter a task: ";
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task added successfully\n";
            printTasks(tasks);
            break;
        case 2:                 //View Tasks
            if (tasks.size() != 0)
            {
                printTasks(tasks);

            }
            else
            {
                std::cout << "No tasks to be displayed\n";
            }
            break;
        case 3:                 //Mark Completed
            index = 0;
            std::cout << "Enter the index of the task completed: \n";
            std::cin >> index;
            if (index > 0 && index <= tasks.size())
            {
                tasks[index - 1] += " (Done)";
                std::cout << "Task marked as done successfully\n";
            }
            else
            {
                std::cout << "Invaild index!!!\n";
            }
            printTasks(tasks);
            break;
        case 4:                 //Delete Task
            index = 0;
            std::cout << "Enter index of the task to be deleted \n";
            std::cin >> index;
            if (index > 0 && index <= tasks.size())
            {
                tasks.erase(tasks.begin() + (index - 1));
                std::cout << "Task deleted successfully\n";
            }
            else
            {
                std::cout << "Invalid index!!!\n";
            }
            printTasks(tasks);
            break;
        case 5:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid Choice!!";
            break;

        }

    } while (ch!=5);
    
    return 0;
}


void printTasks(const std::vector<std::string>& tasks)
{
    int count{ 1 };
    for (const auto& task : tasks)
    {
        std::cout << count++ << ": " << task << "\n";
    }
}