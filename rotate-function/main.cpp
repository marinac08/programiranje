#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long total_sum = 0;
        long long current_f = 0;

        for (int i = 0; i < n; ++i) {
            total_sum += nums[i];
            current_f += (long long)i * nums[i];
        }

        long long max_f = current_f;
        for (int k = 1; k < n; ++k) {
            current_f = current_f + total_sum - (n * nums[n - k]);
            max_f = std::max(max_f, current_f);
        }

        return static_cast<int>(max_f);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 6};
    cout << "Maximum Rotate Function Value: " << solution.maxRotateFunction(nums) << endl;
    return 0;
}
