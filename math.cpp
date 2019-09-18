#include <iostream>
#include <cmath>

using namespace std;

int main() {

    cout << "10 / 3 = " << 10 / 3 << endl;
    cout << "10.0 / 3.0 = " << 10.0 / 3.0 << endl;

    cout << "2^^5 = " << pow(2, 5) << endl;

    cout << "4.5 runden : " << round(4.5) << endl;
    cout << "4.2 aufrunden : " << ceil(4.2) << endl;
    cout << "4.8 abrunden : " << floor(4.8) << endl;

    cout << "Max of 2 & 5 : " << fmax(2, 5) << endl;


    return 0;
}
