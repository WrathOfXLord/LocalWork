#include "Savings.hpp"
#include <iostream>
#include <vector>


using namespace std;

/**
 * interface sınıflar içerisinde pure virtual function deklarasyonu bulundururlar. 
 * içerisinde hiçbir member function veya veri elemanı bulunduramaz.
 * kendisinden inherit eden alt sınıflar pure virtual functionları implement etmek zorundadır. Aksi halde abstract class olarak kalırlar.
 */

int main()
{
    vector<Account *> accList;
    try {
        Account *acc {new Account {"veli", 123.0}};
        acc->deposit(6);
        accList.push_back(std::move(acc));
        acc = nullptr;
        std::cout << *(accList.at(0)) << endl;

        Account *printable {new Savings {"ali", 50, 12}};
        accList.push_back(std::move(printable));
        printable = nullptr;
        accList.at(1)->withdraw(100.0);
        accList.at(1)->deposit(125.0);
        cout << accList.at(1) << endl;
    
    } catch (IllegalBalanceException &except) {
        std::cerr << except.what() << std::endl;
    } catch (NegativeIntRateException &except) {
        std::cerr << except.what() << std::endl;
    } catch (ExceededWithdrawalAmountException &except) {
        std::cerr << except.what() << std::endl;
    } catch (IllegalBalanceException &except) {
        std::cerr << except.what() << std::endl;
    } catch (NegativeAmountException &except) {
        std::cerr << except.what() << std::endl;
    }
    
    cout << "--------------------------------------------------" << endl;
    displayAccVec(accList);

    

    return 0;
}