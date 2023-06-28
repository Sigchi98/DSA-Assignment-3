class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
    
    // Check for any overlapping intervals
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (intervals[i][1] > intervals[j][0] && intervals[i][0] < intervals[j][1]) {
                    return false; // Overlapping intervals found, person cannot attend all meetings
                }
            }
        }
    
    return true; // No overlapping intervals found, person can attend all meetings
}
};
