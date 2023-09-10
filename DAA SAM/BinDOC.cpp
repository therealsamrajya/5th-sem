#include <iostream>

using namespace std;

// Initialize a counter to keep track of the number of comparisons
int comparison_counter = 0;

// Function to perform binary search using divide and conquer
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the element is found, return its index
        if (arr[mid] == target) {
            comparison_counter++;
            return mid;
        }

        // If the target is less than the middle element, search the left subarray
        if (arr[mid] > target) {
            comparison_counter++;
            return binarySearch(arr, left, mid - 1, target);
        }

        // If the target is greater than the middle element, search the right subarray
        comparison_counter++;
        return binarySearch(arr, mid + 1, right, target);
    }

    // If the element is not in the array, return -1
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, arrSize - 1, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    cout << "Number of comparisons made: " << comparison_counter << endl;

    return 0;
}

