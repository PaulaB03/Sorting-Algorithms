#include "sorting.h"

void shellSort(long v[], long n) {
    for (long longerval = n / 2; longerval > 0; longerval /= 2)
        for (long i = longerval; i < n; i += 1){
            long temp = v[i];
            long j;

            for (j = i; j >= longerval && v[j - longerval] > temp; j -= longerval)
                v[j] = v[j - longerval];

        v[j] = temp;
    }
}

/// Complexity
// Best O(n*log n)
// Worst O(n^2)
// Average O(n*log n)
// Space Complexity O(1)
