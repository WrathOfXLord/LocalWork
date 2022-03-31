#ifndef _A_TO_LL_H_
#define _A_TO_LL_H_

#include <exception>
#include <string>

namespace My {

    class InvalidInputException: std::exception {
    public:
        virtual const char *what() const noexcept override {
            return "Invalid Input For AtoLL Function";
        }
    };

    using int64_t = long long;
    using uint64_t = unsigned long long;

    int64_t AtoLL(const char *str) {
        uint64_t index {};
        short sign {1};
        int64_t value {0};
        bool bit {};

        if(str[0] == '-') {
            sign = -1;
            ++index;
            bit = true;
        } else if(str[0] == '+') {
            ++index;
            bit = true;
        }

        for(; str[index] >= '0' && str[index] <= '9'; ++index) {
            value = value * 10 + str[index] - '0';
        }

        if(value == 0) {
            if(!bit && index == 0)
                throw InvalidInputException {};
            else if (bit && index == 1) {
                throw InvalidInputException {};
            }
        }
        
        return sign * value;
    }

}

#endif