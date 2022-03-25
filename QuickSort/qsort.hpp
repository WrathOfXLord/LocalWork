#ifndef _QSORT_HPP_
#define _QSORT_HPP_
#include <iostream>

class Sort
{
private:
    // to swap last element with a random one
    static int64_t randPivot(int64_t start, int64_t end);

    // efficient swapping
    template <typename type>
    static void swap(type &first, type &second)
    {
        if (first == second)
            return;
        type temp {std::move(first)};
        first = std::move(second);
        second = std::move(temp);
    }

public:
    template <typename type>
    static void quicksort(type *dataset, int64_t start, int64_t end)
    {
        if (start >= end || end <= 0)
            return;
        // swapping last element to not face with worst case
        Sort::swap(dataset[randPivot(start, end)], dataset[end]);
        // pivot index
        int64_t pivot{end};
        // debug code
        std::cout << "pivot : " << dataset[pivot] << "\n";
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
        Sort::quicksort(dataset, start, lesserThanCount - 1);
        Sort::quicksort(dataset, lesserThanCount + 1, end);
    }
};

#endif