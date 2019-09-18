#include <iostream>

using namespace std;

int main() {


    // int age;
    string age;
    cout << "Enter your age: ";
    // cin >> age;
    getline(cin, age);
    cout << "You are " << age << " years old." << endl;

    /*
        Assuming you typed: 5<enter>John<enter>. Then cin >> age reads JUST 5. leaving the new-line (enter) character on the stream.
        Thus when you try and read the name with getline(cin,name) it reads to the end of line.
        BUT NOTE there is a new-line character just there ready to be read (thus names will be empty (because you did not read off the new-line character after the 5).
        If you want to switch between >> and getline() you need to be carefull about trailing end of lines on your input. – Martin York Apr 21 '11 at 8:41
        https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin
    */
    cout << "(press enter)" << endl;
    cin.ignore(256, '\n'); // remaining input characters up to the next newline character are ignored

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, your name has " << name.length() << " characters and ist starting with " << name[0] << "!" << endl;
    int addressOfMyName = name.find("Lydia", 0);
    if (addressOfMyName > -1) {
        cout << "You have my name "  << name.substr(addressOfMyName, 2)<< "!";
    };

    return 0;
}
