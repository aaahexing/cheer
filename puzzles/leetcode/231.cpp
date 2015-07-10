//Given an integer, write a function to determine if it is a power of two. 

//violance solution
//trial times: two
//time complexity: O(k), k is binary digits of n
bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        bool res = true;
        while(n != 1)
        {
            if(n%2 != 0)
                res = false;
            n >>= 1;
        }
        
        return res;
}

//second solution
//time complexity: O(1)
bool isPowofTwo(int n){
	return n & (n-1) == 0 ? true : false;
}