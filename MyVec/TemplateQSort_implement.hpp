#pragma once
#include <iostream>
#include <chrono>

//----------------------------------------------------------------------------------------
//
//	Xoshiro-cpp
//	Xoshiro PRNG wrapper library for C++17 / C++20
//
//	Copyright (C) 2020 Ryo Suzuki <reputeless@gmail.com>
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files(the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions :
//	
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//	
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//
//----------------------------------------------------------------------------------------
#include "XoshiroCpp.hpp"

#include "MyTemplateVec.hpp"
#include "MyTemplateVec.hpp"
#include <random>

using int64 = long long;

template<typename Type> void swap_elements(Type &var1, Type &var2);

template<typename Type> int64 randPivotIndex(MyTemplateVec<Type> &dataset, int64 start_index, int64 end_index);
template<typename Type> int64 pivotIndex(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point);
template<typename Type> void QSort(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point);

template<typename Type> int64 RrandPivotIndex(MyTemplateVec<Type> &dataset, int64 start_index, int64 end_index);
template<typename Type> int64 RpivotIndex(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point);
template<typename Type> void RQSort(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point);


template<typename Type>
inline void swap_elements(Type &var1, Type &var2)
{
    if(var1 == var2)
        return;
    Type tmp {std::move(var1)};
    var1 = std::move(var2);
    var2 = std::move(tmp);
}

//In order
// give ending index no the size
template<typename Type>
void QSort(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point)
{
     if(start_point < end_point)
     {
        int64 pivot {randPivotIndex(dataset, start_point, end_point)};
        QSort(dataset, start_point, pivot - 1);     //exclude pivot point, it's been already placed with pivotindex, if you include you will run into recursive loop
        QSort(dataset, pivot + 1, end_point);
     }
}

template<typename Type>
int64 randPivotIndex(MyTemplateVec<Type> &dataset, int64 start_index, int64 end_index)
{
    uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();  //pseudo seed, faster    //brace initialization gives a warning about narrow from int to uint
    // std::random_device seed;    //true seed, slower
    
    XoshiroCpp::Xoshiro256PlusPlus rng {seed};
    std::uniform_int_distribution<int64> dist {start_index, end_index};
    int64 random_index {dist(rng)};

    swap_elements(dataset[random_index], dataset[end_index]);
    return pivotIndex(dataset, start_index, end_index);

}

template<typename Type>
int64 pivotIndex(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point)
{
    Type *pivot {&dataset[end_point]};
    int64 pivot_index {start_point}; //bu değişken pivottan küçük değer bulunduğunda kullanılır
    
    for(int64 loopVar {start_point}; loopVar < end_point; ++loopVar) //no need to check pivot point
    {
        if(dataset[loopVar] < *pivot)
        {
            swap_elements(dataset[pivot_index], dataset[loopVar]);
            ++pivot_index;
        }
    }

    if(*pivot != dataset[pivot_index]){
        Type tmp {*pivot};
        *pivot = dataset[pivot_index]; 
        dataset[pivot_index] = tmp;
    }
    return pivot_index;
}


//Reverse Order
template<typename Type>
void RQSort(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point)
{
    if(start_point < end_point)
     {
        int64 pivot {RrandPivotIndex(dataset, start_point, end_point)};
        RQSort(dataset, start_point, pivot - 1);    //exclude pivot point, it's been already placed with pivotindex, if you include you will run into recursive loop
        RQSort(dataset, pivot + 1, end_point);
     }    
}

template<typename Type>
int64 RrandPivotIndex(MyTemplateVec<Type> &dataset, int64 start_index, int64 end_index)
{
    uint64_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // std::random_device seed;
    XoshiroCpp::Xoshiro256PlusPlus rng {seed};
    std::uniform_int_distribution<int64> dist {start_index, end_index};
    int64 random_index {dist(rng)};

    swap_elements(dataset[random_index], dataset[end_index]);
    return RpivotIndex(dataset, start_index, end_index);

}

template<typename Type>
int64 RpivotIndex(MyTemplateVec<Type> &dataset, int64 start_point, int64 end_point)
{
    Type *pivot {&dataset[end_point]};
    int64 pivot_index {start_point}; //bu değişken pivottan küçük değer bulunduğunda kullanılır
    
    for(int64 loopVar {start_point}; loopVar < end_point; ++loopVar) //no need to check pivot point
    {
        if(dataset[loopVar] > *pivot)
        {
            swap_elements(dataset[pivot_index], dataset[loopVar]);
            ++pivot_index;
        }
    }

    if(*pivot != dataset[pivot_index]){
        Type tmp {*pivot};
        *pivot = dataset[pivot_index]; 
        dataset[pivot_index] = tmp;
    }

    return pivot_index;
}