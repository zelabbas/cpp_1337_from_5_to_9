#include <iostream>
#include <vector>
#include <algorithm>

// Binary search to find the correct insertion position
int binarySearch(std::vector<int>& S, int low, int high, int key) {
    if (high <= low)
        return (key > S[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (key == S[mid])
        return mid + 1;

    if (key > S[mid])
        return binarySearch(S, mid + 1, high, key);

    return binarySearch(S, low, mid - 1, key);
}

// Recursive sort of the larger elements
void fordJohnsonSort(std::vector<int>& X) {
    int n = X.size();

    // Base case for recursion
    if (n <= 1)
        return;

    // Step 1: Group elements into pairs
    std::vector<int> S, remaining;

    for (int i = 0; i < n / 2; ++i) {
        int larger = std::max(X[2 * i], X[2 * i + 1]);
        int smaller = std::min(X[2 * i], X[2 * i + 1]);
        S.push_back(larger);
        remaining.push_back(smaller);
    }

    if (n % 2 == 1) {
        remaining.push_back(X[n - 1]);
    }

    // Step 2: Recursively sort the larger elements
    fordJohnsonSort(S);

    // Step 3: Insert the first remaining element
    int first_remaining = remaining[0];
    int pos = binarySearch(S, 0, S.size() - 1, first_remaining);
    S.insert(S.begin() + pos, first_remaining);

    // Step 4: Insert the remaining elements
    for (int i = 1; i < remaining.size(); ++i) {
        int pos = binarySearch(S, 0, S.size() - 1, remaining[i]);
        S.insert(S.begin() + pos, remaining[i]);
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; ++i) {
        X[i] = S[i];
    }
}

int main() {
    std::vector<int> X = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    std::cout << "Original array:\n";
    for (int x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    fordJohnsonSort(X);

    std::cout << "Sorted array:\n";
    for (int x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
