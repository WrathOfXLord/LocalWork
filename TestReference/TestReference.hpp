#ifndef __TESTREFERENCE_HPP__
#define __TESTREFERENCE_HPP__

class TestReference {
private:
    int someValue {};
    
public:
    TestReference(int someValue = 0) : someValue {someValue} {

    }

    bool setValue(int val) {
        this->someValue = val;
        if(someValue == val)
            return true;
        return false;
    }

    int getVal() {
        return this->someValue;
    }

    int &getValueRef() {
        int &refX = this->someValue;
        return refX;
    }

    
};

#endif