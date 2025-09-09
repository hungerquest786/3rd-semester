#include<iostream>
#include<string>

using namespace std;

class dynamic_memory 
{
    public:
    int * array ;
    int array_size;
        dynamic_memory(int s)
        {
            array_size = s;
            array = new int [s];
            for (int i = 0; i < s ; i++)
            {
                array[i] = 0;
            }
        }

        void update(int index, int value)
        {
            if (index >= 0 && index < array_size)
                array[index] = value;
            else
                cout << "Invalid index!" << endl;
        }

        void print ()
        {
            for (size_t i = 0; i < array_size; i++)
            {
                cout << " value stored in index "<< i+1 << " : " << array[i] << endl;
            }
        }

        ~dynamic_memory()
        {
            delete[] array;
        }
};

int main ()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    dynamic_memory A(n);

    char choice;
    do {
        int idx, val;
        cout << "Enter index (0 to " << n-1 << "): ";
        cin >> idx;
        cout << "Enter value: ";
        cin >> val;
        A.update(idx, val);

        cout << "Do you want to update another? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    A.print();
}
