#include <iostream>
#include <queue>
#include <vector>
#include <set>

/*BRUTE FORCE:
    -> Iterate over all the elements, find the index of minimum value,and mark it and its adjacent elements as visited. Continue until all the elements are
    marked visited.
    ->Time complexity-O(n^2)

USING PRIORITY QUEUE:
    ->create a min heap with the vector nums.if the elements are equal, make the index next priority.
    ->pop the elements from the heap and if in visited set continue, else, add it to visited and check fo its adjacent elements. If not in visited add them to visited
    ->Time complexity-O(nlogn)->while loop runs for n timees till the nums i empty and each time heap is altered,which takes logn time to heapify.
*/


class Solution {
public:
    long long findScore(vector<int>& nums) {
        //bbuild a min heap, first priority isthe element and second is the index
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second; 
            return a.first > b.first;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
        std::set<int> visited;// set to keep track of marked indices

        long long score = 0;
        for (int i = 0; i < nums.size(); ++i){
            minHeap.push({nums[i], i});// build the heap
        }
        
        while(!minHeap.empty()){
            auto [value,index] = minHeap.top(); // get the top element and pop the root.
            minHeap.pop();

            if(visited.count(index)){
                continue;
            }
            visited.insert(index);
            //add its adjacent elements to the visited set
            if(index>0) visited.insert(index - 1);
            if(index<nums.size() - 1) visited.insert(index+1);
            score = score + value;
        }
        return score;
    }
};