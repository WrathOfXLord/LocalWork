#include "DelegatingConstructors.hpp"
/*
 *Delegation: havale etmek, devretmek
 * burada en başta 4 parametreli constructor'ı tanımladık ardından
 * tek parametreli constructor'da initilization list yerine 4 parametreli constructor'ı çağırarak initialization yaptık
 * bu aynı kodların tekrarından kaynaklanan hataların önüne geçebilmemizi sağlıyor
 * ancak unutulmamalıdır ki objenin datalarını initialize ederken çağırdığımız 4 parametreli constructor kendi kod bloğunu da çalıştırıyor
 * örnek olarak main'de tek parametreli bir nesne oluşturduk bunu initialize (başlatma) ederken tek argümanlı constructor, 
 * initialization list içerisinde belli değerlerle 4 parametreli constructor'ı çağırdı. 4 parametreli constructor önce değerleri başlattı
 * ardından kendi kod bloğunu çalıştırdı. 4 lü constructor çalışmayı bitirince tek parametreli constructor kaldığı yerden yani,
 * kendi kod bloğundan devam etti, o bloğu da çalıştırdı
 * nesne oluşturulurken çıktı aşağıdaki gibi oldu:
 * "four arguments constructor is called."
 * "Single argument constructor is called."
 **********************************************
 * Son olarak delege constructor'ı süslü parantez ile çağırma işlemi ( Player {name, 100, 18, 0} ), normal paranteze [ Player(name, 100, 18, 0) ] göre
 * yaptığım deneyler sonucunda daha verimli çıktı.
 * süslü parantez başlatma süresi ort : 0.00098
 * normal constructor başlatma süresi ort : 0.0015
 */
//constructor definitions
Player::Player(string name, unsigned int health, unsigned int age, size_t xp)
: name {name}, health {health}, age {age}, xp {xp}
{
    cout << "four arguments constructor is called." << endl;
}

Player::Player()
: Player("None", 100, 18, 0)
{
    cout << "No argument constructor is called." << endl;
}

Player::Player(string name)
: Player {name, 100, 18, 0}
{
    cout << "Single argument constructor is called." << endl;
}

//destructor definition
Player::~Player()
{
    cout << "Destructor is called." << endl;
    cout << "This object no longer exists." << endl;
}


//member functions
void Player::talk(string any)
{
    cout << name << " : " << any << endl;
}

bool Player::isDead()
{
    if(health == 0)
    {
        cout << "player is dead." << endl;
        return true;
    }
    
    cout << "player is alive." << endl;  
    return false;
}