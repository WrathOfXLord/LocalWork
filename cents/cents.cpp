#include <iostream>
#include <iomanip>

//#include <bitset>

using namespace std;

int main()
{
    const int dollar_val {100};
    const int quarter_val {25};
    const int dime_val {10};
    const int nickel_val {5};

    cout << "Please enter cent value that you want to be converted to dollars, quarters etc : ";
    unsigned int money {};    //suppose 1236 given
    cin >> money;
    if (money < 0){
        cerr << "invalid amount" << endl;
        exit(EXIT_FAILURE);
    }
    unsigned int money_remain {money};

    unsigned int dollars {money / dollar_val};
    cout << "dolars are : " << dollars << endl;

    money_remain -= dollar_val * dollars;
    
    unsigned int quarters {money_remain / quarter_val};
    cout << "quarters are : " << quarters << endl;

    money_remain -= quarter_val * quarters; 

    unsigned int dimes {money_remain / dime_val};
    cout << "dimes are : " << dimes << endl;

    money_remain -= dime_val * dimes;

    unsigned int nickels {money_remain / nickel_val};
    cout << "nickels are : " << nickels << endl;

    money_remain -= nickel_val * nickels;

    cout << "pennies are : " << money_remain << endl;

 

    //cout << std::bitset<8>(237) << endl;

    return 0;
}