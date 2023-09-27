#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // Value-to-weight ratio

    Item(int w, int v) : weight(w), value(v), ratio(static_cast<double>(v) / w) {}
};

bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity, int& counter) {
    // Sort items by decreasing value-to-weight ratio
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (size_t i = 0; i < items.size(); i++) {
        const Item& item = items[i];
        counter++; // Increment the counter for each item considered

        if (currentWeight + item.weight <= capacity) {
            // Take the whole item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take a fraction of the item to fill the remaining capacity
            int remainingCapacity = capacity - currentWeight;
            totalValue += (item.ratio * remainingCapacity);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int counter = 0;
    double maxTotalValue = fractionalKnapsack(items, capacity, counter);

    cout << "Maximum total value in the knapsack: " << maxTotalValue << endl;
    cout << "Number of items considered: " << counter << endl;

    return 0;
}

