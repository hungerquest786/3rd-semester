#include <iostream>
using namespace std;

class Matrix {
    int** data;
    int row, column;

public:
    Matrix(int a, int b) {
        row = a;
        column = b;
        data = new int*[row];
        for (int i = 0; i < row; i++) {
            data[i] = new int[column];
        }
        cout << "Enter elements (" << row << "x" << column << "):\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cin >> data[i][j];
            }
        }
    }

    void display() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(Matrix& other) {
        Matrix result(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(Matrix& other) {
        Matrix result(row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);
        m1.display();
        m2.display();

    Matrix sum = m1 + m2;
    Matrix diff = m1 - m2;

     sum.display();
     diff.display();

    return 0;
}
