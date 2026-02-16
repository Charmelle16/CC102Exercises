#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int s, q;

        cout << "Enter number of students: ";
        cin >> s;

        cout << "Enter number of quizzes: ";
        cin >> q;

        float scores[50][50];
        float average[50];

        // INPUT SCORES
        for (int i = 0; i < s; i++) {
            float sum = 0;

            cout << "\nStudent " << i + 1 << " scores: ";

            for (int j = 0; j < q; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / q;
        }

        cout << fixed << setprecision(2);

        // TABLE HEADER
        cout << "\n-----------------------------------------------------------\n";
        cout << setw(10) << "Student";

        for (int j = 0; j < q; j++) {
            cout << setw(8) << "Q" + to_string(j + 1);
        }

        cout << setw(10) << "Average\n";
        cout << "-----------------------------------------------------------\n";

        // DISPLAY TABLE
        for (int i = 0; i < s; i++) {
            cout << setw(10) << i + 1;

            for (int j = 0; j < q; j++) {
                cout << setw(8) << scores[i][j];
            }

            cout << setw(10) << average[i] << endl;
        }

        cout << "---------------------------------------------------------\n";

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}