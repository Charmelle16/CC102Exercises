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

            cout << "Do you want to enter another sales slip? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\nProduct\t1\t2\t3\t4\tTotal\n";

        double grandTotal = 0;

        // Row totals (per product)
        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << i+1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        // Column totals (per salesperson)
        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double colTotal = 0;
            for (int i = 0; i < 5; i++) {
                colTotal += sales[i][j];
            }
            cout << colTotal << "\t";
        }

        cout << grandTotal << endl;

        cout <<"\nDo you want to enter another sales slip? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}