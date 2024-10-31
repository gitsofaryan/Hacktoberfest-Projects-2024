#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct Expense {
    double amount;
    string category;
    string description;
};

class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    void addExpense(double amount, const string& category, const string& description) {
        Expense expense = {amount, category, description};
        expenses.push_back(expense);
        saveExpenses();
        cout << "Expense added successfully." << endl;
    }

    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses recorded." << endl;
            return;
        }

        cout << "\nExpenses:" << endl;
        for (size_t i = 0; i < expenses.size(); ++i) {
            cout << i + 1 << ". Amount: $" << fixed << setprecision(2) 
                 << expenses[i].amount << ", Category: " << expenses[i].category 
                 << ", Description: " << expenses[i].description << endl;
        }
    }

    void totalExpenses() {
        double total = 0.0;
        for (const auto& expense : expenses) {
            total += expense.amount;
        }
        cout << "\nTotal Expenses: $" << fixed << setprecision(2) << total << endl;
    }

    void saveExpenses() {
        ofstream file("expenses.txt");
        if (file.is_open()) {
            for (const auto& expense : expenses) {
                file << expense.amount << " " << expense.category << " " << expense.description << endl;
            }
            file.close();
        }
    }

    void loadExpenses() {
        ifstream file("expenses.txt");
        if (file.is_open()) {
            Expense expense;
            while (file >> expense.amount) {
                file >> expense.category;
                file.ignore(); // Ignore space before description
                getline(file, expense.description);
                expenses.push_back(expense);
            }
            file.close();
        }
    }
};

int main() {
    ExpenseTracker tracker;
    tracker.loadExpenses(); // Load existing expenses at the start

    while (true) {
        cout << "\nExpense Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Total Expenses" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Choose an option (1-4): ";
        cin >> choice;

        if (choice == 1) {
            double amount;
            string category, description;

            cout << "Enter expense amount: $";
            cin >> amount;
            cout << "Enter expense category: ";
            cin >> category;
            cout << "Enter expense description: ";
            cin.ignore(); // Clear the newline character from the input buffer
            getline(cin, description);

            tracker.addExpense(amount, category, description);
        } 
        else if (choice == 2) {
            tracker.viewExpenses();
        } 
        else if (choice == 3) {
            tracker.totalExpenses();
        } 
        else if (choice == 4) {
            cout << "Exiting Expense Tracker. Goodbye!" << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
