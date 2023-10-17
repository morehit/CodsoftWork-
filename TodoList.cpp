#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

std::vector<Task> taskList;

void AddTask() {
    std::string taskDescription;
    std::cout << "Enter the task description: ";
    std::cin.ignore();
    std::getline(std::cin, taskDescription);
    taskList.push_back(Task(taskDescription));
    std::cout << "Task added successfully!" << std::endl;
}

void ViewTasks() {
    std::cout << "Task List:" << std::endl;
    for (int i = 0; i < taskList.size(); i++) {
        std::cout << "[" << (taskList[i].completed ? "X" : " ") << "] " << i + 1 << ". " << taskList[i].description << std::endl;
    }
}

void MarkTaskAsCompleted() {
    ViewTasks();
    int taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskList.size()) {
        taskList[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void RemoveTask() {
    ViewTasks();
    int taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskList.size()) {
        taskList.erase(taskList.begin() + taskNumber - 1);
        std::cout << "Task removed!" << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                AddTask();
                break;
            case 2:
                ViewTasks();
                break;
            case 3:
                MarkTaskAsCompleted();
                break;
            case 4:
                RemoveTask();
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
