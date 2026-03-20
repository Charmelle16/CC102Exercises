#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct student{
    int id;
    string name;
    string course;
    float gpa;
};

string standing(float gpa){
    if(gpa >= 90 && gpa <= 100)
        return "Excellent";
    else if(gpa >= 80)
        return "Very Good";
    else if(gpa >= 70)
        return "Good";
    else if(gpa >= 60)
        return "Passing";
    else
        return "Failed";
}

void input(student s[], int n){
    for(int i = 0; i < n; i++){
        cout << "\nStudent " << i+1 << endl;

        // Duplicate ID check
        bool unique;
        do {
            unique = true;
            cout << "Enter ID: ";
            cin >> s[i].id;

            // Check against previous IDs
            for(int j = 0; j < i; j++){
                if(s[i].id == s[j].id){
                    cout << "Student ID already exists!, Enter a different ID.\n";
                    unique = false;
                    break;
                }
            }
        } while(!unique);

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter Course: ";
        getline(cin, s[i].course);

        cout << "Enter GPA: ";
        cin >> s[i].gpa;
    }
}

void display(student s[], int n){
    int totalWidth = 12 + 25 + 20 + 10 + 15;

    cout << "\n\nStudent Records\n";
    cout << string(totalWidth,'-') << endl;

    cout << left
         << setw(12) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Course"
         << setw(10) << "GPA"
         << "Standing" << endl;

    cout << string(totalWidth,'-') << endl;

    for(int i = 0; i < n; i++){
        cout << left
             << setw(12) << s[i].id
             << setw(25) << s[i].name
             << setw(20) << s[i].course
             << setw(10) << fixed << setprecision(2) << s[i].gpa
             << standing(s[i].gpa) << endl;
    }

    cout << string(totalWidth,'-') << endl;
}

int main(){
    char again;
    int n;
    do{
        cout << "Enter number of students: ";
        cin >> n;

        student obj[n];

        input(obj,n);
        display(obj,n);

        cout << "\nDo you want to repeat? (y/n): ";
        cin >> again;

    } while(again == 'y' || again == 'Y');

    return 0;
}
