#pragma once

#include <iostream>
#include <string>

using std::string;

class Base {
private:
    string belongsToBase; //this  data member cannot be reached without public getter function from the class that inherits.
                          // even with public inheritance
    //no need to create member methods as private since they cannot be accessed from outside
protected:
    string protectedFromOutside;

public:
    string freeForAll;
    
    Base()  :belongsToBase {"private base"}, protectedFromOutside {"protected base"}, freeForAll {"public base"} {}

    string getPrivateAsPublic() const { return belongsToBase; }
    string getProtectedAsPublic() const { return  protectedFromOutside; }
    string getPublicAsPublic() const { return freeForAll; } //unnecessary, public data can be accessed anywhere.


};