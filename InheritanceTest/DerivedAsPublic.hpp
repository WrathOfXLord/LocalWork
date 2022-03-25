#pragma once

#include "Base.hpp"

class DerivedAsPublic : public Base {
private:
    string newAsPublic;
protected:

public:
    DerivedAsPublic() : newAsPublic {"newAsPublic"} {}
    string getNewAsPublic() const { return newAsPublic; }

};