#include "ReadFile.hpp"


ReadFile::ReadFile(const std::string &filename, Students &destination)
: filename {filename}, read {filename, std::ios::in}
{
    if(!read.is_open()) { throw FileIsNotOpenedException {}; }

    std::vector<Student> tempSt;
    read >> answer_key;
    Student temp;
    while(read >> temp.name >> temp.response) {
        grade(temp, answer_key);
        tempSt.push_back(temp);
    }
    destination.students = std::move(tempSt);

    std::cout << "reading is done" << std::endl;
}

ReadFile::ReadFile(std::string &&filename, Students &destination)
: filename {filename}, read {std::move(filename), std::ios::in}
{
    if(!read.is_open()) { throw FileIsNotOpenedException {}; }
    
    std::vector<Student> tempSt;
    read >> answer_key;
    Student temp;
    while(read >> temp.name >> temp.response) {
        grade(temp, answer_key);
        tempSt.push_back(temp);
    }
    destination.students = std::move(tempSt);

    std::cout << "reading is done" << std::endl;
}

ReadFile::~ReadFile()
{
    this->read.close();
}

size_t ReadFile::grade(Student &s, const std::string &answer_key)
{
    size_t counter {};
    for(size_t i {}; i < answer_key.size(); ++i) {
        if(s.response.at(i) == answer_key.at(i))
            ++counter;
    }
    s.mark = counter;

    return counter;
}
