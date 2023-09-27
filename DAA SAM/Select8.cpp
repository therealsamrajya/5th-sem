#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to partition the array and return the pivot element's final position
int partition(int arr[], int left, int right, int& counter) {
    int pivot = arr[right]; // Choose the rightmost element as the pivot
    int i = left - 1; // Initialize the index of the smaller element

    for (int j = left; j < right; j++) {
        counter++; // Increment the comparison counter
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// QuickSelect algorithm to find the k-th smallest element
int quickSelect(int arr[], int left, int right, int k, int& counter) {
    if (left == right) // Base case: If the array has only one element
        return arr[left];

    // Partition the array and get the pivot position
    int pivotIndex = partition(arr, left, right, counter);

    // Calculate the position of the pivot element in the sorted array
    int pivotPosition = pivotIndex - left + 1;

    // Recurse on the appropriate subarray
    if (k == pivotPosition)
        return arr[pivotIndex];
    else if (k < pivotPosition)
        return quickSelect(arr, left, pivotIndex - 1, k, counter);
    else
        return quickSelect(arr, pivotIndex + 1, right, k - pivotPosition, counter);
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k (1-based index): ";
    cin >> k;

    int counter = 0;
    int kthSmallest = quickSelect(arr, 0, n - 1, k, counter);

    cout << "The " << k << "-th smallest element is: " << kthSmallest << endl;
    cout << "Number of comparisons made: " << counter << endl;

    return 0;
}

