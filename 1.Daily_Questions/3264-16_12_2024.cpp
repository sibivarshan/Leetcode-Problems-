class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
        }
        while(k>0){
            auto [val,idx] = minHeap.top();
            minHeap.pop();
            long new_val = (long)val*multiplier;
            nums[idx] = new_val;
            minHeap.push({new_val,idx});
            k--;
        }
        return nums;
    }
};