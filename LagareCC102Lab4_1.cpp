#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;
    do {
        int s, q;
        cout << "Students: ";
        cin >> s;
        cout << "Quizzes: ";
        cin >> q;

        float scores[50][50], avg;

        for (int i = 0; i < s; i++) {
            float sum = 0;
            cout << "\nStudent " << i+1 << ":\n";
            for (int j = 0; j < q; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            avg = sum / q;

            cout << "Average: " << fixed << setprecision(2) << avg << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}