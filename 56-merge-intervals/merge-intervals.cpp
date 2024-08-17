class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        // cout << "sorted arr: ";
        // for(auto it: intervals) {
        //     cout << "{" << it[0] << "," << it[1] << "}";
        // }
        // cout << endl;

        vector<vector<int>> ans;        
        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            // cout << "before start: " << start << " before end: " << end << endl;
            int j = i+1;
            for(; j < intervals.size(); j++) {
                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }
            i = j-1;
            // cout << "after start: " << start << " after end: " << end << endl;
            ans.push_back({start, end});
        }
        return ans;
    }
};