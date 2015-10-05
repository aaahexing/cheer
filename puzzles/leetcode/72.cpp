/***************************
Edit Distance: https://leetcode.com/problems/edit-distance/

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
**/

//@time complexity: O(m*n)
//@space complexity: O(m*n)
int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
        
    vector<vector<int> > step(len1 + 1, vector<int>(len2 + 1));
    step[0][0] = 0;
    for (int i = 1; i <= len1; i++) {
        step[i][0] = i;
    }
    for (int j = 1; j <= len2; j++) {
        step[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            step[i][j] = (word1[i-1] == word2[j-1] ? step[i-1][j-1] : step[i-1][j-1] + 1);
            step[i][j] = min(step[i - 1][j] + 1, step[i][j]);
            step[i][j] = min(step[i][j - 1] + 1, step[i][j]);
        }
    }

    return step[len1][len2];
}
