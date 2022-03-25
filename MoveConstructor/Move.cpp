#include "Move.hpp"

Move::Move(int val)
: data{new int {val}}
{
    cout << "Single arg - constructor was called for - " << *data << endl;
}

Move::Move(const Move &source)
: Move {*(source.data)}    //delegating constructor instead of initialisation list

{   
    cout << "Copy constructor was called for - " << *data << endl;
}

/*
 * Fonksiyonlara vector'lara nesne veya değişken yerine değer (r value)
 * verildiğinde fonskyion veya vector ilk önce veriyi isimsiz geçici bir değişkende veya nesnede saklar
 * daha sonra copy constructor ile nesneye/değişkene kopyalanır. Bu fazlasıyla yapıldığında oldukça verimsiz olur.
 * Bunun önüne geçmek için move constructor tanımlanmalıdır
 * Move constructor verimli olması açısından raw pointer içeren sınıflarda kullanılmalıdır
 * Move constructor örnek olarak;
 *     "vector <Move> m;
 *      m.push_back(10);"
 * tanımlansın böyle bir durumda eğer move constructor yoksa
 * pointer datası 10 olan (*ptr = 10) geçici bir nesne üretilir ve bu nesne vector'a
 * kopyalanır bunun yerine direkt olarak veriyi alıp kullanmak için move constructor kullanılır
 * Bunun için move constructor'ın data pointer'ını kaynak data pointer'ı ile başlatıp
 * kaynak pointer'ı nullptr'a eşitlemeliyiz (bunu yapmalıyız yoksa sığ kopyalama yapmış oluruz)
 * 
 */
Move::Move(Move &&source)
: data {source.data}
{
    source.data = nullptr;
    cout << "Move constructor was called for - " << *data << endl;
}

Move::~Move()
{
    if(data != nullptr)
    {
        cout << "Destructor was called for - " << *data << endl;
    }  
    else
    {
        cout << "Destructor was called for nullptr. " << endl;
    }
    
    delete data; //or delete this->data;
}

int Move::getData()
{
    return *data;
}

void Move::setData(int val)
{
    *data = val;
}



// void printData(Move &source)
// {
//     cout << "[ ";
//     for(size_t i {0}; i < source.getSize(); ++i)
//         cout << source.getData()[i] << " ";
//     cout << "]" << endl;
// }


