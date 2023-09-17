#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to swap two elements in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array using a random pivot
int partition(int arr[], int low, int high, int& counter) {
    // Choose a random pivot
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];

    // Move the pivot to the end
    swap(arr[pivotIndex], arr[high]);

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            counter++; // Increment the counter for each comparison
        }
    }

    swap(arr[i + 1], arr[high]);
    counter++; // Increment the counter for the final comparison
    return i + 1;
}

// Function to perform randomized quicksort
void quicksort(int arr[], int low, int high, int& counter) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, counter);
        quicksort(arr, low, pivotIndex - 1, counter);
        quicksort(arr, pivotIndex + 1, high, counter);
    }
}

int main() {
  
    srand(time(0));

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int counter = 0; 

    quicksort(arr, 0, n - 1, counter);

    std::cout << "Sorted array:";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << "\n";

    std::cout << "Number of comparisons: " << counter << "\n";

    return 0;
}

