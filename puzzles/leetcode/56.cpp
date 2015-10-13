/*********************************
Merge Intervals : https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.
For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18]. 
**/

//---------------------------solution 1---------------------------
//@TLE
//@time complexity: O(nlogn)
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        for (vector<Interval>::iterator itr = intervals.begin(); itr < intervals.end() - 1; ) {
            vector<Interval>::iterator itr1 = itr + 1;
            if (isInterlace(*itr, *itr1)) {
                itr->start = itr->start < itr1->start ? itr->start : itr1->start;
                itr->end = itr->end > itr1->end ? itr->end : itr1->end;
                intervals.erase(itr1);
            } else {
                itr++;
            }
        }
        
        return intervals;
    }
    
    bool isInterlace(Interval a, Interval b) {
        if (a.end < b.start || b.end < a.start) {
            return false;
        } else {
            return true;
        }
    }
};