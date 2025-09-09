#include<iostream>
#include<string>
using namespace std;

class movie {
    int **seating;
    int row, column;

public:
    movie(int a, int b) {
        row = a;
        column = b;
        seating = new int*[row];
        for (int i = 0; i < row; i++) {
            seating[i] = new int[column];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                seating[i][j] = 0;
            }
        }
    }

    void book_seats(int c) {
        while (c) {
            int a, b;
            cout << "Enter row (0-" << row-1 << "): ";
            cin >> a;
            cout << "Enter column (0-" << column-1 << "): ";
            cin >> b;

            if (a >= 0 && a < row && b >= 0 && b < column) {
                seating[a][b] = 1;
            } else {
                cout << "Invalid seat!" << endl;
            }
            c--;
        }
    }

    void display() {
        cout << "\nFinal Seating Chart:\n";
        for (int i = 0; i < row; i++) {
            cout << "{ ";
            for (int j = 0; j < column; j++) {
                cout << seating[i][j] << " ";
            }
            cout << "}" << endl;
        }
    }

    ~movie() {
        for (int i = 0; i < row; i++) {
            delete[] seating[i];
        }
        delete[] seating;
    }
};

int main() {
    int r, c, seats;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    movie m(r, c);

    cout << "How many seats do you want to book? ";
    cin >> seats;
    m.book_seats(seats);

    m.display();

    return 0;
}
