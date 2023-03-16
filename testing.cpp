#include "testing.h"
#include <random>

bool rightSort(long v[], long n) {
    for (long i = 0; i < n-1; ++i)
        if (v[i] > v[i+1])
            return false;

    return true;
}

long* copyArray(long v[], long n) {
    long* result = new long[n];

    for (long i = 0; i < n; ++i)
        result[i] = v[i];

    return result;
}

long* generateRandomArray(long n, long maxValue) {
    long* result = new long[n];

    for (long i = 0; i < n; ++i)
        result[i] = rand() % maxValue;

    return result;
}

long* generateReverseSortArray(long n, long maxValue) {
    long * result = new long[n];
    result[0] = maxValue;

    for (long i = 1; i < n; ++i)
        result[i] = result[i-1] - 1;

    return result;
}
