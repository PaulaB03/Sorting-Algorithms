#include "sorting.h"

// Function to get the largest element from an array
int getMax(long v[], long n) {
    long max = v[0];

    for (long i = 1; i < n; ++i)
        if (v[i] > max)
            max = v[i];

    return max;
}

void countingSort(long v[], long n, long place) {
    const long max= 10;
    long output[n];
    long count[max] = {0};

    // Calculate count of elements
    for (long i = 0; i < n; ++i)
        ++count[(v[i] / place) % 10];

    // Calculate cumulative count_vector
    for (long i = 1; i < max; ++i)
        count[i] += count[i-1];

    // Place the elements in sorted order
    for (long i = n- 1; i >= 0; --i) {
        output[count[(v[i] / place) % 10] - 1] = v[i];
        --count[(v[i] / place) % 10];
    }

    for (long i = 0; i < n; ++i)
        v[i] = output[i];
}

void radixSort(long v[], long n) {
    // Get maximum element
    long max = getMax(v, n);

    // Apply counting sort to sort elements based on place value
    for (long place = 1; max / place > 0; place *= 10)
        countingSort(v, n, place);
}

/// Complexity
// Best O(n + k)
// Worst O(n + k)
// Average O(n + k)
// Space Complexity O(max)
