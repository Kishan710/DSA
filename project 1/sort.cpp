// Sorting student marks using Bubble Sort and find maximum and minimum marks.

#include <iostream>
using namespace std;

int main() {
    int n;
    int marks[50];

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks:\n";
    for(int i = 0; i < n; i++) {
        cin >> marks[i];
    }


    int maxMarks = marks[0];
    int minMarks = marks[0];

    for(int i = 1; i < n; i++) {
        if(marks[i] > maxMarks)
            maxMarks = marks[i];
        if(marks[i] < minMarks)
            minMarks = marks[i];
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(marks[j] > marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "\nMarks in ascending order:\n";
    for(int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }

    cout << "Maximum Marks = " << maxMarks << endl;
    cout << "Minimum Marks = " << minMarks << endl;

}
