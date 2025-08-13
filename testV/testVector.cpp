#include <vector>
#include <iostream>

template <typename T>
void merge(std::vector<T> &array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArray(n1);
    std::vector<T> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T> &array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

template <typename T>
void printArray(const std::vector<T> &array)
{
    for (const auto &element : array)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> array = {12, 11, 13, 5, 6, 7};

    std::cout << "Unsorted array: ";
    printArray(array);

    mergeSort(array, 0, array.size() - 1);

    std::cout << "Sorted array: ";
    printArray(array);

    return 0;
}
