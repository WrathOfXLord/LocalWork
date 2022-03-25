#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include "XoshiroCpp.hpp"

using llint = long long;



template<typename Type>
void swap(Type &var1, Type &var2)
{
    if(var1 == var2)
        return;
    Type tmp {var1};
    var1 = var2;
    var2 = tmp;
}

template<typename Type>
llint pivotIndex(Type *dataset, llint start_index, llint end_index)
{
    Type *pivot {&dataset[end_index]};
    llint pivot_index {start_index}; //bu değişken pivottan küçük değer bulunduğunda kullanılır
    
    for(llint loopVar {start_index}; loopVar < end_index; ++loopVar) //no need to check pivot point
    {
        if(dataset[loopVar] < *pivot)
        {
            swap(dataset[pivot_index], dataset[loopVar]);
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

template<typename Type>
llint RpivotIndex(Type *dataset, llint start_index, llint end_index)
{
    Type *pivot {&dataset[end_index]};
    llint pivot_index {start_index}; //bu değişken pivottan küçük değer bulunduğunda kullanılır
    
    for(llint loopVar {start_index}; loopVar < end_index; ++loopVar) //no need to check pivot point
    {
        if(dataset[loopVar] > *pivot)
        {
            swap(dataset[pivot_index], dataset[loopVar]);
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

template<typename Type>
llint randPivotIndex(Type *dataset, llint start_index, llint end_index)
{
    llint seed {std::chrono::duration_cast<std::chrono::duration<llint>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()};
    XoshiroCpp::Xoshiro256PlusPlus rng {(static_cast<uint64_t>(seed))};
    std::uniform_int_distribution<llint> dist {start_index, end_index};
    llint random_index {dist(rng)};

    swap(dataset[random_index], dataset[end_index]);
    return pivotIndex(dataset, start_index, end_index);

}

template<typename Type>
llint RrandPivotIndex(Type *dataset, llint start_index, llint end_index)
{
    llint seed {std::chrono::duration_cast<std::chrono::duration<llint>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()};
    XoshiroCpp::Xoshiro256PlusPlus rng {static_cast<uint64_t>(seed)};
    std::uniform_int_distribution<llint> dist {start_index, end_index};
    llint random_index {dist(rng)};

    swap(dataset[random_index], dataset[end_index]);
    return RpivotIndex(dataset, start_index, end_index);

}

//(array, start_index, end_index)
template<typename Type> void QSort(Type *dataset, llint start_index, llint end_index)
{
     if(start_index < end_index)
     {
        llint pivot {randPivotIndex(dataset, start_index, end_index)};
        QSort(dataset, start_index, pivot - 1);     //excluding the pivot point because it's already placed.
        QSort(dataset, pivot + 1, end_index);
     }
}

//(array, start_index, end_index)
template<typename Type> void RQSort(Type *dataset, llint start_index, llint end_index)
{
    if(start_index < end_index)
     {
        llint pivot {RrandPivotIndex(dataset, start_index, end_index)};
        RQSort(dataset, start_index, pivot - 1);    //excluding the pivot point because it's already placed.
        RQSort(dataset, pivot + 1, end_index);
     }    
}

