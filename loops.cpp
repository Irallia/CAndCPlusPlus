#include <iostream>

using namespace std;

int power(int baseNum, int powNum){
    int result = 1;
    for (int i = 0; i < powNum; i++)
    {
        result = result * baseNum;
    }
    return result;
}

int main() {

    int index = 2;
    while(index <=4){
        cout << "index=" << index << endl;
        index++;
    }
    
    index = 6;
    do{
        cout << "index=" << index << endl;
        index++;
    }while(index <=5);

    for(int i=0; i<4; i++){
        cout << "i=" << i << endl;
    }

    cout << "3^4=" << power(3, 4) << endl;

    // Matrix: row x column
    int numberGrid[3][4] = {
        {1,3,5,7},
        {6,4,6,2},
        {8,4,3,5}
    };

    int rows = sizeof(numberGrid)/sizeof(numberGrid[0]);
    int cols = sizeof(numberGrid)[0]/sizeof(numberGrid[0][0]);
    cout << rows << "x" << cols << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << numberGrid[i][j] << " ";
        }
        cout << endl;
        
    };

    return 0;
}
