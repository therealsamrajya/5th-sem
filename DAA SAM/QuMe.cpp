#include <iostream>

using namespace std;

// Initialize a counter to keep track of the number of comparisons for Quick Sort
int quickSortComparisonCounter = 0;

// Initialize a counter to keep track of the number of comparisons for Merge Sort
int mergeSortComparisonCounter = 0;

// Function to perform partition for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            quickSortComparisonCounter++; // Increment the comparison counter
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to merge two subarrays for Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
        mergeSortComparisonCounter++; // Increment the comparison counter
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int quickSortArr[arrSize];
    int mergeSortArr[arrSize];

    // Copy the original array for sorting
    for (int i = 0; i < arrSize; i++) {
        quickSortArr[i] = arr[i];
        mergeSortArr[i] = arr[i];
    }

    // Perform Quick Sort
    quickSort(quickSortArr, 0, arrSize - 1);
    cout << "Quick Sort Result: ";
    for (int i = 0; i < arrSize; i++) {
        cout << quickSortArr[i] << " ";
    }
    cout << "\nNumber of comparisons made in Quick Sort: " << quickSortComparisonCounter << endl;

    // Perform Merge Sort
    mergeSort(mergeSortArr, 0, arrSize - 1);
    cout << "Merge Sort Result: ";
    for (int i = 0; i < arrSize; i++) {
        cout << mergeSortArr[i] << " ";
    }
    cout << "\nNumber of comparisons made in Merge Sort: " << mergeSortComparisonCounter << endl;

    return 0;
}

