#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;

/*The problem states that,given an array with n elements replace the max elements with floor of square root.

The problem can be solved by finding the max element and its index and replacing it with square root of that element.- O(n*k)

Alternate approach:
1. Build a max heap - O(n)
2. Replace the max element with square root - O(log n) for each iteration for k times.

therefore, O(k*logn)

*/


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Convert the vector into a max-heap
        make_heap(gifts.begin(), gifts.end());

        //Perform the gift picking operation 'k' times
        for (int i = 0; i < k; i++) {
            // Extract the maximum element
            pop_heap(gifts.begin(), gifts.end());
            int x = gifts.back();

            // Stop if the maximum element becomes 1
            if (x <= 1) break;

            // Replace the largest gift with its square root and reheapify
            gifts.back() = sqrt(x);
            push_heap(gifts.begin(), gifts.end());
        }

        // Step 3: Return the sum of all elements in the heap
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
