#pragma once

#include "Base.hpp"

class DerivedAsPublic : public Base {
private:
    string newAsPublic;
protected:

public:
    DerivedAsPublic() : newAsPublic {"newAsPublic"} {}
    const string &getNewAsPublic() const { return newAsPublic; }

};