/*********************************
Merge Intervals : https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.
For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18]. 
**/

//---------------------------solution 1---------------------------
//@TLE
//@time complexity: O(n^2)
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

//-----------------------------------solution 2-------------------------------------
//@time compelxity: O(nlogn)
//@space complexity: O(1)
//@3A

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
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval>::iterator itr1 = intervals.begin();
        vector<Interval>::iterator itr2 = itr1 + 1;
        while (itr1 < intervals.end() && itr2 < intervals.end()) {
            if (isInterlace(*itr1, *itr2)) {
                itr1->start = itr1->start < itr2->start ? itr1->start : itr2->start;
                itr1->end = itr1->end > itr2->end ? itr1->end : itr2->end;
                itr2 = itr2 + 1;
            } else {
                ret.push_back(*itr1);
                itr1 = itr2;
                itr2 = itr1 + 1;
            }
        }
        
        if (itr1 < intervals.end()) {
            ret.push_back(*itr1);
        }
        
        return ret;
    }
    
    bool isInterlace(Interval a, Interval b) {
        if (a.end < b.start || b.end < a.start) {
            return false;
        } else {
            return true;
        }
    }
};