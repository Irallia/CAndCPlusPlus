#include <iostream>
#include <cmath>

using namespace std;

int main() {

    cout << "10 / 3 = " << 10 / 3 << "\n";
    cout << "10.0 / 3.0 = " << 10.0 / 3.0 << "\n";

    cout << "2^^5 = " << pow(2, 5) << "\n";

    cout << "4.5 runden : " << round(4.5) << "\n";
    cout << "4.2 aufrunden : " << ceil(4.2) << "\n";
    cout << "4.8 abrunden : " << floor(4.8) << "\n";

    cout << "Max of 2 & 5 : " << fmax(2, 5) << "\n";

    /* arithmetic assignment operators: */
    int i = 4;
    i = i + 5;
    i +=5;              // or -= *= /= %=

    int j = 7;
    bool d = (i = j);   // i will be assigned to j, because j is >0, d will be assigned to true.
    cout << d;

}
