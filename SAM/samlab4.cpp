#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath> // Include the cmath header for the log function

using namespace std;

// Function to generate random exponential variate
double exponentialRandom(double lambda) {
    double u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) / lambda;
}

int main() {
    srand(time(0));

    int numCustomers = 1000; // Number of customers to simulate
    double lambda = 0.5;    // Arrival rate (customers per time unit)
    double mu = 1.0;        // Service rate (customers per time unitA)

    queue<double> arrivalTimes;
    double currentTime = 0.0;
    double totalWaitingTime = 0.0;
    double totalServiceTime = 0.0;

    for (int i = 0; i < numCustomers; ++i) {
        double interarrivalTime = exponentialRandom(lambda);
        double serviceTime = exponentialRandom(mu);

        // Update arrival time for the next customer
        if (i == 0) {
            arrivalTimes.push(interarrivalTime);
        } else {
            arrivalTimes.push(arrivalTimes.back() + interarrivalTime);
        }

        // Calculate waiting time and service time for this customer
        double waitTime = max(0.0, currentTime - arrivalTimes.front());
        totalWaitingTime += waitTime;
        totalServiceTime += serviceTime;

        // Update current time
        currentTime = max(currentTime, arrivalTimes.front()) + serviceTime;

        arrivalTimes.pop();
    }

    double averageWaitingTime = totalWaitingTime / numCustomers;
    double averageServiceTime = totalServiceTime / numCustomers;

    cout << "Average Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Service Time: " << averageServiceTime << endl;

    return 0;
}

