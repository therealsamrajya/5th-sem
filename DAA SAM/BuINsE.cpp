#include<iostream>
using namespace std;

int countB = 0;
int countS = 0;
int countI = 0;

int bubbleSort(int A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        countB++;
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
    cout << "Output of bubble sort is:" << endl;
    for (i = 0; i < n; i++)
        cout << A[i] << endl;
    cout << "Time complexity of bubble sort is " << countB << endl;
}

int selectionSort(int A[], int n) {
    int i, j, minIndex, minValue;
    for (i = 0; i < n; i++) {
        minIndex = i;
        minValue = A[i];
        for (j = i + 1; j < n; j++) {
            countS++;
            if (A[j] < minValue) {
                minIndex = j;
                minValue = A[j];
            }
        }
        swap(A[i], A[minIndex]);
    }
    cout << "Output of selection sort is:" << endl;
    for (i = 0; i < n; i++)
        cout << A[i] << endl;
    cout << "Time complexity of selection sort is " << countS << endl;
}

int insertionSort(int B[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = B[i];
        j = i - 1;
        while (j >= 0 && B[j] > key) {
            B[j + 1] = B[j];
            j--;
            countI++; // Increment the comparison count here
        }
        B[j + 1] = key;
    }
    cout << "Output of insertion sort is:" << endl;
    for (i = 0; i < n; i++)
        cout << B[i] << endl;
    cout << "Time complexity of insertion sort is " << countI << endl;
}




int main() {
    int A[] = {1, 5, 3, 4, 6, 2, 9};
    int B[] = {1, 5, 3, 4, 6, 2, 9};
    int n=7;
//    int n = sizeof(A) / sizeof(A[0]);

    bubbleSort(A, n);
    selectionSort(A, n);
    insertionSort(B, n);

    return 0;
}

