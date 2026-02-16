#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int left;
    int right;
    int sum;
};

// Find maximum crossing subarray
Result maxCrossingSubarray(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    int maxLeft = mid;

    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    int maxRight = mid + 1;

    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}

// Divide and Conquer function
Result maxSubarray(int arr[], int left, int right) {
    if (left == right) {
        return {left, right, arr[left]};
    }

    int mid = (left + right) / 2;

    Result leftResult = maxSubarray(arr, left, mid);
    Result rightResult = maxSubarray(arr, mid + 1, right);
    Result crossResult = maxCrossingSubarray(arr, left, mid, right);

    if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossResult.sum)
        return leftResult;
    else if (rightResult.sum >= leftResult.sum && rightResult.sum >= crossResult.sum)
        return rightResult;
    else
        return crossResult;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Result result = maxSubarray(arr, 0, n - 1);

    cout << "\nMaximum subarray sum: " << result.sum << endl;
    cout << "From index " << result.left << " to " << result.right << endl;

    cout << "Subarray elements: ";
    for (int i = result.left; i <= result.right; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
