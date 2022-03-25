#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Students.hpp"
#include "FileIsNotOpenedException.hpp"


class Students;

class ReadFile {
    friend class Students;
private:
    std::string filename;
    std::ifstream read;
    std::string answer_key;
    size_t grade(Student &s, const std::string &answer_key);
public:
    ReadFile(const std::string &filename, Students &destination);
    ReadFile(std::string &&filename, Students &destination);
    ~ReadFile();

};