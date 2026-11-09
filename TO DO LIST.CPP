#include <iostream>
#include <string>
using namespace std;

struct Task
{
    string name;
    bool completed;
};

Task tasks[100];
int count = 0;

void addTask()
{
    if (count >= 100)
    {
        cout << "\nTask list is full!\n";
        return;
    }

    cout << "\nEnter task name: ";
    getline(cin, tasks[count].name);

    tasks[count].completed = false;
    count++;

    cout << "Task added successfully!\n";
}

void viewTasks()
{
    if (count == 0)
    {
        cout << "\nNo tasks available!\n";
        return;
    }

    cout << "\n----- YOUR TO-DO LIST -----\n";

    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << tasks[i].name;

        if (tasks[i].completed)
            cout << " [Completed]\n";
        else
            cout << " [Pending]\n";
    }
}

void completeTask()
{
    int num;

    viewTasks();

    if (count == 0)
        return;

    cout << "\nEnter task number to complete: ";
    cin >> num;

    if (num >= 1 && num <= count)
    {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    }
    else
    {
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task
void removeTask()
{
    int num;

    viewTasks();

    if (count == 0)
        return;

    cout << "\nEnter task number to remove: ";
    cin >> num;

    if (num >= 1 && num <= count)
    {

        for (int i = num - 1; i < count - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }

        count--;

        cout << "Task removed successfully!\n";
    }
    else
    {
        cout << "Invalid task number!\n";
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n========== TO-DO LIST MANAGER ==========\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            completeTask();
            break;

        case 4:
            removeTask();
            break;

        case 5:
            cout << "\nThank you for using To-Do List Manager!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}