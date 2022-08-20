#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <iostream>
#include <string>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    size_t age;
public:
    const std::string &getFirstName() const { return firstName; }
    void setFirstName(const std::string_view name) { firstName = name; }
    const std::string &getLastName() const { return lastName; }
    void setLastName(const std::string_view name) { lastName = name; }
    size_t getAge() { return age; }
    void setAge(size_t age) { this->age = age; }
    
    Person() : firstName {}, lastName {}, age {18} { std::cout << "constructor from the base of the base\n"; }
};

#endif