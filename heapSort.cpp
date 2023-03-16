#include "sorting.h"
#include <iostream>
using namespace std;

void heapify(long v[], long n, long i) {
    // find the largest among root, left child, right child
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(long v[], long n) {
    // Build max head
    for (long i = n / 2 - 1; i >= 0; --i)
        heapify(v, n, i);

    // Heap sort
    for (long i = n-1; i >= 0; --i) {
        swap(v[0], v[i]);

        // Heapify root element to get highest element at root again
        heapify(v, i, 0);
    }
}

/// Complexity
// Best O(n*log n)
// Worst O(n * log n)
// Average O(n*log n)
// Space Complexity O(1)
