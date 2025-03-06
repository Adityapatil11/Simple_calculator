#include <iostream>
#include <string>

void print_tasks(std::string *tasks, int task_count)
{
    std::cout << "Tasks to do:  \n";
    std::cout << "`````````````````````````````\n";
    for (int i = 0; i < task_count; i++)
    {
        std::cout << "task " << i + 1 <<"\t"<< tasks[i] << '\n';
    }
    std::cout << "`````````````````````````````\n";
}

int main()
{
    std::string tasks[10] = {""};
    int task_count = 0; // to know how many task we have

    int option = -1;

    while (option != 0)
    {
        // display menue here
        std::cout << "-------TO-DO LIST---------\n";
        std::cout << "0.TERMINATE PROGRAM\n";
        std::cout << "1.ADD NEW TASK\n";
        std::cout << "2.VIEW TASKS\n";
        std::cout << "3.DELETE TASKS\n";
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            if (task_count > 9)
            {
                std::cout << "```````TASK LIST IS FULL```````````\n";
            }
            else
            {
                std::cout << "Enter a task\n";
                std::cin.ignore();
                std::getline(std::cin, tasks[task_count]);
                task_count++;
            }
            break ;
        }
        case 2:
            print_tasks(tasks, task_count);
            break;

        case 3:
        {
            int del_tsk = 0;
            std::cout << "Enter task number to delete :  ";
            std::cin >>
                del_tsk;
            if (del_tsk < 0 | del_tsk > 9)
            {
                std::cout << "Enter a number between the range 0 to 9";
                break;
            }
            for (int i = del_tsk; i < task_count; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            task_count -= 1;
            break;
        }
        }
    }
    return 0;
}