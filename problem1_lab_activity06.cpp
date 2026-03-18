#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    float gpa;
};

string getStanding(float gpa) {
    if (gpa >= 90 && gpa <= 100)
        return "Excellent";
    else if (gpa >= 80)
        return "Very Good";
    else if (gpa >= 70)
        return "Good";
    else if (gpa >= 60)
        return "Passing";
    else
        return "Failed";
}

int main() {
    char again;
    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student s[n];

        for (int i = 0; i < n; i++) {
            cout << "\nStudent " << i + 1 << endl;

            bool unique;
            do {
                unique = true;
                cout << "Enter Student ID: ";
                cin >> s[i].studentID;

                for (int j = 0; j < i; j++) {
                    if (s[i].studentID == s[j].studentID) {
                        cout << "Student ID already exists, Enter another ID.\n";
                        unique = false;
                        break;
                    }
                }
            } while (!unique);

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, s[i].name);

            cout << "Enter Course: ";
            getline(cin, s[i].course);

            cout << "Enter GPA: ";
            cin >> s[i].gpa;
        }

        // total width of table
        int totalWidth = 12 + 25 + 20 + 10 + 15;

        cout << "\n\nStudent Records\n";
        cout << string(totalWidth, '-') << endl;

        cout << left << setw(12) << "ID"
             << setw(25) << "Name"
             << setw(20) << "Course"
             << setw(10) << "GPA"
             << "Standing" << endl;

        cout << string(totalWidth, '-') << endl;

        for (int i = 0; i < n; i++) {
            cout << left
                 << setw(12) << s[i].studentID
                 << setw(25) << s[i].name
                 << setw(20) << s[i].course
                 << setw(10) << fixed << setprecision(2) << s[i].gpa
                 << getStanding(s[i].gpa) << endl;
        }

        cout << string(totalWidth, '-') << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}