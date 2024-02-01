#ifndef __SEARCH_HPP_
#define __SEARCH_HPP_

namespace Search {
    template <typename T>
    int binSearch(const T &value, T values[], int start, int end) {
        if(start > end || start < 0)
            return -1;

        int mid {};
        do {
            mid = (start + end) / 2;
            if(values[mid] == value)
                return mid;
            else if(values[mid] > value) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } while(start <= end);
        return -1;
    }

    template <typename T>
    int binSearchBySize(const T &value, T values[], int size) {
        return binSearch(value, values, 0, size - 1);
    }
}

#endif
