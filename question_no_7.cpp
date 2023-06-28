class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> missingRanges;
    
    // Helper function to add a range to the result vector
    auto addRange = [&](long long start, long long end) {
        if (start == end)
            missingRanges.push_back(to_string(start));
        else
            missingRanges.push_back(to_string(start) + "->" + to_string(end));
    };
    
    // Handle the lower bound
    if (lower < nums[0]) {
        addRange(lower, nums[0] - 1);
    }
    
    // Handle the middle part
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1] + 1) {
            addRange(nums[i - 1] + 1, nums[i] - 1);
        }
    }
    
    // Handle the upper bound
    if (nums[n - 1] < upper) {
        addRange(nums[n - 1] + 1, upper);
    }
    
    return missingRanges;
}
};
