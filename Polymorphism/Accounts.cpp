#include <iostream>

using namespace std;

/*
 * Compiler inheritance kullanıldığında compile time sırasında nesneleri birbirine bağlama yapar (Static binding)
 * public inheritance'da ("a" is a "b" - a, b'dir.) Temel sınıfın pointerı veya referansı kullanılarak oluşturulan alt sınıf nesnesinin
 * temel sınıf nesnesiyle aynı imzaya sahip fonksiyonunu çağırmaya çalıştığımızda bize yine de temel sınıf fonksiyonunu çağırır.
 * Bunun aslında olmaması gerekir çünkü alt sınıf da ana sınıfın bir nesnesidir ve alt sınıfın da özelleşmiş aynı isimli fonksiyonu
 * olabilir. Ama compiler bunu compile time içerisinde anlayamaz bu yüzden aynı isimli ana sınıf fonksiyonunu çağırır. 
 * Bunun önüne geçmek için polymorphism kullanılır. Polymorphism'de aynı imzaya sahip fonsksiyonların imzalarının 
 * en başına "virtual" kelimesi getirilir. Bu sayede doğru fonksiyonlar doğru sınıflara runtime (çalışma süresi) içerisinde
 * bağlanır. "virtual" kelimesi kullanıldığı andan itibaren kendisiyle beraber alt sınıfın da aynı imzalı fonksiyonları 
 * kapalı bir şekilde (implicitly) "virtual" olur. Ama hangi fonksiyonların virtual olduğunu anlamak için aynı imzalı fonksiyonların
 * hepsine "virtual" kelimesini eklemekte yarar var.
 * 
 * Nesneler yok edilirken de compile time binding (derleme süresinde bağlama) yapılır. Temel sınıfın pointerı veya
 * referansı kullanılarak oluşturulmuş alt sınıf nesnelerinin sadece üst sınıf kısmı için destructor çağırılır 
 * "virtual" kullanılmış bir alt sınıf nesnesi temel sınıf pointerı veya referansıyla oluşturulmuşsa alt sınıfın kendisi de
 * destruct edilmeli (yok edilmeli). çünkü alt sınıfın içerisinde hafızanın heap bölümünde alan ayrılmış olabilir veya dosya açılmış
 * olabilir. alanın destructor ile serbest bırakılması veya açık dosyanın kapatılması gerekir yoksa ciddi sorunlar ortaya çıkabilir.
 * Bunun için de temel sınıfın destructor'ının başına "virtual" kelimesi getirilmelidir
 * Bu sayede temel sınıfın destructor'ı yerine alt sınıfın destructor'ı çağırılır.
 * Eğer "virtual" kelimesi yazılmazsa compiler büyük ihtimalle uyarı verecektir
 * Fonksiyonlarda olduğu gibi destructor'da da virtual yazıldığından itibaren inherit edilen bütün alt sınıfların da destructor'ı
 * kapalı bir biçimde (implicitly) "virtual" olur. Ancak kodun anlaşılırlığı ve açıkça belirtmek adına (explicitly) her alt sınıf
 * destructor'ının başına "virtual" kelimesi getirilmelidir.
 * 
 * Polymorphism'in kısacası mantığı geçersiz kılmadır (overriding). Polymorphism kullanılırken alt sınıf üye fonksiyonları
 * üst sınıf fonksiyonlarını geçersiz kılarak kendi fonksiyonlarının çalışmasını sağlar.
 */

//Basit bir hesap sınıfı örneği

class Account {
protected:
    string name;

public:
    const string &getName() const { return name; }
    Account(string name = "empty") : name {name} {}
    virtual void withdraw(double amount) { cout << "In Account::withdraw " << endl; }
    virtual ~Account() {};
};

class Checking: public Account {
public:
    Checking(string name = "empty") : Account {name} {}
    virtual void withdraw(double amount) { cout << "In Checking::withdraw " << endl; }
    virtual ~Checking() {};
};

class Savings: public Account {
public:
    Savings(string name = "empty") : Account {name} {}
    virtual void withdraw(double amount) { cout << "In Savings::withdraw " << endl; }
    virtual ~Savings() {};
};

class Trust: public Savings {
public:
    Trust(string name = "empty") : Savings {name} {}
    virtual void withdraw(double amount) { cout << "In Trust::withdraw " << endl; }
    virtual ~Trust() {};
};

int main()
{
    cout << "===================================================" << endl;
    cout << "Pointers" << endl;
    Account *ptr1 {new Account{}};
    Account *ptr2 {new Checking{}};
    Account *ptr3 {new Savings{}};
    Account *ptr4 {new Trust{}};
    cout << "===================================================" << endl;
    cout << "Withdrawals" << endl;
    ptr1->withdraw(50.0);
    ptr2->withdraw(50.0);
    ptr3->withdraw(50.0);
    ptr4->withdraw(50.0);
    cout << "===================================================" << endl;
    cout << "Deleting allocated space for Accounts" << endl;
    delete ptr1;
    delete ptr2;
    delete ptr3;
    delete ptr4;

    return 0;
}
