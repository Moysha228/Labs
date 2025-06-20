#ifndef Functions
#define Functions
#include <fstream>
bool CheckInputFile(std::ifstream&);
bool CheckOutputFile(std::ofstream&);
void OutputArrayToConsole(double*, size_t);
void FillArrayFromConsole(double*, size_t);
void OutputArrayToFile(std::ostream&, double*, size_t);
void Sort(double*, size_t, void (*Sorts[4])(double*, size_t, bool));
int Compare(const void*, const void*);
void QuickSort(double*, size_t, bool);
void Swap(double&, double&);
void InsertionSort(double*, size_t, bool);
void SelectionSort(double*, size_t, bool);
void ImprovedBubbleSort(double*, size_t, bool);
#endif