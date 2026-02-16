#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        double sales[5][4] = {0};  // 5 products, 4 salespeople
        int sp, prod;
        double amt;
        char choice;

        // Input sales
        do {
            cout << "\nSalesperson (1-4): ";
            cin >> sp;
            cout << "Product (1-5): ";
            cin >> prod;
            cout << "Amount: ";
            cin >> amt;

            sales[prod-1][sp-1] += amt;

            cout << "Enter another sales slip? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << fixed << setprecision(2);

        // Header
        cout << "\n-----------------------------------------------------------\n";
        cout << setw(10) << "Product";
        cout << setw(10) << "1"
             << setw(10) << "2"
             << setw(10) << "3"
             << setw(10) << "4"
             << setw(10) << "Total\n";
        cout << "-----------------------------------------------------------\n";

        double grandTotal = 0;

        // Row totals (per product)
        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;

            cout << setw(10) << i + 1;

            for (int j = 0; j < 4; j++) {
                cout << setw(10) << sales[i][j];
                rowTotal += sales[i][j];
            }

            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "-----------------------------------------------------------\n";

        // Column totals
        cout << setw(10) << "Total";

        for (int j = 0; j < 4; j++) {
            double colTotal = 0;
            for (int i = 0; i < 5; i++) {
                colTotal += sales[i][j];
            }
            cout << setw(10) << colTotal;
        }

        cout << setw(10) << grandTotal << endl;
        cout << "-----------------------------------------------------------\n";

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}