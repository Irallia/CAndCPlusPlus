/*
* ofstream: Stream class to write on files.
* ifstream: Stream class to read from files.
* fstream: Stream class to read and write from/to files.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream myFile;
    myFile.open("test.txt");
    myFile << "5\n3\n7";
    myFile.close();                 // Don't forget to close the file.

    ifstream inputFile;
    inputFile.open("test.txt");
    if (inputFile.fail()) {         // Check for Error
        cerr << "Error opening file" << endl;
        exit(1);
    }
    int x, y, z;
    inputFile >> x >> y >> z;
    cout << "x, y, z: " << x << ", " << y << ", " << z << endl;

    inputFile.close();

    ofstream myFileAgain;
    myFileAgain.open("test.txt");
    myFileAgain << "Mango\nApfel\nKiwi\nOrange\nPflaume\nOrange\nBanane";
    myFileAgain.close();

    ifstream inputFileAgain;
    inputFileAgain.open("test.txt");
    if (inputFileAgain.fail()) {         // Check for Error
        cerr << "Error opening file" << endl;
        exit(1);
    }
    string line;
    string text[255];
    int count = 0;
    int oranges = 0;

    while (!inputFileAgain.eof()) {     // eof == end of file
        inputFileAgain >> line;
        text[count] = line;
        if (line == "Orange") {
            oranges++;
        }
        count++;
    }

    cout << count << " Früchte gefunden!" << endl;
    cout << "Davon " << oranges << " Orangen." << endl;

    inputFileAgain.close();

    return 0;
}