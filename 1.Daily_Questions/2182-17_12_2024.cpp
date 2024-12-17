#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

/* The question states that we have a string and we must construct a new string such that, 
1. The occurence of all the letters in new string should not exceed the old string.
2. No string must repeat more than maxLimit times.
3.the new string must be lexiographcally largest among all the strings possible by rule 1 and 2.

APPROACH:
->Start by counting the occurence of all the character in the orriginal string.
->Build a max heap with ascii of each letter and their frequency.
->start my appending the max value char reapeatLimit number of times. when the limit is reached, move to the next char which is in the heap. 
->then again check the previous string, if the count of the previous, string if itts count is greater, again repeat the step 4.
*/


class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // Max-heap to store characters based on their ASCII value
        priority_queue<pair<char, int>> maxHeap;
        for (auto& [ch, cnt] : freq) {
            maxHeap.push({ch, cnt});
        }

        string result;
        while (!maxHeap.empty()) {
            auto [ch1, cnt1] = maxHeap.top();
            maxHeap.pop();

            int use = min(cnt1, limit);  // Use up to the limit of the current character
            result.append(use, ch1);
            cnt1 -= use;

            if (cnt1 > 0) {
                if (maxHeap.empty()) {
                    break;  // No other characters to use, stop here
                }

                auto [ch2, cnt2] = maxHeap.top();
                maxHeap.pop();

                result.push_back(ch2);  // Use one instance of the next character
                cnt2--;

                // Push back the characters with remaining counts
                maxHeap.push({ch1, cnt1});
                if (cnt2 > 0) {
                    maxHeap.push({ch2, cnt2});
                }
            }
        }

        return result;
    }
};
