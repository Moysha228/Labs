void InputSize(int32_t&);
template <typename T>
void CreateArray(T*& array, int32_t size) {
    array = new T[size];
}
template <typename T>
void DeleteArray(T*& array) {
    delete[] array;
}
template <typename T>
T InputNum(T& num) {
    std::cin >> num;
    return num;
}
#include <cstdlib>
template <typename T>
void AutoFillArray(T* array, int32_t size) {
    srand(time(NULL));
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 100 - 50;
    }
}
template <typename T>
void ManualFillArray(T* array, int32_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cin >> array[i];
    }
}
template <typename T>
void PrintArray(T* array, int32_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << '\t';
    }
}
void Swap(int&, int&);
void Swap(double&, double&);
int32_t CountSignChanges(int32_t*, int32_t);
int32_t ProductOfNumbersBetweenZeros(int32_t*, int32_t);
void SortByParity(int32_t*, int32_t);
int32_t NumWitnMinSummDifference(double*, int32_t);
void FindModularlyMaxNum(double *, int32_t);
void ShrinkArray(double*, int32_t, double, double);
