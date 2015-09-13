/**************************************************
Repeated DNA Sequences: https://leetcode.com/problems/repeated-dna-sequences/

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].
**/

//---------------------------first solution-----------------------------------
//use hash idea
//time complexity: O(n)
//space compleixty: O(n * 10 * sizeof(char))
//memory limit exceeded
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, bool> m;
		vector<string> ret;
		const int length = 10;
		for (int i = 0; i <= (int)s.size() - length; i++) {
			string strSub = s.substr(i, length);
			unordered_map<string, bool>::iterator itr = m.find(strSub); 
			if (itr != m.end()) {
				if (itr->second == false) {
					ret.push_back(strSub);
					itr->second = true;
				} 
			} else {
				m[strSub] = false;
			}
		}
		return ret;
	}
};

//-----------------------------------second solution------------------------------------
//trie tree idea
//time complexity: O(10*n)
//space complexity: 8M
//memory limit exceeded
class trieNode {
public:
	bool isFull;
	bool beenSearched;
	trieNode * child[4];
	trieNode() {
		isFull = false;
		beenSearched = false;
		child[0] = child[1] = child[2] = child[3] = NULL; //0 saves 'A', 1 saves 'C', 2 saves 'G', 3 saves 'T'
	}
};

class Solution {
public:
	Solution() {
		root = new trieNode();
	}

	void addSequence(string s) {
		trieNode * curNode = root;
		int size = s.size();
		int pos;
		for (int i = 0; i < s.size(); i++) {
			switch(s[i]) {
			case 'A':
				pos = 0;
				break;
			case 'C':
				pos = 1;
				break;
			case 'G':
				pos = 2;
				break;
			case 'T':
				pos = 3; 
				break;
			}
			if (curNode->child[pos] == NULL) {
				curNode->child[pos] = new trieNode();
			}
			curNode = curNode->child[pos];
		}
		curNode->isFull = true;
	}

	bool searchFirstSequence(string s) {
		trieNode * curNode = root;
		int pos;
		bool ret = false;

		for (int i = 0; i < s.size(); i ++) {
			switch(s[i]) {
			case 'A':
				pos = 0;
				break;
			case 'C':
				pos = 1;
				break;
			case 'G':
				pos = 2;
				break;
			case 'T':
				pos = 3;
				break;
			}
			if (curNode->child[pos] == NULL) {
				return false;
			} else {
				curNode = curNode->child[pos];
			}
		}
		if (curNode->isFull && !curNode->beenSearched) {
			ret = true;
			curNode->beenSearched = true;
		}
		return ret;
	}

	vector<string> findRepeatedDnaSequences(string s) {
		const int length = 10;
		vector<string> ret;
		if (s.size() < 10) {
			return ret;
		}

		string subStr = s.substr(0, length);
		addSequence(subStr);
		for (int i = 1; i <= (int)s.size() - length; i++) {
			subStr = s.substr(i, length);
			if (searchFirstSequence(subStr)) {
				ret.push_back(subStr);
			} else {
				addSequence(subStr);
			}
		}
		return ret;
	}
private:
	trieNode * root;
};

//-----------------------------------------third solution----------------------------
//time complexity: O(n)
//space complexity: O(n * sizeof(int));
class Solution {
private:
    static const int length = 10;
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> ret;
        for (int i = 0; i <= (int)s.size() - length; i++) {
            string strSub = s.substr(i, length);
            int num = strToNum(strSub);
            if(m.find(num) != m.end()) {
                m[num]++;
            } else {
                m[num] = 1;
            }
        }
        
        for (unordered_map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if (itr->second > 1) {
                ret.push_back(numToStr(itr->first));
            }
        }
        return ret;
    }
    
    int strToNum(string s) {
        int ret = 0;
        for (int i = 0; i < Solution::length; i++) {
            int c;
            switch(s[i]) {
                case 'A': 
                    c = 0;
                    break;
                case 'C':
                    c = 1;
                    break;
                case 'G':
                    c = 2;
                    break;
                case 'T':
                    c = 3;
            }
            ret = (ret << 2) | c;
        }
        return ret;
    }
    
    string numToStr(int num) {
        string ret;
        char dic[] = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < Solution::length * 2; i += 2) {
            int a = num & 3;
            num >>= 2;
            ret = dic[a] + ret;
        }
        return ret;
    }
};