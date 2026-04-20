#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream writeFile;
    ifstream readFile;
    ofstream copyFile;
    string line;


    writeFile.open("color.txt");

    if (!writeFile) {
        cout << "Failed to open color.txt for writing." << endl;
        return 1;
    }

    writeFile << "Red" << endl;
    writeFile << "Black" << endl;
    writeFile << "Green" << endl;
    writeFile << "Yellow" << endl;
    writeFile << "Pink" << endl;

    writeFile.close();

    readFile.open("color.txt");

    if (!readFile) {
        cout << "Failed to open color.txt for reading." << endl;
        return 1;
    }


    copyFile.open("color_copy.txt");

    if (!copyFile) {
        cout << "Failed to open color_copy.txt for writing." << endl;
        return 1;
    }

    while (getline(readFile, line)) {
        copyFile << line << endl;
        cout << line << endl;
    }

    readFile.close();
    copyFile.close();

    cout << "File copied successfully." << endl;
    

    return 0;
}
