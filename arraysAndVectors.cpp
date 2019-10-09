#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

int main() {

    /* arrays: */
    int luckyNums[20] = {4, 8, 15, 16, 23, 42};
    luckyNums[10] = 100;
    cout << luckyNums[10] << endl;
    cout << luckyNums[11] << endl;

    /* std arrays: */
    array<double, 3> ad1;    // use std arrays instead of build in arrays
    array<double, 3> ad2{3.1,4.5,3.5};
    cout << ad1.size() << ' ';
    cout << ad1.end() << '\n';
    cout << ad2.size() << ' ';
    cout << ad2.end() << '\n';

    /* std vectors: */
    vector<double> vd1;      // resizable arrays
    vector<double> vd2{3.1,4.5,3.5};
    // cout << vd1[0] << ' ';
    cout << vd1.size() << '\n';
    vd2.push_back(6.5);
    cout << vd2.size() << ' ';
    cout << vd2.back() << '\n';

    vector<uint16_t> vec{1, 22, 333, 4444};
    for(uint16_t e : vec)
        cout << e << ' ';

    for (size_t i = 0; i < vec.size(); i++) {
        cout << "elem no." << i << " is " << vec[i] << '\n';
    }

    /* std string: */
    string s;              // similar to vector<char> (but a string you can print in a whole)
    cout << s << '\n';
}
