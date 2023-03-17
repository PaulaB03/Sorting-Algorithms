#include "sorting.h"

// Function to swap two elements
void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

// Function to return the median of three
long medianOfThree(long v[], long low, long high) {
    long mid = (low + high) / 2;

    // Sort the left, middle and right elemens
    if (v[mid] < v[low])
        swap(&v[low], &v[mid]);

    if (v[high] < v[low])
        swap(&v[low], &v[high]);

    if (v[high] < v[mid])
        swap(&v[mid], &v[high]);

    // Swap the middle and previous to last element
    swap(&v[mid], &v[high-1]);
    return v[high-1];
}

// Use a simple sort to sort the last 3 elements
void insertionSort(long v[], long low, long high) {
    for (long i = low + 1; i <= high; i++) {
        long key = v[i];
        long j = i - 1;
        while (j >= low && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

// Sort the partition
long partition(long v[], long low, long high, long pivot) {
    long left = low, right = high-1;

    while (left <= right) {
        while (v[left] < pivot)
            left++;

        while (v[right] > pivot)
            right--;

        if (left <= right)
            swap(&v[left++], &v[right--]);
    }

    return left;
}

void quickSort(long v[], long low, long high) {
    long size = high - low + 1;

    if (size > 3) {
        long median = medianOfThree(v, low, high);
        long part = partition(v, low, high, median);
        quickSort(v, low, part-1);
        quickSort(v, part, high);
    }
    else
        insertionSort(v, low, high);
}
