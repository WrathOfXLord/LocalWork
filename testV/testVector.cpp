#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    vector <double> test_1d {3, 4, 2};
    vector <vector<double>> test_2d (3, test_1d);   //vector <vector<double>> test_2d (3, test_1d);
    test_2d.push_back(test_1d);
    
    vector <vector<vector<double>>> test (3, (vector <vector<double>>(3, (vector <double> {3, 4, 2}))));
    cout << "test [0][0][1] is " << test.at(0).at(0).at(1) << endl;

    double matrix[3][3] {{3, 4, 2},
                         {3, 4, 2},
                         {3, 4, 2}};

    cout << "matrix row 0 is " << matrix[0][0] << ", "
                               << matrix[0][1] << ", "
                               << matrix[0][2] << endl;
    
    // test.at(0).at(0).at(0) = 25;
    cout << "val is : " << test_2d.at(0).at(2) << endl;

    return 0;
}