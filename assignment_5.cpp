#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ofstream writeFile("original.txt");

    if (!writeFile) {
        cout << "Failed to open original.txt for writing.\n";
        return 1;
    }

    writeFile << "One" << endl;
    writeFile << "Two" << endl;
    writeFile << "Three" << endl;
    writeFile << "Four" << endl;
    writeFile << "Five" << endl;
    writeFile << "Six" << endl;

    writeFile.close();


    ifstream readFile("original.txt");

    if (!readFile) {
        cout << "Failed to open original.txt for reading.\n";
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(readFile, line)) {
        words.push_back(line);
    }

    readFile.close();

    sort(words.begin(), words.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "Failed to create the sorted file.\n";
        return 1;
    }

    for (string word : words) {
        sortedFile << word << endl;
    }

    sortedFile.close();

    cout <<  "Sorting complete. Check sorted.txt" << endl;

    return 0;
}
