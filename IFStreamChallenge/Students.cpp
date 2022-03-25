#include "Students.hpp"

std::ostream &operator<<(std::ostream &out, const Students &rhs)
{
    rhs.display();
    return out;
}


double Students::meanScore() const
{
    size_t sum {};
    size_t count {};
    for(const Student &s : this->students) {
        sum += s.mark;
        ++count;
    }
    return static_cast<double>(sum) / count;
}

void Students::display() const
{
    if(this->students.size() == 0) {
        std::cout << "no students" << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::left << "Student"
              << std::setw(10) << std::right << "Score" << std::endl;
    
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    for(const Student &stud : this->students)
    {
        std::cout << std::setw(10) << std::left << std::setfill(' ') 
                  << stud.name << std::setw(10) << std::right 
                  << stud.mark << std::endl;
    }
    std::cout << std::setw(20) << std::setfill('-') << '-' << std::endl;
    std::cout << std::setw(10) << std::left << "Average Score"
              << std::setw(7) << std::right << std::setfill(' ') 
              << this->meanScore() << std::endl;

}