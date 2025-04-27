#include <iostream>
#include <string>
using namespace std;

// Function to sort grades and names using Bubble Sort
void sortGrades(string names[], int grades[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                // Swap grades
                int tempGrade = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = tempGrade;
                // Swap corresponding names
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
}

// Function to search for a student's grade using Linear Search
int searchStudent(string names[], int grades[], int size, string searchName) {
    for (int i = 0; i < size; i++) {
        if (names[i] == searchName) {
            return grades[i];
        }
    }
    return -1; // Return -1 if not found
}

// Function to calculate class statistics
void calculateStatistics(int grades[], int size, double &average, int &highest, int &lowest) {
    int total = 0;
    highest = grades[0];
    lowest = grades[0];

    for (int i = 0; i < size; i++) {
        total += grades[i];
        if (grades[i] > highest) {
            highest = grades[i];
        }
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    average = static_cast<double>(total) / size;
}

int main() {
    const int SIZE = 5; // You can change this size based on your needs
    string names[SIZE];
    int grades[SIZE];

    // Enter student names and grades
    cout << "Enter the names and grades for " << SIZE << " students:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Student " << (i + 1) << " name: ";
        getline(cin, names[i]);
        cout << "Student " << (i + 1) << " grade: ";
        cin >> grades[i];
        cin.ignore(); // To clear the newline character from the input buffer
    }

    // Sort the students by grades
    sortGrades(names, grades, SIZE);

    // Display sorted list
    cout << "\nStudents sorted by grades (ascending):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << names[i] << " - " << grades[i] << endl;
    }

    // Search for a student's grade
    string searchName;
    cout << "\nEnter a student's name to search for their grade: ";
    getline(cin, searchName);
    int foundGrade = searchStudent(names, grades, SIZE, searchName);
    if (foundGrade != -1) {
        cout << searchName << "'s grade is: " << foundGrade << endl;
    } else {
        cout << "Student not found.\n";
    }

    // Calculate and display statistics
    double average;
    int highest, lowest;
    calculateStatistics(grades, SIZE, average, highest, lowest);

    cout << "\nClass Statistics:\n";
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highest << endl;
    cout << "Lowest Grade: " << lowest << endl;

    return 0;
}