#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    /**
     * Function: continuousSubarrays
     * ---------------------------------
     * Calculates the total number of continuous subarrays in the input vector `nums`
     * such that the difference between the maximum and minimum elements of each 
     * subarray is at most 2.
     *
     * Approach:
     * - Utilizes a sliding window technique with two deques (`maxDeque` and `minDeque`)
     *   to efficiently track the maximum and minimum values in the current window.
     * - Expands the window by moving the `right` pointer and adjusts the `left` pointer 
     *   whenever the condition (max - min <= 2) is violated.
     * - Counts the number of valid subarrays ending at each position `right` by 
     *   calculating the size of the valid window (right - left + 1).
     *
     * Complexity:
     * - Time: O(n), as each element is added and removed from the deques at most once.
     * - Space: O(n), for the deques used to track maximum and minimum indices.
     */
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        deque<int> maxDeque, minDeque;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == left) maxDeque.pop_front();
                if (minDeque.front() == left) minDeque.pop_front();
                ++left;
            }

            total += (right - left + 1);
        }

        return total;
    }
};
