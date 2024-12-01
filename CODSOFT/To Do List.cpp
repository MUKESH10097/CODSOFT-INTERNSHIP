#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool isCompleted;

    // Constructor to initialize a task
    Task(string desc) : description(desc), isCompleted(false) {}
};

// Function to add a task to the to-do list
void addTask(vector<Task>& tasks, const string& taskDescription) {
    tasks.push_back(Task(taskDescription));
    cout << "Task added: " << taskDescription << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [Status: " << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].isCompleted = true;
        cout << "Task " << taskIndex << " marked as completed." << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task " << taskIndex << " removed." << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string taskDescription;
    int taskIndex;

    do {
        // Display menu
        cout << "\n--- To-Do List Manager ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character left in the input buffer

        switch (choice) {
            case 1:
                // Add a new task
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;

            case 2:
                // View all tasks
                viewTasks(tasks);
                break;

            case 3:
                // Mark a task as completed
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex);
                break;

            case 4:
                // Remove a task
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;

            case 5:
                // Exit the program
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

