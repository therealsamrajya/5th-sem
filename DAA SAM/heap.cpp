#include <iostream>

// Function to heapify a subtree rooted with the given node
void heapify(int arr[], int n, int i, int& counter) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest element is not the root
    if (largest != i) {
        std::swap(arr[i], arr[largest]); // Swap root and largest element
        counter++; // Increment the counter for each comparison
        heapify(arr, n, largest, counter); // Recursively heapify the affected sub-tree
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n, int& counter) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, counter);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]); // Move the current root to the end
        counter++; // Increment the counter for each swap
        heapify(arr, i, 0, counter); // Call heapify on the reduced heap
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int counter = 0; // Initialize the counter

    heapSort(arr, n, counter);

    std::cout << "Sorted array:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n";

    std::cout << "Number of comparisons: " << counter << "\n";

    return 0;
}

