/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> m;
        for(auto& it:intervals)
        {
            m[it.start]++;
            m[it.end]--;
        }
        int maxi=0,curr=0;
        for(auto& [time,cnt]:m)
        {
            curr+=cnt;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};
