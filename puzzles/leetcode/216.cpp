/******************
Contains Duplicate III : https://leetcode.com/problems/contains-duplicate-iii/

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
**/

//time compleixty: O(nlogk)
//space compleixity: O(k)
//NA: usage of set,,,be careful of overflow
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0) {
            return false;
        }
        
        set<long long> s;
        for (int i = 1; i <= k && i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        for (int i = 0; i < int(nums.size()) - 1; i++) {
			set<long long>::iterator itr = s.upper_bound(nums[i]);
			if (itr != s.end() && abs(*itr - (long long)nums[i]) <= t) {
				return true;
			}
			
			if (itr != s.begin()) {
    			itr--;
	    		if (abs(*itr - nums[i]) <= t) {
		    		return true;
		    	}
			}
            
            s.erase(nums[i+1]);
            if (i+1+k < nums.size()) {
                s.insert(nums[i+1+k]);
            }
        }
        
        return false;
    }