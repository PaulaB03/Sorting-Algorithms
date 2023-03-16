#include "sorting.h"

// Merge two subarrays
void merge(long v[], long p, long q, long r) {
    long n1 = q - p + 1;
    long n2 = r - q;

    int L[n1], R[n2];

    for (long i = 0; i < n1; ++i)
        L[i] = v[p + i];
    for (long j = 0; j < n2; ++j)
        R[j] = v[q + 1 + j];

    long i=0, j=0, k=p;

    // Merge the arrays
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            ++i;
        }
        else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Add the rest of the left array
    while (i < n1) {
        v[k] = L[i];
        ++i; ++k;
    }

    // Add the rest of the right array
    while (j < n2) {
        v[k] = R[j];
        ++j; ++k;
    }

}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(long v[], long l, long r) {
    if (l < r) {
        // m - where the array is divided into two subarrays
        long m = l + (r - l) / 2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        // Merge the sorted subarrays
        merge(v, l, m, r);
    }
}

/// Complexity
// Best O(n*log n)
// Worst O(n * log n)
// Average O(n*log n)
// Space Complexity O(n)
