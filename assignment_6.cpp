#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile;
    inputFile.open("NUMS.txt");

    if (!inputFile) {
        cout << "Error: could not open NUMS.TXT" << endl;
        return 1;
    }

    int num;
    int count = 0;

    cout << "Prime numbers found: \n" << endl;

    while (inputFile >> num) {
        if (isPrime(num)) {
            cout << num << endl;
            count++;
        }
    }

    inputFile.close();

    cout << "\nTotal: " << count << endl;

    return 0;
}
