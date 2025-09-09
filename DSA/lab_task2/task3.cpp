#include<iostream>
#include<string>

using namespace std;

class enrollment  
{
    public:
    int** courses;
    int no_of_student;
    int* num_courses_each_student;
    int* avg ;

    enrollment(int a)
    {
        no_of_student = a;
        avg = new int[no_of_student];   
        num_courses_each_student = new int [no_of_student];
        courses = new int*[no_of_student];
        
        for (size_t i = 0; i < no_of_student; i++)
        {
            cout << "enter number of course for the student: "<<endl;
            cin >> num_courses_each_student[i]; 
            courses[i] = new int [num_courses_each_student[i]];
        }
    }

    void enter_marks()
    {
        for (size_t i = 0; i < no_of_student; i++)
        {
            for (size_t j = 0; j < num_courses_each_student[i]; j++)
            {
               cout << "enter marks for student "<< i+1 << " for course " << j+1 << " :"<<endl;
               cin >> courses[i][j];
            }
        }
    }

    void average_marks()
    {
        for (size_t i = 0; i < no_of_student; i++)
        {
            avg[i] = 0;   
            for (size_t j = 0; j < num_courses_each_student[i]; j++)
            {
                avg[i] += courses[i][j];
            }
            avg[i] /= num_courses_each_student[i];   
            cout << "average for student " << i+1 << " is : " << avg[i] << endl;
        }
    }

    ~enrollment()
    {
        for (size_t i = 0; i < no_of_student; i++)
        {
            delete [] courses[i];
        }
        delete [] courses;
        delete [] num_courses_each_student;
        delete [] avg;  
    }
};

int main ()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    enrollment e(n);
    e.enter_marks();
    e.average_marks();

    return 0;
}
