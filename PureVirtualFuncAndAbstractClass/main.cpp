#include <iostream>
#include <vector>
#include "Shape.hpp"

using namespace std;

/* -- Sınıflar abstract (soyut) ve concrete (somut) olmak üzere ikiye ayrılır.
 * - Concrete classlar şimdiye kadar kullandığımız kendilerinden bir şeyler üretilebilen nesnesi olan sınıflardı
 * - Abstract classlar ise daha çok soyut veya jenerik daha genel olan sınıflardır. Kendilerinden nesne üretilemez.
 * 
 * - Örnek olarak şekil ve kare sınıflarını düşünelim.
 * - kare sınıfının belli bir özelliği vardır, örneğin köşe sayısı, kenarları, köşegeni vardır nasıl çizileceği bilinir.
 * - Ancak şekil dediğimiz zaman herkesin zihninde belirli bir şekil canlanmaz bu yüzden de köşesi, kenarı olup olmadığı bilinmez
 *   bu yüzden de şeklin nasıl çizileceği de bilinemez. Çünkü şekil daha genel ve soyut bir tanımdır. 
 * - Bu yüzden şekil sınıfı abstract sınıf tipine girerken, kare concrete sınıf tipine girer. Tüm bunları tanımlayabilmemiz için de
 *   c++'da abstract classlar tanımlanmıştır.
 * - Abstract class'lar soyut (ya da daha genel) olduğundan nesneleri olamaz, nesneleri üretilemez (ya da başlatılamaz).
 * - kendilerine ait bir pointer'ı olabilir ancak pointer kullanarak bile heap'den alan ayırarak başlatılamazlar.   
 * 
 * -- C++ 'da abstract sınıf tanımlanırken sınıfın prototipi normal sınıfla aynıdır ancak sınıfın içerisinde 
 *   (tercihen public veya protected bölümde) en az bir tane pure virtual function (tümüyle sanal fonksiyon) bulunmalıdır.
 * - Pure Virtual Function tanımı örnek olarak aşağıdaki gibidir:
 * 
 *      "virtual void draw(double amount) = 0;"
 * 
 * - fonksiyon imzasından sonra 0'a eşitleme yapılır. Pure virtual function implementasyonu abstract class içerisinde yapılmaz, abstract
 *   class'dan inherit eden alt sınıfların kendine uygun bir şekilde implement etmesi beklenir.
 * - Abstract sınıftan inherit eden alt sınıflar eğer pure virtual function'ları implement etmez ise 
 *   alt sınıflar da abstract olur. Bu yüzden alt sınıfların nesneleri oluşturulmak isteniyorsa pure virtual function'ları
 *   implement edilmelidir. 
 * 
 */

void displayShapeVec(const std::vector <Shape *> &source, double value)
{
    for(const auto ptr:source)
        ptr->draw(value);
}


int main()
{
    std::vector<Shape *> shapes;

    Square *sqr {new Square {}};        //OK.
    sqr->draw(50);                      //OK.
    shapes.push_back(sqr);

    Shape *shape1 {new Square {}};      //OK.
    shape1->draw(100);                  //OK.
    shapes.push_back(shape1);

    OpenShape *shape2 {new Line {}};    //OK.
    shape2->draw(25);                   //OK.
    shapes.push_back(shape2);

    CloseShape *shape3 {new Square {}}; //OK.
    shape3->draw(35);                   //OK.
    shapes.push_back(shape3);

    cout << "==========================================================" << endl;
    displayShapeVec(shapes, 50.0);  //we are displaying all shapes in shapes vector no need to create specific display method

    //abstract classes

    // Shape s1;                        //Compile Error, abstract class cannot has any objects
    // Shape *shpPtr {new Shape {}};    //Compile Error, abstract class cannot has any objects




}