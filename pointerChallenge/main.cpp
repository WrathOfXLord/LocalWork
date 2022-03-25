#include <iostream>

using namespace std;

using uint64 = unsigned long long;

int *apply_all(const int arr1[], const uint64 size1, const int arr2[], const uint64 size2);
void printArr(const int arr[], const uint64 size);

int main()
{
    int arr1[] {1, 2, 3, 4, 5, 6, 7, 8};
    const uint64 size1 {sizeof(arr1) / sizeof(unsigned long)};
    int arr2[] {10, 20, 30, 40, 50};
    const uint64 size2 {sizeof(arr2) / sizeof(unsigned long)};

    cout << "----------------------------------------" << endl;
    cout << "Array 1 " << endl;
    printArr(arr1, size1);

    cout << "----------------------------------------" << endl;
    cout << "Array 2 " << endl;
    printArr(arr2, size2);

    int *productArr {apply_all(arr1, size1, arr2, size2)};
    cout << "----------------------------------------" << endl;
    uint64 productSize {size1 * size2};
    cout << "product size is : " << productSize << endl;
    printArr(productArr, productSize);

    delete [] productArr;
    productArr = nullptr;
    
}

int *apply_all(const int arr1[], const uint64 size1, const int arr2[], const uint64 size2)
{

    int *productArr {new int [size1 * size2]};
    
    // if(productArr == nullptr){
    //     cout << "Allocating memory failed, exiting the function.." << endl;
    //     return nullptr;
    // }

    uint64 indexProduct {};
    for(uint64 i {0}; i < size1; ++i){
        for(uint64 j {0}; j < size2; ++j){
            productArr[indexProduct] = arr1[i] * arr2[j];
            ++indexProduct;
        }
    }
    return productArr;
}

void printArr(const int arr[], const uint64 size)
{
    for(uint64 i {0}; i < size; ++i)
        cout << "element " << i << " is : " << arr[i] << endl;
}