#include <iostream>
using  namespace std;

int fibonacci(int n, int &counter) {
    counter++;
    if (n <= 1) {
        return n;
    }
    else
    {
    return fibonacci(n - 1, counter) + fibonacci(n - 2, counter);
	}
	}


void displayFibonacciSeries(int n, int &counter) {
    for (int i = 0; i < n; ++i) {
        cout << fibonacci(i, counter) << " ";
    }
    cout << endl;
}

int main() {
    int n;
   cout << "Enter the value of n: ";
   cin >> n;

    int counter = 0; 
    cout << "Fibonacci Series up to " << n << " terms: ";
    displayFibonacciSeries(n, counter);

    cout << "Total number of function calls: " << counter;

    return 0;
}

