#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = rand();

    auto start = chrono::high_resolution_clock::now();
    selectionSort(arr, N);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Selection Sort completed in " << duration.count() << " ms\n";

    return 0;
}
