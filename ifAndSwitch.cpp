#include <iostream>

using namespace std;

int getMax(int num1, int num2){

    int result;

    if(num1 > num2){
        result = num1;
    } else {
        result = num2;
    }
    return result;
}

string getDayOfWeek(int dayNum){
    string dayName;

    switch (dayNum)
    {
    case 0:
        dayName = "Monday";
        break;
    case 1:
        dayName = "Tuesday";
        break;
    case 2:
        dayName = "Wednesday";
        break;
    case 3:
        dayName = "Thursday";
        break;
    case 4:
        dayName = "Friday";
        break;
    case 5:
    {
        string day = "Saturday";  // If you introduce variables, you need braces.
        dayName = day;
        break;
    }

    case 6:
        dayName = "Sunday";
        break;
    default:
        dayName = "Invalid Day Number";
        break;
    }

    return dayName;
}

int main() {

    bool amIcorrect = false;
    bool correctAnswer = true;

    if(amIcorrect && correctAnswer) {
        cout << "You are correct!";
    } else if(amIcorrect || correctAnswer) {
        cout << "You are still correct!";
    } else {
        cout << "You are not correct!";
    };
    cout << endl;

    cout << getMax(5,6) << endl;

    cout << getDayOfWeek(5) << endl;
    cout << getDayOfWeek(65) << endl;

    int const i = 6;
    // decision at compile-time
    if constexpr (i - 7 > 3)
    {
        // ...
    }

    return 0;
}
