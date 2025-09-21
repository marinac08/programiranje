#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = rand();

    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, N);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Insertion Sort completed in " << duration.count() << " ms\n";

    return 0;
}