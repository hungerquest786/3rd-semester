#include <iostream>
using namespace std;

class monthly_expense_tracker 
{
    double* expenses;
    int size;

  public:
    monthly_expense_tracker(int n) {
        size = n;
        expenses = new double[size];
        for (int i = 0; i < size; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> expenses[i];
        }
    }

    void resize(int newSize) {
        double* newArr = new double[newSize];
        for (int i = 0; i < size; i++) newArr[i] = expenses[i];
        for (int i = size; i < newSize; i++) {
            cout << "Enter expense for month " << i + 1 << ": ";
            cin >> newArr[i];
        }
        delete[] expenses;
        expenses = newArr;
        size = newSize;
    }

    double total() {
        double sum = 0;
        for (int i = 0; i < size; i++) sum += expenses[i];
        return sum;
    }

    double average() {
        return total() / size;
    }

    void display() {
        cout << "\nExpenses for " << size << " months:\n";
        for (int i = 0; i < size; i++) {
            cout << "Month " << i + 1 << ": " << expenses[i] << endl;
        }
        cout << "Total Expenses: " << total() << endl;
        cout << "Average Expenses: " << average() << endl;
    }

    ~monthly_expense_tracker() {
        delete[] expenses;
    }
};

int main ()
{
    monthly_expense_tracker tracker(3);
    tracker.resize(5);
    tracker.display();
    return 0;
}
