#include <iostream>
using namespace std;

int gcd(int a, int b, int &counter) {
    counter = 0;
    while (b != 0) {
        counter++; 
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
   cout << "Enter two numbers: ";
   cin >> a >> b;

    int counter;
    int result = gcd(a, b, counter);

   cout << "GCD of " << a << " and " << b << " is " << result;
   cout << "Number of iterations: " << counter;

    return 0;
}

