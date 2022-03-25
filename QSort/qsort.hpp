#ifndef _QSORT_HPP_
#define _QSORT_HPP_
#include <iostream>
#include <random>
#include <chrono>

template <typename type> class Sort
{
private:
    // to swap last element with a random one
    static int64_t randPivot(int64_t start, int64_t end)
    {
        // random seed provided by time in seconds
        int64_t seed{std::chrono::steady_clock::now().time_since_epoch().count()};
        // mersenne twister 64 bit random engine
        std::mt19937_64 generator_engine{static_cast<size_t>(seed)};
        // uniform distribution
        std::uniform_int_distribution<int64_t> dist{start, end};
        return dist(generator_engine);
    }

    // efficient swapping
    static void swap(type &first, type &second)
    {
        if (&first == &second)
            return;
        // debug code
        // std::cout << "first: " << first << " - " << "second: " << second << "\n";
        type temp{std::move(first)};
        first = std::move(second);
        second = std::move(temp);
    }

    static void sortByIndex(type *dataset, int64_t start, int64_t end)
    {
        if (start >= end)
            return;
        // swapping last element to not face with worst case
        Sort::swap(dataset[randPivot(start, end)], dataset[end]);
        // pivot index
        int64_t pivot{end};
        // debug code
        // std::cout << "pivot : " << dataset[pivot] << "\n";
        int64_t lesserThanCount{start};
        for (int64_t index{start}; index <= end; ++index)
        {
            if (dataset[index] < dataset[pivot])
            {
                Sort::swap(dataset[index], dataset[lesserThanCount]);
                ++lesserThanCount;
            }
        }

        Sort::swap(dataset[pivot], dataset[lesserThanCount]);
        Sort::sortByIndex(dataset, start, lesserThanCount - 1);
        Sort::sortByIndex(dataset, lesserThanCount + 1, end);
    }

public:
    // data, start index, data size
    static void quicksort(type *dataset, int64_t start, int64_t size, bool useIterator = false)
    {
        Sort::sortByIndex(dataset, start, size - 1);
    }
};

#endif