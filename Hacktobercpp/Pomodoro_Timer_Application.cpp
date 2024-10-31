#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

struct Task {
    string name;
    int pomodoros;
};

class TaskTracker {
private:
    vector<Task> tasks;

public:
    void addTask(const string& taskName) {
        tasks.push_back({taskName, 0});
        cout << "Task added: " << taskName << endl;
    }

    void viewTasks() {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].name << " - Pomodoros: " << tasks[i].pomodoros << endl;
        }
    }

    void startPomodoro(int index) {
        if (index < 0 || index >= tasks.size()) {
            cout << "Invalid task index!" << endl;
            return;
        }
        cout << "Starting Pomodoro for: " << tasks[index].name << endl;
        this_thread::sleep_for(chrono::minutes(25));
        tasks[index].pomodoros++;
        cout << "Pomodoro completed for task: " << tasks[index].name << endl;
    }
};

int main() {
    TaskTracker tracker;
    tracker.addTask("Complete project report");
    tracker.addTask("Study for exams");

    tracker.viewTasks();
    tracker.startPomodoro(0);

    return 0;
}
