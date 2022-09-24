class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int new_start = newInterval[0], new_end = newInterval[1];

        //case 1: old intervals empty
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }

        int old_start = intervals[0][0];
        int old_end = intervals[intervals.size() - 1][1];
        int x  = 0, k = 0, n = intervals.size();

        //case 2: new intervals is on left and doesn't intersect
        if(new_end < old_start) {
            ans.push_back(newInterval);
            ans.insert(ans.end(), intervals.begin(), intervals.end());
            return ans;
        }

        //case 3: new intervals is on right and doesn't intersect
        else if(new_start > old_end) {
            intervals.push_back(newInterval);
            return intervals;
        }

        //case 4: new interval start engulfs all old intervals
        else if(new_start <= old_start && new_end >= old_end) {
            ans.push_back(newInterval);
            return ans;
        }

        //case 5: partial overlap or no overlap
        for(int i = 0; i < n; i++) {
            int cur_left = intervals[i][0];
            int cur_right = intervals[i][1];

            //case 5.1: current interval is exact as new intervals or engulfs it
            if(new_start >= cur_left && new_end <= cur_right) {
                return intervals;
            }

            //case 5.2: current interval is in middle of two intervals
            if(i + 1 < n) {
                if(new_start > cur_right && new_end < intervals[i+1][0]) {
                    ans.push_back(intervals[i]);
                    ans.push_back(newInterval);
                    ans.insert(ans.end(), intervals.begin()+i+1, intervals.end());
                    return ans;
                }
            
            }

            //case 5.3: overlap
            if(max(new_start, cur_left) <=  min(new_end, cur_right)) {
                /***
                 * if overlaps then new start of this overap will be minimum of 
                 * new_start and cur_left and then will traverse the next overlaps 
                 * to find >= of new_end
                 ***/
                int temp_start = min(cur_left, new_start);
                int temp_end = max(cur_right, new_end);
                while(i + 1 < n) {
                    /***
                     * now we have to check again if the current one overlaps
                     * if not we can get the current temp_end else we need to calculate 
                     * new temp_end
                     ***/
                    int temp_left = intervals[i+1][0], temp_right = intervals[i+1][1];
                    if(max(new_start, temp_left) <=  min(new_end, temp_right)) {
                        temp_end = max(temp_end, temp_right);
                        i++;
                        continue;
                    }
                    else {
                        break;
                    }
                }
                ans.push_back({temp_start, temp_end});
                if(i + 1 < n) {
                    ans.insert(ans.end(), intervals.begin()+i+1, intervals.end());
                }
                return ans;

            } 
            //case 5.4: no overlap
            else {
                ans.push_back(intervals[i]);
            }
            
        } 
        return ans;
    }
};