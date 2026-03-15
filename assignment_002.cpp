#include <iostream>
using namespace std;

void analyzeGades(int *grades, int students, int subjects){
    int highest=*(grades);

    cout << "\nGrade Matrix:\n";

    for (int i=0; i< students; i++){
            double sum=0;
        for(int j=0; j<subjects; j++){
            int value= *(grades + i * subjects + j);
            cout << value << "\t";
            sum += value;
            if (value >highest){
                highest=value;
            }
        }
       cout << " | Average: "<< sum / subjects;
       cout <<endl;
    }
    cout << "\nHighest Grade in Matrix: "<<highest<<endl;

}

int main(){
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades [students][subjects];

    cout << "\nEnter Grades: \n";

    for (int i=0; i< students; i++){
        for (int j=0; j< subjects; j++){
            cout << "Student " << i + 1 << ", subjects " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }
    analyzeGades(&grades[0][0], students , subjects);

return 0;
}
