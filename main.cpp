#include <iostream>
#include <algorithm>
#include <chrono>
#include "sorting.h"
#include "testing.h"
using namespace std;
using namespace std::chrono;

// prlong function
void print(long v[], long n) {
    for (long i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

void timeTest(long* arr, long n) {
    clock_t start, end;
    long* testing = copyArray(arr, n);

    /// Default sort
    start = clock();
    sort(testing, testing + n);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Default Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";

    /// Radix Sort test
    testing = copyArray(arr, n);
    start = clock();
    radixSort(testing, n);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Radix Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";

    /// Merge Sort test
    testing = copyArray(arr, n);
    start = clock();
    mergeSort(testing, 0, n-1);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Merge Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";

    /// Shell Sort test
    testing = copyArray(arr, n);
    start = clock();
    shellSort(testing, n);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Shell Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";

    /// Heap Sort test
    testing = copyArray(arr, n);
    start = clock();
    heapSort(testing, n);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Heap Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";

    /// Quick Sort test
    testing = copyArray(arr, n);
    start = clock();
    quickSort(testing, 0, n-1);
    end = clock();

    // Check if the test is correct and show results
    if (rightSort(testing, n))
        printf("Quick Sort Time: %.5f\n",1.0*(end-start)/CLOCKS_PER_SEC);
    else
        cout << "TEST FAILED\n";
}

void arrayTest(long n, long vmax) {
    // Generate a random vector
    long* arr = generateRandomArray(n, vmax);
    cout << "\nVector random cu valoare maxima " << vmax << "\n";
    timeTest(arr, n);

    // Generate a vector sortes
    arr = generateReverseSortArray(n, n);
    cout << "\nVector sortat descrescator\n";
    timeTest(arr, n);
}

int main()
{
    int nr_teste;
    long n, val_max;

    cout << "Numarul de teste = ";
    cin >> nr_teste;

    for (int i = 0; i < nr_teste; ++i) {
        cout << "\nTestul " << i+1 << "\n";
        cout << "N = ";
        cin >> n;

        cout << "MAX = ";
        cin >> val_max;

        arrayTest(n, val_max);
    }

    return 0;
}
