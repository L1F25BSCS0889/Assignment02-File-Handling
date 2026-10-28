/*
 * Name       : Momina
 * Reg No     : L1f25bscs0889
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship Report
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char path[100];
    cout << "Enter the file name: ";
    cin.getline(path, 100);
    ifstream inFile(path);
    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!";
        return 0;
    }
    int n;
    inFile >> n;
    if (n > 30) {
        cout << "Too many students!";
        inFile.close();
        return 0;
    }
    inFile.ignore(100, '\n');
    ofstream outFile("scholarship.txt");
    char name[30];
    char topName[30];
    int students = 0;
    int eligible = 0;
    double cgpa;
    double total = 0;
    double highest = -1;
    for (int i = 0; i < n; i++) {
        inFile.getline(name, 30, ',');
        if (!inFile)  {
            break;
        }
        if (!(inFile >> cgpa)) {
            break;
        }
        inFile.ignore(100, '\n');
        cout << "[" << name << "] CGPA: " << cgpa << endl;
        students++;
        total += cgpa;
        if (cgpa >= 3.50)
        {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }
        if (cgpa > highest) {
            highest = cgpa;
            int j = 0;
            while (name[j] != '\0')  {
                topName[j] = name[j];
                j++;
            }
            topName[j] = '\0';
        }
    }
    if (students < n) {
        cout << "Warning: only " << students
            << " of " << n << " records found." << endl;
    }

    if (students == 0) {
        cout << "No students found!";
        inFile.close();
        outFile.close();
        return 0;
    }
    double average = total / students;
    cout << "Students: " << students << endl;
    cout << "Average CGPA: " << average << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName
        << " (" << highest << ")" << endl;
    inFile.close();
    outFile.close();
    return 0;
}
