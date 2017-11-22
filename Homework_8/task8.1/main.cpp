#include <iostream>

using namespace std;

struct Student
{
    int number = 0;
    Student *origin = nullptr;
};

int main()
{
    int n = 0;
    cout << "Enter a number of students: ";
    cin >> n;

    int number = 0;
    int originNumber = 0;
    Student *students = new Student[n];
    cout << "Enter students:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> number >> originNumber;
        number--;
        originNumber--;
        students[number].number = number;
        students[number].origin = &students[originNumber];
    }

    cout << "Numbers of students with numbers of origins:\n";
    Student *tmp = new Student;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << ' ';
        tmp = &students[i];
        while (tmp->origin != tmp)
            tmp = tmp->origin;
        cout << tmp->number + 1 << endl;
    }
    delete[] students;
    delete tmp;
}
