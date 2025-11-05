#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void getData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int findHighestScore(const studentType students[], int size);
void printHighest(const studentType students[], int size, int highest);
void printData(const studentType students[], int size);

int main() {
    const int SIZE = 20;
    studentType students[SIZE];

    getData(students, SIZE);
    assignGrade(students, SIZE);

    cout << left << setw(15) << "Last Name"
         << setw(15) << "First Name"
         << setw(10) << "Score"
         << "Grade" << endl;

    printData(students, SIZE);

    int highest = findHighestScore(students, SIZE);
    cout << "\nHighest test score: " << highest << endl;
    cout << "Student(s) with the highest score:" << endl;
    printHighest(students, SIZE, highest);

    return 0;
}

// ------------------------------

void getData(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name, last name, and test score for student "
             << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90) students[i].grade = 'A';
        else if (score >= 80) students[i].grade = 'B';
        else if (score >= 70) students[i].grade = 'C';
        else if (score >= 60) students[i].grade = 'D';
        else students[i].grade = 'F';
    }
}

int findHighestScore(const studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

void printHighest(const studentType students[], int size, int highest) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highest) {
            cout << students[i].studentLName << ", "
                 << students[i].studentFName << endl;
        }
    }
}

void printData(const studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << students[i].studentLName
             << setw(15) << students[i].studentFName
             << setw(10) << students[i].testScore
             << students[i].grade << endl;
    }
}