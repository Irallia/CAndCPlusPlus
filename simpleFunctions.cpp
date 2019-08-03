#include <iostream>

using namespace std;

int main() {

    cout << 10 / 3 << endl;
    cout << 10.0 / 3.0 << endl;

    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old.";

    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello " << name << "!";

    return 0;
}
