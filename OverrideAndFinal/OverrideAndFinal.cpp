#include <iostream>

using namespace std;

/***************************************************************************************************************************************************
 * -- "final" keyword'ü (anahtar kelimesi) inheritance kullanan sınıflar için ve üst sınıftan inherit eden alt sınıfa ait
 * aynı imzalı fonksiyonlar kullanılırken (override) için kullanılır.
 * - Sınıflardaki amacı; bir sınıftan başka bir alt sınıf üretilmesini engellemektir.
 * sınıf adından hemen sonra "final" keyword'ü kullanılır.
 * örnek olarak :   "class Base final {...};" 
 *                          veya 
 *                  "class Lower final: public High {...};"
 * Base ve Lower sınıflarından artık alt sınıflar üretilemez.
 * -----------------------------------------------------------------------------------------------------------------------
 * - Fonksiyonlardaki amacı ise; temel sınıftan üretilen alt sınıfın aynı imzaya sahip fonksiyonlarının temel sınıfın 
 * fonksiyonlarının yerine geçmesini yani temel sınıfın fonksiyonlarının geçerliliğini kaybettirip alt sınıfın aynı imzaya
 * sahip fonksiyonunun kullanımını (overriding) engellemektir.
 * 
 * örnek olarak :   "virtual void sayHello() const final {...};"
 * temel sınıfta bu tanımı yaptıktan sonra alt sınıfta tanımlanan: 
 *                  "virtual void sayHello() const {...};"
 * compile hatası verdirecektir. Çünkü üstteki fonksiyon "final" keyword'ü içeriyor, hiçbir şekilde override edilemez.
 * **************************************************************************************************************************************************
 * -- "override" keyword'ü ise temel(üst) sınıftan inherit eden bir alt sınıfa ait aynı imzaya sahip fonksiyonu temel
 * sınıfa ait fonksiyonun geçerliliğini ortadan kaldırırken (overriding) kullanılır. Aslında bu keyword'ü kullanmasak bile 
 * compiler kapalı bir şekilde(implicitly) bunu yapar ancak fonksiyon imzasında yapılan bir hata overriding değil
 * redefining(yeniden tanımlama) yapar bu da temel sınıf pointer'ı veya referensı kullanırken dynamic binding değil static
 * binding yapmasına sebep olur. Bu yüzden de alt sınıfın fonksiyonu çağırılamaz. Bunun önüne geçmek için fonksiyonun 
 * imzasından sonra ve fonksiyon bloğundan önce "override" yazılır ki olası yanlış yazımların önüne geçilsin ve kodun anlaşılırlığı artsın
 * 
 * örnek olarak :  "virtual void sayHello() const override {...}"
 * - sayHello fonksiyonu temel sınıfın sayHello fonksiyonunu override eder bu sayede. alt sınıf fonksiyonunun imzasında hata
 * varsa compile hatası almamızı sağlar. 
 */

class Base {
public:
    virtual void sayHello() const { cout << "Hello from base class" << endl; }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    virtual void sayHello() const override final { cout << "Hello from derived class" << endl; }
    // virtual void sayHello() override { cout << "Hello from derived class" << endl; }
    //yorumdaki fonksiyon imzası Base sınıfındaki imzayla birebir aynı olmadığı için redefining olur ancak sonunda override
    //yazıldığından override edilemedi diye compile hatası alınır
    virtual ~Derived() {}
};

class SubDerived final: public Derived {
public:
    // virtual void sayHello() const override { cout << "Hello from subderived class" << endl; }
    //üstteki fonksiyon üst sınıfta final edilmiş bir fonksiyonun yerine geçmeye çalışıyor compile hatasına sebep olur

};

//class SubSubDerived: public SubDerived {...};
//yukarıdaki kod compile hatası verir çünkü final edilmiş bir sınıftan alt sınıf üretiliyor

int main()
{
    Base *ptr1 {new Base {}};
    Base *ptr2 {new Derived {}};
    cout << "=========================================" << endl;
    ptr1->sayHello();
    ptr2->sayHello();

    return 0;
}