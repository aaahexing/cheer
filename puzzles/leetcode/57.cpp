/***************************************
Insert Interval : https://leetcode.com/problems/insert-interval/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 
Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16]. 
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
**/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//@time complexity: O(n)
//@space complexity: O(1)
//@2A, failed the first time as line 33-37 was not considered....
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() <= 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (newInterval.start <= intervals[0].start && newInterval.end >= intervals[intervals.size()-1].end) {
            intervals.clear();
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<Interval>::iterator itr = insertInterval(intervals, newInterval);
        merge(intervals, itr); //merge from index
        return intervals;
    }
    
    vector<Interval>::iterator insertInterval(vector<Interval>& intervals, Interval newInterval) {
        for (vector<Interval>::iterator itr = intervals.begin(); itr != intervals.end(); itr++) {
            if (newInterval.end < itr->start) {    //insert the newInterval in this position
                itr = intervals.insert(itr, newInterval);
                return itr;
            } else if (isInterlace(*itr, newInterval)) {
                *itr = mergeInterval(*itr, newInterval);
                return itr;
            }
        }
        
        intervals.insert(intervals.end(), newInterval);
        return intervals.end() - 1;
    }
    
    bool isInterlace(Interval a, Interval b) {
        if (a.start > b.end || b.start > a.end) {
            return false;
        } else {
            return true;
        }
    }
    
    Interval mergeInterval(Interval a, Interval b) {
        Interval ret;
        ret.start = a.start < b.start ? a.start : b.start;
        ret.end = a.end > b.end ? a.end : b.end;
        
        return ret;
    }
    
    void merge(vector<Interval>& intervals, vector<Interval>::iterator itr) {
        for ( ;itr + 1 < intervals.end(); ) {
            vector<Interval>::iterator itr2 = itr + 1;
            if (isInterlace(*itr, *itr2)) {
                *itr = mergeInterval(*itr, *itr2);
                intervals.erase(itr2);
            } else {
                break;
            }
        }
    }
};