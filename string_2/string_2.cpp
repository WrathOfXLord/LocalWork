#include <iostream>
#include <string>
#include <limits>

struct byte {
    using schar_limits = std::numeric_limits<int8_t>;
    using uchar_limits = std::numeric_limits<uint8_t>;

    short value;
    
    byte() : value {} {}
    byte(int value) : value {checkValueRange(value)} {}

    bool is_signed() const { return value <= schar_limits::max(); }
    short checkValueRange(int value) {
        bool is_signed = value <= schar_limits::max();
        if(is_signed && value < schar_limits::min()) {
            return value % schar_limits::min();
        }
        if(!(value >= uchar_limits::min() && value <= uchar_limits::max())) {
            return value % uchar_limits::max();
        }
        return value;
    }

    byte &operator=(const byte &rhs) {
        bool is_signedL = this->is_signed();
        bool is_signedR = rhs.is_signed();
        if(this == &rhs || is_signedL != is_signedR) {
            return *this;
        }
        this->value = rhs.value;
        return *this;
    }

    byte &operator=(int value) {
        bool is_signed = value <= schar_limits::max();
        if(this->is_signed() != is_signed) {
            return *this;
        }
        this->value = checkValueRange(value);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const byte &rhs) {
        out << rhs.value;
        return out;
    }

    byte &operator<<(const byte &rhs) {
        return operator=(rhs);
    }

    byte &operator<<(int value) {
        return operator=(value);
    }

    byte &operator>>(byte &rhs) {
        return rhs.operator=(*this);
    }

    int &operator>>(int &value) {
        return value = this->value;
    }
};

int main()
{
    byte b {119}, c {7}, d{2};
    int val {};
    b >> c >> d >> val;
    std::cout << "min: " << (int)std::numeric_limits<int8_t>::min() << "\n";
    std::cout << "byte b, c, d, val: " << b << " - " << c << " - " << d << " - " << val << "\n";

    return 0;
}