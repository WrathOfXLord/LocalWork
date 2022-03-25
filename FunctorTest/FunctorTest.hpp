#ifndef __FUNCTORTEST_HPP__
#define __FUNCTORTEST_HPP__

//forward declaration is not allowed, causes compile error
template <typename num> class MultiplyBy {
private:
    num val;
public:
    MultiplyBy(num val) : val {val} {}
    
    template <typename numtype> 
    auto operator ()(const numtype val) const { return this->val * val; }     //auto here, decides which type will be returned according to the types
};

// template<typename num> template <typename numtype>
// auto MultiplyBy<num>::operator () (const numtype val) const { return this->val * val; } 

#endif