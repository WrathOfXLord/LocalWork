#ifndef _SORT_HPP_
#define _SORT_HPP_

#include <utility>
#include <random>
#include <chrono>

#include "XoshiroCpp.hpp"

namespace Sort {
    namespace qs {

        template<typename Type>
        int pivotIndex(Type dataset[], int start_point, int end_point) {
            Type &pivot {dataset[end_point]};
            int pivot_index {start_point}; //bu değişken pivottan küçük değer bulunduğunda kullanılır
            
            for(int loopIndex {start_point}; loopIndex < end_point; ++loopIndex) {  //no need to check pivot point
                if(dataset[loopIndex] < pivot) {
                    std::swap(dataset[pivot_index], dataset[loopIndex]);
                    ++pivot_index;
                }
            }

            std::swap(pivot, dataset[pivot_index]);

            return pivot_index;
        }

        static uint64_t seed = std::chrono::steady_clock::now().time_since_epoch().count();
        static XoshiroCpp::Xoshiro256PlusPlus rng {seed};
        
        template<typename Type>
        int randPivotIndex(Type dataset[], int start_index, int end_index) {
            std::uniform_int_distribution<int> dist {start_index, end_index};
            int random_index {dist(rng)};

            std::swap(dataset[random_index], dataset[end_index]);
            return pivotIndex(dataset, start_index, end_index);
        }
    }

    template<typename Type>
    void quicksort(Type dataset[], int start_point, int end_point) {
        if(start_point < end_point) {
            int pivot {qs::randPivotIndex(dataset, start_point, end_point)};
            quicksort(dataset, start_point, pivot - 1);     //exclude pivot point, it's already been placed with pivotindex, if you include you will run into recursive loop
            quicksort(dataset, pivot + 1, end_point);
        }
    }
}

#endif