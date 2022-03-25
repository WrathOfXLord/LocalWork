#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //vector <int> test;       //empty vector
    //vector <int> test (10);  //10 integer declared, direct initialization is required
    //vector <int> test {5, 7};//vector initialised with 2 elements

    // 1 x N size vector (1d - 1 dimensional)
    vector <int> test (10, 5); //10 integer declared and all initialised to 5, direct initialization is required
    for(auto i {0}; i < test.size(); i++)   //vector.size() returns the size of given vector
        cout << "index " << i << " value is "
             << test.at(i) << endl;             //vector.at(i) goes to element i of vector
    //test[i]; works too but no bounds checking
    //this loop could be done as the following way
    //  for(auto it {test.begin()}; it != test.end(); it++)
    //      cout << "value is " << *it << endl; 

    cout << "enter a value to change element 9: ";
    cin >> test.at(9);  //reads user input into element 9
    cout << "element 9 is now " << test.at(9) << endl;

    cout << "enter a value to add a new element: ";
    auto user_input {0};
    cin >> user_input;

    test.push_back(user_input);     //adds a new element to the end of the vector
    cout << "last element is now: " << test.at(test.size() - 1) << endl;

    cout << "last element was " << test.back() << " and removed." << endl;  //vector.back() returns the last element
    test.pop_back();    //removes the last element and reduce the size by 1

    cout << "last element is now: " << test.back() << endl;
    for(auto i {0}; i < test.size(); i++)   //vector.size() returns the size of given vector
        cout << "index " << i << " value is "
             << test.at(i) << endl;

    //cin >> test.at(10);   //throws exception out of bounds

    // N x N size vector (2d - 2 dimensional)
    vector <vector<int>> test_vector_2d_test{{2, 0},        //think of like x,y pairs
                                             {2, 1},        //2d vector
                                             {2, 2}};       //this one is 3x2 vector

    vector <vector<int>> test_2d (4, {5, 2, 3});            //all elements are initialised to {5, 2, 3}

                                /*****************
                                 * equals to :   *
                                 * {5, 2, 3}     *
                                 * {5, 2, 3}     *
                                 * {5, 2, 3}     *
                                 * {5, 2, 3}     *
                                 * ***************/
                                
    cout << "any element of test_2d is: " << test_2d.at(2).at(2) << endl;   //accessing to 3 in {5, 2, 3}

    vector <vector<int>> test_2d_2 (4, vector<int> (5));          //initialising 4x5 2d vector
    vector <vector<int>> test_2d_3 (4, vector<int> (5, 2) );      //initialising all elements of 4x5 2d vector with 2
    /*********************************************
     * this could be done with the following way *
     * vector <int> v (5, 2);                    *
     * vector <vector<int>> v_2d (4, v);         *
     *********************************************/

    test_2d_2.push_back(test);
    cout << "last element of test_2d_2 is: " << test_2d_2.back().back() << endl;

    //to access 2d vector elements
    cout << "second element of first pair is: ";
    cout << test_vector_2d_test.at(0).at(1) << endl;    //vector.at(0) accesses to {2, 0} pair, but cannot print, compile error
                                                        //vector.at(0).at(1) accesses to 0 of {2, 0} pair

    return 0;
}