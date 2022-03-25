#include "Move.hpp"
#include <vector>

using namespace std;

int main()
{
    // Move m1(12);
    // Move m2(m1);

    vector <Move> mList;
    mList.push_back(Move {15});
    // mList.push_back(Move {20});
    // mList.push_back(Move {10});
    cout << "---------------------------------" << endl;
    cout << mList.at(0).getData() << endl;;
    cout << "---------------------------------" << endl;

    return 0;
}